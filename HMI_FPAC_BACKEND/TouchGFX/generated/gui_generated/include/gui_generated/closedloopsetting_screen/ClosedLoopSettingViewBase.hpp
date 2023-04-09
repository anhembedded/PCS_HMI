/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef CLOSEDLOOPSETTINGVIEWBASE_HPP
#define CLOSEDLOOPSETTINGVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/closedloopsetting_screen/ClosedLoopSettingPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/ButtonWithLabel.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/widgets/BoxWithBorder.hpp>
#include <touchgfx/containers/buttons/Buttons.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/containers/ModalWindow.hpp>
#include <touchgfx/widgets/RadioButton.hpp>
#include <touchgfx/widgets/RadioButtonGroup.hpp>
#include <touchgfx/widgets/ButtonWithIcon.hpp>
#include <gui/containers/Keyboard.hpp>

class ClosedLoopSettingViewBase : public touchgfx::View<ClosedLoopSettingPresenter>
{
public:
    ClosedLoopSettingViewBase();
    virtual ~ClosedLoopSettingViewBase();
    virtual void setupScreen();

    /*
     * Virtual Action Handlers
     */
    virtual void confirmUpdateParamter()
    {
        // Override and implement this function in ClosedLoopSetting
    }
    virtual void buttonText_Kp_clickHandle()
    {
        // Override and implement this function in ClosedLoopSetting
    }
    virtual void buttonText_Ki_clickHandle()
    {
        // Override and implement this function in ClosedLoopSetting
    }
    virtual void buttonText_Kd_clickHandle()
    {
        // Override and implement this function in ClosedLoopSetting
    }
    virtual void buttonText_setPoint_clickHandle()
    {
        // Override and implement this function in ClosedLoopSetting
    }
    virtual void button_level_select_Handle()
    {
        // Override and implement this function in ClosedLoopSetting
    }
    virtual void button_flowRate_select_Handle()
    {
        // Override and implement this function in ClosedLoopSetting
    }
    virtual void button_pressure_select_Handle()
    {
        // Override and implement this function in ClosedLoopSetting
    }
    virtual void button_temperature_select_Handle()
    {
        // Override and implement this function in ClosedLoopSetting
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
    touchgfx::TextArea textArea2_1;
    touchgfx::ButtonWithLabel buttonWithLabel_Confirm;
    touchgfx::Container PidCon;
    touchgfx::BoxWithBorder boxWithBorder1;
    touchgfx::TextArea textArea1_1_1;
    touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >  buttonText_Kd;
    touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >  buttonText_setPoint;
    touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >  buttonText_Ki;
    touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >  buttonText_Kp;
    touchgfx::TextAreaWithOneWildcard text_analogVal_Kd;
    touchgfx::TextAreaWithOneWildcard text_setPoint;
    touchgfx::TextAreaWithOneWildcard text_analogVal_Ki;
    touchgfx::TextAreaWithOneWildcard text_analogVal_Kp;
    touchgfx::TextArea textArea1;
    touchgfx::TextArea textArea1_2;
    touchgfx::TextArea textArea1_1;
    touchgfx::TextArea textArea2;
    touchgfx::TextArea textArea2_2;
    touchgfx::ButtonWithLabel button_openModelWindow;
    touchgfx::ModalWindow modalWindow1;
    touchgfx::RadioButtonGroup<4> radioButtonGroup1;
    touchgfx::RadioButton button_level;
    touchgfx::RadioButton button_flowRate;
    touchgfx::RadioButton button_pressure;
    touchgfx::RadioButton button_temperature;
    touchgfx::ButtonWithIcon button_closeModelWindow;
    touchgfx::TextArea textArea3;
    touchgfx::TextArea textt;
    touchgfx::TextArea textArea3_1_1;
    touchgfx::TextArea textArea3_1_1_1;
    Keyboard keyboard1;

    /*
     * Wildcard Buffers
     */
    static const uint16_t TEXT_ANALOGVAL_KD_SIZE = 6;
    touchgfx::Unicode::UnicodeChar text_analogVal_KdBuffer[TEXT_ANALOGVAL_KD_SIZE];
    static const uint16_t TEXT_SETPOINT_SIZE = 6;
    touchgfx::Unicode::UnicodeChar text_setPointBuffer[TEXT_SETPOINT_SIZE];
    static const uint16_t TEXT_ANALOGVAL_KI_SIZE = 6;
    touchgfx::Unicode::UnicodeChar text_analogVal_KiBuffer[TEXT_ANALOGVAL_KI_SIZE];
    static const uint16_t TEXT_ANALOGVAL_KP_SIZE = 6;
    touchgfx::Unicode::UnicodeChar text_analogVal_KpBuffer[TEXT_ANALOGVAL_KP_SIZE];

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<ClosedLoopSettingViewBase, const touchgfx::AbstractButton&> buttonCallback;
    touchgfx::Callback<ClosedLoopSettingViewBase, const touchgfx::AbstractButtonContainer&> flexButtonCallback;
    touchgfx::Callback<ClosedLoopSettingViewBase, const touchgfx::AbstractButton&> radioButtonSelectedCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);
    void flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src);
    void radioButtonSelectedCallbackHandler(const touchgfx::AbstractButton& src);

};

#endif // CLOSEDLOOPSETTINGVIEWBASE_HPP
