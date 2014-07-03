/***********************************************************************
    created:    Sun, 6th April 2014
    author:     Lukas E Meindl
*************************************************************************/
/***************************************************************************
 *   Copyright (C) 2004 - 2014 Paul D Turner & The CEGUI Development Team
 *
 *   Permission is hereby granted, free of charge, to any person obtaining
 *   a copy of this software and associated documentation files (the
 *   "Software"), to deal in the Software without restriction, including
 *   without limitation the rights to use, copy, modify, merge, publish,
 *   distribute, sublicense, and/or sell copies of the Software, and to
 *   permit persons to whom the Software is furnished to do so, subject to
 *   the following conditions:
 *
 *   The above copyright notice and this permission notice shall be
 *   included in all copies or substantial portions of the Software.
 *
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 *   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 *   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 *   IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 *   OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 *   ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 *   OTHER DEALINGS IN THE SOFTWARE.
 ***************************************************************************/
#include "CEGUI/RendererModules/Direct3D11/Renderer.h"
#include "CEGUI/RendererModules/Direct3D11/GeometryBuffer.h"
#include "CEGUI/RendererModules/Direct3D11/TextureTarget.h"
#include "CEGUI/RendererModules/Direct3D11/ViewportTarget.h"
#include "CEGUI/RendererModules/Direct3D11/Texture.h"
#include "CEGUI/RendererModules/Direct3D11/ShaderWrapper.h"
#include "CEGUI/RendererModules/Direct3D11/Shader.h"
#include "CEGUI/Exceptions.h"
#include "CEGUI/System.h"
#include "CEGUI/DefaultResourceProvider.h"
#include "CEGUI/Logger.h"
#include "Shaders.inl"

#include <algorithm>

