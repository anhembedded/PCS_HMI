/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/information_screen/InformationViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <images/BitmapDatabase.hpp>

InformationViewBase::InformationViewBase()
{
    __background.setPosition(0, 0, 800, 480);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    boxBackground.setPosition(0, 0, 800, 480);
    boxBackground.setColor(touchgfx::Color::getColorFromRGB(214, 236, 255));
    add(boxBackground);

    buttonDone1.setXY(720, 0);
    add(buttonDone1);

    boxWithBorder1.setPosition(19, 427, 287, 51);
    boxWithBorder1.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    boxWithBorder1.setBorderColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    boxWithBorder1.setBorderSize(5);
    add(boxWithBorder1);

    textArea1.setXY(45, 435);
    textArea1.setColor(touchgfx::Color::getColorFromRGB(0, 12, 145));
    textArea1.setLinespacing(0);
    textArea1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_ASQG));
    add(textArea1);

    image1.setXY(0, 66);
    image1.setBitmap(touchgfx::Bitmap(BITMAP_SCREENSHOT_ID));
    add(image1);
}

InformationViewBase::~InformationViewBase()
{

}

void InformationViewBase::setupScreen()
{
    buttonDone1.initialize();
}