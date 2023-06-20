/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef SETTINGVIEWBASE_HPP
#define SETTINGVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/setting_screen/SettingPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/ButtonWithIcon.hpp>
#include <gui/containers/ButtonDone.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/widgets/BoxWithBorder.hpp>
#include <touchgfx/containers/buttons/Buttons.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/containers/Slider.hpp>
#include <gui/containers/DigitalInputIndicator.hpp>
#include <touchgfx/containers/ModalWindow.hpp>
#include <touchgfx/containers/SlideMenu.hpp>
#include <touchgfx/widgets/ToggleButton.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <gui/containers/Keyboard.hpp>
#include <touchgfx/mixins/Draggable.hpp>

class SettingViewBase : public touchgfx::View<SettingPresenter>
{
public:
    SettingViewBase();
    virtual ~SettingViewBase();
    virtual void setupScreen();

    /*
     * Custom Actions
     */
    virtual void action1()
    {
        // Override and implement this function in Screen1
    }
    

    /*
     * Virtual Action Handlers
     */
    virtual void buttonTextFactor0ClickHandle()
    {
        // Override and implement this function in Setting
    }
    virtual void buttonTextFactor1ClickHandle()
    {
        // Override and implement this function in Setting
    }
    virtual void buttonTextFactor2ClickHandle()
    {
        // Override and implement this function in Setting
    }
    virtual void buttonTextFactor3ClickHandle()
    {
        // Override and implement this function in Setting
    }
    virtual void buttonTextOffset0ClickHandle()
    {
        // Override and implement this function in Setting
    }
    virtual void buttonTextOffset1ClickHandle()
    {
        // Override and implement this function in Setting
    }
    virtual void buttonTextOffset2ClickHandle()
    {
        // Override and implement this function in Setting
    }
    virtual void buttonTextOffset3ClickHandle()
    {
        // Override and implement this function in Setting
    }
    virtual void sliderAnalogOutHandle0(int value)
    {
        // Override and implement this function in Setting
    }
    virtual void sliderAnalogOutHandle1(int value)
    {
        // Override and implement this function in Setting
    }
    virtual void button_confirm_ClickHandle()
    {
        // Override and implement this function in Setting
    }
    virtual void buttonDigital0Handle()
    {
        // Override and implement this function in Setting
    }
    virtual void buttonDigital1Handle()
    {
        // Override and implement this function in Setting
    }
    virtual void buttonDigital2Handle()
    {
        // Override and implement this function in Setting
    }
    virtual void buttonDigital3Handle()
    {
        // Override and implement this function in Setting
    }
    virtual void buttonDigital4Handle()
    {
        // Override and implement this function in Setting
    }

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::Box Background;
    touchgfx::ButtonWithIcon buttonWithIcon1;
    ButtonDone buttonDone1;
    touchgfx::Container containerParameter;
    touchgfx::BoxWithBorder boxWithBorder3;
    touchgfx::BoxWithBorder boxWithBorder1_1;
    touchgfx::BoxWithBorder boxWithBorder1_1_1;
    touchgfx::BoxWithBorder boxWithBorder1_1_2;
    touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >  buttonTextFactor0;
    touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >  buttonTextFactor1;
    touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >  buttonOffset0;
    touchgfx::TextAreaWithOneWildcard textAreaFactor0;
    touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >  buttonOffset1;
    touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >  buttonOffset2;
    touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >  buttonOffset3;
    touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >  buttonTextFactor2;
    touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >  buttonTextFactor3;
    touchgfx::TextAreaWithOneWildcard textAreaFactor1;
    touchgfx::TextAreaWithOneWildcard textAreaOffset0;
    touchgfx::TextAreaWithOneWildcard textAreaOffset1;
    touchgfx::TextAreaWithOneWildcard textAreaOffset2;
    touchgfx::TextAreaWithOneWildcard textAreaOffset3;
    touchgfx::TextAreaWithOneWildcard textAreaFactor2;
    touchgfx::TextAreaWithOneWildcard textAreaFactor3;
    touchgfx::BoxWithBorder boxWithBorder1;
    touchgfx::TextAreaWithOneWildcard textProcessVar0;
    touchgfx::TextAreaWithOneWildcard textProcessVar1;
    touchgfx::TextAreaWithOneWildcard textProcessVar2;
    touchgfx::TextAreaWithOneWildcard textProcessVar3;
    touchgfx::TextAreaWithOneWildcard textAreaCH0;
    touchgfx::TextAreaWithOneWildcard textAreaCH1;
    touchgfx::TextAreaWithOneWildcard textAreaCH2;
    touchgfx::TextAreaWithOneWildcard textAreaCH3;
    touchgfx::TextArea textArea3_2_1;
    touchgfx::TextArea textArea3_2;
    touchgfx::TextArea textArea3_1;
    touchgfx::TextArea textArea3;
    touchgfx::Container analogContainer;
    touchgfx::Slider sliderAnalogOut0;
    touchgfx::Slider sliderAnalogOut1;
    touchgfx::TextAreaWithOneWildcard textAreaAnalogOut1;
    touchgfx::TextAreaWithOneWildcard textAreaAnalogOut0;
    DigitalInputIndicator digitalInputIndicator1;
    touchgfx::ModalWindow modalWindow_inf;
    touchgfx::ButtonWithIcon buttonWithIcon2;
    touchgfx::ButtonWithIcon button_Confirm;
    touchgfx::SlideMenu binaryMenu;
    touchgfx::Container binaryButton;
    touchgfx::ToggleButton buttonDigital4;
    touchgfx::ToggleButton buttonDigital3;
    touchgfx::ToggleButton buttonDigital2;
    touchgfx::ToggleButton buttonDigital1;
    touchgfx::ToggleButton buttonDigital0;
    touchgfx::TextArea textArea4;
    touchgfx::TextArea textArea4_2;
    touchgfx::TextArea textArea4_2_1;
    touchgfx::TextArea textArea4_2_1_1;
    touchgfx::TextArea textArea4_1;
    touchgfx::Image image1_1;
    touchgfx::Draggable< Keyboard > keyboard1;

