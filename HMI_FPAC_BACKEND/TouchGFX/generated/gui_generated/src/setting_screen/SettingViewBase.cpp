/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/setting_screen/SettingViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <images/BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>

SettingViewBase::SettingViewBase() :
    flexButtonCallback(this, &SettingViewBase::flexButtonCallbackHandler),
    sliderValueChangedCallback(this, &SettingViewBase::sliderValueChangedCallbackHandler),
    buttonCallback(this, &SettingViewBase::buttonCallbackHandler)
{
    __background.setPosition(0, 0, 800, 480);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    Background.setPosition(0, 1, 800, 479);
    Background.setColor(touchgfx::Color::getColorFromRGB(214, 236, 255));
    add(Background);

    buttonWithIcon1.setXY(17, 400);
    buttonWithIcon1.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_TINY_FILL_DISABLED_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_TINY_FILL_DISABLED_ID), touchgfx::Bitmap(BITMAP_ICON_THEME_IMAGES_ACTION_HELP_OUTLINE_50_50_E8F6FB_SVG_ID), touchgfx::Bitmap(BITMAP_ICON_THEME_IMAGES_ACTION_DONE_50_50_E8F6FB_SVG_ID));
    buttonWithIcon1.setIconXY(5, 5);
    add(buttonWithIcon1);

    buttonDone1.setXY(725, 0);
    add(buttonDone1);

    containerParameter.setPosition(77, -16, 618, 305);
    boxWithBorder3.setPosition(0, 22, 618, 283);
    boxWithBorder3.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    boxWithBorder3.setBorderColor(touchgfx::Color::getColorFromRGB(145, 1, 133));
    boxWithBorder3.setBorderSize(5);
    containerParameter.add(boxWithBorder3);

    boxWithBorder1_1.setPosition(453, 66, 140, 46);
    boxWithBorder1_1.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    boxWithBorder1_1.setBorderColor(touchgfx::Color::getColorFromRGB(219, 0, 132));
    boxWithBorder1_1.setBorderSize(5);
    containerParameter.add(boxWithBorder1_1);

    boxWithBorder1_1_1.setPosition(453, 185, 140, 46);
    boxWithBorder1_1_1.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    boxWithBorder1_1_1.setBorderColor(touchgfx::Color::getColorFromRGB(219, 0, 132));
    boxWithBorder1_1_1.setBorderSize(5);
    containerParameter.add(boxWithBorder1_1_1);

    boxWithBorder1_1_2.setPosition(453, 242, 140, 46);
    boxWithBorder1_1_2.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    boxWithBorder1_1_2.setBorderColor(touchgfx::Color::getColorFromRGB(219, 0, 132));
    boxWithBorder1_1_2.setBorderSize(5);
    containerParameter.add(boxWithBorder1_1_2);

    buttonTextFactor0.setBoxWithBorderPosition(0, 0, 119, 46);
    buttonTextFactor0.setBorderSize(5);
    buttonTextFactor0.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(87, 119, 243), touchgfx::Color::getColorFromRGB(51, 102, 153));
    buttonTextFactor0.setAction(flexButtonCallback);
    buttonTextFactor0.setPosition(164, 66, 119, 46);
    containerParameter.add(buttonTextFactor0);

    buttonTextFactor1.setBoxWithBorderPosition(0, 0, 119, 46);
    buttonTextFactor1.setBorderSize(5);
    buttonTextFactor1.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(87, 119, 243), touchgfx::Color::getColorFromRGB(51, 102, 153));
    buttonTextFactor1.setAction(flexButtonCallback);
    buttonTextFactor1.setPosition(164, 123, 119, 46);
    containerParameter.add(buttonTextFactor1);

    buttonOffset0.setBoxWithBorderPosition(0, 0, 119, 46);
    buttonOffset0.setBorderSize(5);
    buttonOffset0.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(87, 119, 243), touchgfx::Color::getColorFromRGB(51, 102, 153));
    buttonOffset0.setAction(flexButtonCallback);
    buttonOffset0.setPosition(311, 66, 119, 46);
    containerParameter.add(buttonOffset0);

    textAreaFactor0.setPosition(171, 76, 105, 24);
    textAreaFactor0.setColor(touchgfx::Color::getColorFromRGB(214, 236, 255));
    textAreaFactor0.setLinespacing(0);
    Unicode::snprintf(textAreaFactor0Buffer, TEXTAREAFACTOR0_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_2BAG).getText());
    textAreaFactor0.setWildcard(textAreaFactor0Buffer);
    textAreaFactor0.setTypedText(touchgfx::TypedText(T___SINGLEUSE_7ZAQ));
    containerParameter.add(textAreaFactor0);

    buttonOffset1.setBoxWithBorderPosition(0, 0, 119, 46);
    buttonOffset1.setBorderSize(5);
    buttonOffset1.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(87, 119, 243), touchgfx::Color::getColorFromRGB(51, 102, 153));
    buttonOffset1.setAction(flexButtonCallback);
    buttonOffset1.setPosition(311, 123, 119, 46);
    containerParameter.add(buttonOffset1);

    buttonOffset2.setBoxWithBorderPosition(0, 0, 119, 46);
    buttonOffset2.setBorderSize(5);
    buttonOffset2.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(87, 119, 243), touchgfx::Color::getColorFromRGB(51, 102, 153));
    buttonOffset2.setAction(flexButtonCallback);
    buttonOffset2.setPosition(311, 185, 119, 46);
    containerParameter.add(buttonOffset2);

    buttonOffset3.setBoxWithBorderPosition(0, 0, 119, 46);
    buttonOffset3.setBorderSize(5);
    buttonOffset3.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(87, 119, 243), touchgfx::Color::getColorFromRGB(51, 102, 153));
    buttonOffset3.setAction(flexButtonCallback);
    buttonOffset3.setPosition(311, 240, 119, 46);
    containerParameter.add(buttonOffset3);

    buttonTextFactor2.setBoxWithBorderPosition(0, 0, 119, 46);
    buttonTextFactor2.setBorderSize(5);
    buttonTextFactor2.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(87, 119, 243), touchgfx::Color::getColorFromRGB(51, 102, 153));
    buttonTextFactor2.setAction(flexButtonCallback);
    buttonTextFactor2.setPosition(164, 185, 119, 46);
    containerParameter.add(buttonTextFactor2);

    buttonTextFactor3.setBoxWithBorderPosition(0, 0, 119, 46);
    buttonTextFactor3.setBorderSize(5);
    buttonTextFactor3.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(87, 119, 243), touchgfx::Color::getColorFromRGB(51, 102, 153));
    buttonTextFactor3.setAction(flexButtonCallback);
    buttonTextFactor3.setPosition(164, 240, 119, 46);
    containerParameter.add(buttonTextFactor3);

    textAreaFactor1.setPosition(171, 134, 105, 24);
    textAreaFactor1.setColor(touchgfx::Color::getColorFromRGB(214, 236, 255));
    textAreaFactor1.setLinespacing(0);
    Unicode::snprintf(textAreaFactor1Buffer, TEXTAREAFACTOR1_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_AN3X).getText());
    textAreaFactor1.setWildcard(textAreaFactor1Buffer);
    textAreaFactor1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_WSAG));
    containerParameter.add(textAreaFactor1);

    textAreaOffset0.setPosition(321, 76, 105, 24);
    textAreaOffset0.setColor(touchgfx::Color::getColorFromRGB(214, 236, 255));
    textAreaOffset0.setLinespacing(0);
    Unicode::snprintf(textAreaOffset0Buffer, TEXTAREAOFFSET0_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_I393).getText());
    textAreaOffset0.setWildcard(textAreaOffset0Buffer);
    textAreaOffset0.setTypedText(touchgfx::TypedText(T___SINGLEUSE_F3NF));
    containerParameter.add(textAreaOffset0);

    textAreaOffset1.setPosition(321, 134, 105, 24);
    textAreaOffset1.setColor(touchgfx::Color::getColorFromRGB(214, 236, 255));
    textAreaOffset1.setLinespacing(0);
    Unicode::snprintf(textAreaOffset1Buffer, TEXTAREAOFFSET1_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_4CZ5).getText());
    textAreaOffset1.setWildcard(textAreaOffset1Buffer);
    textAreaOffset1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_8R2G));
    containerParameter.add(textAreaOffset1);

    textAreaOffset2.setPosition(321, 196, 105, 24);
    textAreaOffset2.setColor(touchgfx::Color::getColorFromRGB(214, 236, 255));
    textAreaOffset2.setLinespacing(0);
    Unicode::snprintf(textAreaOffset2Buffer, TEXTAREAOFFSET2_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_O5A3).getText());
    textAreaOffset2.setWildcard(textAreaOffset2Buffer);
    textAreaOffset2.setTypedText(touchgfx::TypedText(T___SINGLEUSE_ZTUO));
    containerParameter.add(textAreaOffset2);

    textAreaOffset3.setPosition(318, 251, 105, 24);
    textAreaOffset3.setColor(touchgfx::Color::getColorFromRGB(214, 236, 255));
    textAreaOffset3.setLinespacing(0);
    Unicode::snprintf(textAreaOffset3Buffer, TEXTAREAOFFSET3_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_OA5M).getText());
    textAreaOffset3.setWildcard(textAreaOffset3Buffer);
    textAreaOffset3.setTypedText(touchgfx::TypedText(T___SINGLEUSE_SGH8));
    containerParameter.add(textAreaOffset3);

    textAreaFactor2.setPosition(171, 196, 105, 24);
    textAreaFactor2.setColor(touchgfx::Color::getColorFromRGB(214, 236, 255));
    textAreaFactor2.setLinespacing(0);
    Unicode::snprintf(textAreaFactor2Buffer, TEXTAREAFACTOR2_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_P5M1).getText());
    textAreaFactor2.setWildcard(textAreaFactor2Buffer);
    textAreaFactor2.setTypedText(touchgfx::TypedText(T___SINGLEUSE_FRC2));
    containerParameter.add(textAreaFactor2);

    textAreaFactor3.setPosition(171, 251, 105, 24);
    textAreaFactor3.setColor(touchgfx::Color::getColorFromRGB(214, 236, 255));
    textAreaFactor3.setLinespacing(0);
    Unicode::snprintf(textAreaFactor3Buffer, TEXTAREAFACTOR3_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_2333).getText());
    textAreaFactor3.setWildcard(textAreaFactor3Buffer);
    textAreaFactor3.setTypedText(touchgfx::TypedText(T___SINGLEUSE_9C92));
    containerParameter.add(textAreaFactor3);

    boxWithBorder1.setPosition(453, 123, 140, 46);
    boxWithBorder1.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    boxWithBorder1.setBorderColor(touchgfx::Color::getColorFromRGB(219, 0, 132));
    boxWithBorder1.setBorderSize(5);
    containerParameter.add(boxWithBorder1);

    textProcessVar0.setPosition(466, 76, 105, 24);
    textProcessVar0.setColor(touchgfx::Color::getColorFromRGB(0, 102, 153));
    textProcessVar0.setLinespacing(0);
    Unicode::snprintf(textProcessVar0Buffer, TEXTPROCESSVAR0_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_8MK0).getText());
    textProcessVar0.setWildcard(textProcessVar0Buffer);
    textProcessVar0.setTypedText(touchgfx::TypedText(T___SINGLEUSE_23CX));
    containerParameter.add(textProcessVar0);

    textProcessVar1.setPosition(466, 132, 105, 24);
    textProcessVar1.setColor(touchgfx::Color::getColorFromRGB(0, 102, 153));
    textProcessVar1.setLinespacing(0);
    Unicode::snprintf(textProcessVar1Buffer, TEXTPROCESSVAR1_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_RS99).getText());
    textProcessVar1.setWildcard(textProcessVar1Buffer);
    textProcessVar1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_NHNS));
    containerParameter.add(textProcessVar1);

    textProcessVar2.setPosition(466, 195, 105, 24);
    textProcessVar2.setColor(touchgfx::Color::getColorFromRGB(0, 102, 153));
    textProcessVar2.setLinespacing(0);
    Unicode::snprintf(textProcessVar2Buffer, TEXTPROCESSVAR2_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_6N5H).getText());
    textProcessVar2.setWildcard(textProcessVar2Buffer);
    textProcessVar2.setTypedText(touchgfx::TypedText(T___SINGLEUSE_MI3N));
    containerParameter.add(textProcessVar2);

    textProcessVar3.setPosition(466, 252, 105, 24);
    textProcessVar3.setColor(touchgfx::Color::getColorFromRGB(0, 102, 153));
    textProcessVar3.setLinespacing(0);
    Unicode::snprintf(textProcessVar3Buffer, TEXTPROCESSVAR3_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_EHP6).getText());
    textProcessVar3.setWildcard(textProcessVar3Buffer);
    textProcessVar3.setTypedText(touchgfx::TypedText(T___SINGLEUSE_F52N));
    containerParameter.add(textProcessVar3);

    textAreaCH0.setPosition(27, 78, 130, 22);
    textAreaCH0.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textAreaCH0.setLinespacing(0);
    Unicode::snprintf(textAreaCH0Buffer, TEXTAREACH0_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_YI40).getText());
    textAreaCH0.setWildcard(textAreaCH0Buffer);
    textAreaCH0.setTypedText(touchgfx::TypedText(T___SINGLEUSE_8Y8U));
    containerParameter.add(textAreaCH0);

    textAreaCH1.setPosition(27, 138, 130, 20);
    textAreaCH1.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textAreaCH1.setLinespacing(0);
    Unicode::snprintf(textAreaCH1Buffer, TEXTAREACH1_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_468E).getText());
    textAreaCH1.setWildcard(textAreaCH1Buffer);
    textAreaCH1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_6YFH));
    containerParameter.add(textAreaCH1);

    textAreaCH2.setPosition(27, 197, 130, 23);
    textAreaCH2.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textAreaCH2.setLinespacing(0);
    Unicode::snprintf(textAreaCH2Buffer, TEXTAREACH2_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_2HH1).getText());
    textAreaCH2.setWildcard(textAreaCH2Buffer);
    textAreaCH2.setTypedText(touchgfx::TypedText(T___SINGLEUSE_KR23));
    containerParameter.add(textAreaCH2);

    textAreaCH3.setPosition(27, 253, 130, 23);
    textAreaCH3.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textAreaCH3.setLinespacing(0);
    Unicode::snprintf(textAreaCH3Buffer, TEXTAREACH3_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_A386).getText());
    textAreaCH3.setWildcard(textAreaCH3Buffer);
    textAreaCH3.setTypedText(touchgfx::TypedText(T___SINGLEUSE_CQ7B));
    containerParameter.add(textAreaCH3);

    textArea3_2_1.setXY(321, 33);
    textArea3_2_1.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textArea3_2_1.setLinespacing(0);
    textArea3_2_1.setTypedText(touchgfx::TypedText(T_RESOURCEID2));
    containerParameter.add(textArea3_2_1);

    textArea3_2.setXY(450, 33);
    textArea3_2.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textArea3_2.setLinespacing(0);
    textArea3_2.setTypedText(touchgfx::TypedText(T_RESOURCEID3));
    containerParameter.add(textArea3_2);

    textArea3_1.setXY(14, 33);
    textArea3_1.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textArea3_1.setLinespacing(0);
    textArea3_1.setTypedText(touchgfx::TypedText(T_ANALOGCHANNEL));
    containerParameter.add(textArea3_1);

    textArea3.setXY(178, 33);
    textArea3.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textArea3.setLinespacing(0);
    textArea3.setTypedText(touchgfx::TypedText(T_RESOURCEID1));
    containerParameter.add(textArea3);

    add(containerParameter);

    analogContainer.setPosition(223, 336, 527, 94);
    sliderAnalogOut0.setXY(7, 4);
    sliderAnalogOut0.setBitmaps(touchgfx::Bitmap(BITMAP_CLAY_THEME_IMAGES_WIDGETS_SLIDER_HORIZONTAL_THICK_TRACK_LARGE_ID), touchgfx::Bitmap(BITMAP_CLAY_THEME_IMAGES_WIDGETS_SLIDER_HORIZONTAL_THICK_FILLER_LARGE_ID), touchgfx::Bitmap(BITMAP_CLAY_THEME_IMAGES_WIDGETS_SLIDER_HORIZONTAL_THICK_ROUNDED_LIGHT_ID));
    sliderAnalogOut0.setupHorizontalSlider(16, 11, 0, 0, 400);
    sliderAnalogOut0.setValueRange(0, 4095);
    sliderAnalogOut0.setValue(0);
    sliderAnalogOut0.setNewValueCallback(sliderValueChangedCallback);
    analogContainer.add(sliderAnalogOut0);

    sliderAnalogOut1.setXY(10, 62);
    sliderAnalogOut1.setBitmaps(touchgfx::Bitmap(BITMAP_CLAY_THEME_IMAGES_WIDGETS_SLIDER_HORIZONTAL_THICK_TRACK_LARGE_ID), touchgfx::Bitmap(BITMAP_CLAY_THEME_IMAGES_WIDGETS_SLIDER_HORIZONTAL_THICK_FILLER_LARGE_ID), touchgfx::Bitmap(BITMAP_CLAY_THEME_IMAGES_WIDGETS_SLIDER_HORIZONTAL_THICK_ROUNDED_LIGHT_ID));
    sliderAnalogOut1.setupHorizontalSlider(16, 11, 0, 0, 400);
    sliderAnalogOut1.setValueRange(0, 4095);
    sliderAnalogOut1.setValue(0);
    sliderAnalogOut1.setNewValueCallback(sliderValueChangedCallback);
    analogContainer.add(sliderAnalogOut1);

    textAreaAnalogOut1.setPosition(458, 64, 67, 28);
    textAreaAnalogOut1.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textAreaAnalogOut1.setLinespacing(0);
    Unicode::snprintf(textAreaAnalogOut1Buffer, TEXTAREAANALOGOUT1_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_SLIN).getText());
    textAreaAnalogOut1.setWildcard(textAreaAnalogOut1Buffer);
    textAreaAnalogOut1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_QCVD));
    analogContainer.add(textAreaAnalogOut1);

    textAreaAnalogOut0.setPosition(458, 7, 67, 27);
    textAreaAnalogOut0.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textAreaAnalogOut0.setLinespacing(0);
    Unicode::snprintf(textAreaAnalogOut0Buffer, TEXTAREAANALOGOUT0_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_5LPZ).getText());
    textAreaAnalogOut0.setWildcard(textAreaAnalogOut0Buffer);
    textAreaAnalogOut0.setTypedText(touchgfx::TypedText(T___SINGLEUSE_K41B));
    analogContainer.add(textAreaAnalogOut0);

    add(analogContainer);

    digitalInputIndicator1.setXY(282, 295);
    add(digitalInputIndicator1);

    modalWindow_inf.setBackground(touchgfx::BitmapId(BITMAP_ALTERNATE_THEME_IMAGES_CONTAINERS_LARGE_WIDE_OUTLINED_DARK_ID), 160, 105);
    modalWindow_inf.setShadeColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    modalWindow_inf.setShadeAlpha(177);
    modalWindow_inf.hide();
    buttonWithIcon2.setXY(370, 224);
    buttonWithIcon2.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_REGULAR_HEIGHT_36_TINY_ROUNDED_NORMAL_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_REGULAR_HEIGHT_36_TINY_ROUNDED_PRESSED_ID), touchgfx::Bitmap(BITMAP_ICON_THEME_IMAGES_ACTION_DONE_50_50_E8F6FB_SVG_ID), touchgfx::Bitmap(BITMAP_ICON_THEME_IMAGES_ACTION_DONE_50_50_E8F6FB_SVG_ID));
    buttonWithIcon2.setIconXY(25, -7);
    modalWindow_inf.add(buttonWithIcon2);

    add(modalWindow_inf);

    keyboard1.setXY(93, 0);
    keyboard1.setVisible(false);
    add(keyboard1);

    button_Confirm.setXY(59, 372);
    button_Confirm.setBitmaps(touchgfx::Bitmap(BITMAP_CLAY_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_TINY_FILL_ACTION_ID), touchgfx::Bitmap(BITMAP_CLAY_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_TINY_FILL_PRESSED_ID), touchgfx::Bitmap(BITMAP_ICON_THEME_IMAGES_ACTION_DONE_50_50_E8F6FB_SVG_ID), touchgfx::Bitmap(BITMAP_ICON_THEME_IMAGES_ACTION_DONE_50_50_E8F6FB_SVG_ID));
    button_Confirm.setIconXY(39, 33);
    button_Confirm.setAction(buttonCallback);
    add(button_Confirm);

    digitalOutput1.setXY(0, 358);
    add(digitalOutput1);
}

