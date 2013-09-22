/***********************************************************************
 *    filename:   InputAggregator.cpp
 *    created:    10/7/2013
 *    author:     Timotei Dolean <timotei21@gmail.com>
 *************************************************************************/
/***************************************************************************
 *   Copyright (C) 2004 - 2013 Paul D Turner & The CEGUI Development Team
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

#include <boost/test/unit_test.hpp>

#include <vector>
#include <iostream>
#include <map>

#include "CEGUI/CEGUI.h"

using namespace CEGUI;

class MockInputEventReceiver : public InputEventReceiver
{
public:
    std::string d_text;
    float d_totalScroll;
    Vector2f d_pointerPosition;
    std::vector<int> d_semanticValues;

    MockInputEventReceiver() :
        d_text(""),
        d_pointerPosition(0.0f, 0.0f),
        d_totalScroll(0)
    {}

    ~MockInputEventReceiver()
    {
        for (HandlersMap::const_iterator itor = d_handlersMap.begin();
            itor != d_handlersMap.end(); ++ itor)
        {
            delete (*itor).second;
        }

        d_handlersMap.clear();
    }

    bool injectInputEvent(const InputEvent& event)
    {
        HandlersMap::const_iterator itor = d_handlersMap.find(event.d_eventType);
        if (itor != d_handlersMap.end())
        {
            return (*(*itor).second)(event);
        }
        else
        {
            std::cout << "No event handler for event type: " << event.d_eventType << std::endl;
            return false;
        }
    }

    bool handleTextEvent(const TextInputEvent& event)
    {
        d_text += event.d_character;
        return true;
    }

    bool handleMovementEvent(const SemanticInputEvent& event)
    {
        d_pointerPosition = Vector2f(event.d_payload.array[0],
            event.d_payload.array[1]);
        return true;
    }

    bool handleScrollEvent(const SemanticInputEvent& event)
    {
        d_totalScroll += event.d_payload.single;
        return true;
    }

    bool handleSemanticEvent(const SemanticInputEvent& event)
    {
        HandlersMap::const_iterator itor =
            d_semanticEventsHandlersMap.find(event.d_value);
        if (itor != d_semanticEventsHandlersMap.end())
        {
            return (*(*itor).second)(event);
        }
        else
        {
            d_semanticValues.push_back(event.d_value);
        }

        return true;
    }

    void initializeEventHandlers()
    {
        d_handlersMap.insert(std::make_pair(IET_TextInputEventType,
            new InputEventHandlerSlot<MockInputEventReceiver, TextInputEvent>(
                &MockInputEventReceiver::handleTextEvent, this)));

        d_handlersMap.insert(std::make_pair(IET_SemanticInputEventType,
            new InputEventHandlerSlot<MockInputEventReceiver, SemanticInputEvent>(
                &MockInputEventReceiver::handleSemanticEvent, this)));
    }

    void initializeSemanticEventHandlers()
    {
        d_semanticEventsHandlersMap.insert(std::make_pair(SV_VerticalScroll,
            new InputEventHandlerSlot<MockInputEventReceiver, SemanticInputEvent>(
                &MockInputEventReceiver::handleScrollEvent, this)));

        d_semanticEventsHandlersMap.insert(std::make_pair(SV_PointerMove,
            new InputEventHandlerSlot<MockInputEventReceiver, SemanticInputEvent>(
                &MockInputEventReceiver::handleMovementEvent, this)));
    }

private:
    typedef std::map<int, SlotFunctorBase<InputEvent>*> HandlersMap;
    HandlersMap d_semanticEventsHandlersMap;
    HandlersMap d_handlersMap;
};

struct InputAggregatorFixture
{
    InputAggregatorFixture()
    {
        d_inputEventReceiver = new MockInputEventReceiver;
        d_inputEventReceiver->initializeEventHandlers();
        d_inputEventReceiver->initializeSemanticEventHandlers();
        d_inputAggregator = new InputAggregator(d_inputEventReceiver);
        d_inputAggregator->initialise();
    }

    ~InputAggregatorFixture()
    {
        delete d_inputEventReceiver;
        delete d_inputAggregator;
    }

    InputAggregator* d_inputAggregator;
    MockInputEventReceiver* d_inputEventReceiver;
};

//----------------------------------------------------------------------------//

BOOST_FIXTURE_TEST_SUITE(InputAggregator, InputAggregatorFixture)

BOOST_AUTO_TEST_CASE(TextEventOneChar)
{
    d_inputAggregator->injectChar('a');

    BOOST_REQUIRE_EQUAL(d_inputEventReceiver->d_text, "a");
}

BOOST_AUTO_TEST_CASE(TextEventMultipleChars)
{
    d_inputAggregator->injectChar('a');
    d_inputAggregator->injectChar('b');
    d_inputAggregator->injectChar('c');

    BOOST_REQUIRE_EQUAL(d_inputEventReceiver->d_text, "abc");
}

BOOST_AUTO_TEST_CASE(MovementEventNoDelta)
{
    d_inputAggregator->injectMouseMove(0, 0);

    BOOST_REQUIRE_EQUAL(d_inputEventReceiver->d_pointerPosition.d_x, 0);
    BOOST_REQUIRE_EQUAL(d_inputEventReceiver->d_pointerPosition.d_y, 0);
}

BOOST_AUTO_TEST_CASE(MovementEventSingleDelta)
{
    d_inputAggregator->injectMouseMove(0, 0);
    d_inputAggregator->injectMouseMove(3, 5);

    BOOST_REQUIRE_EQUAL(d_inputEventReceiver->d_pointerPosition.d_x, 3);
    BOOST_REQUIRE_EQUAL(d_inputEventReceiver->d_pointerPosition.d_y, 5);
}

BOOST_AUTO_TEST_CASE(MovementEventMultipleDeltas)
{
    d_inputAggregator->injectMouseMove(0, 0);
    d_inputAggregator->injectMouseMove(3, 5);

    BOOST_REQUIRE_EQUAL(d_inputEventReceiver->d_pointerPosition.d_x, 3);
    BOOST_REQUIRE_EQUAL(d_inputEventReceiver->d_pointerPosition.d_y, 5);

    d_inputAggregator->injectMouseMove(3, -3);

    BOOST_REQUIRE_EQUAL(d_inputEventReceiver->d_pointerPosition.d_x, 6);
    BOOST_REQUIRE_EQUAL(d_inputEventReceiver->d_pointerPosition.d_y, 2);
}

BOOST_AUTO_TEST_CASE(MovementEventZeroPosition)
{
    d_inputAggregator->injectMousePosition(0, 0);

    BOOST_REQUIRE_EQUAL(d_inputEventReceiver->d_pointerPosition.d_x, 0);
    BOOST_REQUIRE_EQUAL(d_inputEventReceiver->d_pointerPosition.d_y, 0);
}

BOOST_AUTO_TEST_CASE(MovementEventNonZeroPosition)
{
    d_inputAggregator->injectMousePosition(30, 40);

    BOOST_REQUIRE_EQUAL(d_inputEventReceiver->d_pointerPosition.d_x, 30);
    BOOST_REQUIRE_EQUAL(d_inputEventReceiver->d_pointerPosition.d_y, 40);
}

BOOST_AUTO_TEST_CASE(MovementEventMultiplePositions)
{
    d_inputAggregator->injectMousePosition(3, 5);

    BOOST_REQUIRE_EQUAL(d_inputEventReceiver->d_pointerPosition.d_x, 3);
    BOOST_REQUIRE_EQUAL(d_inputEventReceiver->d_pointerPosition.d_y, 5);

    d_inputAggregator->injectMousePosition(3, -3);

    BOOST_REQUIRE_EQUAL(d_inputEventReceiver->d_pointerPosition.d_x, 3);
    BOOST_REQUIRE_EQUAL(d_inputEventReceiver->d_pointerPosition.d_y, -3);
}

BOOST_AUTO_TEST_CASE(ScrollEventNoDelta)
{
    d_inputAggregator->injectMouseWheelChange(0);

    BOOST_REQUIRE_EQUAL(d_inputEventReceiver->d_totalScroll, 0);
}

BOOST_AUTO_TEST_CASE(ScrollEventMultipleDelta)
{
    d_inputAggregator->injectMouseWheelChange(1);
    BOOST_REQUIRE_EQUAL(d_inputEventReceiver->d_totalScroll, 1);

    d_inputAggregator->injectMouseWheelChange(3);
    BOOST_REQUIRE_EQUAL(d_inputEventReceiver->d_totalScroll, 4);

    d_inputAggregator->injectMouseWheelChange(5);
    BOOST_REQUIRE_EQUAL(d_inputEventReceiver->d_totalScroll, 9);

    d_inputAggregator->injectMouseWheelChange(-2);
    BOOST_REQUIRE_EQUAL(d_inputEventReceiver->d_totalScroll, 7);
}

BOOST_AUTO_TEST_CASE(CutRequestToCut)
{
    std::vector<SemanticValue> expected_values;
    expected_values.push_back(SV_Cut);

    d_inputAggregator->injectCutRequest();

    BOOST_REQUIRE_EQUAL_COLLECTIONS(expected_values.begin(), expected_values.end(),
        d_inputEventReceiver->d_semanticValues.begin(),
        d_inputEventReceiver->d_semanticValues.end());
}

BOOST_AUTO_TEST_CASE(CopyRequestToCopy)
{
    std::vector<SemanticValue> expected_values;
    expected_values.push_back(SV_Copy);

    d_inputAggregator->injectCopyRequest();

    BOOST_REQUIRE_EQUAL_COLLECTIONS(expected_values.begin(), expected_values.end(),
        d_inputEventReceiver->d_semanticValues.begin(),
        d_inputEventReceiver->d_semanticValues.end());
}

BOOST_AUTO_TEST_CASE(PasteRequestToPaste)
{
    std::vector<SemanticValue> expected_values;
    expected_values.push_back(SV_Paste);

    d_inputAggregator->injectPasteRequest();

    BOOST_REQUIRE_EQUAL_COLLECTIONS(expected_values.begin(), expected_values.end(),
        d_inputEventReceiver->d_semanticValues.begin(),
        d_inputEventReceiver->d_semanticValues.end());
}

BOOST_AUTO_TEST_CASE(MouseButtonDownToPointerHold)
{
    std::vector<SemanticValue> expected_values;
    expected_values.push_back(SV_PointerPressHold);

    d_inputAggregator->injectMouseButtonDown(LeftButton);

    BOOST_REQUIRE_EQUAL_COLLECTIONS(expected_values.begin(), expected_values.end(),
        d_inputEventReceiver->d_semanticValues.begin(),
        d_inputEventReceiver->d_semanticValues.end());
}

BOOST_AUTO_TEST_CASE(MouseButtonDownAndControlToSelectCumulative)
{
    std::vector<SemanticValue> expected_values;
    expected_values.push_back(SV_SelectCumulative);

    d_inputAggregator->injectKeyDown(Key::LeftControl);
    d_inputAggregator->injectMouseButtonDown(LeftButton);

    BOOST_REQUIRE_EQUAL_COLLECTIONS(expected_values.begin(), expected_values.end(),
        d_inputEventReceiver->d_semanticValues.begin(),
        d_inputEventReceiver->d_semanticValues.end());
}

BOOST_AUTO_TEST_CASE(MouseButtonDownAndShiftToSelectMultiple)
{
    std::vector<SemanticValue> expected_values;
    expected_values.push_back(SV_SelectRange);

    d_inputAggregator->injectKeyDown(Key::LeftShift);
    d_inputAggregator->injectMouseButtonDown(LeftButton);

    BOOST_REQUIRE_EQUAL_COLLECTIONS(expected_values.begin(), expected_values.end(),
        d_inputEventReceiver->d_semanticValues.begin(),
        d_inputEventReceiver->d_semanticValues.end());
}

BOOST_AUTO_TEST_CASE(MouseButtonUpToPointerActivate)
{
    std::vector<SemanticValue> expected_values;
    expected_values.push_back(SV_PointerActivate);

    d_inputAggregator->injectMouseButtonUp(LeftButton);

    BOOST_REQUIRE_EQUAL_COLLECTIONS(expected_values.begin(), expected_values.end(),
        d_inputEventReceiver->d_semanticValues.begin(),
        d_inputEventReceiver->d_semanticValues.end());
}

BOOST_AUTO_TEST_CASE(MouseButtonDownAndUpCombined)
{
    std::vector<SemanticValue> expected_values;
    expected_values.push_back(SV_PointerPressHold);
    expected_values.push_back(SV_PointerActivate);

    d_inputAggregator->injectMouseButtonDown(LeftButton);
    d_inputAggregator->injectMouseButtonUp(LeftButton);

    BOOST_REQUIRE_EQUAL_COLLECTIONS(expected_values.begin(), expected_values.end(),
        d_inputEventReceiver->d_semanticValues.begin(),
        d_inputEventReceiver->d_semanticValues.end());
}

BOOST_AUTO_TEST_CASE(MouseClickToPointerActivate)
{
    std::vector<SemanticValue> expected_values;
    expected_values.push_back(SV_PointerActivate);

    d_inputAggregator->injectMouseButtonClick(LeftButton);

    BOOST_REQUIRE_EQUAL_COLLECTIONS(expected_values.begin(), expected_values.end(),
        d_inputEventReceiver->d_semanticValues.begin(),
        d_inputEventReceiver->d_semanticValues.end());
}

BOOST_AUTO_TEST_CASE(MouseClickAndControlToSelectCumulative)
{
    std::vector<SemanticValue> expected_values;
    expected_values.push_back(SV_SelectCumulative);

    d_inputAggregator->injectKeyDown(Key::LeftControl);
    d_inputAggregator->injectMouseButtonClick(LeftButton);

    BOOST_REQUIRE_EQUAL_COLLECTIONS(expected_values.begin(), expected_values.end(),
        d_inputEventReceiver->d_semanticValues.begin(),
        d_inputEventReceiver->d_semanticValues.end());
}

BOOST_AUTO_TEST_CASE(MouseClickAndShiftToSelectMultipleItems)
{
    std::vector<SemanticValue> expected_values;
    expected_values.push_back(SV_PointerActivate);

    d_inputAggregator->injectKeyDown(Key::LeftShift);
    d_inputAggregator->injectMouseButtonClick(LeftButton);

    BOOST_REQUIRE_EQUAL_COLLECTIONS(expected_values.begin(), expected_values.end(),
        d_inputEventReceiver->d_semanticValues.begin(),
        d_inputEventReceiver->d_semanticValues.end());
}

BOOST_AUTO_TEST_CASE(MouseDoubleClickToSelectWord)
{
    std::vector<SemanticValue> expected_values;
    expected_values.push_back(SV_SelectWord);

    d_inputAggregator->injectMouseButtonDoubleClick(LeftButton);

    BOOST_REQUIRE_EQUAL_COLLECTIONS(expected_values.begin(), expected_values.end(),
        d_inputEventReceiver->d_semanticValues.begin(),
        d_inputEventReceiver->d_semanticValues.end());
}

BOOST_AUTO_TEST_CASE(MouseTripleClickToSelectAll)
{
    std::vector<SemanticValue> expected_values;
    expected_values.push_back(SV_SelectAll);

    d_inputAggregator->injectMouseButtonTripleClick(LeftButton);

    BOOST_REQUIRE_EQUAL_COLLECTIONS(expected_values.begin(), expected_values.end(),
        d_inputEventReceiver->d_semanticValues.begin(),
        d_inputEventReceiver->d_semanticValues.end());
}

BOOST_AUTO_TEST_CASE(KeyDownBackspaceToDeletePreviousCharacter)
{
    std::vector<SemanticValue> expected_values;
    expected_values.push_back(SV_DeletePreviousCharacter);

    d_inputAggregator->injectKeyDown(Key::Backspace);
    d_inputAggregator->injectKeyUp(Key::Backspace);

    BOOST_REQUIRE_EQUAL_COLLECTIONS(expected_values.begin(), expected_values.end(),
        d_inputEventReceiver->d_semanticValues.begin(),
        d_inputEventReceiver->d_semanticValues.end());
}

BOOST_AUTO_TEST_CASE(KeyDownDeleteToDeleteNextCharacter)
{
    std::vector<SemanticValue> expected_values;
    expected_values.push_back(SV_DeleteNextCharacter);

    d_inputAggregator->injectKeyDown(Key::Delete);
    d_inputAggregator->injectKeyUp(Key::Delete);

    BOOST_REQUIRE_EQUAL_COLLECTIONS(expected_values.begin(), expected_values.end(),
        d_inputEventReceiver->d_semanticValues.begin(),
        d_inputEventReceiver->d_semanticValues.end());
}

BOOST_AUTO_TEST_CASE(KeyDownLeftArrowToGoToPreviousCharacter)
{
    std::vector<SemanticValue> expected_values;
    expected_values.push_back(SV_GoToPreviousCharacter);

    d_inputAggregator->injectKeyDown(Key::ArrowLeft);
    d_inputAggregator->injectKeyUp(Key::ArrowLeft);

    BOOST_REQUIRE_EQUAL_COLLECTIONS(expected_values.begin(), expected_values.end(),
        d_inputEventReceiver->d_semanticValues.begin(),
        d_inputEventReceiver->d_semanticValues.end());
}

BOOST_AUTO_TEST_CASE(KeyDownLeftArrowAndShiftToSelectPreviousCharacter)
{
    std::vector<SemanticValue> expected_values;
    expected_values.push_back(SV_SelectPreviousCharacter);

    d_inputAggregator->injectKeyDown(Key::LeftShift);
    d_inputAggregator->injectKeyDown(Key::ArrowLeft);
    d_inputAggregator->injectKeyUp(Key::ArrowLeft);

    BOOST_REQUIRE_EQUAL_COLLECTIONS(expected_values.begin(), expected_values.end(),
        d_inputEventReceiver->d_semanticValues.begin(),
        d_inputEventReceiver->d_semanticValues.end());
}

BOOST_AUTO_TEST_CASE(KeyDownLeftArrowAndControlToGoToPreviousWord)
{
    std::vector<SemanticValue> expected_values;
    expected_values.push_back(SV_GoToPreviousWord);

    d_inputAggregator->injectKeyDown(Key::LeftControl);
    d_inputAggregator->injectKeyDown(Key::ArrowLeft);
    d_inputAggregator->injectKeyUp(Key::ArrowLeft);

    BOOST_REQUIRE_EQUAL_COLLECTIONS(expected_values.begin(), expected_values.end(),
        d_inputEventReceiver->d_semanticValues.begin(),
        d_inputEventReceiver->d_semanticValues.end());
}

BOOST_AUTO_TEST_SUITE_END()
