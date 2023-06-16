#include <gui/information_screen/InformationView.hpp>

InformationView::InformationView()
{

}

void InformationView::setupScreen()
{
    InformationViewBase::setupScreen();
     notifyActiveScreen();
}

void InformationView::tearDownScreen()
{
    InformationViewBase::tearDownScreen();
}
