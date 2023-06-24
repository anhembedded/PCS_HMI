/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/closedloopgraph_screen/ClosedLoopGraphViewBase.hpp>
#include <touchgfx/canvas_widget_renderer/CanvasWidgetRenderer.hpp>
#include <touchgfx/Color.hpp>
#include <images/BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>

ClosedLoopGraphViewBase::ClosedLoopGraphViewBase() :
    buttonCallback(this, &ClosedLoopGraphViewBase::buttonCallbackHandler)
{
    touchgfx::CanvasWidgetRenderer::setupBuffer(canvasBuffer, CANVAS_BUFFER_SIZE);
    
    __background.setPosition(0, 0, 800, 480);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    boxBackground.setPosition(0, 0, 800, 480);
    boxBackground.setColor(touchgfx::Color::getColorFromRGB(214, 236, 255));
    add(boxBackground);

    spOpFb1.setXY(590, 381);
    add(spOpFb1);

    boxWithBorder1.setPosition(10, 380, 431, 96);
    boxWithBorder1.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    boxWithBorder1.setBorderColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    boxWithBorder1.setBorderSize(5);
    add(boxWithBorder1);

    buttonWithLabel_start.setXY(132, 387);
    buttonWithLabel_start.setBitmaps(touchgfx::Bitmap(BITMAP_DARK_THEME_IMAGES_WIDGETS_BUTTON_REGULAR_HEIGHT_36_SMALL_ROUNDED_ACTIVE_ID), touchgfx::Bitmap(BITMAP_DARK_THEME_IMAGES_WIDGETS_BUTTON_REGULAR_HEIGHT_36_SMALL_ROUNDED_PRESSED_ID));
    buttonWithLabel_start.setLabelText(touchgfx::TypedText(T___SINGLEUSE_V6NC));
    buttonWithLabel_start.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonWithLabel_start.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonWithLabel_start.setAction(buttonCallback);
    add(buttonWithLabel_start);

    graphBackgroud.setPosition(10, 6, 780, 380);
    graphBackgroud.setScale(100);
    graphBackgroud.setGraphRangeX(0, 600);
    graphBackgroud.setGraphAreaMargin(17, 24, 0, 29);
    graphBackgroud.setGraphAreaPadding(0, 0, 10, 0);
    graphBackgroud.setGraphRangeY(-1.0f, 11.3f);
    graphBackgroudMajorXAxisGrid.setColor(touchgfx::Color::getColorFromRGB(20, 151, 197));
    graphBackgroudMajorXAxisGrid.setInterval(250);
    graphBackgroudMajorXAxisGrid.setLineWidth(1);
    graphBackgroudMajorXAxisGrid.setAlpha(64);
    graphBackgroudMajorXAxisGrid.setScale(100);
    graphBackgroud.addGraphElement(graphBackgroudMajorXAxisGrid);

    graphBackgroudMajorYAxisGrid.setColor(touchgfx::Color::getColorFromRGB(20, 151, 197));
    graphBackgroudMajorYAxisGrid.setInterval(1);
    graphBackgroudMajorYAxisGrid.setLineWidth(1);
    graphBackgroudMajorYAxisGrid.setAlpha(104);
    graphBackgroudMajorYAxisGrid.setScale(100);
    graphBackgroud.addGraphElement(graphBackgroudMajorYAxisGrid);

    graphBackgroudMajorXAxisLabel.setInterval(500);
    graphBackgroudMajorXAxisLabel.setLabelTypedText(touchgfx::TypedText(T___SINGLEUSE_8LM6));
    graphBackgroudMajorXAxisLabel.setColor(touchgfx::Color::getColorFromRGB(74, 74, 74));
    graphBackgroudMajorXAxisLabel.setScale(100);
    graphBackgroud.addBottomElement(graphBackgroudMajorXAxisLabel);

    graphBackgroudMajorYAxisLabel.setInterval(1);
    graphBackgroudMajorYAxisLabel.setLabelTypedText(touchgfx::TypedText(T___SINGLEUSE_WL29));
    graphBackgroudMajorYAxisLabel.setColor(touchgfx::Color::getColorFromRGB(74, 74, 74));
    graphBackgroudMajorYAxisLabel.setScale(100);
    graphBackgroud.addLeftElement(graphBackgroudMajorYAxisLabel);


    add(graphBackgroud);

    graphFeadback.setPosition(10, 6, 780, 380);
    graphFeadback.setScale(100);
    graphFeadback.setGraphRangeX(0, 600);
    graphFeadback.setGraphAreaMargin(17, 24, 0, 29);
    graphFeadback.setGraphAreaPadding(0, 0, 10, 0);
    graphFeadback.setGraphRangeY(-1.0f, 11.3f);
    graphFeadback.setVisible(false);
    graphFeadbackLine1Painter.setColor(touchgfx::Color::getColorFromRGB(188, 0, 201));
    graphFeadbackLine1.setPainter(graphFeadbackLine1Painter);
    graphFeadbackLine1.setLineWidth(2);
    graphFeadback.addGraphElement(graphFeadbackLine1);

    add(graphFeadback);

    graphSetpoint.setPosition(10, 6, 780, 380);
    graphSetpoint.setScale(100);
    graphSetpoint.setGraphRangeX(0, 600);
    graphSetpoint.setGraphAreaMargin(17, 24, 0, 29);
    graphSetpoint.setGraphAreaPadding(0, 0, 10, 0);
    graphSetpoint.setGraphRangeY(-1.0f, 11.3f);
    graphSetpoint.setVisible(false);
    graphSetpointLine1Painter.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    graphSetpointLine1.setPainter(graphSetpointLine1Painter);
    graphSetpointLine1.setLineWidth(2);
    graphSetpoint.addGraphElement(graphSetpointLine1);

    add(graphSetpoint);

    buttonDone1.setXY(725, 0);
    add(buttonDone1);

    digitalInputIndicator1.setXY(20, 434);
    add(digitalInputIndicator1);

    buttonWithLabel_stop.setXY(283, 386);
    buttonWithLabel_stop.setBitmaps(touchgfx::Bitmap(BITMAP_DARK_THEME_IMAGES_WIDGETS_BUTTON_REGULAR_HEIGHT_36_SMALL_ROUNDED_ACTION_ID), touchgfx::Bitmap(BITMAP_DARK_THEME_IMAGES_WIDGETS_BUTTON_REGULAR_HEIGHT_36_SMALL_ROUNDED_PRESSED_ID));
    buttonWithLabel_stop.setLabelText(touchgfx::TypedText(T___SINGLEUSE_2CQX));
    buttonWithLabel_stop.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonWithLabel_stop.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonWithLabel_stop.setAction(buttonCallback);
    add(buttonWithLabel_stop);

    buttonWithLabel_clear.setXY(283, 428);
    buttonWithLabel_clear.setBitmaps(touchgfx::Bitmap(BITMAP_LIGHT_THEME_IMAGES_WIDGETS_BUTTON_REGULAR_HEIGHT_36_SMALL_ROUNDED_NORMAL_ID), touchgfx::Bitmap(BITMAP_LIGHT_THEME_IMAGES_WIDGETS_BUTTON_REGULAR_HEIGHT_36_SMALL_ROUNDED_PRESSED_ID));
    buttonWithLabel_clear.setLabelText(touchgfx::TypedText(T___SINGLEUSE_AZT2));
    buttonWithLabel_clear.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonWithLabel_clear.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonWithLabel_clear.setAction(buttonCallback);
    add(buttonWithLabel_clear);

    buttonWithLabel_set.setXY(20, 387);
    buttonWithLabel_set.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_REGULAR_HEIGHT_36_TINY_ROUNDED_NORMAL_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_REGULAR_HEIGHT_36_TINY_ROUNDED_PRESSED_ID));
    buttonWithLabel_set.setLabelText(touchgfx::TypedText(T___SINGLEUSE_6CM6));
    buttonWithLabel_set.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonWithLabel_set.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonWithLabel_set.setAction(buttonCallback);
    add(buttonWithLabel_set);

    boxWithBorder2.setPosition(455, 381, 95, 76);
    boxWithBorder2.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    boxWithBorder2.setBorderColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    boxWithBorder2.setBorderSize(5);
    add(boxWithBorder2);

    text_analogVal_Kp.setXY(464, 384);
    text_analogVal_Kp.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    text_analogVal_Kp.setLinespacing(0);
    Unicode::snprintf(text_analogVal_KpBuffer, TEXT_ANALOGVAL_KP_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_Z6EL).getText());
    text_analogVal_Kp.setWildcard(text_analogVal_KpBuffer);
    text_analogVal_Kp.resizeToCurrentText();
    text_analogVal_Kp.setTypedText(touchgfx::TypedText(T___SINGLEUSE_21S9));
    add(text_analogVal_Kp);

    text_analogVal_Ki.setXY(464, 405);
    text_analogVal_Ki.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    text_analogVal_Ki.setLinespacing(0);
    Unicode::snprintf(text_analogVal_KiBuffer, TEXT_ANALOGVAL_KI_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_NIL7).getText());
    text_analogVal_Ki.setWildcard(text_analogVal_KiBuffer);
    text_analogVal_Ki.resizeToCurrentText();
    text_analogVal_Ki.setTypedText(touchgfx::TypedText(T___SINGLEUSE_66OT));
    add(text_analogVal_Ki);

    text_analogVal_Kd.setXY(465, 426);
    text_analogVal_Kd.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    text_analogVal_Kd.setLinespacing(0);
    Unicode::snprintf(text_analogVal_KdBuffer, TEXT_ANALOGVAL_KD_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_ABRK).getText());
    text_analogVal_Kd.setWildcard(text_analogVal_KdBuffer);
    text_analogVal_Kd.resizeToCurrentText();
    text_analogVal_Kd.setTypedText(touchgfx::TypedText(T___SINGLEUSE_5HQL));
    add(text_analogVal_Kd);

    digitalOutput1.setXY(0, 358);
    add(digitalOutput1);
}

