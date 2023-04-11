#include <gui/setting_screen/SettingView.hpp>
#include <touchgfx/Color.hpp>

SettingView::SettingView() : f_channelFactor0(1.),
                             f_channelFactor1(1.),
                             f_channelFactor2(1.),
                             f_channelFactor3(1.),
                             f_channelOffset0(0.),
                             f_channelOffset1(0.),
                             f_channelOffset2(0.),
                             f_channelOffset3(0.),
                             f_channelProcessVariable0(0.),
                             f_channelProcessVariable1(0.),
                             f_channelProcessVariable2(0.),
                             f_channelProcessVariable3(0.),
                             f_analogChannel0(0.f),
                             f_analogChannel1(0.f),
                             f_analogChannel2(0.f),
                             f_analogChannel3(0.f),
                             u32_channelAnalogOut0(0u),
                             u32_channelAnalogOut1(0u)
{
}

void SettingView::setupScreen()
{
    SettingViewBase::setupScreen();
    settingVar = presenter->getSettingVar();
}

void SettingView::tearDownScreen()
{
    SettingViewBase::tearDownScreen();
}

void SettingView::handleTickEvent()
{

#ifdef SIMULATOR

    this->analogIn = getAnalogIn();
    drawTextAdcIn0(analogIn.getAnalogValueFloat(0));
    drawTextAdcIn1(analogIn.getAnalogValueFloat(1));
    drawTextAdcIn2(analogIn.getAnalogValueFloat(2));
    drawTextAdcIn3(analogIn.getAnalogValueFloat(3));

    drawTextProcessVar0();
    drawTextProcessVar1();
    drawTextProcessVar2();
    drawTextProcessVar3();

    drawTextAreaFactor0();
    drawTextAreaFactor1();
    drawTextAreaFactor2();
    drawTextAreaFactor3();

    drawTextAreaOffset0();
    drawTextAreaOffset1();
    drawTextAreaOffset2();
    drawTextAreaOffset3();

#endif // ! SIMULATOR
}

inline void SettingView::buttonTextFactor0ClickHandle()
{

    keyboard1.callKeyboard(&settingVar.f_factor[0], TEXTAREAFACTOR0_SIZE);
}

inline void SettingView::buttonTextFactor1ClickHandle()
{
    keyboard1.callKeyboard(&settingVar.f_factor[1], TEXTAREAFACTOR1_SIZE);
}

inline void SettingView::buttonTextFactor2ClickHandle()
{
    keyboard1.callKeyboard(&settingVar.f_factor[2], TEXTAREAFACTOR2_SIZE);
}

inline void SettingView::buttonTextFactor3ClickHandle()
{
    keyboard1.callKeyboard(&settingVar.f_factor[3], TEXTAREAFACTOR3_SIZE);
}

inline void SettingView::buttonTextOffset0ClickHandle()
{
    keyboard1.callKeyboard(&settingVar.f_offset[0], TEXTAREAOFFSET0_SIZE);
}

inline void SettingView::buttonTextOffset1ClickHandle()
{
    keyboard1.callKeyboard(&settingVar.f_offset[1], TEXTAREAOFFSET1_SIZE);
}

inline void SettingView::buttonTextOffset2ClickHandle()
{
    keyboard1.callKeyboard(&settingVar.f_offset[2], TEXTAREAOFFSET2_SIZE);
}

inline void SettingView::buttonTextOffset3ClickHandle()
{
    keyboard1.callKeyboard(&settingVar.f_offset[3], TEXTAREAOFFSET3_SIZE);
}

void SettingView::sliderAnalogOutHandle0(int value)
{
    updateAnalogOut0();
}
void SettingView::sliderAnalogOutHandle1(int value)
{
    updateAnalogOut1();
}
void SettingView::setADC(std::array<uint32_t, 4> arrayParameters)
{
 

    drawTextAdcIn0(analogIn.getAnalogValueFloat(0));
    drawTextAdcIn1(analogIn.getAnalogValueFloat(1));
    drawTextAdcIn2(analogIn.getAnalogValueFloat(2));
    drawTextAdcIn3(analogIn.getAnalogValueFloat(3));

    drawTextProcessVar0();
    drawTextProcessVar1();
    drawTextProcessVar2();
    drawTextProcessVar3();
}

