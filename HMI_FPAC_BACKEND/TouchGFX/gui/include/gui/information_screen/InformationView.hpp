#ifndef INFORMATIONVIEW_HPP
#define INFORMATIONVIEW_HPP

#include <gui_generated/information_screen/InformationViewBase.hpp>
#include <gui/information_screen/InformationPresenter.hpp>

class InformationView : public InformationViewBase
{
public:
    InformationView();
    virtual ~InformationView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void notifyActiveScreen()
    {
        presenter->notifyActiveScreen();
    }
    activeScreen_type getActiveScreen() const
    {
        return activeScreen_type::inforScreen;
    }
protected:
};

#endif // INFORMATIONVIEW_HPP
