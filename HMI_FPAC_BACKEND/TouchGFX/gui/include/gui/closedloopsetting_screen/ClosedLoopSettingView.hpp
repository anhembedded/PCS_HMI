#ifndef CLOSEDLOOPSETTINGVIEW_HPP
#define CLOSEDLOOPSETTINGVIEW_HPP

#include <gui_generated/closedloopsetting_screen/ClosedLoopSettingViewBase.hpp>
#include <gui/closedloopsetting_screen/ClosedLoopSettingPresenter.hpp>

class ClosedLoopSettingView : public ClosedLoopSettingViewBase
{
public:
    ClosedLoopSettingView();
    virtual ~ClosedLoopSettingView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // CLOSEDLOOPSETTINGVIEW_HPP
