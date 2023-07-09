#ifndef CLOSEDLOOPGRAPHVIEW_HPP
#define CLOSEDLOOPGRAPHVIEW_HPP

extern "C"
{
#include "gui/model/u_helpFunction.h"
}

#include "gui/model/u_touchGfxUtilities.hpp"
#include <gui/closedloopgraph_screen/ClosedLoopGraphPresenter.hpp>
#include <gui_generated/closedloopgraph_screen/ClosedLoopGraphViewBase.hpp>

enum class graphState_type
{
  stop,
  run,
  clear
};
class ClosedLoopGraphView : public ClosedLoopGraphViewBase
{
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
  virtual void zoomInXHandle() final
  {
    auto actualValue = presenter->getActualValue();
    if (this->zoomX >= 4)
    {
    }
    else
    {
      zoomX++;

      if (actualValue == actualValue_type::level)
      {
        setGarphLevel(zoomX, 1, graphTimeOffset);
      }
      else if (actualValue == actualValue_type::flowRate)
      {
        setGarphFlow(zoomX, 1);
      }
      else if (actualValue == actualValue_type::pressure)
      {
        setGarphPressure(zoomX, 1);
      }
    }
  }
  virtual void zoomOutXHandle() final
  {
    auto actualValue = presenter->getActualValue();
    if (this->zoomX <= 1)
    {
    }
    else
    {
      zoomX--;
      if (actualValue == actualValue_type::level)
      {
        setGarphLevel(zoomX, 1,graphTimeOffset);
      }
      else if (actualValue == actualValue_type::flowRate)
      {
        setGarphFlow(zoomX, 1);
      }
      else if (actualValue == actualValue_type::pressure)
      {
        setGarphPressure(zoomX, 1);
      }
    }
  }
    virtual void buttonForwardHandle()
    {
        auto actualValue = presenter->getActualValue();
      if (actualValue == actualValue_type::level)
      {
       graphTimeOffset += 100;
      setGarphLevel(zoomX, 1, graphTimeOffset);
      }
     
    }
    virtual void buttonBackwardHandle()
    {
        auto actualValue = presenter->getActualValue();
      if (graphTimeOffset <= 1)
        {

        }
        else
        {
            graphTimeOffset -= 100;
        }
      if (actualValue == actualValue_type::level)
      {
        setGarphLevel(zoomX, 1, graphTimeOffset);

      }
        
       
    }

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

  void updateDigitalOut(digitaOut_type digitalout)
  {
    this->digitalOutput = digitalout;
  }
  void drawTextAreaKp();
  void drawTextAreaKi();
  void drawTextAreaKd();
  struct diff_type diffVar;
  uint32_t outPutCount;
  uint32_t feedbackPutCount;
  int32_t zoomX;
  int32_t zoomY;

