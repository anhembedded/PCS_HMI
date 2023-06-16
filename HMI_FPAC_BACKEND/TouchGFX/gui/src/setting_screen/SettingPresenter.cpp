#include <gui/setting_screen/SettingView.hpp>
#include <gui/setting_screen/SettingPresenter.hpp>

SettingPresenter::SettingPresenter(SettingView &v)
    : view(v)
{
}

void SettingPresenter::activate()
{
 
}

void SettingPresenter::deactivate()
{
}

void SettingPresenter::notifyADCChanged(std::array<uint32_t, 4> arrayParameters)
{
    view.setADC(arrayParameters);
}
void SettingPresenter::notifyDigitalInputChanged(digitalIn_type par)
{
    view.drawDigitalIn(par);
}
void SettingPresenter::notifyAnalogOutputChanged_1(uint32_t registerVar)
{
    model->sendAdcOuputToBackEnd_1(registerVar);
}

 void SettingPresenter::notifyActiveScreen()
{
    model->updateActiveScreen(activeScreen_type::settingScreen);
}


void SettingPresenter::notifyAnalogOutputChanged_0(uint32_t registerVar)
{
    model->sendAdcOuputToBackEnd_0(registerVar);
    // View action
    /* Hello add this line*/
}