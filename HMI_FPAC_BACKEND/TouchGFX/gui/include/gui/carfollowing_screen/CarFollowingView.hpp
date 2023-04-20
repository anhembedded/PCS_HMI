#ifndef CARFOLLOWINGVIEW_HPP
#define CARFOLLOWINGVIEW_HPP

#include <gui_generated/carfollowing_screen/CarFollowingViewBase.hpp>
#include <gui/carfollowing_screen/CarFollowingPresenter.hpp>

class CarFollowingView : public CarFollowingViewBase
{
public:
    CarFollowingView();
    virtual ~CarFollowingView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // CARFOLLOWINGVIEW_HPP
