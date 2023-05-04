#ifndef INCLUDE_GUI_DEV_SCREEN_DEVVIEW
#define INCLUDE_GUI_DEV_SCREEN_DEVVIEW

extern "C"
{
#include "gui/model/u_helpFunction.h"
}

#include <gui_generated/dev_screen/DevViewBase.hpp>
#include <gui/dev_screen/DevPresenter.hpp>

enum class whichFunction_type
{
    stop = 0,
    run,
    sine,
    increase,
    accelerated
};

class DevView : public DevViewBase
{
public:
    DevView();
    virtual ~DevView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void handleTickEvent() override;

    virtual void radioSineFuntionHandle()
    {
        this->whichFunction = whichFunction_type::sine;
        reinitFunction();
    }
    virtual void radioIncrieaseFuntionHandle()
    {
        this->whichFunction = whichFunction_type::increase;
        reinitFunction();
    }
    virtual void radioAcceleratedFuntionHandle()
    {
        this->whichFunction = whichFunction_type::accelerated;
        reinitFunction();
    }
    virtual void buttonOnOffHandle()
    {
        if (buttonOnOff.getState())
        {
            this->isRun = whichFunction_type::run;
        }
        else
        {
            this->isRun = whichFunction_type::stop;
        }
    }

protected:
private:
    float mathTick;
    struct diff_type diffVar;
    struct diff_type diffVar2;
    whichFunction_type whichFunction;
    whichFunction_type isRun;
    void reinitFunction()
    {
        mathTick = 0;
        diff_constructor(&this->diffVar, 0.F, 0.F);
        diff_constructor(&this->diffVar2, 0.F, 0.F);
    }
};

#endif /* INCLUDE_GUI_DEV_SCREEN_DEVVIEW */
