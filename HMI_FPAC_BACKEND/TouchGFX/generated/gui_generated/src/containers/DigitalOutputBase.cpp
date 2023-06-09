/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/containers/DigitalOutputBase.hpp>
#include <images/BitmapDatabase.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>

DigitalOutputBase::DigitalOutputBase() :
    buttonCallback(this, &DigitalOutputBase::buttonCallbackHandler)
{
    setWidth(800);
    setHeight(121);
    binaryMenu.setXY(-86, -19);
    binaryMenu.setup(touchgfx::SlideMenu::NORTH,
        touchgfx::Bitmap(BITMAP_CLAY_THEME_IMAGES_BARS_1024X600_BOTTOM_DIM_DARK_ID),
        touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_TINY_FILL_NORMAL_ID),
        touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_TINY_FILL_ACTION_ID),
        601, 43, 730, 0);
    binaryMenu.setState(touchgfx::SlideMenu::COLLAPSED);
    binaryMenu.setVisiblePixelsWhenCollapsed(39);
    binaryMenu.setHiddenPixelsWhenExpanded(0);
    binaryMenu.setAnimationEasingEquation(touchgfx::EasingEquations::cubicEaseInOut);
    binaryMenu.setAnimationDuration(18);
    binaryMenu.setExpandedStateTimeout(0);
    boxWithBorder6.setPosition(600, 43, 288, 94);
    boxWithBorder6.setColor(touchgfx::Color::getColorFromRGB(105, 119, 144));
    boxWithBorder6.setBorderColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    boxWithBorder6.setBorderSize(5);
    binaryMenu.add(boxWithBorder6);

    binaryButton.setPosition(391, 38, 495, 126);
    image1_1.setXY(-306, 19);
    image1_1.setBitmap(touchgfx::Bitmap(BITMAP_CLAY_THEME_IMAGES_EFFECTS_800X480_SHADE_TOP_DARK_ID));
    binaryButton.add(image1_1);

    buttonDigital4.setXY(232, 19);
    buttonDigital4.setBitmaps(touchgfx::Bitmap(BITMAP_OFF_ID), touchgfx::Bitmap(BITMAP_ON_ID));
    buttonDigital4.setAction(buttonCallback);
    binaryButton.add(buttonDigital4);

    buttonDigital3.setXY(284, 19);
    buttonDigital3.setBitmaps(touchgfx::Bitmap(BITMAP_OFF_ID), touchgfx::Bitmap(BITMAP_ON_ID));
    buttonDigital3.setAction(buttonCallback);
    binaryButton.add(buttonDigital3);

    buttonDigital2.setXY(339, 19);
    buttonDigital2.setBitmaps(touchgfx::Bitmap(BITMAP_OFF_ID), touchgfx::Bitmap(BITMAP_ON_ID));
    buttonDigital2.setAction(buttonCallback);
    binaryButton.add(buttonDigital2);

    buttonDigital1.setXY(395, 19);
    buttonDigital1.setBitmaps(touchgfx::Bitmap(BITMAP_OFF_ID), touchgfx::Bitmap(BITMAP_ON_ID));
    buttonDigital1.setAction(buttonCallback);
    binaryButton.add(buttonDigital1);

    buttonDigital0.setXY(450, 19);
    buttonDigital0.setBitmaps(touchgfx::Bitmap(BITMAP_OFF_ID), touchgfx::Bitmap(BITMAP_ON_ID));
    buttonDigital0.setAction(buttonCallback);
    binaryButton.add(buttonDigital0);

    textArea4.setXY(461, 49);
    textArea4.setColor(touchgfx::Color::getColorFromRGB(34, 42, 56));
    textArea4.setLinespacing(0);
    textArea4.setTypedText(touchgfx::TypedText(T___SINGLEUSE_RPJE));
    binaryButton.add(textArea4);

    textArea4_2.setXY(350, 50);
    textArea4_2.setColor(touchgfx::Color::getColorFromRGB(34, 42, 56));
    textArea4_2.setLinespacing(0);
    textArea4_2.setTypedText(touchgfx::TypedText(T___SINGLEUSE_LHZC));
    binaryButton.add(textArea4_2);

    textArea4_2_1.setXY(295, 50);
    textArea4_2_1.setColor(touchgfx::Color::getColorFromRGB(34, 42, 56));
    textArea4_2_1.setLinespacing(0);
    textArea4_2_1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_R2I1));
    binaryButton.add(textArea4_2_1);

    textArea4_2_1_1.setXY(243, 50);
    textArea4_2_1_1.setColor(touchgfx::Color::getColorFromRGB(34, 42, 56));
    textArea4_2_1_1.setLinespacing(0);
    textArea4_2_1_1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_GT1U));
    binaryButton.add(textArea4_2_1_1);

    textArea4_1.setXY(405, 50);
    textArea4_1.setColor(touchgfx::Color::getColorFromRGB(34, 42, 56));
    textArea4_1.setLinespacing(0);
    textArea4_1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_3O2A));
    binaryButton.add(textArea4_1);

    binaryMenu.add(binaryButton);

    add(binaryMenu);
}

DigitalOutputBase::~DigitalOutputBase()
{

}

void DigitalOutputBase::initialize()
{

}

void DigitalOutputBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &buttonDigital0)
    {
        //buttonDigital0Handle
        //When buttonDigital0 clicked call virtual function
        //Call buttonDigital0Handle
        buttonDigital0Handle();
    }
    if (&src == &buttonDigital1)
    {
        //Interaction1
        //When buttonDigital1 clicked call virtual function
        //Call buttonDigital1Handle
        buttonDigital1Handle();
    }
    if (&src == &buttonDigital2)
    {
        //Interaction2
        //When buttonDigital2 clicked call virtual function
        //Call buttonDigital2Handle
        buttonDigital2Handle();
    }
    if (&src == &buttonDigital3)
    {
        //Interaction3
        //When buttonDigital3 clicked call virtual function
        //Call buttonDigital3Handle
        buttonDigital3Handle();
    }
    if (&src == &buttonDigital4)
    {
        //Interaction4
        //When buttonDigital4 clicked call virtual function
        //Call buttonDigital4Handle
        buttonDigital4Handle();
    }
}
