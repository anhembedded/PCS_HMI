#include <gui/closedloopsetting_screen/ClosedLoopSettingView.hpp>
#include <gui/closedloopsetting_screen/ClosedLoopSettingPresenter.hpp>

ClosedLoopSettingPresenter::ClosedLoopSettingPresenter(ClosedLoopSettingView& v)
    : view(v)
{

}

void ClosedLoopSettingPresenter::activate()
{

}

void ClosedLoopSettingPresenter::deactivate()
{

}

 void ClosedLoopSettingPresenter::setPidParam(pidParam_type pid)
{
    model->setPidParam(pid);
}

 pidParam_type ClosedLoopSettingPresenter::getPidParam()
{
    return model->getPidParam();
}

 void ClosedLoopSettingPresenter::setActualValue(actualValue_type view_actualValue)
{
    model->setActualValue(view_actualValue);
}

 actualValue_type ClosedLoopSettingPresenter::getActualValue()
{
    return model->getActualValue();
}

  void ClosedLoopSettingPresenter::notifyActiveScreen()
 {
     model->updateActiveScreen(view.getActiveScreen());
 }

