// This file has been generated by Py++.

#include "boost/python.hpp"
#include "generators/include/python_CEGUI.h"
#include "ConstBaseIterator_9b6259ec5f5ed443accef2ab6f116fda.pypp.hpp"

namespace bp = boost::python;

struct ConstBaseIterator_less__std_scope_map_less_CEGUI_scope_String_comma__CEGUI_scope_ImagerySection_comma__CEGUI_scope_StringFastLessCompare_comma__std_scope_allocator_less_std_scope_pair_less_CEGUI_scope_String_const_comma__CEGUI_scope_ImagerySection_greater___greater___greater__comma__CEGUI_scope_ImagerySection__greater__wrapper : CEGUI::ConstBaseIterator< std::map<CEGUI::String, CEGUI::ImagerySection, CEGUI::StringFastLessCompare, std::allocator<std::pair<CEGUI::String const, CEGUI::ImagerySection> > >, CEGUI::ImagerySection >, bp::wrapper< CEGUI::ConstBaseIterator< std::map<CEGUI::String, CEGUI::ImagerySection, CEGUI::StringFastLessCompare, std::allocator<std::pair<CEGUI::String const, CEGUI::ImagerySection> > >, CEGUI::ImagerySection > > {

    ConstBaseIterator_less__std_scope_map_less_CEGUI_scope_String_comma__CEGUI_scope_ImagerySection_comma__CEGUI_scope_StringFastLessCompare_comma__std_scope_allocator_less_std_scope_pair_less_CEGUI_scope_String_const_comma__CEGUI_scope_ImagerySection_greater___greater___greater__comma__CEGUI_scope_ImagerySection__greater__wrapper( )
    : CEGUI::ConstBaseIterator<std::map<CEGUI::String, CEGUI::ImagerySection, CEGUI::StringFastLessCompare, std::allocator<std::pair<CEGUI::String const, CEGUI::ImagerySection> > >, CEGUI::ImagerySection>( )
      , bp::wrapper< CEGUI::ConstBaseIterator< std::map<CEGUI::String, CEGUI::ImagerySection, CEGUI::StringFastLessCompare, std::allocator<std::pair<CEGUI::String const, CEGUI::ImagerySection> > >, CEGUI::ImagerySection > >(){
        // null constructor
    
    }

    virtual ::CEGUI::ImagerySection getCurrentValue(  ) const {
        bp::override func_getCurrentValue = this->get_override( "getCurrentValue" );
        return func_getCurrentValue(  );
    }

};

