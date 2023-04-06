#ifndef INCLUDE_GUI_MESUARING_SCREEN_MESUARINGVIEW
#define INCLUDE_GUI_MESUARING_SCREEN_MESUARINGVIEW

#include <gui_generated/mesuaring_screen/MesuaringViewBase.hpp>
#include <gui/mesuaring_screen/MesuaringPresenter.hpp>
#include <array>

class MesuaringView : public MesuaringViewBase
{
public:
    MesuaringView();
    virtual ~MesuaringView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void handleTickEvent() override;
    /*
     * Virtual Action Handlers
     */
    virtual void graphCH0Click(AbstractDataGraph::GraphClickEvent value);
    virtual void graphCH0Dragged(AbstractDataGraph::GraphDragEvent value);

    void setADC(std::array<uint32_t, 4> arrayyParam);

    virtual void buttonGraphIn0Handle();
    virtual void buttonGraphIn1Handle();
    virtual void buttonGraphIn2Handle();
    virtual void buttonGraphIn3Handle();
    virtual void buttonGraphOut0Handle();
    virtual void buttonGraphOut1Handle();
    virtual void buttonGraphOutHandle();
    virtual void buttonClearGraphHandle();

    
    virtual void buttonSetTimeHandle();
    virtual void graphLineMenuHandle();
    virtual void graphLineControlPanelHandle();
    virtual void graphLineControlPanelAEHandle();
    virtual void sliderGraphLineAEHandle();


protected:
    void updateGraphInf(decltype(AbstractDataGraph::GraphClickEvent::index) var);
    uint32_t u32_dataPoint;
    float f_time;

private:
    const uint32_t maxAdcRawVal = 1024;
    const float maxVoltage = 10.0F;
    void setGraphVisible(decltype(graphCH0) &graphParam, const decltype(butonGraphIn0) &buttonParm);
    float adcRawValueToVoltage(uint32_t adcVal) const;
};

#endif /* INCLUDE_GUI_MESUARING_SCREEN_MESUARINGVIEW */
