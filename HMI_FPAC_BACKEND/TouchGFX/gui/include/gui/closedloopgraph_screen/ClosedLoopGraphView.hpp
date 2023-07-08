#ifndef CLOSEDLOOPGRAPHVIEW_HPP
#define CLOSEDLOOPGRAPHVIEW_HPP

extern "C" {
#include "gui/model/u_helpFunction.h"
}

#include "gui/model/u_touchGfxUtilities.hpp"
#include <gui/closedloopgraph_screen/ClosedLoopGraphPresenter.hpp>
#include <gui_generated/closedloopgraph_screen/ClosedLoopGraphViewBase.hpp>

enum class graphState_type { stop, run, clear };
class ClosedLoopGraphView : public ClosedLoopGraphViewBase {
public:
  ClosedLoopGraphView();
  virtual ~ClosedLoopGraphView() {}
  virtual void setupScreen();
  virtual void tearDownScreen();

  virtual void handleTickEvent();
  virtual void afterTransition();
  virtual void setButtonHandle();
  virtual void startButton_Handle();
  virtual void stopButton_Handle();
  virtual void clearButton_Handle();
  virtual void buttonDoneHandle();
  virtual void buttonDigital0Handle() final;
  virtual void buttonDigital1Handle() final;
  virtual void buttonDigital2Handle() final;
  virtual void buttonDigital3Handle() final;

  void notifyActiveScreen();
  activeScreen_type getActiveScreen() const;
  void addFeedbackDataPoint(float dataPoint);
  void addSetPointDataPoint(float setPointData);
  void getFeedbackDataPoint();
  void updatePidOutput(uint32_t pidOutput);
  void setDigitalOut(digitaOut_type digiOut);
    
  void updateGraphYRange();

protected:
private:
  void updateScreenParam();
  uint32_t viewTick;
  pidParam_type pidParam;
  float mathTick;
  graphState_type graphState;
  digitaOut_type digitalOutput;

  void updateDigitalOut(digitaOut_type digitalout) {
    this->digitalOutput = digitalout;
  }
  void drawTextAreaKp();
  void drawTextAreaKi();
  void drawTextAreaKd();
  struct diff_type diffVar;
  uint32_t outPutCount;
  uint32_t feedbackPutCount;
};

#endif // CLOSEDLOOPGRAPHVIEW_HPP
