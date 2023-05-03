/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef CLOSEDLOOPGRAPHVIEWBASE_HPP
#define CLOSEDLOOPGRAPHVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/closedloopgraph_screen/ClosedLoopGraphPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <gui/containers/SpOpFb.hpp>
#include <touchgfx/widgets/BoxWithBorder.hpp>
#include <touchgfx/widgets/ButtonWithLabel.hpp>
#include <touchgfx/widgets/graph/GraphWrapAndClear.hpp>
#include <touchgfx/widgets/graph/GraphElements.hpp>
#include <touchgfx/widgets/graph/GraphLabels.hpp>
#include <touchgfx/widgets/canvas/PainterRGB565.hpp>
#include <gui/containers/ButtonDone.hpp>
#include <gui/containers/DigitalInputIndicator.hpp>
#include <gui/containers/DigitalOutput.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>

class ClosedLoopGraphViewBase : public touchgfx::View<ClosedLoopGraphPresenter>
{
public:
    ClosedLoopGraphViewBase();
    virtual ~ClosedLoopGraphViewBase();
    virtual void setupScreen();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::Box boxBackground;
    SpOpFb spOpFb1;
    touchgfx::BoxWithBorder boxWithBorder1;
    touchgfx::ButtonWithLabel buttonWithLabel_start;
    touchgfx::GraphWrapAndClear<600> graphBackgroud;
    touchgfx::GraphElementGridX graphBackgroudMajorXAxisGrid;
    touchgfx::GraphElementGridY graphBackgroudMajorYAxisGrid;
    touchgfx::GraphLabelsX graphBackgroudMajorXAxisLabel;
    touchgfx::GraphLabelsY graphBackgroudMajorYAxisLabel;
    touchgfx::GraphWrapAndClear<600> graphFeadback;
    touchgfx::GraphElementLine graphFeadbackLine1;
    touchgfx::PainterRGB565 graphFeadbackLine1Painter;
    touchgfx::GraphWrapAndClear<600> graphSetpoint;
    touchgfx::GraphElementLine graphSetpointLine1;
    touchgfx::PainterRGB565 graphSetpointLine1Painter;
    ButtonDone buttonDone1;
    DigitalInputIndicator digitalInputIndicator1;
    touchgfx::Box box1;
    touchgfx::ButtonWithLabel buttonWithLabel_stop;
    touchgfx::ButtonWithLabel buttonWithLabel_set;
    touchgfx::BoxWithBorder boxWithBorder2;
    DigitalOutput digitalOutput1;
    touchgfx::TextAreaWithOneWildcard text_analogVal_Kp;
    touchgfx::TextAreaWithOneWildcard text_analogVal_Ki;
    touchgfx::TextAreaWithOneWildcard text_analogVal_Kd;

    /*
     * Wildcard Buffers
     */
    static const uint16_t TEXT_ANALOGVAL_KP_SIZE = 10;
    touchgfx::Unicode::UnicodeChar text_analogVal_KpBuffer[TEXT_ANALOGVAL_KP_SIZE];
    static const uint16_t TEXT_ANALOGVAL_KI_SIZE = 10;
    touchgfx::Unicode::UnicodeChar text_analogVal_KiBuffer[TEXT_ANALOGVAL_KI_SIZE];
    static const uint16_t TEXT_ANALOGVAL_KD_SIZE = 10;
    touchgfx::Unicode::UnicodeChar text_analogVal_KdBuffer[TEXT_ANALOGVAL_KD_SIZE];

private:

    /*
     * Canvas Buffer Size
     */
    static const uint32_t CANVAS_BUFFER_SIZE = 12000;
    uint8_t canvasBuffer[CANVAS_BUFFER_SIZE];

    /*
     * Callback Declarations
     */
    touchgfx::Callback<ClosedLoopGraphViewBase, const touchgfx::AbstractButton&> buttonCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);

};

#endif // CLOSEDLOOPGRAPHVIEWBASE_HPP