void SettingView::updateAnalogOut0()
{
    u32_channelAnalogOut0 = sliderAnalogOut0.getValue();
    auto sliderAnalog0MaxValue = sliderAnalogOut0.getMaxValue();
    auto analogOut = (maxVol / sliderAnalog0MaxValue) * u32_channelAnalogOut0;
    Unicode::snprintfFloat(textAreaAnalogOut0Buffer, TEXTAREAANALOGOUT0_SIZE, "%2.1f", static_cast<float>(analogOut));
    textAreaAnalogOut0.invalidate();
#ifndef SIMMULATION
    presenter->notifyAnalogOutputChanged_0(u32_channelAnalogOut0);
#endif // !SIMMULATION
}

void SettingView::updateAnalogOut1()
{
    u32_channelAnalogOut1 = sliderAnalogOut1.getValue();
    auto sliderAnalog1MaxValue = sliderAnalogOut1.getMaxValue();
    auto analogOut = (maxVol / sliderAnalog1MaxValue) * u32_channelAnalogOut1;
    Unicode::snprintfFloat(textAreaAnalogOut1Buffer, TEXTAREAANALOGOUT1_SIZE, "%2.1f", static_cast<float>(analogOut));
    textAreaAnalogOut1.invalidate();
#ifndef SIMMULATION
    presenter->notifyAnalogOutputChanged_1(u32_channelAnalogOut1);
#endif // !SIMMULATION
}
 analogIn_type SettingView::getAnalogIn()
{
    return presenter->getAnalogIn();
}
void SettingView::drawTextAreaFactor0()
{
    Unicode::snprintfFloat(textAreaFactor0Buffer, TEXTAREAFACTOR0_SIZE, "%4.2f", static_cast<float>(settingVar.f_factor[0]));
    textAreaFactor0.invalidate();
}
void SettingView::drawTextAreaFactor1()
{
    Unicode::snprintfFloat(textAreaFactor1Buffer, TEXTAREAFACTOR1_SIZE, "%4.2f", static_cast<float>(settingVar.f_factor[1]));
    textAreaFactor1.invalidate();
}
inline void SettingView::drawTextAreaFactor2()
{
    Unicode::snprintfFloat(textAreaFactor2Buffer, TEXTAREAFACTOR2_SIZE, "%4.2f", static_cast<float>(settingVar.f_factor[2]));
    textAreaFactor2.invalidate();
}
inline void SettingView::drawTextAreaFactor3()
{
    Unicode::snprintfFloat(textAreaFactor3Buffer, TEXTAREAFACTOR3_SIZE, "%4.2f", static_cast<float>(settingVar.f_factor[3]));
    textAreaFactor3.invalidate();
}
inline void SettingView::drawTextAreaOffset0()
{
    Unicode::snprintfFloat(textAreaOffset0Buffer, TEXTAREAOFFSET0_SIZE, "%4.2f", static_cast<float>(settingVar.f_offset[0]));
    textAreaOffset0.invalidate();
}
inline void SettingView::drawTextAreaOffset1()
{
    Unicode::snprintfFloat(textAreaOffset1Buffer, TEXTAREAOFFSET1_SIZE, "%4.2f", static_cast<float>(settingVar.f_offset[1]));
    textAreaOffset1.invalidate();
}
inline void SettingView::drawTextAreaOffset2()
{
    Unicode::snprintfFloat(textAreaOffset2Buffer, TEXTAREAOFFSET2_SIZE, "%4.2f", static_cast<float>(settingVar.f_offset[2]));
    textAreaOffset2.invalidate();
}
inline void SettingView::drawTextAreaOffset3()
{
    Unicode::snprintfFloat(textAreaOffset3Buffer, TEXTAREAOFFSET3_SIZE, "%4.2f", static_cast<float>(settingVar.f_offset[3]));
    textAreaOffset3.invalidate();
}
inline void SettingView::drawTextProcessVar0()
{
    f_channelProcessVariable0 = (f_analogChannel0 * f_channelFactor0) + f_channelOffset0;
    auto  analogFloat = analogIn.getAnalogValueFloat(0);
    auto processVar = settingVar.getProcessValue(0, analogFloat);
    Unicode::snprintfFloat(textProcessVar0Buffer, TEXTPROCESSVAR0_SIZE, "%4.2f", static_cast<float>(processVar));
    textProcessVar0.invalidate();
}
inline void SettingView::drawTextProcessVar1()
{
    f_channelProcessVariable1 = (f_analogChannel1 * f_channelFactor1) + f_channelOffset1;
    auto  analogFloat = analogIn.getAnalogValueFloat(1);
    auto processVar = settingVar.getProcessValue(1, analogFloat);
    Unicode::snprintfFloat(textProcessVar1Buffer, TEXTPROCESSVAR1_SIZE, "%4.2f", static_cast<float>(processVar));
    textProcessVar1.invalidate();
}
inline void SettingView::drawTextProcessVar2()
{
    f_channelProcessVariable2 = (f_analogChannel2 * f_channelFactor2) + f_channelOffset2;
    auto  analogFloat = analogIn.getAnalogValueFloat(2);
    auto processVar = settingVar.getProcessValue(2, analogFloat);
    Unicode::snprintfFloat(textProcessVar2Buffer, TEXTPROCESSVAR2_SIZE, "%4.2f", static_cast<float>(processVar));
    textProcessVar2.invalidate();
}
inline void SettingView::drawTextProcessVar3()
{
    f_channelProcessVariable3 = (f_analogChannel3 * f_channelFactor3) + f_channelOffset3;
    auto  analogFloat = analogIn.getAnalogValueFloat(3);
    auto processVar = settingVar.getProcessValue(3, analogFloat);
    Unicode::snprintfFloat(textProcessVar3Buffer, TEXTPROCESSVAR3_SIZE, "%4.2f", static_cast<float>(processVar));
    textProcessVar3.invalidate();
}
void SettingView::drawTextFloat(decltype(textAreaFactor1Buffer) textBuffer, decltype(TEXTAREAFACTOR1_SIZE) textBufferSize, decltype("%4.2f") textFormat, decltype(textAreaFactor0) textObject, float number)
{
    Unicode::snprintfFloat(textBuffer, textBufferSize, textFormat, number);
    textObject.invalidate();
}
inline void SettingView::drawTextAdcIn0(float adcValue)
{
    Unicode::snprintfFloat(textAreaCH0Buffer, TEXTAREACH0_SIZE, "%2.1f", adcValue);
    textAreaCH0.invalidate();
}
inline void SettingView::drawTextAdcIn1(float adcValue)
{
    Unicode::snprintfFloat(textAreaCH1Buffer, TEXTAREACH1_SIZE, "%2.1f", adcValue);
    textAreaCH1.invalidate();
}
inline void SettingView::drawTextAdcIn2(float adcValue)
{
    Unicode::snprintfFloat(textAreaCH2Buffer, TEXTAREACH2_SIZE, "%2.1f", adcValue);
    textAreaCH2.invalidate();
}
inline void SettingView::drawTextAdcIn3(float adcValue)
{
    Unicode::snprintfFloat(textAreaCH3Buffer, TEXTAREACH3_SIZE, "%2.1f", adcValue);
    textAreaCH3.invalidate();
}
inline float SettingView::adcRawValueToVoltage(uint32_t adcVal) const
{
    auto vol = static_cast<float>(adcVal) / maxAdcRawVal;
    vol = vol * maxVoltage;
    return vol;
}
