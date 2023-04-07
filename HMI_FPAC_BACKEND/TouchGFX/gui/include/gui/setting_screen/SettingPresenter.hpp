#ifndef INCLUDE_GUI_SETTING_SCREEN_SETTINGPRESENTER
#define INCLUDE_GUI_SETTING_SCREEN_SETTINGPRESENTER

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class SettingView;

class SettingPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    SettingPresenter(SettingView &v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~SettingPresenter(){};

    virtual void notifyADCChanged(std::array<uint32_t, 4> arrayParameters);
    virtual void notifyDigitalInput(uint32_t registerVar); 
    virtual void notifyAnalogOutputChanged_0(uint32_t registerVar);
    virtual void notifyAnalogOutputChanged_1(uint32_t registerVar);

private:
    SettingPresenter();

    SettingView &view;

protected:
    uint32_t inputState;
};

#endif /* INCLUDE_GUI_SETTING_SCREEN_SETTINGPRESENTER */
