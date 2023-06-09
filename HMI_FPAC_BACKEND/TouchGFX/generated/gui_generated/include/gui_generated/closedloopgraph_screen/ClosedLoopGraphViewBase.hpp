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
#include <gui/containers/DigitalInputIndicator.hpp>
#include <touchgfx/widgets/graph/GraphWrapAndClear.hpp>
#include <touchgfx/widgets/graph/GraphElements.hpp>
#include <touchgfx/widgets/graph/GraphLabels.hpp>
#include <touchgfx/widgets/canvas/PainterRGB565.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/widgets/ButtonWithIcon.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/containers/SlideMenu.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/widgets/ToggleButton.hpp>
#include <touchgfx/widgets/Image.hpp>

class ClosedLoopGraphViewBase : public touchgfx::View<ClosedLoopGraphPresenter>
{
public:
    ClosedLoopGraphViewBase();
    virtual ~ClosedLoopGraphViewBase();
    virtual void setupScreen();

    /*
     * Virtual Action Handlers
     */
    virtual void startButton_Handle()
    {
        // Override and implement this function in ClosedLoopGraph
    }
    virtual void stopButton_Handle()
    {
        // Override and implement this function in ClosedLoopGraph
    }
    virtual void clearButton_Handle()
    {
        // Override and implement this function in ClosedLoopGraph
    }
    virtual void setButtonHandle()
    {
        // Override and implement this function in ClosedLoopGraph
    }
    virtual void buttonDigital0Handle()
    {
        // Override and implement this function in ClosedLoopGraph
    }
    virtual void buttonDigital1Handle()
    {
        // Override and implement this function in ClosedLoopGraph
    }
    virtual void buttonDigital2Handle()
    {
        // Override and implement this function in ClosedLoopGraph
    }
    virtual void buttonDigital3Handle()
    {
        // Override and implement this function in ClosedLoopGraph
    }
    virtual void buttonDoneHandle()
    {
        // Override and implement this function in ClosedLoopGraph
    }
    virtual void zoomInXHandle()
    {
        // Override and implement this function in ClosedLoopGraph
    }
    virtual void zoomOutXHandle()
    {
        // Override and implement this function in ClosedLoopGraph
    }
    virtual void buttonForwardHandle()
    {
        // Override and implement this function in ClosedLoopGraph
    }
    virtual void buttonBackwardHandle()
    {
        // Override and implement this function in ClosedLoopGraph
    }

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
    DigitalInputIndicator digitalInputIndicator1;
    touchgfx::GraphWrapAndClear<1700> graphBackgroud;
    touchgfx::GraphElementGridX graphBackgroudMajorXAxisGrid;
    touchgfx::GraphElementGridY graphBackgroudMajorYAxisGrid;
    touchgfx::GraphLabelsX graphBackgroudMajorXAxisLabel;
    touchgfx::GraphLabelsY graphBackgroudMajorYAxisLabel;
    touchgfx::GraphWrapAndClear<1700> graphFeadback;
    touchgfx::GraphElementLine graphFeadbackLine1;
    touchgfx::PainterRGB565 graphFeadbackLine1Painter;
    touchgfx::GraphWrapAndClear<1700> graphSetpoint;
    touchgfx::GraphElementLine graphSetpointLine1;
    touchgfx::PainterRGB565 graphSetpointLine1Painter;
    touchgfx::GraphWrapAndClear<1700> graphOutput;
    touchgfx::GraphElementGridX graphOutputMajorXAxisGrid;
    touchgfx::GraphElementGridY graphOutputMajorYAxisGrid;
    touchgfx::GraphElementLine graphOutputLine1;
    touchgfx::PainterRGB565 graphOutputLine1Painter;
    touchgfx::ButtonWithLabel buttonWithLabel_stop;
    touchgfx::ButtonWithLabel buttonWithLabel_clear;
    touchgfx::ButtonWithLabel buttonWithLabel_set;
    touchgfx::BoxWithBorder boxWithBorder2;
    touchgfx::TextAreaWithOneWildcard text_analogVal_Kp;
    touchgfx::TextAreaWithOneWildcard text_analogVal_Ki;
    touchgfx::TextAreaWithOneWildcard text_analogVal_Kd;
    touchgfx::ButtonWithIcon buttonDone;
    touchgfx::TextArea textArea5;
    touchgfx::ButtonWithIcon buttonXZoomIn;
    touchgfx::ButtonWithIcon buttonBackward;
    touchgfx::ButtonWithIcon buttonXZoomOut;
    touchgfx::ButtonWithIcon buttonForward;
    touchgfx::SlideMenu binaryMenu;
    touchgfx::BoxWithBorder boxWithBorder6;
    touchgfx::Container binaryButton;
    touchgfx::ToggleButton buttonDigital3;
    touchgfx::ToggleButton buttonDigital2;
    touchgfx::ToggleButton buttonDigital1;
    touchgfx::ToggleButton buttonDigital0;
    touchgfx::TextArea textArea4;
    touchgfx::TextArea textArea4_2;
    touchgfx::TextArea textArea4_2_1;
    touchgfx::TextArea textArea4_1;
    touchgfx::Image image1_1;

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
