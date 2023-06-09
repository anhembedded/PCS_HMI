/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef SLIDERWITHTEXTBASE_HPP
#define SLIDERWITHTEXTBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/containers/buttons/Buttons.hpp>
#include <touchgfx/containers/Slider.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>

class sliderWithTextBase : public touchgfx::Container
{
public:
    sliderWithTextBase();
    virtual ~sliderWithTextBase();
    virtual void initialize();

    /*
     * Virtual Action Handlers
     */
    virtual void slider_analog_valueChangeHandle(int value)
    {
        // Override and implement this function in sliderWithText
    }
    virtual void slider_analog_valueConfirmHandle(int value)
    {
        // Override and implement this function in sliderWithText
    }

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >  buttonText;
    touchgfx::Slider slider_analog;
    touchgfx::TextAreaWithOneWildcard text_analogVal;

    /*
     * Wildcard Buffers
     */
    static const uint16_t TEXT_ANALOGVAL_SIZE = 6;
    touchgfx::Unicode::UnicodeChar text_analogValBuffer[TEXT_ANALOGVAL_SIZE];

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<sliderWithTextBase, const touchgfx::Slider&, int> sliderValueChangedCallback;
    touchgfx::Callback<sliderWithTextBase, const touchgfx::Slider&, int> sliderValueConfirmedCallback;

    /*
     * Callback Handler Declarations
     */
    void sliderValueChangedCallbackHandler(const touchgfx::Slider& src, int value);
    void sliderValueConfirmedCallbackHandler(const touchgfx::Slider& src, int value);

};

#endif // SLIDERWITHTEXTBASE_HPP
