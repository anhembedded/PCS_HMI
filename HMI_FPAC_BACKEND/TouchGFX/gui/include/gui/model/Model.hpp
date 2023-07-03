#ifndef INCLUDE_GUI_MODEL_MODEL
#define INCLUDE_GUI_MODEL_MODEL

// HOangANh

#include <stdint.h>
#include <touchgfx/Utils.hpp>
#include <array>

#ifndef SIMULATOR
extern "C"
{
#include "u_appMain.h"
#include "u_pwm.h"
#include "array"
#include "u_appMain.h"
}
#else

#endif
#include "u_type.h"

namespace pidRange
{
   constexpr auto KP_MAX = 10.0F; 
   constexpr auto KI_MAX = 2.0F; 
   constexpr auto KD_MAX = 10.0F; 
   constexpr auto KP_MIN = 1.0F; 
   constexpr auto KI_MIN = 0.0F; 
   constexpr auto KD_MIN = 0.0F; 
}
struct pidParam_type
{
    float f_kp;
    float f_ki;
    float f_kd;
    float f_setPoint;
    float getFloatSetpint();
};
enum class actualValue_type
{
    level = 0,
    flowRate = 1,
    pressure = 2,
    temperature = 3,
    non
};
enum class activeScreen_type
{
    nonScreen,
    inforScreen,
    mainScreen,
    settingScreen,
    mesuaringScreen,
    closedLoopSettingScreen,
    closedLoopGraphScreen
};


struct analogIn_type
{
    
    const float maxVolage = 10.0F;
    const uint32_t rawAnalogMax = 1024U;
    std::array<uint32_t, 4> u32_10BitAnalogIn;

    float getAnalogValueFloat(uint32_t indexChannel);
    analogIn_type &operator=(analogIn_type other) noexcept
    {
        u32_10BitAnalogIn = other.u32_10BitAnalogIn;
        return *this;
    }
};

struct settingVar_type
{
    const float maxVolage = 10.0F;
    const uint32_t rawAnalogMax = 1024U;

    std::array<float, 4> f_factor;
    std::array<float, 4> f_offset;
    settingVar_type &operator=(settingVar_type other) noexcept
    {
        f_factor = other.f_factor;
        f_offset = other.f_offset;
        return *this;
    }

    float getProcessValue(uint32_t indexChannel, float analogInFloat);
};

struct digitaOut_type
{
    std::array<uint8_t, 5> u8_digiOut;
};
struct digitalIn_type
{
    std::array<uint8_t, 7> u8_digiIn;
};
class ModelListener;

/**
 * The Model class defines the data model in the model-view-presenter paradigm.
 * The Model is a singular object used across all presenters. The currently active
 * presenter will have a pointer to the Model through deriving from ModelListener.
 *
 * The Model will typically contain UI state information that must be kept alive
 * through screen transitions. It also usually provides the interface to the rest
 * of the system (the backend). As such, the Model can receive events and data from
 * the backend and inform the current presenter of such events through the modelListener
 * pointer, which is automatically configured to point to the current presenter.
 * Conversely, the current presenter can trigger events in the backend through the Model.
 */
class Model
{
public:
    pidParam_type pidParam;
    actualValue_type actualValue;
    settingVar_type settingVar;
    analogIn_type analogIn;
    digitaOut_type digitalOutput;
    digitalIn_type digitalInput;
    activeScreen_type activeScreenVar;
    systemState_type systemEntryState; 
    uint32_t pidOutFromBackend;
  
    Model();

    /**
     * Sets the modelListener to point to the currently active presenter. Called automatically
     * when switching screen.
     */
    void bind(ModelListener *listener)
    {
        modelListener = listener;
    }

    /**
     * This function will be called automatically every frame. Can be used to e.g. sample hardware
     * peripherals or read events from the surrounding system and inject events to the GUI through
     * the ModelListener interface.
     */
    void tick();

    void sendAdcOuputToBackEnd_1(uint32_t registerVar);
    void sendAdcOuputToBackEnd_0(uint32_t registerVar);
    void sendDigitalOutputToBackEnd();
    void updateActiveScreen(activeScreen_type param);

#ifndef SIMULATOR

    std::array<uint32_t, 4> getCurrentADC() const
    {
        return adcValue;
    };
#endif // !SIMULATOR
    pidParam_type getPidParam();
    actualValue_type getActualValue();
    settingVar_type getSettingVar();
    analogIn_type getAnalogIn();
    digitaOut_type getDigitalOut();
    digitalIn_type getDigitalIn();

    void setPidParam(pidParam_type pidSet);
    void setActualValue(actualValue_type view_actualValue);
    void setSettingVar(settingVar_type setVar);
    void setDigitalOut(digitaOut_type setOutput);
    void setDigitalIn(digitalIn_type setInput);
    void setActiveScreen(activeScreen_type activeScreenParam);
    void setState(systemState_type sysState);
    void updateActualValue(actualValue_type actualValueParam);
    float getFeedBackToPresentor();

    void statePidGraphRun_entry();
    void stateSettingVar_entry();
    void stateSettingVar_exit();
    void statePidGraphRun_exit();
    
    
protected:
    /**
     * Pointer to the currently active presenter.
     */
    ModelListener *modelListener;

    uint32_t modelGetTick();
    uint32_t frameTickVal;

private:
    uint32_t *u32_adcPtr;
    std::array<uint32_t, 4> adcValue;
};

#endif /* INCLUDE_GUI_MODEL_MODEL */
