// This file has been generated by Py++.

#include "boost/python.hpp"
#include "generators/include/python_CEGUI.h"
#include "WidgetLookManager.pypp.hpp"

namespace bp = boost::python;

void register_WidgetLookManager_class(){

    { //::CEGUI::WidgetLookManager
        typedef bp::class_< CEGUI::WidgetLookManager, bp::bases< CEGUI::Singleton< CEGUI::WidgetLookManager > >, boost::noncopyable > WidgetLookManager_exposer_t;
        WidgetLookManager_exposer_t WidgetLookManager_exposer = WidgetLookManager_exposer_t( "WidgetLookManager", bp::init< >("*!\n\
        \n\
            Constructor.\n\
        *\n") );
        bp::scope WidgetLookManager_scope( WidgetLookManager_exposer );
        { //::CEGUI::WidgetLookManager::addWidgetLook
        
            typedef void ( ::CEGUI::WidgetLookManager::*addWidgetLook_function_type )( ::CEGUI::WidgetLookFeel const & ) ;
            
            WidgetLookManager_exposer.def( 
                "addWidgetLook"
                , addWidgetLook_function_type( &::CEGUI::WidgetLookManager::addWidgetLook )
                , ( bp::arg("look") )
                , "*!\n\
                    \n\
                        Add the given WidgetLookFeel.\n\
            \n\
                    \note\n\
                        If the WidgetLookFeel specification uses a name that already exists within the system,\
                        it is not an error;\n\
                        the previous definition is overwritten by the new data.  An entry will appear in the log\
                        each time any\n\
                        look & feel component is overwritten.\n\
            \n\
                    @param look\n\
                        WidgetLookFeel object to be added to the system.  NB: The WidgetLookFeel is copied, no\
                        change of ownership of the\n\
                        input object occurrs.\n\
            \n\
                    @return\n\
                        Nothing.\n\
                    *\n" );
        
        }
        { //::CEGUI::WidgetLookManager::eraseAllWidgetLooks
        
            typedef void ( ::CEGUI::WidgetLookManager::*eraseAllWidgetLooks_function_type )(  ) ;
            
            WidgetLookManager_exposer.def( 
                "eraseAllWidgetLooks"
                , eraseAllWidgetLooks_function_type( &::CEGUI::WidgetLookManager::eraseAllWidgetLooks )
                , "! erase all defined WidgetLookFeel.\n" );
        
        }
        { //::CEGUI::WidgetLookManager::eraseWidgetLook
        
            typedef void ( ::CEGUI::WidgetLookManager::*eraseWidgetLook_function_type )( ::CEGUI::String const & ) ;
            
            WidgetLookManager_exposer.def( 
                "eraseWidgetLook"
                , eraseWidgetLook_function_type( &::CEGUI::WidgetLookManager::eraseWidgetLook )
                , ( bp::arg("widget") )
                , "*!\n\
                    \n\
                        Erase the WidgetLookFeel that has the specified name.\n\
            \n\
                    @param widget\n\
                        String object holding the name of a widget look to be erased.  If no such WidgetLookFeel\
                        exists, nothing\n\
                        happens.\n\
            \n\
                    @return\n\
                        Nothing.\n\
                    *\n" );
        
        }
        { //::CEGUI::WidgetLookManager::getDefaultResourceGroup
        
            typedef ::CEGUI::String const & ( *getDefaultResourceGroup_function_type )(  );
            
            WidgetLookManager_exposer.def( 
                "getDefaultResourceGroup"
                , getDefaultResourceGroup_function_type( &::CEGUI::WidgetLookManager::getDefaultResourceGroup )
                , bp::return_value_policy< bp::copy_const_reference >()
                , "*!\n\
                    \n\
                        Returns the default resource group currently set for LookNFeels.\n\
            \n\
                    @return\n\
                        String describing the default resource group identifier that will be\n\
                        used when loading LookNFeel data.\n\
                    *\n" );
        
        }
        { //::CEGUI::WidgetLookManager::getSingleton
        
            typedef ::CEGUI::WidgetLookManager & ( *getSingleton_function_type )(  );
            
            WidgetLookManager_exposer.def( 
                "getSingleton"
                , getSingleton_function_type( &::CEGUI::WidgetLookManager::getSingleton )
                , bp::return_value_policy< bp::reference_existing_object >()
                , "*!\n\
                     \n\
                          Return singleton WidgetLookManager object\n\
            \n\
                     @return\n\
                          Singleton WidgetLookManager object\n\
                     *\n" );
        
        }
        { //::CEGUI::WidgetLookManager::getWidgetLook
        
            typedef ::CEGUI::WidgetLookFeel const & ( ::CEGUI::WidgetLookManager::*getWidgetLook_function_type )( ::CEGUI::String const & ) const;
            
            WidgetLookManager_exposer.def( 
                "getWidgetLook"
                , getWidgetLook_function_type( &::CEGUI::WidgetLookManager::getWidgetLook )
                , ( bp::arg("widget") )
                , bp::return_value_policy< bp::copy_const_reference >()
                , "*!\n\
                    \n\
                        Return a const reference to a WidgetLookFeel object which has the specified name.\n\
            \n\
                    @param widget\n\
                        String object holding the name of a widget look that is to be returned.\n\
            \n\
                    @return\n\
                        const reference to the requested WidgetLookFeel object.\n\
            \n\
                    @exception UnknownObjectException   thrown if no WidgetLookFeel is available with the\
                    requested name.\n\
                    *\n" );
        
        }
        { //::CEGUI::WidgetLookManager::getWidgetLookAsString
        
            typedef ::CEGUI::String ( ::CEGUI::WidgetLookManager::*getWidgetLookAsString_function_type )( ::CEGUI::String const & ) const;
            
            WidgetLookManager_exposer.def( 
                "getWidgetLookAsString"
                , getWidgetLookAsString_function_type( &::CEGUI::WidgetLookManager::getWidgetLookAsString )
                , ( bp::arg("widgetLookName") )
                , "*!\n\
                    \n\
                        Writes a complete WidgetLookFeel to a string. Note that XML file header and\n\
                        Falagard openingclosing tags will also be written.\n\
            \n\
                    @param name\n\
                        String holding the name of the WidgetLookFeel to be output to the string.\n\
            \n\
                    @return\n\
                        String containing the WidgetLook parsed to XML.\n\
                    *\n" );
        
        }
        { //::CEGUI::WidgetLookManager::getWidgetLookIterator
        
            typedef ::CEGUI::ConstMapIterator< std::map<CEGUI::String, CEGUI::WidgetLookFeel, CEGUI::StringFastLessCompare, std::allocator<std::pair<CEGUI::String const, CEGUI::WidgetLookFeel> > > > ( ::CEGUI::WidgetLookManager::*getWidgetLookIterator_function_type )(  ) const;
            
            WidgetLookManager_exposer.def( 
                "getWidgetLookIterator"
                , getWidgetLookIterator_function_type( &::CEGUI::WidgetLookManager::getWidgetLookIterator )
                , "!  deprecated Marked for removal in the next version.\n\
            !  deprecated Marked for removal in the next version.\n" );
        
        }
        { //::CEGUI::WidgetLookManager::getWidgetLookMap
        
            typedef ::std::map<CEGUI::String,CEGUI::WidgetLookFeel*,CEGUI::StringFastLessCompare,std::allocator<std::pair<const CEGUI::String, CEGUI::WidgetLookFeel*> > > ( ::CEGUI::WidgetLookManager::*getWidgetLookMap_function_type )(  ) ;
            
            WidgetLookManager_exposer.def( 
                "getWidgetLookMap"
                , getWidgetLookMap_function_type( &::CEGUI::WidgetLookManager::getWidgetLookMap )
                , "*!\n\
                    \n\
                        Returns a map containing Strings to WidgetLookFeel pointers. The map contains pointers\
                        to the WidgetLookFeels\n\
                        that were added to this Manager.\n\
            \n\
                    @return\n\
                        A map of Strings to WidgetLookFeel pointers.\n\
                    *\n" );
        
        }
        { //::CEGUI::WidgetLookManager::getWidgetLookSetAsString
        
            typedef ::CEGUI::String ( ::CEGUI::WidgetLookManager::*getWidgetLookSetAsString_function_type )( ::std::set<CEGUI::String, CEGUI::StringFastLessCompare, std::allocator<CEGUI::String> > const & ) const;
            
            WidgetLookManager_exposer.def( 
                "getWidgetLookSetAsString"
                , getWidgetLookSetAsString_function_type( &::CEGUI::WidgetLookManager::getWidgetLookSetAsString )
                , ( bp::arg("widgetLookNameSet") )
                , "*!\n\
                    \n\
                        Writes a set WidgetLookFeels to a string. Note that XML file header and\n\
                        Falagard openingclosing tags will also be written.\n\
            \n\
                    @param widgetLookNameSet\n\
                        Set of strings containing the WidgetLookFeel names to be output to the string.\n\
            \n\
                    @return\n\
                        String containing the set of WidgetLookFeels parsed to XML.\n\
                    *\n" );
        
        }
        { //::CEGUI::WidgetLookManager::isWidgetLookAvailable
        
            typedef bool ( ::CEGUI::WidgetLookManager::*isWidgetLookAvailable_function_type )( ::CEGUI::String const & ) const;
            
            WidgetLookManager_exposer.def( 
                "isWidgetLookAvailable"
                , isWidgetLookAvailable_function_type( &::CEGUI::WidgetLookManager::isWidgetLookAvailable )
                , ( bp::arg("widget") )
                , "*!\n\
                    \n\
                        Return whether a WidgetLookFeel has been created with the specified name.\n\
            \n\
                    @param widget\n\
                        String object holding the name of a widget look to test for.\n\
            \n\
                    @return\n\
                        - true if a WidgetLookFeel named  widget is available.\n\
                        - false if so such WidgetLookFeel is currently available.\n\
                    *\n" );
        
        }
        { //::CEGUI::WidgetLookManager::parseLookNFeelSpecificationFromContainer
        
            typedef void ( ::CEGUI::WidgetLookManager::*parseLookNFeelSpecificationFromContainer_function_type )( ::CEGUI::RawDataContainer const & ) ;
            
            WidgetLookManager_exposer.def( 
                "parseLookNFeelSpecificationFromContainer"
                , parseLookNFeelSpecificationFromContainer_function_type( &::CEGUI::WidgetLookManager::parseLookNFeelSpecificationFromContainer )
                , ( bp::arg("source") )
                , "*!\n\
                    \n\
                        Parses a file containing window look & feel specifications (in the form of XML).\n\
            \n\
                    \note\n\
                        If the new file contains specifications for widget types that are already specified, it\
                        is not an error;\n\
                        the previous definitions are overwritten by the new data.  An entry will appear in the\
                        log each time any\n\
                        look & feel component is overwritten.\n\
            \n\
                    @param source\n\
                        RawDataContainer containing the source code that will be parsed\n\
            \n\
                    @param resourceGroup\n\
                        Resource group identifier to pass to the resource provider when loading the file.\n\
            \n\
                    @return\n\
                        Nothing.\n\
            \n\
                    @exception FileIOException             thrown if there was some problem accessing or parsing\
                    the file  filename\n\
                    @exception InvalidRequestException     thrown if an invalid filename was provided.\n\
                    *\n" );
        
        }
        { //::CEGUI::WidgetLookManager::parseLookNFeelSpecificationFromFile
        
            typedef void ( ::CEGUI::WidgetLookManager::*parseLookNFeelSpecificationFromFile_function_type )( ::CEGUI::String const &,::CEGUI::String const & ) ;
            
            WidgetLookManager_exposer.def( 
                "parseLookNFeelSpecificationFromFile"
                , parseLookNFeelSpecificationFromFile_function_type( &::CEGUI::WidgetLookManager::parseLookNFeelSpecificationFromFile )
                , ( bp::arg("filename"), bp::arg("resourceGroup")="" )
                , "*!\n\
            @see WidgetLookManager.parseLookNFeelSpecificationFromContainer\n\
            *\n" );
        
        }
        { //::CEGUI::WidgetLookManager::parseLookNFeelSpecificationFromString
        
            typedef void ( ::CEGUI::WidgetLookManager::*parseLookNFeelSpecificationFromString_function_type )( ::CEGUI::String const & ) ;
            
            WidgetLookManager_exposer.def( 
                "parseLookNFeelSpecificationFromString"
                , parseLookNFeelSpecificationFromString_function_type( &::CEGUI::WidgetLookManager::parseLookNFeelSpecificationFromString )
                , ( bp::arg("source") )
                , "*!\n\
            @see WidgetLookManager.parseLookNFeelSpecificationFromContainer\n\
            *\n" );
        
        }
        { //::CEGUI::WidgetLookManager::setDefaultResourceGroup
        
            typedef void ( *setDefaultResourceGroup_function_type )( ::CEGUI::String const & );
            
            WidgetLookManager_exposer.def( 
                "setDefaultResourceGroup"
                , setDefaultResourceGroup_function_type( &::CEGUI::WidgetLookManager::setDefaultResourceGroup )
                , ( bp::arg("resourceGroup") )
                , "*!\n\
                    \n\
                        Sets the default resource group to be used when loading LookNFeel data\n\
            \n\
                    @param resourceGroup\n\
                        String describing the default resource group identifier to be used.\n\
            \n\
                    @return\n\
                        Nothing.\n\
                    *\n" );
        
        }
        { //::CEGUI::WidgetLookManager::writeWidgetLookSeriesToStream
        
            typedef void ( ::CEGUI::WidgetLookManager::*writeWidgetLookSeriesToStream_function_type )( ::CEGUI::String const &,::CEGUI::OutStream & ) const;
            
            WidgetLookManager_exposer.def( 
                "writeWidgetLookSeriesToStream"
                , writeWidgetLookSeriesToStream_function_type( &::CEGUI::WidgetLookManager::writeWidgetLookSeriesToStream )
                , ( bp::arg("prefix"), bp::arg("out_stream") )
                , "*!\n\
                    \n\
                        Writes a series of complete WidgetLook objects to a stream. Note that XML file header\
                        and\n\
                        Falagard openingclosing tags will also be written.\n\
            \n\
                        The  prefix specifies a name prefix common to all widget looks to be written, you\
                        could\n\
                        specify this as TaharezLook and then any defined widget look starting with that prefix,\
                        such\n\
                        as TaharezLookButton and TaharezLookListbox will be written to the stream.\n\
            \n\
                    @param prefix\n\
                        String holding the widget look name prefix, which will be used when searching for the\
                        widget looks\n\
                        to be output to the stream.\n\
            \n\
                    @param out_stream\n\
                        OutStream where XML data should be sent.\n\
                    *\n" );
        
        }
        { //::CEGUI::WidgetLookManager::writeWidgetLookSetToStream
        
            typedef void ( ::CEGUI::WidgetLookManager::*writeWidgetLookSetToStream_function_type )( ::std::set<CEGUI::String, CEGUI::StringFastLessCompare, std::allocator<CEGUI::String> > const &,::CEGUI::OutStream & ) const;
            
            WidgetLookManager_exposer.def( 
                "writeWidgetLookSetToStream"
                , writeWidgetLookSetToStream_function_type( &::CEGUI::WidgetLookManager::writeWidgetLookSetToStream )
                , ( bp::arg("widgetLookNameSet"), bp::arg("out_stream") )
                , "*!\n\
                    \n\
                        Writes a series of complete WidgetLook objects to a stream. Note that XML file header\
                        and\n\
                        Falagard openingclosing tags will also be written.\n\
            \n\
                        The  widgetLookSet specifies a set of strings containing the names of the\
                        WidgetLookFeels\n\
                        to be written to the stream.\n\
            \n\
                    @param widgetLookNameSet\n\
                        Set of strings containing the WidgetLookFeel names to be added to be written to the\
                        stream.\n\
            \n\
                    @param out_stream\n\
                        OutStream where XML data should be sent.\n\
                    *\n" );
        
        }
        { //::CEGUI::WidgetLookManager::writeWidgetLookToStream
        
            typedef void ( ::CEGUI::WidgetLookManager::*writeWidgetLookToStream_function_type )( ::CEGUI::String const &,::CEGUI::OutStream & ) const;
            
            WidgetLookManager_exposer.def( 
                "writeWidgetLookToStream"
                , writeWidgetLookToStream_function_type( &::CEGUI::WidgetLookManager::writeWidgetLookToStream )
                , ( bp::arg("widgetLookName"), bp::arg("out_stream") )
                , "*!\n\
                    \n\
                        Writes a complete WidgetLookFeel to a stream. Note that XML file header and\n\
                        Falagard openingclosing tags will also be written.\n\
            \n\
                    @param name\n\
                        String holding the name of the WidgetLookFeel to be output to the stream.\n\
            \n\
                    @param out_stream\n\
                        OutStream where XML data should be sent.\n\
                    *\n" );
        
        }
        WidgetLookManager_exposer.staticmethod( "getDefaultResourceGroup" );
        WidgetLookManager_exposer.staticmethod( "getSingleton" );
        WidgetLookManager_exposer.staticmethod( "setDefaultResourceGroup" );
    }

}
