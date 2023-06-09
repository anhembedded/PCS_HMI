#include <gui/closedloopgraph_screen/ClosedLoopGraphView.hpp>
#ifdef SIMULATOR

#endif //  simulator

ClosedLoopGraphView::ClosedLoopGraphView() : zoomX(1), zoomY(1){

  diff_constructor(&this->diffVar, 0, 0);
  graphLevelRangeXMin = -1.F;
  graphLevelRangeXMax = 800.F;
   graphFlowRangeXMin = -1.F;
   graphFlowRangeXMax = 300.F;
   graphPressureRangeXMin = -1.F;
   graphPressureRangeXMax = 300.F;
  graphTimeOffset  = 0;
}

void ClosedLoopGraphView::setupScreen() {
  ClosedLoopGraphViewBase::setupScreen();
  pidParam = presenter->getPidParam();
  this->drawTextAreaKp();
  this->drawTextAreaKi();
  this->drawTextAreaKd();
  spOpFb1.drawtextAreaFeedback(pidParam.f_setPoint);
  spOpFb1.drawtextAreaSetpoint(pidParam.f_setPoint);
  digitalOutput = presenter->getDigitalOutFormModel();
  updateGraphYRange();
  notifyActiveScreen();
}

void ClosedLoopGraphView::tearDownScreen() {
  ClosedLoopGraphViewBase::tearDownScreen();
}

void ClosedLoopGraphView::handleTickEvent() {
#ifdef SIMULATOR
    auto pidVar = presenter->getPidParam();
  graphFeadback.addDataPoint(pidVar.f_setPoint +100);
  graphSetpoint.addDataPoint(pidVar.f_setPoint);
#endif // SIMULATOR
}

void ClosedLoopGraphView::afterTransition() {
  this->graphFeadback.setVisible(true);
  this->graphBackgroud.setVisible(true);
  this->graphSetpoint.setVisible(true);
  this->graphBackgroud.invalidate();
  this->graphFeadback.invalidate();
  this->graphSetpoint.invalidate();
}

void ClosedLoopGraphView::setButtonHandle() {
  presenter->statePidGraphRunP_exit();
  presenter->statePidGrap_exit();
}

void ClosedLoopGraphView::startButton_Handle() {
  this->graphState = graphState_type::run;
  presenter->statePidGrap_exit();
  presenter->statePidGraphRunP_entry();
}

void ClosedLoopGraphView::stopButton_Handle() {
  this->graphState = graphState_type::stop;
  presenter->statePidGraphRunP_exit();
  presenter->statePidGraph_entry();
}

void ClosedLoopGraphView::clearButton_Handle() {
  this->graphState = graphState_type::clear;
  graphFeadback.clear();
  graphSetpoint.clear();
  graphOutput.clear();
  presenter->statePidGraphRunP_exit();
  presenter->statePidGraph_entry();
}

void ClosedLoopGraphView::buttonDoneHandle() {
  this->graphState = graphState_type::clear;
  graphFeadback.clear();
  graphSetpoint.clear();
  graphOutput.clear();
  presenter->statePidGraphRunP_exit();
}

void ClosedLoopGraphView::buttonDigital0Handle() {
  if (buttonDigital0.getState() == ClickEvent::RELEASED) {
    digitalOutput.u8_digiOut.at(0) = 1U;
  } else {
    digitalOutput.u8_digiOut.at(0) = 0U;
  }
  setDigitalOut(this->digitalOutput);
}

void ClosedLoopGraphView::buttonDigital1Handle() {
  if (buttonDigital1.getState() == ClickEvent::RELEASED) {
    digitalOutput.u8_digiOut.at(1) = 1U;
    digitalOutput.u8_digiOut.at(2) = 0U;
    buttonDigital2.forceState(ClickEvent::PRESSED);
    buttonDigital2.invalidate();
  } else {
    digitalOutput.u8_digiOut.at(1) = 0U;
  }
  setDigitalOut(this->digitalOutput);
}