SettingViewBase::~SettingViewBase()
{

}

void SettingViewBase::setupScreen()
{
    buttonDone1.initialize();
    digitalInputIndicator1.initialize();
    keyboard1.initialize();
    digitalOutput1.initialize();
}

void SettingViewBase::flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src)
{
    if (&src == &buttonTextFactor0)
    {
        //buttonTextFactor0
        //When buttonTextFactor0 clicked call virtual function
        //Call buttonTextFactor0ClickHandle
        buttonTextFactor0ClickHandle();
    }
    if (&src == &buttonTextFactor1)
    {
        //buttonTextFactor1
        //When buttonTextFactor1 clicked call virtual function
        //Call buttonTextFactor1ClickHandle
        buttonTextFactor1ClickHandle();
    }
    if (&src == &buttonTextFactor2)
    {
        //buttonTextFactor2
        //When buttonTextFactor2 clicked call virtual function
        //Call buttonTextFactor2ClickHandle
        buttonTextFactor2ClickHandle();
    }
    if (&src == &buttonTextFactor3)
    {
        //buttonTextFactor3
        //When buttonTextFactor3 clicked call virtual function
        //Call buttonTextFactor3ClickHandle
        buttonTextFactor3ClickHandle();
    }
    if (&src == &buttonOffset0)
    {
        //buttonTextOffset0
        //When buttonOffset0 clicked call virtual function
        //Call buttonTextOffset0ClickHandle
        buttonTextOffset0ClickHandle();
    }
    if (&src == &buttonOffset1)
    {
        //buttonTextOffset1
        //When buttonOffset1 clicked call virtual function
        //Call buttonTextOffset1ClickHandle
        buttonTextOffset1ClickHandle();
    }
    if (&src == &buttonOffset2)
    {
        //buttonTextOffset2
        //When buttonOffset2 clicked call virtual function
        //Call buttonTextOffset2ClickHandle
        buttonTextOffset2ClickHandle();
    }
    if (&src == &buttonOffset3)
    {
        //buttonTextOffset3
        //When buttonOffset3 clicked call virtual function
        //Call buttonTextOffset3ClickHandle
        buttonTextOffset3ClickHandle();
    }
}

void SettingViewBase::sliderValueChangedCallbackHandler(const touchgfx::Slider& src, int value)
{
    if (&src == &sliderAnalogOut0)
    {
        //Interaction1
        //When sliderAnalogOut0 value changed call virtual function
        //Call sliderAnalogOutHandle0
        sliderAnalogOutHandle0(value);
    }
    if (&src == &sliderAnalogOut1)
    {
        //Interaction2
        //When sliderAnalogOut1 value changed call virtual function
        //Call sliderAnalogOutHandle1
        sliderAnalogOutHandle1(value);
    }
}

void SettingViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &button_Confirm)
    {
        //button_confirm_ClickHandle
        //When button_Confirm clicked call virtual function
        //Call button_confirm_ClickHandle
        button_confirm_ClickHandle();
    }
}
