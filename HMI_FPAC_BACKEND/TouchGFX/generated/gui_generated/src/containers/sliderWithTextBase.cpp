/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/containers/sliderWithTextBase.hpp>
#include <touchgfx/Color.hpp>
#include <images/BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>

sliderWithTextBase::sliderWithTextBase() :
    sliderValueChangedCallback(this, &sliderWithTextBase::sliderValueChangedCallbackHandler),
    sliderValueConfirmedCallback(this, &sliderWithTextBase::sliderValueConfirmedCallbackHandler)
{
    setWidth(534);
    setHeight(41);
    buttonText.setBoxWithBorderPosition(0, 0, 102, 32);
    buttonText.setBorderSize(5);
    buttonText.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(87, 119, 243), touchgfx::Color::getColorFromRGB(51, 102, 153));
    buttonText.setPosition(432, 4, 102, 32);
    add(buttonText);

    slider_analog.setXY(0, 4);
    slider_analog.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_SLIDER_HORIZONTAL_THICK_TRACK_LARGE_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_SLIDER_HORIZONTAL_THICK_FILLER_LARGE_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_SLIDER_HORIZONTAL_THICK_ROUNDED_LIGHT_ID));
    slider_analog.setupHorizontalSlider(16, 11, 0, 0, 400);
    slider_analog.setValueRange(0, 1023);
    slider_analog.setValue(0);
    slider_analog.setNewValueCallback(sliderValueChangedCallback);
    slider_analog.setStopValueCallback(sliderValueConfirmedCallback);
    add(slider_analog);

    text_analogVal.setXY(457, 5);
    text_analogVal.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    text_analogVal.setLinespacing(0);
    Unicode::snprintf(text_analogValBuffer, TEXT_ANALOGVAL_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_IWZ6).getText());
    text_analogVal.setWildcard(text_analogValBuffer);
    text_analogVal.resizeToCurrentText();
    text_analogVal.setTypedText(touchgfx::TypedText(T___SINGLEUSE_L00Q));
    add(text_analogVal);
}

sliderWithTextBase::~sliderWithTextBase()
{

}

void sliderWithTextBase::initialize()
{

}

void sliderWithTextBase::sliderValueChangedCallbackHandler(const touchgfx::Slider& src, int value)
{
    if (&src == &slider_analog)
    {
        //slider_analog_valueChangeHandle
        //When slider_analog value changed call virtual function
        //Call slider_analog_valueChangeHandle
        slider_analog_valueChangeHandle(value);
    }
}

void sliderWithTextBase::sliderValueConfirmedCallbackHandler(const touchgfx::Slider& src, int value)
{
    if (&src == &slider_analog)
    {
        //slider_analog_valueConfirmHandle
        //When slider_analog value confirmed call virtual function
        //Call slider_analog_valueConfirmHandle
        slider_analog_valueConfirmHandle(value);
    }
}