void ClosedLoopGraphView::buttonDigital2Handle() {
  if (buttonDigital2.getState() == ClickEvent::RELEASED) {
    digitalOutput.u8_digiOut.at(2) = 1U;
    digitalOutput.u8_digiOut.at(1) = 0U;
    buttonDigital1.forceState(ClickEvent::PRESSED);
    buttonDigital1.invalidate();
  } else {
    digitalOutput.u8_digiOut.at(2) = 0U;
  }
  setDigitalOut(this->digitalOutput);
}

void ClosedLoopGraphView::buttonDigital3Handle() {
  if (buttonDigital3.getState() == ClickEvent::RELEASED) {
    digitalOutput.u8_digiOut.at(3) = 1U;
  } else {
    digitalOutput.u8_digiOut.at(3) = 0U;
  }
  setDigitalOut(this->digitalOutput);
}

void ClosedLoopGraphView::notifyActiveScreen() {
  presenter->notifyActiveScreen();
}

activeScreen_type ClosedLoopGraphView::getActiveScreen() const {
  return activeScreen_type::closedLoopGraphScreen;
}

void ClosedLoopGraphView::addFeedbackDataPoint(float dataPoint) {
  if (graphState == graphState_type::run) {
    graphFeadback.addDataPoint(dataPoint);
    feedbackPutCount ++;
    spOpFb1.drawtextAreaFeedback(dataPoint);
  } else {
    /*Do not add graph*/
  }
}

void ClosedLoopGraphView::addSetPointDataPoint(float setPointData) {
  if (graphState == graphState_type::run) {
    graphSetpoint.addDataPoint(setPointData);
  } else {
    /*Do not add graph*/
  }
}

void ClosedLoopGraphView::getFeedbackDataPoint() {
  auto dataPoint = presenter->getFeedbackDataPointFormModel();
  auto setPointFromModel = presenter->getPidParam().f_setPoint;
  graphSetpoint.addDataPoint(setPointFromModel);
}

void ClosedLoopGraphView::updatePidOutput(uint32_t pidOutput) {
  auto pidOut10Float = cov1024to10Float(pidOutput);
  graphOutput.addDataPoint(pidOut10Float);
  outPutCount++;
  spOpFb1.drawLineProgressOutput((int)pidOutput);
}

void ClosedLoopGraphView::updateScreenParam() {}

void ClosedLoopGraphView::drawTextAreaKp() {
  Unicode::snprintfFloat(text_analogVal_KpBuffer, TEXT_ANALOGVAL_KP_SIZE,
                         "%2.2f", static_cast<float>(this->pidParam.f_kp));
  text_analogVal_Kp.invalidate();
}

void ClosedLoopGraphView::drawTextAreaKi() {

  Unicode::snprintfFloat(text_analogVal_KiBuffer, TEXT_ANALOGVAL_KI_SIZE,
                         "%2.2f", static_cast<float>(this->pidParam.f_ki));
  text_analogVal_Ki.invalidate();
}

void ClosedLoopGraphView::drawTextAreaKd() {
  Unicode::snprintfFloat(text_analogVal_KdBuffer, TEXT_ANALOGVAL_KD_SIZE,
                         "%2.2f", static_cast<float>(this->pidParam.f_kd));
  text_analogVal_Kd.invalidate();
}

void ClosedLoopGraphView::setDigitalOut(digitaOut_type digiOut) {
  presenter->setDigitalOut(digiOut);
}

 void ClosedLoopGraphView::updateGraphYRange()
{
    auto actualValue = presenter->getActualValue();
    if (actualValue == actualValue_type::level)
    {
      setGarphLevel(1,1,graphTimeOffset);
    }
    else if(actualValue == actualValue_type::flowRate)
    {
        setGarphFlow(1,1);
    }
    else if (actualValue == actualValue_type::pressure)
    {
        setGarphPressure(1,1);
    }
}

