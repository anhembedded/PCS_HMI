#include <gui/mesuaring_screen/MesuaringView.hpp>
#include <cmath>

MesuaringView::MesuaringView()
{
}

void MesuaringView::setupScreen()
{
    MesuaringViewBase::setupScreen();
    graphBackgroud.setGraphRange(0, 600, 0, 10);
     notifyActiveScreen();
}

void MesuaringView::tearDownScreen()
{
    MesuaringViewBase::tearDownScreen();
}

void MesuaringView::handleTickEvent()
{
#ifdef SIMULATOR
    if (!static_cast<bool>(u32_dataPoint % 10))
    {
        graphOut.addDataPoint(2);
        Unicode::snprintf(textSetTimeBuffer, TEXTSETTIME_SIZE, "%d", (uint32_t)f_time);
        textSetTime.invalidate();
    }
#endif /* SIMULATOR */
}

/*
 * Virtual Action Handlers
 */

inline void MesuaringView::graphCH0Click(AbstractDataGraph::GraphClickEvent value)
{
    if (value.clickEvent.getType() == ClickEvent::PRESSED)
    {
        updateGraphInf(value.index);
    }
}

inline void MesuaringView::graphCH0Dragged(AbstractDataGraph::GraphDragEvent value)
{
    updateGraphInf(value.index);
}
void MesuaringView::setADC(const std::array<uint32_t, 4> arrayyParam)
{
    graphCH0.addDataPoint(adcRawValueToVoltage(arrayyParam[0]));
    graphCH1.addDataPoint(adcRawValueToVoltage(arrayyParam[1]));
    graphCH2.addDataPoint(adcRawValueToVoltage(arrayyParam[2]));
    graphCH3.addDataPoint(adcRawValueToVoltage(arrayyParam[3]));
}

inline void MesuaringView::buttonGraphIn0Handle()
{
    // Override and implement this function in Mesuaring
    setGraphVisible(graphCH0, butonGraphIn0);
}

inline void MesuaringView::buttonGraphIn1Handle()
{
    // Override and implement this function in Mesuaring
    setGraphVisible(graphCH1, butonGraphIn1);
}

inline void MesuaringView::buttonGraphIn2Handle()
{
    // Override and implement this function in Mesuaring
    setGraphVisible(graphCH2, butonGraphIn2);
}

inline void MesuaringView::buttonGraphIn3Handle()
{
    // Override and implement this function in Mesuaring
    setGraphVisible(graphCH3, butonGraphIn3);
}

inline void MesuaringView::buttonGraphOut0Handle()
{
    // Override and implement this function in Mesuaring
    setGraphVisible(graphOut0, butonGraphOut0);
}

inline void MesuaringView::buttonGraphOut1Handle()
{
    // Override and implement this function in Mesuaring
    setGraphVisible(graphOut1, butonGraphOut1);
}

inline void MesuaringView::buttonGraphOutHandle()
{
    // Override and implement this function in Mesuaring
    setGraphVisible(graphOut, butonGraphOut);
}

inline void MesuaringView::buttonClearGraphHandle()
{
    // Override and implement this function in Mesuaring
    graphCH0.clear();
    graphCH1.clear();
    graphCH2.clear();
    graphCH3.clear();
    graphOut0.clear();
    graphOut1.clear();
    graphOut.clear();
}



inline void MesuaringView::buttonSetTimeHandle()
{
    // Override and implement this function in Mesuaring
    keyboard1.callKeyboard(&f_time, TEXTSETTIME_SIZE);
}
void MesuaringView::graphLineMenuHandle()
{
    graphCH0.setVisible(0);
    graphCH1.setVisible(0);
    graphCH2.setVisible(0);
    graphCH3.setVisible(0);
    graphOut0.setVisible(0);
    graphOut1.setVisible(0);
    graphOut.setVisible(0);
    graphCH0.invalidate();
    graphCH1.invalidate();
    graphCH2.invalidate();
    graphCH3.invalidate();
    graphOut0.invalidate();
    graphOut1.invalidate();
    graphOut.invalidate();
}
void MesuaringView::graphLineControlPanelHandle()
{
    graphCH0.setVisible(0);
    graphCH1.setVisible(0);
    graphCH2.setVisible(0);
    graphCH3.setVisible(0);
    graphOut0.setVisible(0);
    graphOut1.setVisible(0);
    graphOut.setVisible(0);
    graphCH0.invalidate();
    graphCH1.invalidate();
    graphCH2.invalidate();
    graphCH3.invalidate();
    graphOut0.invalidate();
    graphOut1.invalidate();
    graphOut.invalidate();
}
void MesuaringView::graphLineControlPanelAEHandle()
{
    graphCH0.setVisible(1);
    graphCH1.setVisible(1);
    graphCH2.setVisible(1);
    graphCH3.setVisible(1);
    graphOut0.setVisible(1);
    graphOut1.setVisible(1);
    graphOut.setVisible(1);
    graphCH0.invalidate();
    graphCH1.invalidate();
    graphCH2.invalidate();
    graphCH3.invalidate();
    graphOut0.invalidate();
    graphOut1.invalidate();
    graphOut.invalidate();
}
void MesuaringView::sliderGraphLineAEHandle()
{
    graphCH0.setVisible(1);
    graphCH1.setVisible(1);
    graphCH2.setVisible(1);
    graphCH3.setVisible(1);
    graphOut0.setVisible(1);
    graphOut1.setVisible(1);
    graphOut.setVisible(1);

    graphCH0.invalidate();
    graphCH1.invalidate();
    graphCH2.invalidate();
    graphCH3.invalidate();
    graphOut0.invalidate();
    graphOut1.invalidate();
    graphOut.invalidate();
}

void MesuaringView::updateGraphInf(decltype(AbstractDataGraph::GraphClickEvent::index) index)
{
    graphInf1.moveTo(graphCH0.indexToScreenX(index) + graphCH0.getX() + graphCH0.getGraphAreaMarginLeft(),
                     graphCH0.indexToScreenY(index) + graphCH0.getY() + +graphCH0.getGraphAreaMarginTop());
    graphInf1.updateValue(graphCH0.indexToDataPointYAsInt(index));
}

inline void MesuaringView::setGraphVisible(decltype(graphCH0) &graphParam, const decltype(butonGraphIn0) &buttonParm)
{
    auto buttonState = buttonParm.getState();
    graphParam.setVisible(buttonState);
    graphParam.invalidate();
}

inline float MesuaringView::adcRawValueToVoltage(uint32_t adcVal) const
{
    auto vol = static_cast<float>(adcVal) / static_cast<float>(maxAdcRawVal);
    vol = vol * maxVoltage;
    return vol;
}