// Start of CEGUI namespace section
namespace CEGUI
{
//----------------------------------------------------------------------------//
const String Direct3D11Renderer::d_rendererID(
"CEGUI::Direct3D11Renderer - Official Direct3D 11 based 3rd generation renderer module.");


//----------------------------------------------------------------------------//
Direct3D11Renderer::Direct3D11Renderer(ID3D11Device* device,
                                       ID3D11DeviceContext*deviceContext)
    : d_device(device)
    , d_deviceContext(deviceContext)
    , d_displayDPI(96, 96)
    , d_defaultTarget(0)
    , d_samplerState(0)
    , d_currentBlendState(0)
    , d_currentRasterizerState(0)
{
 
	if(!device || !deviceContext) 
	{
		std::string msg("In Order To Use Direct3D11 Module, You Must Provide Both Device And Context");
		CEGUI_THROW(RendererException(msg));
	}

	d_displaySize = getViewportSize();

    d_defaultTarget = new Direct3D11ViewportTarget(*this);

    initialiseSamplerStates();
    initialiseBlendStates();
    initialiseRasterizerStates();
    initialiseDepthStencilState();

    


    initialiseShaders();
}

//----------------------------------------------------------------------------//
Direct3D11Renderer::~Direct3D11Renderer()
{
    destroyAllTextureTargets();
    destroyAllTextures();
    destroyAllGeometryBuffers();

    d_blendStateNormal->Release();
    d_blendStatePreMultiplied->Release();

    delete d_defaultTarget;

    delete d_shaderWrapperTextured;
    delete d_shaderWrapperSolid;
}

//----------------------------------------------------------------------------//
Direct3D11Renderer& Direct3D11Renderer::bootstrapSystem(ID3D11Device* device,
                                                        ID3D11DeviceContext* context,
                                                        const int abi)
{
    System::performVersionTest(CEGUI_VERSION_ABI, abi, CEGUI_FUNCTION_NAME);

    if (System::getSingletonPtr())
        CEGUI_THROW(InvalidRequestException(
            "CEGUI::System object is already initialised."));

    Direct3D11Renderer& renderer(create(device, context));
    DefaultResourceProvider* rp = new CEGUI::DefaultResourceProvider();
    System::create(renderer, rp);

    return renderer;
}

//----------------------------------------------------------------------------//
void Direct3D11Renderer::destroySystem()
{
    System* sys;
    if (!(sys = System::getSingletonPtr()))
        CEGUI_THROW(InvalidRequestException(
            "CEGUI::System object is not created or was already destroyed."));

    Direct3D11Renderer* renderer =
        static_cast<Direct3D11Renderer*>(sys->getRenderer());
    DefaultResourceProvider* rp =
        static_cast<DefaultResourceProvider*>(sys->getResourceProvider());

    System::destroy();
    delete rp;
    destroy(*renderer);
}

//----------------------------------------------------------------------------//
Direct3D11Renderer& Direct3D11Renderer::create(ID3D11Device* device,
                                               ID3D11DeviceContext* context,
                                               const int abi)
{
    System::performVersionTest(CEGUI_VERSION_ABI, abi, CEGUI_FUNCTION_NAME);

    return *new Direct3D11Renderer(device, context);
}

//----------------------------------------------------------------------------//
void Direct3D11Renderer::destroy(Direct3D11Renderer& renderer)
{
    delete &renderer;
}

//----------------------------------------------------------------------------//
RenderTarget& Direct3D11Renderer::getDefaultRenderTarget()
{
    return *d_defaultTarget;
}

//----------------------------------------------------------------------------//
void Direct3D11Renderer::destroyGeometryBuffer(const GeometryBuffer& buffer)
{
    GeometryBufferList::iterator i = std::find(d_geometryBuffers.begin(),
                                               d_geometryBuffers.end(),
                                               &buffer);

    if (d_geometryBuffers.end() != i)
    {
        d_geometryBuffers.erase(i);
        delete &buffer;
    }
}

//----------------------------------------------------------------------------//
void Direct3D11Renderer::destroyAllGeometryBuffers()
{
    while (!d_geometryBuffers.empty())
        destroyGeometryBuffer(**d_geometryBuffers.begin());
}

//----------------------------------------------------------------------------//
TextureTarget* Direct3D11Renderer::createTextureTarget()
{
    TextureTarget* t = new Direct3D11TextureTarget(*this);
    d_textureTargets.push_back(t);
    return t;
}

//----------------------------------------------------------------------------//
void Direct3D11Renderer::destroyTextureTarget(TextureTarget* target)
{
    TextureTargetList::iterator i = std::find(d_textureTargets.begin(),
                                              d_textureTargets.end(),
                                              target);

    if (d_textureTargets.end() != i)
    {
        d_textureTargets.erase(i);
        delete target;
    }
}

//----------------------------------------------------------------------------//
void Direct3D11Renderer::destroyAllTextureTargets()
{
    while (!d_textureTargets.empty())
        destroyTextureTarget(*d_textureTargets.begin());
}

//----------------------------------------------------------------------------//
Texture& Direct3D11Renderer::createTexture(const String& name)
{
    throwIfNameExists(name);

    Direct3D11Texture* tex = new Direct3D11Texture(*d_device, *d_deviceContext, name);
    d_textures[name] = tex;

    logTextureCreation(name);

    return *tex;
}

//----------------------------------------------------------------------------//
Texture& Direct3D11Renderer::createTexture(const String& name,
                                           const String& filename,
                                           const String& resourceGroup)
{
    throwIfNameExists(name);

    Direct3D11Texture* tex = new Direct3D11Texture(*d_device, *d_deviceContext,
                                                   name, filename,
                                                   resourceGroup);
    d_textures[name] = tex;

    logTextureCreation(name);

    return *tex;
}

//----------------------------------------------------------------------------//
Texture& Direct3D11Renderer::createTexture(const String& name,
                                           const Sizef& size)
{
    throwIfNameExists(name);

    Direct3D11Texture* tex = new Direct3D11Texture(*d_device, *d_deviceContext, name, size);
    d_textures[name] = tex;

    logTextureCreation(name);

    return *tex;
}

//----------------------------------------------------------------------------//
void Direct3D11Renderer::throwIfNameExists(const String& name) const
{
    if (d_textures.find(name) != d_textures.end())
        CEGUI_THROW(AlreadyExistsException(
            "[Direct3D11Renderer] Texture already exists: " + name));
}

//----------------------------------------------------------------------------//
void Direct3D11Renderer::logTextureCreation(const String& name)
{
    Logger* logger = Logger::getSingletonPtr();
    if (logger)
        logger->logEvent("[Direct3D11Renderer] Created texture: " + name);
}

//----------------------------------------------------------------------------//
void Direct3D11Renderer::destroyTexture(Texture& texture)
{
    destroyTexture(texture.getName());
}

//----------------------------------------------------------------------------//
void Direct3D11Renderer::destroyTexture(const String& name)
{
    TextureMap::iterator i = d_textures.find(name);

    if (d_textures.end() != i)
    {
        logTextureDestruction(name);
        delete i->second;
        d_textures.erase(i);
    }
}

//----------------------------------------------------------------------------//
void Direct3D11Renderer::logTextureDestruction(const String& name)
{
    Logger* logger = Logger::getSingletonPtr();
    if (logger)
        logger->logEvent("[Direct3D11Renderer] Destroyed texture: " + name);
}

//----------------------------------------------------------------------------//
void Direct3D11Renderer::destroyAllTextures()
{
    while (!d_textures.empty())
        destroyTexture(d_textures.begin()->first);
}

//----------------------------------------------------------------------------//
Texture& Direct3D11Renderer::getTexture(const String& name) const
{
    TextureMap::const_iterator i = d_textures.find(name);
    
    if (i == d_textures.end())
        CEGUI_THROW(UnknownObjectException("Texture does not exist: " + name));

    return *i->second;
}

//----------------------------------------------------------------------------//
bool Direct3D11Renderer::isTextureDefined(const String& name) const
{
    return d_textures.find(name) != d_textures.end();
}

//----------------------------------------------------------------------------//
void Direct3D11Renderer::beginRendering()
{
    d_currentBlendState = 0;
    d_currentRasterizerState = 0;

    d_deviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
    d_deviceContext->OMSetDepthStencilState(d_depthStencilStateDefault, 0);
    d_deviceContext->PSSetSamplers(0, 1, &d_samplerState);
}

//----------------------------------------------------------------------------//
void Direct3D11Renderer::endRendering()
{
}

//----------------------------------------------------------------------------//
void Direct3D11Renderer::setDisplaySize(const Sizef& sz)
{
    if (sz != d_displaySize)
    {
        d_displaySize = sz;

        // FIXME: This is probably not the right thing to do in all cases.
        Rectf area(d_defaultTarget->getArea());
        area.setSize(sz);
        d_defaultTarget->setArea(area);
    }
}

//----------------------------------------------------------------------------//
const Sizef& Direct3D11Renderer::getDisplaySize() const
{
    return d_displaySize;
}

//----------------------------------------------------------------------------//
const Vector2f& Direct3D11Renderer::getDisplayDPI() const
{
    return d_displayDPI;
}

//----------------------------------------------------------------------------//
uint Direct3D11Renderer::getMaxTextureSize() const
{
    //Values taken from http://msdn.microsoft.com/en-us/library/windows/desktop/ff476876%28v=vs.85%29.aspx
    D3D_FEATURE_LEVEL featureLevel = d_device->GetFeatureLevel();
    
    switch(featureLevel)
    {
    default:
    case D3D_FEATURE_LEVEL_11_0:
        return D3D11_REQ_TEXTURE2D_U_OR_V_DIMENSION;
        break;
    case D3D_FEATURE_LEVEL_10_1:
        return D3D10_REQ_TEXTURE2D_U_OR_V_DIMENSION;
        break;
    case D3D_FEATURE_LEVEL_10_0:
        return D3D10_REQ_TEXTURE2D_U_OR_V_DIMENSION;
        break;
    case D3D_FEATURE_LEVEL_9_3:
        return 4096;
        break;
    case D3D_FEATURE_LEVEL_9_2:
        return 2048;
        break;
    case D3D_FEATURE_LEVEL_9_1:
        return 2048;
        break;
    }   
}

//----------------------------------------------------------------------------//
const String& Direct3D11Renderer::getIdentifierString() const
{
    return d_rendererID;
}

//----------------------------------------------------------------------------//
Sizef Direct3D11Renderer::getViewportSize()
{
    D3D11_VIEWPORT vp;
    UINT vp_count = 1;

    d_deviceContext->RSGetViewports(&vp_count, &vp);

    if (vp_count != 1)
        CEGUI_THROW(RendererException(
            "Unable to access required view port information from "
            "ID3D11Device."));
    else
        return Sizef(static_cast<float>(vp.Width),
                      static_cast<float>(vp.Height));
}

//----------------------------------------------------------------------------//
void Direct3D11Renderer::setViewProjectionMatrix(const glm::mat4& viewProjectionMatrix)
{
    d_viewProjectionMatrix = viewProjectionMatrix;
}

//----------------------------------------------------------------------------//
const glm::mat4& Direct3D11Renderer::getViewProjectionMatrix()
{
    return d_viewProjectionMatrix;
}

//----------------------------------------------------------------------------//
GeometryBuffer& Direct3D11Renderer::createGeometryBufferTextured(CEGUI::RefCounted<RenderMaterial> renderMaterial)
{
    Direct3D11GeometryBuffer* geom_buffer = CEGUI_NEW_AO Direct3D11GeometryBuffer(*this, renderMaterial);

    geom_buffer->addVertexAttribute(VAT_POSITION0);
    geom_buffer->addVertexAttribute(VAT_COLOUR0);
    geom_buffer->addVertexAttribute(VAT_TEXCOORD0);
    geom_buffer->finaliseVertexAttributes();

    addGeometryBuffer(*geom_buffer);
    return *geom_buffer;
}

//----------------------------------------------------------------------------//
GeometryBuffer& Direct3D11Renderer::createGeometryBufferColoured(CEGUI::RefCounted<RenderMaterial> renderMaterial)
{
    Direct3D11GeometryBuffer* geom_buffer = CEGUI_NEW_AO Direct3D11GeometryBuffer(*this, renderMaterial);

    geom_buffer->addVertexAttribute(VAT_POSITION0);
    geom_buffer->addVertexAttribute(VAT_COLOUR0);
    geom_buffer->finaliseVertexAttributes();

    addGeometryBuffer(*geom_buffer);
    return *geom_buffer;
}

//----------------------------------------------------------------------------//
RefCounted<RenderMaterial> Direct3D11Renderer::createRenderMaterial(const DefaultShaderType shaderType) const
{
    if(shaderType == DS_TEXTURED)
    {
        RefCounted<RenderMaterial> render_material(CEGUI_NEW_AO RenderMaterial(d_shaderWrapperTextured));

        return render_material;
    }
    else if(shaderType == DS_SOLID)
    {
        RefCounted<RenderMaterial> render_material(CEGUI_NEW_AO RenderMaterial(d_shaderWrapperSolid));

        return render_material;
    }
    else
    {
        CEGUI_THROW(RendererException("A default shader of this type does not exist."));

        return RefCounted<RenderMaterial>();
    }
}

//----------------------------------------------------------------------------//
void Direct3D11Renderer::initialiseStandardTexturedShaderWrapper()
{
    Direct3D11Shader* shader_standard_textured = CEGUI_NEW_AO Direct3D11Shader(*this, VertexShaderTextured, PixelShaderTextured);
    d_shaderWrapperTextured = CEGUI_NEW_AO Direct3D11ShaderWrapper(*shader_standard_textured, this);

    d_shaderWrapperTextured->addUniformVariable("texture0", ST_PIXEL, SPT_TEXTURE);

    d_shaderWrapperTextured->addUniformVariable("modelViewPerspMatrix", ST_VERTEX, SPT_MATRIX_4X4);
}

//----------------------------------------------------------------------------//
void Direct3D11Renderer::initialiseStandardColouredShaderWrapper()
{
    Direct3D11Shader* shader_standard_solid = CEGUI_NEW_AO Direct3D11Shader(*this, VertexShaderColoured, PixelShaderColoured);
    d_shaderWrapperSolid = CEGUI_NEW_AO Direct3D11ShaderWrapper(*shader_standard_solid, this);

    d_shaderWrapperSolid->addUniformVariable("modelViewPerspMatrix", ST_VERTEX, SPT_MATRIX_4X4);
}

//----------------------------------------------------------------------------//
void Direct3D11Renderer::initialiseShaders()
{
    initialiseStandardColouredShaderWrapper();
    initialiseStandardTexturedShaderWrapper();
}

//----------------------------------------------------------------------------//
ID3D11DeviceContext* Direct3D11Renderer::getDirect3DDeviceContext()
{
    return d_deviceContext;
}

//----------------------------------------------------------------------------//
ID3D11Device* Direct3D11Renderer::getDirect3DDevice()
{
    return d_device;
}

//----------------------------------------------------------------------------//
void Direct3D11Renderer::initialiseBlendStates()
{
    HRESULT result;

    D3D11_BLEND_DESC blendDesc;
    ZeroMemory(&blendDesc, sizeof(blendDesc));

    D3D11_RENDER_TARGET_BLEND_DESC rtbd;
    ZeroMemory(&rtbd, sizeof(rtbd));

    blendDesc.AlphaToCoverageEnable = FALSE;
    blendDesc.IndependentBlendEnable = FALSE;

    rtbd.BlendEnable			 = TRUE;
    rtbd.SrcBlend				 = D3D11_BLEND_SRC_ALPHA;
    rtbd.DestBlend				 = D3D11_BLEND_INV_SRC_ALPHA;
    rtbd.BlendOp                 = D3D11_BLEND_OP_ADD;
    rtbd.SrcBlendAlpha			 = D3D11_BLEND_INV_DEST_ALPHA;
    rtbd.DestBlendAlpha			 = D3D11_BLEND_ONE;
    rtbd.BlendOpAlpha            = D3D11_BLEND_OP_ADD;
    rtbd.RenderTargetWriteMask   = D3D11_COLOR_WRITE_ENABLE_ALL;
    blendDesc.RenderTarget[0]    = rtbd;

    result = d_device->CreateBlendState(&blendDesc, &d_blendStateNormal);
    if(FAILED(result))
        CEGUI_THROW(RendererException("Creation of BlendState failed"));

    ZeroMemory(&blendDesc, sizeof(blendDesc));
    ZeroMemory(&rtbd, sizeof(rtbd));

    blendDesc.AlphaToCoverageEnable = FALSE;
    blendDesc.IndependentBlendEnable = FALSE;

    rtbd.BlendEnable			 = TRUE;
    rtbd.SrcBlend				 = D3D11_BLEND_ONE;
    rtbd.DestBlend				 = D3D11_BLEND_INV_SRC_ALPHA;
    rtbd.BlendOp                 = D3D11_BLEND_OP_ADD;
    rtbd.SrcBlendAlpha			 = D3D11_BLEND_ONE;
    rtbd.DestBlendAlpha			 = D3D11_BLEND_INV_SRC_ALPHA;
    rtbd.BlendOpAlpha            = D3D11_BLEND_OP_ADD;
    rtbd.RenderTargetWriteMask   = D3D11_COLOR_WRITE_ENABLE_ALL;
    blendDesc.RenderTarget[0]    = rtbd;

    result = d_device->CreateBlendState(&blendDesc, &d_blendStatePreMultiplied);
    if(FAILED(result))
        CEGUI_THROW(RendererException("Creation of BlendState failed"));
}

//----------------------------------------------------------------------------//
void Direct3D11Renderer::bindBlendMode(BlendMode d_blendMode)
{
    const FLOAT blendFactor[4] = {0.0f, 0.0f, 0.0f, 0.0f};

    if (d_blendMode == BM_NORMAL)
    {
        if (d_currentBlendState != d_blendStateNormal)
        {
            d_deviceContext->OMSetBlendState(d_blendStateNormal, blendFactor, 0xFFFFFFFF);
            d_currentBlendState = d_blendStateNormal;
        }
    }

    if (d_blendMode == BM_RTT_PREMULTIPLIED)
    {
        if (d_currentBlendState != d_blendStatePreMultiplied)
        {
            d_deviceContext->OMSetBlendState(d_blendStatePreMultiplied, blendFactor, 0xFFFFFFFF);
            d_currentBlendState = d_blendStatePreMultiplied;
        }
    }
}

//----------------------------------------------------------------------------//
void Direct3D11Renderer::bindRasterizerState(bool scissorEnabled)
{
    if (scissorEnabled)
    {
        if (d_currentRasterizerState != d_rasterizerStateScissorEnabled)
        {
            d_deviceContext->RSSetState(d_rasterizerStateScissorEnabled);
            d_currentRasterizerState = d_rasterizerStateScissorEnabled;
        }
    }
    else
    {
        if (d_currentRasterizerState != d_rasterizerStateScissorDisabled)
        {
            d_deviceContext->RSSetState(d_rasterizerStateScissorDisabled);
            d_currentRasterizerState = d_rasterizerStateScissorDisabled;
        }
    }
}

//----------------------------------------------------------------------------//
void Direct3D11Renderer::initialiseRasterizerStates()
{
    D3D11_RASTERIZER_DESC cmdesc;
    ZeroMemory(&cmdesc, sizeof(D3D11_RASTERIZER_DESC));

    cmdesc.FillMode = D3D11_FILL_SOLID;
    cmdesc.CullMode = D3D11_CULL_NONE;
    cmdesc.DepthClipEnable = TRUE;
    cmdesc.ScissorEnable = TRUE;

    HRESULT result = d_device->CreateRasterizerState(&cmdesc, &d_rasterizerStateScissorEnabled);

    ZeroMemory(&cmdesc, sizeof(D3D11_RASTERIZER_DESC));

    cmdesc.FillMode = D3D11_FILL_SOLID;
    cmdesc.CullMode = D3D11_CULL_NONE;
    cmdesc.DepthClipEnable = TRUE;
    cmdesc.ScissorEnable = FALSE;

    result = d_device->CreateRasterizerState(&cmdesc, &d_rasterizerStateScissorDisabled);

    ZeroMemory(&cmdesc, sizeof(D3D11_RASTERIZER_DESC));
}

//----------------------------------------------------------------------------//
void Direct3D11Renderer::initialiseDepthStencilState()
{
    D3D11_DEPTH_STENCIL_DESC depthStencilDesc;
    ZeroMemory(&depthStencilDesc, sizeof(D3D11_DEPTH_STENCIL_DESC));

    depthStencilDesc.DepthEnable                    = FALSE;
    depthStencilDesc.DepthWriteMask                 = D3D11_DEPTH_WRITE_MASK_ZERO;
    depthStencilDesc.DepthFunc                      = D3D11_COMPARISON_LESS;
    depthStencilDesc.StencilEnable                  = FALSE;
    depthStencilDesc.StencilReadMask                = 0x00;
    depthStencilDesc.StencilWriteMask               = 0x00;
    depthStencilDesc.FrontFace.StencilFunc          = D3D11_COMPARISON_ALWAYS;
    depthStencilDesc.BackFace.StencilFunc           = D3D11_COMPARISON_ALWAYS;
    depthStencilDesc.FrontFace.StencilDepthFailOp   = D3D11_STENCIL_OP_KEEP;
    depthStencilDesc.BackFace.StencilDepthFailOp    = D3D11_STENCIL_OP_KEEP;
    depthStencilDesc.FrontFace.StencilPassOp        = D3D11_STENCIL_OP_KEEP;
    depthStencilDesc.BackFace.StencilPassOp         = D3D11_STENCIL_OP_KEEP;
    depthStencilDesc.FrontFace.StencilFailOp        = D3D11_STENCIL_OP_KEEP;
    depthStencilDesc.BackFace.StencilFailOp         = D3D11_STENCIL_OP_KEEP;
 
    HRESULT result = d_device->CreateDepthStencilState(&depthStencilDesc, &d_depthStencilStateDefault);
    if(FAILED(result))
        CEGUI_THROW(RendererException("SamplerDescription creation failed"));
}

//----------------------------------------------------------------------------//
void CEGUI::Direct3D11Renderer::initialiseSamplerStates()
{
    D3D11_SAMPLER_DESC samplerDescription;
    ZeroMemory( &samplerDescription, sizeof(samplerDescription) );
    samplerDescription.Filter =         D3D11_FILTER_MIN_MAG_MIP_LINEAR;
    samplerDescription.AddressU =       D3D11_TEXTURE_ADDRESS_CLAMP;
    samplerDescription.AddressV =       D3D11_TEXTURE_ADDRESS_CLAMP;
    samplerDescription.AddressW =       D3D11_TEXTURE_ADDRESS_CLAMP;
    samplerDescription.ComparisonFunc = D3D11_COMPARISON_NEVER;
    samplerDescription.MinLOD =         0;
    samplerDescription.MaxLOD =         D3D11_FLOAT32_MAX;

    HRESULT result = d_device->CreateSamplerState( &samplerDescription, &d_samplerState );
    if(FAILED(result))
        CEGUI_THROW(RendererException("SamplerDescription creation failed"));
}


//----------------------------------------------------------------------------//

} // End of  CEGUI namespace section

