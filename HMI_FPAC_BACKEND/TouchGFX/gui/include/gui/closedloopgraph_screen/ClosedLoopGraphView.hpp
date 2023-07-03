#ifndef CLOSEDLOOPGRAPHVIEW_HPP
#define CLOSEDLOOPGRAPHVIEW_HPP

extern "C" {
#include "gui/model/u_helpFunction.h"
}

#include <gui/closedloopgraph_screen/ClosedLoopGraphPresenter.hpp>
#include <gui_generated/closedloopgraph_screen/ClosedLoopGraphViewBase.hpp>
#include "gui/model/u_touchGfxUtilities.hpp"
enum class graphState_type { stop, run, clear };
class ClosedLoopGraphView : public ClosedLoopGraphViewBase {
public:
  ClosedLoopGraphView();
  virtual ~ClosedLoopGraphView() {}
  virtual void setupScreen();
  virtual void tearDownScreen();

  virtual void handleTickEvent();
  virtual void afterTransition() {
    this->graphFeadback.setVisible(true);
    this->graphBackgroud.setVisible(true);
    this->graphSetpoint.setVisible(true);
    this->graphBackgroud.invalidate();
    this->graphFeadback.invalidate();
    this->graphSetpoint.invalidate();
  }

  virtual void startButton_Handle() 
  { 
    this->graphState = graphState_type::run; 
    presenter->statePidGraphRunP_entry();
  }
  virtual void stopButton_Handle() 
  { 
      this->graphState = graphState_type::stop; 
      presenter->statePidGraphRunP_exit();

  }
  virtual void clearButton_Handle() {
    this->graphState = graphState_type::clear;
    graphFeadback.clear();
    graphSetpoint.clear();
    graphOutput.clear();
    presenter->statePidGraphRunP_exit();
  }

  void notifyActiveScreen() { presenter->notifyActiveScreen(); }
  activeScreen_type getActiveScreen() const {
    return activeScreen_type::closedLoopGraphScreen;
  }
  void addFeedbackDataPoint(float dataPoint) {
    if (graphState == graphState_type::run) {
      graphFeadback.addDataPoint(dataPoint);
    } else {
      /*Do not add graph*/
    }
  }
  void addSetPointDataPoint(float setPointData) {
    if (graphState == graphState_type::run) {
      graphSetpoint.addDataPoint(setPointData);
    } else {
      /*Do not add graph*/
    }
  }
  void getFeedbackDataPoint() {
    auto dataPoint = presenter->getFeedbackDataPointFormModel();
    auto setPointFromModel = presenter->getPidParam().f_setPoint;
    graphSetpoint.addDataPoint(setPointFromModel);
    graphFeadback.addDataPoint(dataPoint);
  }
  void updatePidOutput(uint32_t pidOutput)
  {
      auto pidOut10Float = cov1024to10Float(pidOutput);
      graphOutput.addDataPoint(pidOut10Float);
      spOpFb1.drawLineProgressOutput((int)pidOutput);
      spOpFb1.drawtextAreaFeedback(pidOut10Float);
  }
protected:
private:
  void updateScreenParam();
  uint32_t viewTick;
  pidParam_type pidParam;
  float mathTick;
  graphState_type graphState;

  void drawTextAreaKp();
  void drawTextAreaKi();
  void drawTextAreaKd();
  struct diff_type diffVar;
};

#endif // CLOSEDLOOPGRAPHVIEW_HPP