  void setGarphLevel(uint32_t zoomX, uint32_t zoomY, uint32_t timeOffset)
  {
     auto visibleData = graphLevelRangeXMax; //X
    auto visibleDataXZoom = (visibleData / zoomX) + timeOffset;
    auto visibleDataXZoomMin = -1.0F + timeOffset;
    auto visibleDataYZoom = graphRange::LEVEL_MAX / zoomY;

    graphBackgroud.setGraphRangeY(-1.0F, graphRange::LEVEL_MAX);
    graphFeadback.setGraphRangeY(-1.0F, graphRange::LEVEL_MAX);
    graphSetpoint.setGraphRangeY(-1.0F, graphRange::LEVEL_MAX);

    graphBackgroud.setGraphRangeX(visibleDataXZoomMin, visibleDataXZoom);
    graphFeadback.setGraphRangeX(visibleDataXZoomMin, visibleDataXZoom);
    graphSetpoint.setGraphRangeX(visibleDataXZoomMin, visibleDataXZoom);
    graphOutput.setGraphRangeX(visibleDataXZoomMin, visibleDataXZoom);

    graphBackgroudMajorXAxisGrid.setInterval(visibleDataXZoom / 40);
    graphBackgroudMajorXAxisGrid.invalidate();
    graphBackgroudMajorXAxisLabel.setInterval(visibleDataXZoom / 8);
    graphBackgroudMajorXAxisLabel.invalidate();

    graphBackgroudMajorYAxisGrid.setInterval(graphRange::LEVEL_MAX / (30.f));
    graphBackgroudMajorYAxisLabel.setInterval(graphRange::LEVEL_MAX / (10.f));
  }
  void setGarphFlow(uint32_t zoomX, uint32_t zoomY)
  {
     auto visibleData = graphFlowRangeXMax;

    auto visibleDataXZoom = visibleData / zoomX;
    auto visibleDataYZoom = graphRange::FLOW_RATE_MAX / zoomY;

    graphBackgroud.setGraphRangeY(-1.0F, graphRange::FLOW_RATE_MAX);
    graphFeadback.setGraphRangeY(-1.0F, graphRange::FLOW_RATE_MAX);
    graphSetpoint.setGraphRangeY(-1.0F, graphRange::FLOW_RATE_MAX);

    graphBackgroud.setGraphRangeX(-1.F, visibleDataXZoom);
    graphFeadback.setGraphRangeX(-1.F, visibleDataXZoom);
    graphSetpoint.setGraphRangeX(-1.F, visibleDataXZoom);
    graphOutput.setGraphRangeX(-1.F, visibleDataXZoom);

    graphBackgroudMajorXAxisGrid.setInterval(visibleDataXZoom / 40);
    graphBackgroudMajorXAxisGrid.invalidate();
    graphBackgroudMajorXAxisLabel.setInterval(visibleDataXZoom / 8);
    graphBackgroudMajorXAxisLabel.invalidate();

    graphBackgroudMajorYAxisGrid.setInterval(graphRange::FLOW_RATE_MAX / (30.f));
    graphBackgroudMajorYAxisLabel.setInterval(graphRange::FLOW_RATE_MAX / (10.f));
  }
  void setGarphPressure(uint32_t zoomX, uint32_t zoomY)
  {

     auto visibleData = graphPressureRangeXMax;
    auto visibleDataXZoom = visibleData / zoomX;
    auto visibleDataYZoom = graphRange::PRESSURE_MAX / zoomY;

    graphBackgroud.setGraphRangeY(-1.0F, graphRange::PRESSURE_MAX);
    graphFeadback.setGraphRangeY(-1.0F, graphRange::PRESSURE_MAX);
    graphSetpoint.setGraphRangeY(-1.0F, graphRange::PRESSURE_MAX);

    graphBackgroud.setGraphRangeX(-1.F, visibleDataXZoom);
    graphFeadback.setGraphRangeX(-1.F, visibleDataXZoom);
    graphSetpoint.setGraphRangeX(-1.F, visibleDataXZoom);
    graphOutput.setGraphRangeX(-1.F, visibleDataXZoom);

    graphBackgroudMajorXAxisGrid.setInterval(visibleDataXZoom / 40);
    graphBackgroudMajorXAxisGrid.invalidate();
    graphBackgroudMajorXAxisLabel.setInterval(visibleDataXZoom / 8);
    graphBackgroudMajorXAxisLabel.invalidate();

    graphBackgroudMajorYAxisGrid.setInterval(graphRange::PRESSURE_MAX / (30.f));
    graphBackgroudMajorYAxisLabel.setInterval(graphRange::PRESSURE_MAX / (10.f));
  }

  void rangeGarphLevelX(uint32_t forwardBackward, uint32_t min,uint32_t max) 
  {
    constexpr auto visibleData = 800.F;
    auto visibleDataXZoom = visibleData / zoomX;
    auto visibleDataYZoom = graphRange::LEVEL_MAX / zoomY;
  }
  float graphLevelRangeXMin;
  float graphLevelRangeXMax;

  float graphFlowRangeXMin;
  float graphFlowRangeXMax;

  float graphPressureRangeXMin;
  float graphPressureRangeXMax;

  uint32_t graphTimeOffset;
};

#endif // CLOSEDLOOPGRAPHVIEW_HPP
