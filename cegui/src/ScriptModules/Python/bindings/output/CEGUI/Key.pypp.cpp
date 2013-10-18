// This file has been generated by Py++.

#include "boost/python.hpp"
#include "generators/include/python_CEGUI.h"
#include "Key.pypp.hpp"

namespace bp = boost::python;

void register_Key_class(){

    { //::CEGUI::Key
        typedef bp::class_< CEGUI::Key > Key_exposer_t;
        Key_exposer_t Key_exposer = Key_exposer_t( "Key", "*!\n\
        \n\
           struct to give scope to scan code enumeration.\n\
        *\n" );
        bp::scope Key_scope( Key_exposer );
        bp::enum_< CEGUI::Key::Scan>("Scan")
            .value("Unknown", CEGUI::Key::Unknown)
            .value("Escape", CEGUI::Key::Escape)
            .value("One", CEGUI::Key::One)
            .value("Two", CEGUI::Key::Two)
            .value("Three", CEGUI::Key::Three)
            .value("Four", CEGUI::Key::Four)
            .value("Five", CEGUI::Key::Five)
            .value("Six", CEGUI::Key::Six)
            .value("Seven", CEGUI::Key::Seven)
            .value("Eight", CEGUI::Key::Eight)
            .value("Nine", CEGUI::Key::Nine)
            .value("Zero", CEGUI::Key::Zero)
            .value("Minus", CEGUI::Key::Minus)
            .value("Equals", CEGUI::Key::Equals)
            .value("Backspace", CEGUI::Key::Backspace)
            .value("Tab", CEGUI::Key::Tab)
            .value("Q", CEGUI::Key::Q)
            .value("W", CEGUI::Key::W)
            .value("E", CEGUI::Key::E)
            .value("R", CEGUI::Key::R)
            .value("T", CEGUI::Key::T)
            .value("Y", CEGUI::Key::Y)
            .value("U", CEGUI::Key::U)
            .value("I", CEGUI::Key::I)
            .value("O", CEGUI::Key::O)
            .value("P", CEGUI::Key::P)
            .value("LeftBracket", CEGUI::Key::LeftBracket)
            .value("RightBracket", CEGUI::Key::RightBracket)
            .value("Return", CEGUI::Key::Return)
            .value("LeftControl", CEGUI::Key::LeftControl)
            .value("A", CEGUI::Key::A)
            .value("S", CEGUI::Key::S)
            .value("D", CEGUI::Key::D)
            .value("F", CEGUI::Key::F)
            .value("G", CEGUI::Key::G)
            .value("H", CEGUI::Key::H)
            .value("J", CEGUI::Key::J)
            .value("K", CEGUI::Key::K)
            .value("L", CEGUI::Key::L)
            .value("Semicolon", CEGUI::Key::Semicolon)
            .value("Apostrophe", CEGUI::Key::Apostrophe)
            .value("Grave", CEGUI::Key::Grave)
            .value("LeftShift", CEGUI::Key::LeftShift)
            .value("Backslash", CEGUI::Key::Backslash)
            .value("Z", CEGUI::Key::Z)
            .value("X", CEGUI::Key::X)
            .value("C", CEGUI::Key::C)
            .value("V", CEGUI::Key::V)
            .value("B", CEGUI::Key::B)
            .value("N", CEGUI::Key::N)
            .value("M", CEGUI::Key::M)
            .value("Comma", CEGUI::Key::Comma)
            .value("Period", CEGUI::Key::Period)
            .value("Slash", CEGUI::Key::Slash)
            .value("RightShift", CEGUI::Key::RightShift)
            .value("Multiply", CEGUI::Key::Multiply)
            .value("LeftAlt", CEGUI::Key::LeftAlt)
            .value("Space", CEGUI::Key::Space)
            .value("Capital", CEGUI::Key::Capital)
            .value("F1", CEGUI::Key::F1)
            .value("F2", CEGUI::Key::F2)
            .value("F3", CEGUI::Key::F3)
            .value("F4", CEGUI::Key::F4)
            .value("F5", CEGUI::Key::F5)
            .value("F6", CEGUI::Key::F6)
            .value("F7", CEGUI::Key::F7)
            .value("F8", CEGUI::Key::F8)
            .value("F9", CEGUI::Key::F9)
            .value("F10", CEGUI::Key::F10)
            .value("NumLock", CEGUI::Key::NumLock)
            .value("ScrollLock", CEGUI::Key::ScrollLock)
            .value("Numpad7", CEGUI::Key::Numpad7)
            .value("Numpad8", CEGUI::Key::Numpad8)
            .value("Numpad9", CEGUI::Key::Numpad9)
            .value("Subtract", CEGUI::Key::Subtract)
            .value("Numpad4", CEGUI::Key::Numpad4)
            .value("Numpad5", CEGUI::Key::Numpad5)
            .value("Numpad6", CEGUI::Key::Numpad6)
            .value("Add", CEGUI::Key::Add)
            .value("Numpad1", CEGUI::Key::Numpad1)
            .value("Numpad2", CEGUI::Key::Numpad2)
            .value("Numpad3", CEGUI::Key::Numpad3)
            .value("Numpad0", CEGUI::Key::Numpad0)
            .value("Decimal", CEGUI::Key::Decimal)
            .value("OEM_102", CEGUI::Key::OEM_102)
            .value("F11", CEGUI::Key::F11)
            .value("F12", CEGUI::Key::F12)
            .value("F13", CEGUI::Key::F13)
            .value("F14", CEGUI::Key::F14)
            .value("F15", CEGUI::Key::F15)
            .value("Kana", CEGUI::Key::Kana)
            .value("ABNT_C1", CEGUI::Key::ABNT_C1)
            .value("Convert", CEGUI::Key::Convert)
            .value("NoConvert", CEGUI::Key::NoConvert)
            .value("Yen", CEGUI::Key::Yen)
            .value("ABNT_C2", CEGUI::Key::ABNT_C2)
            .value("NumpadEquals", CEGUI::Key::NumpadEquals)
            .value("PrevTrack", CEGUI::Key::PrevTrack)
            .value("At", CEGUI::Key::At)
            .value("Colon", CEGUI::Key::Colon)
            .value("Underline", CEGUI::Key::Underline)
            .value("Kanji", CEGUI::Key::Kanji)
            .value("Stop", CEGUI::Key::Stop)
            .value("AX", CEGUI::Key::AX)
            .value("Unlabeled", CEGUI::Key::Unlabeled)
            .value("NextTrack", CEGUI::Key::NextTrack)
            .value("NumpadEnter", CEGUI::Key::NumpadEnter)
            .value("RightControl", CEGUI::Key::RightControl)
            .value("Mute", CEGUI::Key::Mute)
            .value("Calculator", CEGUI::Key::Calculator)
            .value("PlayPause", CEGUI::Key::PlayPause)
            .value("MediaStop", CEGUI::Key::MediaStop)
            .value("VolumeDown", CEGUI::Key::VolumeDown)
            .value("VolumeUp", CEGUI::Key::VolumeUp)
            .value("WebHome", CEGUI::Key::WebHome)
            .value("NumpadComma", CEGUI::Key::NumpadComma)
            .value("Divide", CEGUI::Key::Divide)
            .value("SysRq", CEGUI::Key::SysRq)
            .value("RightAlt", CEGUI::Key::RightAlt)
            .value("Pause", CEGUI::Key::Pause)
            .value("Home", CEGUI::Key::Home)
            .value("ArrowUp", CEGUI::Key::ArrowUp)
            .value("PageUp", CEGUI::Key::PageUp)
            .value("ArrowLeft", CEGUI::Key::ArrowLeft)
            .value("ArrowRight", CEGUI::Key::ArrowRight)
            .value("End", CEGUI::Key::End)
            .value("ArrowDown", CEGUI::Key::ArrowDown)
            .value("PageDown", CEGUI::Key::PageDown)
            .value("Insert", CEGUI::Key::Insert)
            .value("Delete", CEGUI::Key::Delete)
            .value("LeftWindows", CEGUI::Key::LeftWindows)
            .value("RightWindows", CEGUI::Key::RightWindows)
            .value("AppMenu", CEGUI::Key::AppMenu)
            .value("Power", CEGUI::Key::Power)
            .value("Sleep", CEGUI::Key::Sleep)
            .value("Wake", CEGUI::Key::Wake)
            .value("WebSearch", CEGUI::Key::WebSearch)
            .value("WebFavorites", CEGUI::Key::WebFavorites)
            .value("WebRefresh", CEGUI::Key::WebRefresh)
            .value("WebStop", CEGUI::Key::WebStop)
            .value("WebForward", CEGUI::Key::WebForward)
            .value("WebBack", CEGUI::Key::WebBack)
            .value("MyComputer", CEGUI::Key::MyComputer)
            .value("Mail", CEGUI::Key::Mail)
            .value("MediaSelect", CEGUI::Key::MediaSelect)
            .export_values()
            ;
    }

}
