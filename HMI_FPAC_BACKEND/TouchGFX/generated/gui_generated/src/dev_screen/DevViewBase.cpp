/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/dev_screen/DevViewBase.hpp>
#include <touchgfx/canvas_widget_renderer/CanvasWidgetRenderer.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <images/BitmapDatabase.hpp>

DevViewBase::DevViewBase() :
    radioButtonSelectedCallback(this, &DevViewBase::radioButtonSelectedCallbackHandler),
    buttonCallback(this, &DevViewBase::buttonCallbackHandler)
{
    touchgfx::CanvasWidgetRenderer::setupBuffer(canvasBuffer, CANVAS_BUFFER_SIZE);
    
    __background.setPosition(0, 0, 800, 480);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    boxBackground.setPosition(0, 0, 800, 480);
    boxBackground.setColor(touchgfx::Color::getColorFromRGB(214, 236, 255));
    add(boxBackground);

    textArea1_1_1.setPosition(257, 438, 286, 29);
    textArea1_1_1.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textArea1_1_1.setLinespacing(0);
    textArea1_1_1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_PKNS));
    add(textArea1_1_1);

    graphBackgroud.setPosition(10, 6, 780, 380);
    graphBackgroud.setScale(10000);
    graphBackgroud.setGraphAreaMargin(17, 24, 0, 29);
    graphBackgroud.setGraphAreaPadding(0, 0, 10, 0);
    graphBackgroud.setGraphRangeY(-25, 25);
    graphBackgroudMajorXAxisGrid.setColor(touchgfx::Color::getColorFromRGB(20, 151, 197));
    graphBackgroudMajorXAxisGrid.setInterval(30);
    graphBackgroudMajorXAxisGrid.setLineWidth(1);
    graphBackgroudMajorXAxisGrid.setAlpha(64);
    graphBackgroudMajorXAxisGrid.setScale(10000);
    graphBackgroud.addGraphElement(graphBackgroudMajorXAxisGrid);

    graphBackgroudMajorYAxisGrid.setColor(touchgfx::Color::getColorFromRGB(20, 151, 197));
    graphBackgroudMajorYAxisGrid.setInterval(1);
    graphBackgroudMajorYAxisGrid.setLineWidth(1);
    graphBackgroudMajorYAxisGrid.setAlpha(104);
    graphBackgroudMajorYAxisGrid.setScale(10000);
    graphBackgroud.addGraphElement(graphBackgroudMajorYAxisGrid);

    graphBackgroudMajorXAxisLabel.setInterval(30);
    graphBackgroudMajorXAxisLabel.setLabelTypedText(touchgfx::TypedText(T___SINGLEUSE_08V4));
    graphBackgroudMajorXAxisLabel.setColor(touchgfx::Color::getColorFromRGB(74, 74, 74));
    graphBackgroudMajorXAxisLabel.setScale(10000);
    graphBackgroud.addBottomElement(graphBackgroudMajorXAxisLabel);

    graphBackgroudMajorYAxisLabel.setInterval(1);
    graphBackgroudMajorYAxisLabel.setLabelTypedText(touchgfx::TypedText(T___SINGLEUSE_AC8Q));
    graphBackgroudMajorYAxisLabel.setColor(touchgfx::Color::getColorFromRGB(74, 74, 74));
    graphBackgroudMajorYAxisLabel.setScale(10000);
    graphBackgroud.addLeftElement(graphBackgroudMajorYAxisLabel);


    add(graphBackgroud);

    graphA.setPosition(10, 6, 780, 380);
    graphA.setScale(10000);
    graphA.setGraphAreaMargin(17, 24, 0, 29);
    graphA.setGraphAreaPadding(0, 0, 10, 0);
    graphA.setGraphRangeY(-25, 25);
    graphALine1Painter.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
    graphALine1.setPainter(graphALine1Painter);
    graphALine1.setLineWidth(1);
    graphA.addGraphElement(graphALine1);

    add(graphA);

    graphV.setPosition(10, 6, 780, 380);
    graphV.setScale(10000);
    graphV.setGraphAreaMargin(17, 24, 0, 29);
    graphV.setGraphAreaPadding(0, 0, 10, 0);
    graphV.setGraphRangeY(-25, 25);
    graphVLine1Painter.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    graphVLine1.setPainter(graphVLine1Painter);
    graphVLine1.setLineWidth(1);
    graphV.addGraphElement(graphVLine1);

    add(graphV);

    graphS.setPosition(10, 6, 780, 380);
    graphS.setScale(10000);
    graphS.setGraphAreaMargin(17, 24, 0, 29);
    graphS.setGraphAreaPadding(0, 0, 10, 0);
    graphS.setGraphRangeY(-25, 25);
    graphSLine1Painter.setColor(touchgfx::Color::getColorFromRGB(167, 0, 178));
    graphSLine1.setPainter(graphSLine1Painter);
    graphSLine1.setLineWidth(1);
    graphS.addGraphElement(graphSLine1);

    add(graphS);

    buttonOnOff.setXY(19, 399);
    buttonOnOff.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_TOGGLEBUTTON_MEDIUM_ROUND_SMALL_ON_ACTIVE_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_TOGGLEBUTTON_MEDIUM_ROUND_SMALL_OFF_LIGHT_ID));
    buttonOnOff.setAction(buttonCallback);
    add(buttonOnOff);

    radioButtonGroup1.setRadioButtonSelectedHandler(radioButtonSelectedCallback);
    
    radioSineFunction.setXY(208, 386);
    radioSineFunction.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_RADIOBUTTON_RADIO_MEDIUM_ROUNDED_OFF_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_RADIOBUTTON_RADIO_MEDIUM_ROUNDED_OFF_PRESSED_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_RADIOBUTTON_RADIO_MEDIUM_ROUNDED_ON_DARK_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_RADIOBUTTON_RADIO_MEDIUM_ROUNDED_ON_PRESSED_ID));
    radioSineFunction.setSelected(false);
    radioSineFunction.setDeselectionEnabled(false);
    radioButtonGroup1.add(radioSineFunction);
    add(radioSineFunction);

    radioIncrease.setXY(208, 431);
    radioIncrease.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_RADIOBUTTON_RADIO_MEDIUM_ROUNDED_OFF_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_RADIOBUTTON_RADIO_MEDIUM_ROUNDED_OFF_PRESSED_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_RADIOBUTTON_RADIO_MEDIUM_ROUNDED_ON_DARK_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_RADIOBUTTON_RADIO_MEDIUM_ROUNDED_ON_PRESSED_ID));
    radioIncrease.setSelected(false);
    radioIncrease.setDeselectionEnabled(false);
    radioButtonGroup1.add(radioIncrease);
    add(radioIncrease);

    radioAccelerated.setXY(393, 386);
    radioAccelerated.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_RADIOBUTTON_RADIO_MEDIUM_ROUNDED_OFF_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_RADIOBUTTON_RADIO_MEDIUM_ROUNDED_OFF_PRESSED_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_RADIOBUTTON_RADIO_MEDIUM_ROUNDED_ON_DARK_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_RADIOBUTTON_RADIO_MEDIUM_ROUNDED_ON_PRESSED_ID));
    radioAccelerated.setSelected(false);
    radioAccelerated.setDeselectionEnabled(false);
    radioButtonGroup1.add(radioAccelerated);
    add(radioAccelerated);

    textArea1.setPosition(257, 393, 118, 22);
    textArea1.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textArea1.setLinespacing(0);
    textArea1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_HMK5));
    add(textArea1);

    textArea1_1.setPosition(437, 393, 315, 22);
    textArea1_1.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textArea1_1.setLinespacing(0);
    textArea1_1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_M6HU));
    add(textArea1_1);

    textArea2.setXY(567, 439);
    textArea2.setColor(touchgfx::Color::getColorFromRGB(170, 15, 183));
    textArea2.setLinespacing(0);
    textArea2.setTypedText(touchgfx::TypedText(T___SINGLEUSE_2ZR8));
    add(textArea2);

    textArea2_1.setXY(588, 439);
    textArea2_1.setColor(touchgfx::Color::getColorFromRGB(40, 44, 48));
    textArea2_1.setLinespacing(0);
    textArea2_1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_30XT));
    add(textArea2_1);

    textArea2_1_1.setXY(608, 439);
    textArea2_1_1.setColor(touchgfx::Color::getColorFromRGB(247, 48, 52));
    textArea2_1_1.setLinespacing(0);
    textArea2_1_1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_H03V));
    add(textArea2_1_1);
}

DevViewBase::~DevViewBase()
{
    touchgfx::CanvasWidgetRenderer::resetBuffer();
}

void DevViewBase::setupScreen()
{

}

void DevViewBase::radioButtonSelectedCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &radioSineFunction)
    {
        //Interaction1
        //When radioSineFunction selected call virtual function
        //Call radioSineFuntionHandle
        radioSineFuntionHandle();
    }
    if (&src == &radioIncrease)
    {
        //Interaction2
        //When radioIncrease selected call virtual function
        //Call radioIncrieaseFuntionHandle
        radioIncrieaseFuntionHandle();
    }
    if (&src == &radioAccelerated)
    {
        //Interaction3
        //When radioAccelerated selected call virtual function
        //Call radioAcceleratedFuntionHandle
        radioAcceleratedFuntionHandle();
    }
}

void DevViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &buttonOnOff)
    {
        //Interaction4
        //When buttonOnOff clicked call virtual function
        //Call buttonOnOffHandle
        buttonOnOffHandle();
    }
}
