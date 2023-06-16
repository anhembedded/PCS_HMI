#include <gui/mesuaring_screen/MesuaringView.hpp>
#include <gui/mesuaring_screen/MesuaringPresenter.hpp>


MesuaringPresenter::MesuaringPresenter(MesuaringView& v)
    : view(v)
{

}

void MesuaringPresenter::activate()
{

}

void MesuaringPresenter::deactivate()
{

    
}

void MesuaringPresenter::notifyADCChanged(std::array<uint32_t, 4> arrayParameters)
{
    view.setADC(arrayParameters);
}

 void MesuaringPresenter::notifyActiveScreen()
{
    model->updateActiveScreen(view.getActiveScreen());
}