void register_ConstBaseIterator_9b6259ec5f5ed443accef2ab6f116fda_class(){

    { //::CEGUI::ConstBaseIterator< std::map<CEGUI::String, CEGUI::ImagerySection, CEGUI::StringFastLessCompare, std::allocator<std::pair<CEGUI::String const, CEGUI::ImagerySection> > >, CEGUI::ImagerySection >
        typedef bp::class_< ConstBaseIterator_less__std_scope_map_less_CEGUI_scope_String_comma__CEGUI_scope_ImagerySection_comma__CEGUI_scope_StringFastLessCompare_comma__std_scope_allocator_less_std_scope_pair_less_CEGUI_scope_String_const_comma__CEGUI_scope_ImagerySection_greater___greater___greater__comma__CEGUI_scope_ImagerySection__greater__wrapper, boost::noncopyable > ConstBaseIterator_9b6259ec5f5ed443accef2ab6f116fda_exposer_t;
        ConstBaseIterator_9b6259ec5f5ed443accef2ab6f116fda_exposer_t ConstBaseIterator_9b6259ec5f5ed443accef2ab6f116fda_exposer = ConstBaseIterator_9b6259ec5f5ed443accef2ab6f116fda_exposer_t( "ConstBaseIterator_9b6259ec5f5ed443accef2ab6f116fda", bp::no_init );
        bp::scope ConstBaseIterator_9b6259ec5f5ed443accef2ab6f116fda_scope( ConstBaseIterator_9b6259ec5f5ed443accef2ab6f116fda_exposer );
        ConstBaseIterator_9b6259ec5f5ed443accef2ab6f116fda_exposer.def( bp::init< >("*************************************************************************\n\
           No default construction available\n\
        *************************************************************************\n") );
        { //::CEGUI::ConstBaseIterator< std::map<CEGUI::String, CEGUI::ImagerySection, CEGUI::StringFastLessCompare, std::allocator<std::pair<CEGUI::String const, CEGUI::ImagerySection> > >, CEGUI::ImagerySection >::getCurrentValue
        
            typedef CEGUI::ConstBaseIterator< std::map<CEGUI::String, CEGUI::ImagerySection, CEGUI::StringFastLessCompare, std::allocator<std::pair<CEGUI::String const, CEGUI::ImagerySection> > >, CEGUI::ImagerySection > exported_class_t;
            typedef ::CEGUI::ImagerySection ( exported_class_t::*getCurrentValue_function_type )(  ) const;
            
            ConstBaseIterator_9b6259ec5f5ed443accef2ab6f116fda_exposer.def( 
                "getCurrentValue"
                , bp::pure_virtual( getCurrentValue_function_type(&::CEGUI::ConstBaseIterator< std::map<CEGUI::String, CEGUI::ImagerySection, CEGUI::StringFastLessCompare, std::allocator<std::pair<CEGUI::String const, CEGUI::ImagerySection> > >, CEGUI::ImagerySection >::getCurrentValue) )
                , "*!\n\
            \n\
               Return the value for the item at the current iterator position.\n\
            *\n" );
        
        }
        { //::CEGUI::ConstBaseIterator< std::map<CEGUI::String, CEGUI::ImagerySection, CEGUI::StringFastLessCompare, std::allocator<std::pair<CEGUI::String const, CEGUI::ImagerySection> > >, CEGUI::ImagerySection >::isAtEnd
        
            typedef CEGUI::ConstBaseIterator< std::map<CEGUI::String, CEGUI::ImagerySection, CEGUI::StringFastLessCompare, std::allocator<std::pair<CEGUI::String const, CEGUI::ImagerySection> > >, CEGUI::ImagerySection > exported_class_t;
            typedef bool ( exported_class_t::*isAtEnd_function_type )(  ) const;
            
            ConstBaseIterator_9b6259ec5f5ed443accef2ab6f116fda_exposer.def( 
                "isAtEnd"
                , isAtEnd_function_type( &::CEGUI::ConstBaseIterator< std::map<CEGUI::String, CEGUI::ImagerySection, CEGUI::StringFastLessCompare, std::allocator<std::pair<CEGUI::String const, CEGUI::ImagerySection> > >, CEGUI::ImagerySection >::isAtEnd )
                , "*!\n\
            \n\
               Return whether the current iterator position is at the end of the iterators range.\n\
            *\n" );
        
        }
        { //::CEGUI::ConstBaseIterator< std::map<CEGUI::String, CEGUI::ImagerySection, CEGUI::StringFastLessCompare, std::allocator<std::pair<CEGUI::String const, CEGUI::ImagerySection> > >, CEGUI::ImagerySection >::isAtStart
        
            typedef CEGUI::ConstBaseIterator< std::map<CEGUI::String, CEGUI::ImagerySection, CEGUI::StringFastLessCompare, std::allocator<std::pair<CEGUI::String const, CEGUI::ImagerySection> > >, CEGUI::ImagerySection > exported_class_t;
            typedef bool ( exported_class_t::*isAtStart_function_type )(  ) const;
            
            ConstBaseIterator_9b6259ec5f5ed443accef2ab6f116fda_exposer.def( 
                "isAtStart"
                , isAtStart_function_type( &::CEGUI::ConstBaseIterator< std::map<CEGUI::String, CEGUI::ImagerySection, CEGUI::StringFastLessCompare, std::allocator<std::pair<CEGUI::String const, CEGUI::ImagerySection> > >, CEGUI::ImagerySection >::isAtStart )
                , "*!\n\
            \n\
               Return whether the current iterator position is at the start of the iterators range.\n\
            *\n" );
        
        }
        ConstBaseIterator_9b6259ec5f5ed443accef2ab6f116fda_exposer.def( bp::self != bp::self );
        { //::CEGUI::ConstBaseIterator< std::map<CEGUI::String, CEGUI::ImagerySection, CEGUI::StringFastLessCompare, std::allocator<std::pair<CEGUI::String const, CEGUI::ImagerySection> > >, CEGUI::ImagerySection >::operator=
        
            typedef CEGUI::ConstBaseIterator< std::map<CEGUI::String, CEGUI::ImagerySection, CEGUI::StringFastLessCompare, std::allocator<std::pair<CEGUI::String const, CEGUI::ImagerySection> > >, CEGUI::ImagerySection > exported_class_t;
            typedef ::CEGUI::ConstBaseIterator< std::map<CEGUI::String, CEGUI::ImagerySection, CEGUI::StringFastLessCompare, std::allocator<std::pair<CEGUI::String const, CEGUI::ImagerySection> > >, CEGUI::ImagerySection > & ( exported_class_t::*assign_function_type )( ::CEGUI::ConstBaseIterator< std::map<CEGUI::String, CEGUI::ImagerySection, CEGUI::StringFastLessCompare, std::allocator<std::pair<CEGUI::String const, CEGUI::ImagerySection> > >, CEGUI::ImagerySection > const & ) ;
            
            ConstBaseIterator_9b6259ec5f5ed443accef2ab6f116fda_exposer.def( 
                "assign"
                , assign_function_type( &::CEGUI::ConstBaseIterator< std::map<CEGUI::String, CEGUI::ImagerySection, CEGUI::StringFastLessCompare, std::allocator<std::pair<CEGUI::String const, CEGUI::ImagerySection> > >, CEGUI::ImagerySection >::operator= )
                , ( bp::arg("rhs") )
                , bp::return_self< >()
                , "*!\n\
            \n\
               ConstBaseIterator assignment operator\n\
            *\n" );
        
        }
        ConstBaseIterator_9b6259ec5f5ed443accef2ab6f116fda_exposer.def( bp::self == bp::self );
        { //::CEGUI::ConstBaseIterator< std::map<CEGUI::String, CEGUI::ImagerySection, CEGUI::StringFastLessCompare, std::allocator<std::pair<CEGUI::String const, CEGUI::ImagerySection> > >, CEGUI::ImagerySection >::toEnd
        
            typedef CEGUI::ConstBaseIterator< std::map<CEGUI::String, CEGUI::ImagerySection, CEGUI::StringFastLessCompare, std::allocator<std::pair<CEGUI::String const, CEGUI::ImagerySection> > >, CEGUI::ImagerySection > exported_class_t;
            typedef void ( exported_class_t::*toEnd_function_type )(  ) ;
            
            ConstBaseIterator_9b6259ec5f5ed443accef2ab6f116fda_exposer.def( 
                "toEnd"
                , toEnd_function_type( &::CEGUI::ConstBaseIterator< std::map<CEGUI::String, CEGUI::ImagerySection, CEGUI::StringFastLessCompare, std::allocator<std::pair<CEGUI::String const, CEGUI::ImagerySection> > >, CEGUI::ImagerySection >::toEnd )
                , "*!\n\
            \n\
               Set the iterator current position to the end position.\n\
            *\n" );
        
        }
        { //::CEGUI::ConstBaseIterator< std::map<CEGUI::String, CEGUI::ImagerySection, CEGUI::StringFastLessCompare, std::allocator<std::pair<CEGUI::String const, CEGUI::ImagerySection> > >, CEGUI::ImagerySection >::toStart
        
            typedef CEGUI::ConstBaseIterator< std::map<CEGUI::String, CEGUI::ImagerySection, CEGUI::StringFastLessCompare, std::allocator<std::pair<CEGUI::String const, CEGUI::ImagerySection> > >, CEGUI::ImagerySection > exported_class_t;
            typedef void ( exported_class_t::*toStart_function_type )(  ) ;
            
            ConstBaseIterator_9b6259ec5f5ed443accef2ab6f116fda_exposer.def( 
                "toStart"
                , toStart_function_type( &::CEGUI::ConstBaseIterator< std::map<CEGUI::String, CEGUI::ImagerySection, CEGUI::StringFastLessCompare, std::allocator<std::pair<CEGUI::String const, CEGUI::ImagerySection> > >, CEGUI::ImagerySection >::toStart )
                , "*!\n\
            \n\
               Set the iterator current position to the start position.\n\
            *\n" );
        
        }
    }

}
