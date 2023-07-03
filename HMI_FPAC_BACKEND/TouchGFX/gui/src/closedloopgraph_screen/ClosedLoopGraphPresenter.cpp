#include <gui/closedloopgraph_screen/ClosedLoopGraphView.hpp>
#include <gui/closedloopgraph_screen/ClosedLoopGraphPresenter.hpp>

ClosedLoopGraphPresenter::ClosedLoopGraphPresenter(ClosedLoopGraphView& v)
    : view(v)
{

}

void ClosedLoopGraphPresenter::activate()
{

}

void ClosedLoopGraphPresenter::deactivate()
{

}

pidParam_type ClosedLoopGraphPresenter::getPidParam()
{
    return model->pidParam;
}

 void ClosedLoopGraphPresenter::notifyActiveScreen()
{
    model->updateActiveScreen(view.getActiveScreen());
}

  float ClosedLoopGraphPresenter::getFeedbackDataPointFormModel()
 {
     auto analogIn = model->getAnalogIn();
     auto modelActual = model->getActualValue();
     return analogIn.getAnalogValueFloat(static_cast<uint32_t>(modelActual));
 }

  void ClosedLoopGraphPresenter::notifyADCChanged(analogIn_type analogParam)
 {
     auto analogIn = model->getAnalogIn();
     auto modelActual = model->getActualValue();
     auto pidFeedBack = analogIn.getAnalogValueFloat(static_cast<uint32_t>(modelActual));
 }

   void ClosedLoopGraphPresenter::sendFeedbackToView()
  {
    if(model->getActualValue() != actualValue_type::non)
    {
        auto feedbackValue = model->getFeedBackToPresentor();
        auto setPointFormModel = model->getPidParam().f_setPoint;
        view.addFeedbackDataPoint(feedbackValue);
        view.addSetPointDataPoint(setPointFormModel);
    }else
    {
        /* no actual be selected, so unnecessary to update feedbackValue*/
    }
      
  }

   void ClosedLoopGraphPresenter::statePidGraphRunP_entry()
   {
       model->statePidGraphRun_entry();
   }

    void ClosedLoopGraphPresenter::statePidGraphRunP_exit()
   {
       model->statePidGraphRun_exit();
   }

   void ClosedLoopGraphPresenter::notifyUpdatePidOutput(float pidOutput)
   {
       view.updatePidOutput(pidOutput);
   }