    /*
     * Wildcard Buffers
     */
    static const uint16_t TEXTAREAFACTOR0_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textAreaFactor0Buffer[TEXTAREAFACTOR0_SIZE];
    static const uint16_t TEXTAREAFACTOR1_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textAreaFactor1Buffer[TEXTAREAFACTOR1_SIZE];
    static const uint16_t TEXTAREAOFFSET0_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textAreaOffset0Buffer[TEXTAREAOFFSET0_SIZE];
    static const uint16_t TEXTAREAOFFSET1_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textAreaOffset1Buffer[TEXTAREAOFFSET1_SIZE];
    static const uint16_t TEXTAREAOFFSET2_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textAreaOffset2Buffer[TEXTAREAOFFSET2_SIZE];
    static const uint16_t TEXTAREAOFFSET3_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textAreaOffset3Buffer[TEXTAREAOFFSET3_SIZE];
    static const uint16_t TEXTAREAFACTOR2_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textAreaFactor2Buffer[TEXTAREAFACTOR2_SIZE];
    static const uint16_t TEXTAREAFACTOR3_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textAreaFactor3Buffer[TEXTAREAFACTOR3_SIZE];
    static const uint16_t TEXTPROCESSVAR0_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textProcessVar0Buffer[TEXTPROCESSVAR0_SIZE];
    static const uint16_t TEXTPROCESSVAR1_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textProcessVar1Buffer[TEXTPROCESSVAR1_SIZE];
    static const uint16_t TEXTPROCESSVAR2_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textProcessVar2Buffer[TEXTPROCESSVAR2_SIZE];
    static const uint16_t TEXTPROCESSVAR3_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textProcessVar3Buffer[TEXTPROCESSVAR3_SIZE];
    static const uint16_t TEXTAREACH0_SIZE = 5;
    touchgfx::Unicode::UnicodeChar textAreaCH0Buffer[TEXTAREACH0_SIZE];
    static const uint16_t TEXTAREACH1_SIZE = 5;
    touchgfx::Unicode::UnicodeChar textAreaCH1Buffer[TEXTAREACH1_SIZE];
    static const uint16_t TEXTAREACH2_SIZE = 5;
    touchgfx::Unicode::UnicodeChar textAreaCH2Buffer[TEXTAREACH2_SIZE];
    static const uint16_t TEXTAREACH3_SIZE = 5;
    touchgfx::Unicode::UnicodeChar textAreaCH3Buffer[TEXTAREACH3_SIZE];
    static const uint16_t TEXTAREAANALOGOUT1_SIZE = 4;
    touchgfx::Unicode::UnicodeChar textAreaAnalogOut1Buffer[TEXTAREAANALOGOUT1_SIZE];
    static const uint16_t TEXTAREAANALOGOUT0_SIZE = 4;
    touchgfx::Unicode::UnicodeChar textAreaAnalogOut0Buffer[TEXTAREAANALOGOUT0_SIZE];

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<SettingViewBase, const touchgfx::AbstractButtonContainer&> flexButtonCallback;
    touchgfx::Callback<SettingViewBase, const touchgfx::Slider&, int> sliderValueChangedCallback;
    touchgfx::Callback<SettingViewBase, const touchgfx::AbstractButton&> buttonCallback;

    /*
     * Callback Handler Declarations
     */
    void flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src);
    void sliderValueChangedCallbackHandler(const touchgfx::Slider& src, int value);
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);

};

#endif // SETTINGVIEWBASE_HPP
