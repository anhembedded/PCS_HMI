#include <gui/closedloopsetting_screen/ClosedLoopSettingView.hpp>

ClosedLoopSettingView::ClosedLoopSettingView()
{
   
}

void ClosedLoopSettingView::setupScreen()
{
    ClosedLoopSettingViewBase::setupScreen();
    this->pidParam = presenter->getPidParam();
    this->drawTextAreaKp();
    this->drawTextAreaKi();
    this->drawTextAreaKd();
    this->drawTextAreaSetPoint();
    this->updateActualValue();
    notifyActiveScreen();
}

void ClosedLoopSettingView::tearDownScreen()
{
    ClosedLoopSettingViewBase::tearDownScreen();
}

void ClosedLoopSettingView::handleTickEvent()
{
    this->u32_tick++;

    this->textFrequencyUpdate();
}

 void ClosedLoopSettingView::buttonText_Kp_clickHandle()
{
    keyboard1.callKeyboard(&pidParam.f_kp, TEXT_ANALOGVAL_KP_SIZE);
}

  void ClosedLoopSettingView::buttonText_Ki_clickHandle()
 {
     keyboard1.callKeyboard(&pidParam.f_ki, TEXT_ANALOGVAL_KI_SIZE);
 }

  void ClosedLoopSettingView::buttonText_Kd_clickHandle()
 {
     keyboard1.callKeyboard(&pidParam.f_kd, TEXT_ANALOGVAL_KD_SIZE);
 }

  void ClosedLoopSettingView::buttonText_setPoint_clickHandle()
 {
     keyboard1.callKeyboard(&pidParam.f_setPoint, TEXT_SETPOINT_SIZE);
 }

  void ClosedLoopSettingView::confirmUpdateParamter()
 {
     pidParamCheckRange();
     presenter->setPidParam(pidParam);
     presenter->setActualValue(this->actualValue);
     presenter->notifyActualValueChanged(this->actualValue);
     //presenter->statePidGraph_entry();

 }

  void ClosedLoopSettingView::button_level_select_Handle()
 {

     this->actualValue = actualValue_type::level;

 }

  void ClosedLoopSettingView::button_flowRate_select_Handle()
 {
     this->actualValue = actualValue_type::flowRate;

 }

  void ClosedLoopSettingView::button_pressure_select_Handle()
 {
     this->actualValue = actualValue_type::pressure;

 }

  void ClosedLoopSettingView::button_temperature_select_Handle()
 {
     this->actualValue = actualValue_type::temperature;

 }

  void ClosedLoopSettingView::openModelButton()
 {
     this->updateActualValue();
     if (actualValue == actualValue_type::level)
     {
         radioButtonGroup1.setSelected(button_level);
     }
     else if (actualValue == actualValue_type::flowRate)
     {
         radioButtonGroup1.setSelected(button_flowRate);
     }
     else if (actualValue == actualValue_type::pressure)
     {
         radioButtonGroup1.setSelected(button_pressure);
     }
     else if (actualValue == actualValue_type::temperature)
     {
         radioButtonGroup1.setSelected(button_temperature);
     }
 }

  void ClosedLoopSettingView::updateActualValue()
 {
     this->actualValue = presenter->getActualValueFromModel();
 }

 void ClosedLoopSettingView::drawTextAreaKp()
{
    Unicode::snprintfFloat(text_analogVal_KpBuffer, TEXT_ANALOGVAL_KP_SIZE, "%5.6f", static_cast<float>(this->pidParam.f_kp));
    text_analogVal_Kp.invalidate();
}
void ClosedLoopSettingView::drawTextAreaKi()
{
    Unicode::snprintfFloat(text_analogVal_KiBuffer, TEXT_ANALOGVAL_KI_SIZE, "%5.6f", static_cast<float>(this->pidParam.f_ki));
    text_analogVal_Ki.invalidate();
}
void ClosedLoopSettingView::drawTextAreaKd()
{
    Unicode::snprintfFloat(text_analogVal_KdBuffer, TEXT_ANALOGVAL_KD_SIZE, "%5.6f", static_cast<float>(this-> pidParam.f_kd));
    text_analogVal_Kd.invalidate();
}

void ClosedLoopSettingView::drawTextAreaSetPoint()
{
    Unicode::snprintfFloat(text_setPointBuffer, TEXT_SETPOINT_SIZE, "%3.2f", static_cast<float>(this->pidParam.f_setPoint));
    text_setPoint.invalidate();

}

 void ClosedLoopSettingView::notifyActiveScreen()
{
    presenter->notifyActiveScreen();
}

 activeScreen_type ClosedLoopSettingView::getActiveScreen() const
{
    return activeScreen_type::closedLoopSettingScreen;
}

 void ClosedLoopSettingView::notifyActualValueChanged()
{
    presenter->notifyActualValueChanged(actualValue);
}

 void ClosedLoopSettingView::pidParamCheckRange()
{

    pidParam.f_kp = constraint(pidParam.f_kp, pidRange::KP_MIN, pidRange::KP_MAX);
    pidParam.f_ki = constraint(pidParam.f_ki, pidRange::KI_MIN, pidRange::KI_MAX);
    pidParam.f_kd = constraint(pidParam.f_kd, pidRange::KD_MIN, pidRange::KD_MAX);

}

 void ClosedLoopSettingView::updatePidOutput(float pidOutput)
{
    auto pidOut10Float = cov1024to10Float((uint32_t)pidOutput);

}

void ClosedLoopSettingView::textFrequencyUpdate()
{
    if (this->u32_tick % 50)
    {
        this->pidParamCheckRange();
        this->drawTextAreaKp();
        this->drawTextAreaKi();
        this->drawTextAreaKd();
        this->drawTextAreaSetPoint();
     }
}

 float ClosedLoopSettingView::constraint(float number, float min, float max)
{
    if (number < min)
    {
        number = min;
    }
    else if (number > max)
    {
        number = max;
    }
    else
    {
        // do not thing
    }
    return (number);
}
