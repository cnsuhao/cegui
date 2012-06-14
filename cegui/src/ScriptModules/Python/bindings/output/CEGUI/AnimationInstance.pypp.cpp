// This file has been generated by Py++.

#include "boost/python.hpp"
#include "python_CEGUI.h"
#include "AnimationInstance.pypp.hpp"

namespace bp = boost::python;

void register_AnimationInstance_class(){

    { //::CEGUI::AnimationInstance
        typedef bp::class_< CEGUI::AnimationInstance > AnimationInstance_exposer_t;
        AnimationInstance_exposer_t AnimationInstance_exposer = AnimationInstance_exposer_t( "AnimationInstance", bp::init< CEGUI::Animation * >(( bp::arg("definition") ), "! internal constructor, please use AnimationManager.instantiateAnimation\n") );
        bp::scope AnimationInstance_scope( AnimationInstance_exposer );
        bp::implicitly_convertible< CEGUI::Animation *, CEGUI::AnimationInstance >();
        { //::CEGUI::AnimationInstance::addAutoConnection
        
            typedef void ( ::CEGUI::AnimationInstance::*addAutoConnection_function_type )( ::CEGUI::RefCounted< CEGUI::BoundSlot > ) ;
            
            AnimationInstance_exposer.def( 
                "addAutoConnection"
                , addAutoConnection_function_type( &::CEGUI::AnimationInstance::addAutoConnection )
                , ( bp::arg("conn") )
                , "*!\n\
                \n\
                    Internal method, adds reference to created auto connection\n\
            \n\
                \n\
                    DO NOT USE THIS DIRECTLY\n\
                *\n" );
        
        }
        { //::CEGUI::AnimationInstance::apply
        
            typedef void ( ::CEGUI::AnimationInstance::*apply_function_type )(  ) ;
            
            AnimationInstance_exposer.def( 
                "apply"
                , apply_function_type( &::CEGUI::AnimationInstance::apply )
                , "*!\n\
                \n\
                  Applies this animation instance\n\
            \n\
                \n\
                  You should not need to use this directly unless your requirements are very special.\n\
                  CEGUI calls this automatically in most cases.\n\
               *\n" );
        
        }
        { //::CEGUI::AnimationInstance::getDefinition
        
            typedef ::CEGUI::Animation * ( ::CEGUI::AnimationInstance::*getDefinition_function_type )(  ) const;
            
            AnimationInstance_exposer.def( 
                "getDefinition"
                , getDefinition_function_type( &::CEGUI::AnimationInstance::getDefinition )
                , bp::return_value_policy< bp::reference_existing_object >()
                , "*!\n\
            \n\
                Retrieves the animation definition that is used in this instance\n\
            *\n" );
        
        }
        { //::CEGUI::AnimationInstance::getEventReceiver
        
            typedef ::CEGUI::EventSet * ( ::CEGUI::AnimationInstance::*getEventReceiver_function_type )(  ) const;
            
            AnimationInstance_exposer.def( 
                "getEventReceiver"
                , getEventReceiver_function_type( &::CEGUI::AnimationInstance::getEventReceiver )
                , bp::return_value_policy< bp::reference_existing_object >()
                , "*!\n\
            \n\
                Retrieves the event receiver\n\
            *\n" );
        
        }
        { //::CEGUI::AnimationInstance::getEventSender
        
            typedef ::CEGUI::EventSet * ( ::CEGUI::AnimationInstance::*getEventSender_function_type )(  ) const;
            
            AnimationInstance_exposer.def( 
                "getEventSender"
                , getEventSender_function_type( &::CEGUI::AnimationInstance::getEventSender )
                , bp::return_value_policy< bp::reference_existing_object >()
                , "*!\n\
            \n\
                Retrieves the event sender\n\
            *\n" );
        
        }
        { //::CEGUI::AnimationInstance::getMaxStepDeltaClamp
        
            typedef float ( ::CEGUI::AnimationInstance::*getMaxStepDeltaClamp_function_type )(  ) const;
            
            AnimationInstance_exposer.def( 
                "getMaxStepDeltaClamp"
                , getMaxStepDeltaClamp_function_type( &::CEGUI::AnimationInstance::getMaxStepDeltaClamp )
                , "*!\n\
            \n\
                Gets the max delta before step clamping occurs\n\
            *\n" );
        
        }
        { //::CEGUI::AnimationInstance::getMaxStepDeltaSkip
        
            typedef float ( ::CEGUI::AnimationInstance::*getMaxStepDeltaSkip_function_type )(  ) const;
            
            AnimationInstance_exposer.def( 
                "getMaxStepDeltaSkip"
                , getMaxStepDeltaSkip_function_type( &::CEGUI::AnimationInstance::getMaxStepDeltaSkip )
                , "*!\n\
            \n\
                Gets the max delta before step skipping occurs\n\
            *\n" );
        
        }
        { //::CEGUI::AnimationInstance::getPosition
        
            typedef float ( ::CEGUI::AnimationInstance::*getPosition_function_type )(  ) const;
            
            AnimationInstance_exposer.def( 
                "getPosition"
                , getPosition_function_type( &::CEGUI::AnimationInstance::getPosition )
                , "*!\n\
            \n\
                Retrieves current playback position\n\
            *\n" );
        
        }
        { //::CEGUI::AnimationInstance::getSavedPropertyValue
        
            typedef ::CEGUI::String const & ( ::CEGUI::AnimationInstance::*getSavedPropertyValue_function_type )( ::CEGUI::String const & ) ;
            
            AnimationInstance_exposer.def( 
                "getSavedPropertyValue"
                , getSavedPropertyValue_function_type( &::CEGUI::AnimationInstance::getSavedPropertyValue )
                , ( bp::arg("propertyName") )
                , bp::return_value_policy< bp::copy_const_reference >()
                , "** retrieves saved value, if it isn't cached already, it retrieves it fresh\n\
             * from the properties\n\
             *\n" );
        
        }
        { //::CEGUI::AnimationInstance::getSkipNextStep
        
            typedef bool ( ::CEGUI::AnimationInstance::*getSkipNextStep_function_type )(  ) const;
            
            AnimationInstance_exposer.def( 
                "getSkipNextStep"
                , getSkipNextStep_function_type( &::CEGUI::AnimationInstance::getSkipNextStep )
                , "*!\n\
                \n\
                    Returns true if the next step is *going* to be skipped\n\
            \n\
                \n\
                    If it was skipped already, this returns false as step resets\n\
                    it to false after it skips one step.\n\
                *\n" );
        
        }
        { //::CEGUI::AnimationInstance::getSpeed
        
            typedef float ( ::CEGUI::AnimationInstance::*getSpeed_function_type )(  ) const;
            
            AnimationInstance_exposer.def( 
                "getSpeed"
                , getSpeed_function_type( &::CEGUI::AnimationInstance::getSpeed )
                , "*!\n\
            \n\
                Retrieves current playback speed\n\
            *\n" );
        
        }
        { //::CEGUI::AnimationInstance::getTarget
        
            typedef ::CEGUI::PropertySet * ( ::CEGUI::AnimationInstance::*getTarget_function_type )(  ) const;
            
            AnimationInstance_exposer.def( 
                "getTarget"
                , getTarget_function_type( &::CEGUI::AnimationInstance::getTarget )
                , bp::return_value_policy< bp::reference_existing_object >()
                , "*!\n\
            \n\
                Retrieves the target property set\n\
            *\n" );
        
        }
        { //::CEGUI::AnimationInstance::handlePause
        
            typedef bool ( ::CEGUI::AnimationInstance::*handlePause_function_type )( ::CEGUI::EventArgs const & ) ;
            
            AnimationInstance_exposer.def( 
                "handlePause"
                , handlePause_function_type( &::CEGUI::AnimationInstance::handlePause )
                , ( bp::arg("e") )
                , "*!\n\
            \n\
                handler that pauses the animation instance\n\
            *\n" );
        
        }
        { //::CEGUI::AnimationInstance::handleStart
        
            typedef bool ( ::CEGUI::AnimationInstance::*handleStart_function_type )( ::CEGUI::EventArgs const & ) ;
            
            AnimationInstance_exposer.def( 
                "handleStart"
                , handleStart_function_type( &::CEGUI::AnimationInstance::handleStart )
                , ( bp::arg("e") )
                , "*!\n\
            \n\
                handler that starts the animation instance\n\
            *\n" );
        
        }
        { //::CEGUI::AnimationInstance::handleStop
        
            typedef bool ( ::CEGUI::AnimationInstance::*handleStop_function_type )( ::CEGUI::EventArgs const & ) ;
            
            AnimationInstance_exposer.def( 
                "handleStop"
                , handleStop_function_type( &::CEGUI::AnimationInstance::handleStop )
                , ( bp::arg("e") )
                , "*!\n\
            \n\
                handler that stops the animation instance\n\
            *\n" );
        
        }
        { //::CEGUI::AnimationInstance::handleTogglePause
        
            typedef bool ( ::CEGUI::AnimationInstance::*handleTogglePause_function_type )( ::CEGUI::EventArgs const & ) ;
            
            AnimationInstance_exposer.def( 
                "handleTogglePause"
                , handleTogglePause_function_type( &::CEGUI::AnimationInstance::handleTogglePause )
                , ( bp::arg("e") )
                , "*!\n\
            \n\
                handler that toggles pause on this animation instance\n\
            *\n" );
        
        }
        { //::CEGUI::AnimationInstance::handleUnpause
        
            typedef bool ( ::CEGUI::AnimationInstance::*handleUnpause_function_type )( ::CEGUI::EventArgs const & ) ;
            
            AnimationInstance_exposer.def( 
                "handleUnpause"
                , handleUnpause_function_type( &::CEGUI::AnimationInstance::handleUnpause )
                , ( bp::arg("e") )
                , "*!\n\
            \n\
                handler that unpauses the animation instance\n\
            *\n" );
        
        }
        { //::CEGUI::AnimationInstance::isAutoSteppingEnabled
        
            typedef bool ( ::CEGUI::AnimationInstance::*isAutoSteppingEnabled_function_type )(  ) const;
            
            AnimationInstance_exposer.def( 
                "isAutoSteppingEnabled"
                , isAutoSteppingEnabled_function_type( &::CEGUI::AnimationInstance::isAutoSteppingEnabled )
                , "*!\n\
            \n\
              Checks whether auto stepping is enabled\n\
            *\n" );
        
        }
        { //::CEGUI::AnimationInstance::isRunning
        
            typedef bool ( ::CEGUI::AnimationInstance::*isRunning_function_type )(  ) const;
            
            AnimationInstance_exposer.def( 
                "isRunning"
                , isRunning_function_type( &::CEGUI::AnimationInstance::isRunning )
                , "*!\n\
            \n\
                Returns true if this animation instance is currently unpaused,\n\
                if it is stepping forward.\n\
            *\n" );
        
        }
        { //::CEGUI::AnimationInstance::pause
        
            typedef void ( ::CEGUI::AnimationInstance::*pause_function_type )(  ) ;
            
            AnimationInstance_exposer.def( 
                "pause"
                , pause_function_type( &::CEGUI::AnimationInstance::pause )
                , "*!\n\
            \n\
                Pauses this animation instance - stops it from stepping forward\n\
            *\n" );
        
        }
        { //::CEGUI::AnimationInstance::purgeSavedPropertyValues
        
            typedef void ( ::CEGUI::AnimationInstance::*purgeSavedPropertyValues_function_type )(  ) ;
            
            AnimationInstance_exposer.def( 
                "purgeSavedPropertyValues"
                , purgeSavedPropertyValues_function_type( &::CEGUI::AnimationInstance::purgeSavedPropertyValues )
                , "** this purges all saved values forcing this class to gather new ones fresh\n\
             * from the properties\n\
             *\n" );
        
        }
        { //::CEGUI::AnimationInstance::savePropertyValue
        
            typedef void ( ::CEGUI::AnimationInstance::*savePropertyValue_function_type )( ::CEGUI::String const & ) ;
            
            AnimationInstance_exposer.def( 
                "savePropertyValue"
                , savePropertyValue_function_type( &::CEGUI::AnimationInstance::savePropertyValue )
                , ( bp::arg("propertyName") )
                , "*!\n\
            \n\
                Internal method, saves given property (called before it's affected)\n\
            *\n" );
        
        }
        { //::CEGUI::AnimationInstance::setAutoSteppingEnabled
        
            typedef void ( ::CEGUI::AnimationInstance::*setAutoSteppingEnabled_function_type )( bool ) ;
            
            AnimationInstance_exposer.def( 
                "setAutoSteppingEnabled"
                , setAutoSteppingEnabled_function_type( &::CEGUI::AnimationInstance::setAutoSteppingEnabled )
                , ( bp::arg("enabled") )
                , "*!\n\
                \n\
                  Controls whether auto stepping is enabled\n\
            \n\
                \n\
                  If auto stepping is enabled, CEGUI will step this animation instance forward\n\
                  whenever CEGUI.System.injectTimePulse is called\n\
                 *\n" );
        
        }
        { //::CEGUI::AnimationInstance::setEventReceiver
        
            typedef void ( ::CEGUI::AnimationInstance::*setEventReceiver_function_type )( ::CEGUI::EventSet * ) ;
            
            AnimationInstance_exposer.def( 
                "setEventReceiver"
                , setEventReceiver_function_type( &::CEGUI::AnimationInstance::setEventReceiver )
                , ( bp::arg("receiver") )
                , "*!\n\
            \n\
                Sets event receiver - this class will receive events when something\n\
                happens to the playback of this animation - it starts, stops, pauses,\n\
                unpauses, ends and loops\n\
            *\n" );
        
        }
        { //::CEGUI::AnimationInstance::setEventSender
        
            typedef void ( ::CEGUI::AnimationInstance::*setEventSender_function_type )( ::CEGUI::EventSet * ) ;
            
            AnimationInstance_exposer.def( 
                "setEventSender"
                , setEventSender_function_type( &::CEGUI::AnimationInstance::setEventSender )
                , ( bp::arg("sender") )
                , "*!\n\
            \n\
                Sets event sender - this class will send events and can affect this\n\
                animation instance if there are any auto subscriptions defined in the\n\
                animation definition\n\
            *\n" );
        
        }
        { //::CEGUI::AnimationInstance::setMaxStepDeltaClamp
        
            typedef void ( ::CEGUI::AnimationInstance::*setMaxStepDeltaClamp_function_type )( float ) ;
            
            AnimationInstance_exposer.def( 
                "setMaxStepDeltaClamp"
                , setMaxStepDeltaClamp_function_type( &::CEGUI::AnimationInstance::setMaxStepDeltaClamp )
                , ( bp::arg("maxDelta") )
                , "*!\n\
                \n\
                    Sets the max delta before step clamping occurs\n\
            \n\
                @param\n\
                    maxDelta delta in seconds, if this value is reached, the step is clamped.\n\
                             (use -1.0f if you never want to clamp - this is the default)\n\
            \n\
                \n\
                    If you want to ensure the animation steps at most 1.0  60.0 seconds at a timem\n\
                    you should call setMaxStepDeltaClamp(1.0f  60.0f). This essentially slows\n\
                    the animation down in case the FPS drops below 60.\n\
                *\n" );
        
        }
        { //::CEGUI::AnimationInstance::setMaxStepDeltaSkip
        
            typedef void ( ::CEGUI::AnimationInstance::*setMaxStepDeltaSkip_function_type )( float ) ;
            
            AnimationInstance_exposer.def( 
                "setMaxStepDeltaSkip"
                , setMaxStepDeltaSkip_function_type( &::CEGUI::AnimationInstance::setMaxStepDeltaSkip )
                , ( bp::arg("maxDelta") )
                , "*!\n\
                \n\
                    Sets the max delta before step skipping occurs\n\
            \n\
                @param\n\
                    maxDelta delta in seconds, if this value is reached, the step is skipped\n\
                             (use -1.0f if you never want to skip - this is the default)\n\
            \n\
                \n\
                    If you want to ensure your animation is not skipped entirely after layouts\n\
                    are loaded or other time consuming operations are done, use this method.\n\
            \n\
                    For example setMaxStepDeltaSkip(1.0f  25.0f) ensures that if FPS drops\n\
                    below 25, the animation just stops progressing and waits till FPS raises.\n\
                *\n" );
        
        }
        { //::CEGUI::AnimationInstance::setPosition
        
            typedef void ( ::CEGUI::AnimationInstance::*setPosition_function_type )( float ) ;
            
            AnimationInstance_exposer.def( 
                "setPosition"
                , setPosition_function_type( &::CEGUI::AnimationInstance::setPosition )
                , ( bp::arg("position") )
                , "*!\n\
            \n\
                Sets playback position. Has to be higher or equal to 0.0 and lower or\n\
                equal to Animation definition's duration.\n\
            *\n" );
        
        }
        { //::CEGUI::AnimationInstance::setSkipNextStep
        
            typedef void ( ::CEGUI::AnimationInstance::*setSkipNextStep_function_type )( bool ) ;
            
            AnimationInstance_exposer.def( 
                "setSkipNextStep"
                , setSkipNextStep_function_type( &::CEGUI::AnimationInstance::setSkipNextStep )
                , ( bp::arg("skip") )
                , "*!\n\
            \n\
                Controls whether the next time step is skipped\n\
            *\n" );
        
        }
        { //::CEGUI::AnimationInstance::setSpeed
        
            typedef void ( ::CEGUI::AnimationInstance::*setSpeed_function_type )( float ) ;
            
            AnimationInstance_exposer.def( 
                "setSpeed"
                , setSpeed_function_type( &::CEGUI::AnimationInstance::setSpeed )
                , ( bp::arg("speed") )
                , "*!\n\
            \n\
                Sets playback speed - you can speed up  slow down individual instances\n\
                of the same animation. 1.0 means normal playback.\n\
            *\n" );
        
        }
        { //::CEGUI::AnimationInstance::setTarget
        
            typedef void ( ::CEGUI::AnimationInstance::*setTarget_function_type )( ::CEGUI::PropertySet * ) ;
            
            AnimationInstance_exposer.def( 
                "setTarget"
                , setTarget_function_type( &::CEGUI::AnimationInstance::setTarget )
                , ( bp::arg("target") )
                , "*!\n\
            \n\
                Sets the target property set - this class will get it's properties\n\
                affected by the Affectors!\n\
            *\n" );
        
        }
        { //::CEGUI::AnimationInstance::setTargetWindow
        
            typedef void ( ::CEGUI::AnimationInstance::*setTargetWindow_function_type )( ::CEGUI::Window * ) ;
            
            AnimationInstance_exposer.def( 
                "setTargetWindow"
                , setTargetWindow_function_type( &::CEGUI::AnimationInstance::setTargetWindow )
                , ( bp::arg("target") )
                , "*!\n\
            \n\
                Helper method, sets given window as target property set, event receiver\n\
                and event set\n\
            *\n" );
        
        }
        { //::CEGUI::AnimationInstance::start
        
            typedef void ( ::CEGUI::AnimationInstance::*start_function_type )( bool ) ;
            
            AnimationInstance_exposer.def( 
                "start"
                , start_function_type( &::CEGUI::AnimationInstance::start )
                , ( bp::arg("skipNextStep")=(bool)(true) )
                , "*!\n\
                \n\
                    Starts this animation instance - sets position to 0.0 and unpauses\n\
            \n\
                @param\n\
                    skipNextStep if true the next injected time pulse is skipped\n\
            \n\
                \n\
                    This also causes base values to be purged!\n\
                *\n" );
        
        }
        { //::CEGUI::AnimationInstance::step
        
            typedef void ( ::CEGUI::AnimationInstance::*step_function_type )( float ) ;
            
            AnimationInstance_exposer.def( 
                "step"
                , step_function_type( &::CEGUI::AnimationInstance::step )
                , ( bp::arg("delta") )
                , "*!\n\
                \n\
                    Steps the animation forward by the given delta\n\
            \n\
                \n\
                  You don't need to call this unless AutoStepping is disabled (it is enabled by default)\n\
                *\n" );
        
        }
        { //::CEGUI::AnimationInstance::stop
        
            typedef void ( ::CEGUI::AnimationInstance::*stop_function_type )(  ) ;
            
            AnimationInstance_exposer.def( 
                "stop"
                , stop_function_type( &::CEGUI::AnimationInstance::stop )
                , "*!\n\
            \n\
                Stops this animation instance - sets position to 0.0 and pauses\n\
            *\n" );
        
        }
        { //::CEGUI::AnimationInstance::togglePause
        
            typedef void ( ::CEGUI::AnimationInstance::*togglePause_function_type )( bool ) ;
            
            AnimationInstance_exposer.def( 
                "togglePause"
                , togglePause_function_type( &::CEGUI::AnimationInstance::togglePause )
                , ( bp::arg("skipNextStep")=(bool)(true) )
                , "*!\n\
                \n\
                   Pauses the animation if it's running and unpauses it if it isn't\n\
            \n\
                   @param\n\
                    skipNextStep if true the next injected time pulse is skipped\n\
                                   (only applies when unpausing!)\n\
                *\n" );
        
        }
        { //::CEGUI::AnimationInstance::unpause
        
            typedef void ( ::CEGUI::AnimationInstance::*unpause_function_type )( bool ) ;
            
            AnimationInstance_exposer.def( 
                "unpause"
                , unpause_function_type( &::CEGUI::AnimationInstance::unpause )
                , ( bp::arg("skipNextStep")=(bool)(true) )
                , "*!\n\
                \n\
                   Unpauses this animation instance - allows it to step forward again\n\
            \n\
                @param\n\
                    skipNextStep if true the next injected time pulse is skipped\n\
                *\n" );
        
        }
        { //::CEGUI::AnimationInstance::unsubscribeAutoConnections
        
            typedef void ( ::CEGUI::AnimationInstance::*unsubscribeAutoConnections_function_type )(  ) ;
            
            AnimationInstance_exposer.def( 
                "unsubscribeAutoConnections"
                , unsubscribeAutoConnections_function_type( &::CEGUI::AnimationInstance::unsubscribeAutoConnections )
                , "*!\n\
                \n\
                    Internal method, unsubscribes auto connections\n\
            \n\
                \n\
                    DO NOT USE THIS DIRECTLY\n\
                *\n" );
        
        }
        AnimationInstance_exposer.add_static_property( "EventAnimationEnded"
                        , bp::make_getter( &CEGUI::AnimationInstance::EventAnimationEnded
                                , bp::return_value_policy< bp::return_by_value >() ) );
        AnimationInstance_exposer.add_static_property( "EventAnimationLooped"
                        , bp::make_getter( &CEGUI::AnimationInstance::EventAnimationLooped
                                , bp::return_value_policy< bp::return_by_value >() ) );
        AnimationInstance_exposer.add_static_property( "EventAnimationPaused"
                        , bp::make_getter( &CEGUI::AnimationInstance::EventAnimationPaused
                                , bp::return_value_policy< bp::return_by_value >() ) );
        AnimationInstance_exposer.add_static_property( "EventAnimationStarted"
                        , bp::make_getter( &CEGUI::AnimationInstance::EventAnimationStarted
                                , bp::return_value_policy< bp::return_by_value >() ) );
        AnimationInstance_exposer.add_static_property( "EventAnimationStopped"
                        , bp::make_getter( &CEGUI::AnimationInstance::EventAnimationStopped
                                , bp::return_value_policy< bp::return_by_value >() ) );
        AnimationInstance_exposer.add_static_property( "EventAnimationUnpaused"
                        , bp::make_getter( &CEGUI::AnimationInstance::EventAnimationUnpaused
                                , bp::return_value_policy< bp::return_by_value >() ) );
    }

}
