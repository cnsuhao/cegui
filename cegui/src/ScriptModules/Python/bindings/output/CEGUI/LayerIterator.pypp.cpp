// This file has been generated by Py++.

#include "boost/python.hpp"
#include "generators/include/python_CEGUI.h"
#include "LayerIterator.pypp.hpp"

namespace bp = boost::python;

struct ConstVectorIterator_less__std_scope_multiset_less__CEGUI_scope_LayerSpecification__greater___greater__wrapper : CEGUI::ConstVectorIterator< std::multiset< CEGUI::LayerSpecification > >, bp::wrapper< CEGUI::ConstVectorIterator< std::multiset< CEGUI::LayerSpecification > > > {

    ConstVectorIterator_less__std_scope_multiset_less__CEGUI_scope_LayerSpecification__greater___greater__wrapper(CEGUI::ConstVectorIterator<std::multiset<CEGUI::LayerSpecification, std::less<CEGUI::LayerSpecification>, std::allocator<CEGUI::LayerSpecification> > > const & arg )
    : CEGUI::ConstVectorIterator<std::multiset<CEGUI::LayerSpecification, std::less<CEGUI::LayerSpecification>, std::allocator<CEGUI::LayerSpecification> > >( arg )
      , bp::wrapper< CEGUI::ConstVectorIterator< std::multiset< CEGUI::LayerSpecification > > >(){
        // copy constructor
        
    }

    virtual ::CEGUI::LayerSpecification getCurrentValue(  ) const  {
        if( bp::override func_getCurrentValue = this->get_override( "getCurrentValue" ) )
            return func_getCurrentValue(  );
        else{
            return this->CEGUI::ConstVectorIterator< std::multiset< CEGUI::LayerSpecification > >::getCurrentValue(  );
        }
    }
    
    ::CEGUI::LayerSpecification default_getCurrentValue(  ) const  {
        return CEGUI::ConstVectorIterator< std::multiset< CEGUI::LayerSpecification > >::getCurrentValue( );
    }

};

void Iterator_next(::CEGUI::ConstVectorIterator<std::multiset<CEGUI::LayerSpecification, std::less<CEGUI::LayerSpecification>, std::allocator<CEGUI::LayerSpecification> > >& t)
{
    t++;
}

void Iterator_previous(::CEGUI::ConstVectorIterator<std::multiset<CEGUI::LayerSpecification, std::less<CEGUI::LayerSpecification>, std::allocator<CEGUI::LayerSpecification> > >& t)
{
    t--;
}

void register_LayerIterator_class(){

    { //::CEGUI::ConstVectorIterator< std::multiset< CEGUI::LayerSpecification > >
        typedef bp::class_< ConstVectorIterator_less__std_scope_multiset_less__CEGUI_scope_LayerSpecification__greater___greater__wrapper, bp::bases< CEGUI::ConstBaseIterator< std::multiset< CEGUI::LayerSpecification >, CEGUI::LayerSpecification > > > LayerIterator_exposer_t;
        LayerIterator_exposer_t LayerIterator_exposer = LayerIterator_exposer_t( "LayerIterator", bp::no_init );
        bp::scope LayerIterator_scope( LayerIterator_exposer );
        { //::CEGUI::ConstVectorIterator< std::multiset< CEGUI::LayerSpecification > >::getCurrentValue
        
            typedef CEGUI::ConstVectorIterator< std::multiset< CEGUI::LayerSpecification > > exported_class_t;
            typedef ::CEGUI::LayerSpecification ( exported_class_t::*getCurrentValue_function_type )(  ) const;
            typedef ::CEGUI::LayerSpecification ( ConstVectorIterator_less__std_scope_multiset_less__CEGUI_scope_LayerSpecification__greater___greater__wrapper::*default_getCurrentValue_function_type )(  ) const;
            
            LayerIterator_exposer.def( 
                "getCurrentValue"
                , getCurrentValue_function_type(&::CEGUI::ConstVectorIterator< std::multiset< CEGUI::LayerSpecification > >::getCurrentValue)
                , default_getCurrentValue_function_type(&ConstVectorIterator_less__std_scope_multiset_less__CEGUI_scope_LayerSpecification__greater___greater__wrapper::default_getCurrentValue) );
        
        }
        LayerIterator_exposer.def("next", &::Iterator_next);
        LayerIterator_exposer.def("previous", &::Iterator_previous);
    }

}
