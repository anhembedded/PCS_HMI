#ifndef INCLUDE_GUI_MAIN_SCREEN_MAINVIEW
#define INCLUDE_GUI_MAIN_SCREEN_MAINVIEW

#include <gui_generated/main_screen/MainViewBase.hpp>
#include <gui/main_screen/MainPresenter.hpp>

class MainView : public MainViewBase
{
public:
    MainView();
    virtual ~MainView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

       void notifyActiveScreen()
    {
        presenter->notifyActiveScreen();
    }
     virtual void buttonSettingHandle()
    {
       presenter->sendSystemStateToModel(eSETTING_VAR);
    }
    virtual void buttonClosedLoop()
    {
        // Override and implement this function in Main
    }
protected:
};

#endif /* INCLUDE_GUI_MAIN_SCREEN_MAINVIEW */
