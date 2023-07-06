#include <gui/closedloopgraph_screen/ClosedLoopGraphView.hpp>
#include <gui/closedloopgraph_screen/ClosedLoopGraphPresenter.hpp>
#include "SEGGER_SYSVIEW_FreeRTOS.h"


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
    #ifdef SEGGER_DEBUG
    SEGGER_SYSVIEW_OnTaskStartExec(10);
    #endif // SEGGER

     auto analogIn = model->getAnalogIn();
     auto modelActual = model->getActualValue();
     return analogIn.getAnalogValueFloat(static_cast<uint32_t>(modelActual));
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

   void ClosedLoopGraphPresenter::notifyUpdatePidOutput(uint32_t pidOutput)
   {
       view.updatePidOutput(pidOutput);
   }
void ClosedLoopGraphPresenter::setDigitalOut(digitaOut_type setOutput)
    {
        model->setDigitalOut(setOutput);
    }

    digitaOut_type ClosedLoopGraphPresenter::getDigitalOutFormModel()
    {
        return model->getDigitalOut();
    }
    void ClosedLoopGraphPresenter::statePidGraph_entry()
    {
        model->statePidGraph_entry();
     }
    void ClosedLoopGraphPresenter::statePidGrap_exit()
    {
        model->statePidGraph_exit();

    }