ClosedLoopGraphViewBase::~ClosedLoopGraphViewBase()
{
    touchgfx::CanvasWidgetRenderer::resetBuffer();
}

void ClosedLoopGraphViewBase::setupScreen()
{
    spOpFb1.initialize();
    buttonDone1.initialize();
    digitalInputIndicator1.initialize();
    digitalOutput1.initialize();
}

void ClosedLoopGraphViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &buttonWithLabel_set)
    {
        //setButton
        //When buttonWithLabel_set clicked change screen to ClosedLoopSetting
        //Go to ClosedLoopSetting with screen transition towards East
        application().gotoClosedLoopSettingScreenCoverTransitionEast();
    }
    if (&src == &buttonWithLabel_start)
    {
        //startButton_Handle
        //When buttonWithLabel_start clicked call virtual function
        //Call startButton_Handle
        startButton_Handle();
    }
    if (&src == &buttonWithLabel_stop)
    {
        //stopButton_Handle
        //When buttonWithLabel_stop clicked call virtual function
        //Call stopButton_Handle
        stopButton_Handle();
    }
    if (&src == &buttonWithLabel_clear)
    {
        //clearButton_Handle
        //When buttonWithLabel_clear clicked call virtual function
        //Call clearButton_Handle
        clearButton_Handle();
    }
}
