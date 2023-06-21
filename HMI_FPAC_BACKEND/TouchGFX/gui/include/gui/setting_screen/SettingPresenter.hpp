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

    virtual void notifyADCChanged(analogIn_type analogInParam);
    virtual void notifyDigitalInputChanged(digitalIn_type par);
    virtual void notifyAnalogOutputChanged_0(uint32_t registerVar);
    virtual void notifyAnalogOutputChanged_1(uint32_t registerVar);

   
    void notifyActiveScreen();
    void setSettingVar(settingVar_type setVar)
    {
        model->setSettingVar(setVar);
    }
    settingVar_type getSettingVar()
    {
        return model->getSettingVar();
    }
    analogIn_type getAnalogIn()
    {
        return model->getAnalogIn();
    }

    digitaOut_type getDigitalOut()
    {
        return model->getDigitalOut();
    }
    digitalIn_type getDigitalIn()
    {
        return model->getDigitalIn();
    }

    void setDigitalOut(digitaOut_type setOutput)
    {
        model->setDigitalOut(setOutput);
    }
    void setDigitalIn(digitalIn_type setInput)
    {
        model->setDigitalIn(setInput);
    }

private:
    SettingPresenter();

    SettingView &view;

protected:
    uint32_t inputState;
};

#endif /* INCLUDE_GUI_SETTING_SCREEN_SETTINGPRESENTER */
