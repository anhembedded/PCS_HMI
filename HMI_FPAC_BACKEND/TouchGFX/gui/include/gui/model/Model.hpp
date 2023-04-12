#ifndef INCLUDE_GUI_MODEL_MODEL
#define INCLUDE_GUI_MODEL_MODEL

// HOangANh

#include <stdint.h>
#include <touchgfx/Utils.hpp>
#include <array>

#ifndef SIMULATOR
#include "u_appMain.h"
#include "u_pwm.h"
#include "array"
#else

#endif
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
    level,
    flowRate,
    pressure,
    temperature
};

struct analogIn_type
{
    const float maxVolage = 10.0F;
    const uint32_t rawAnalogMax = 1024U;
    std::array<uint32_t, 4> u32_10BitAnalogIn;

    float getAnalogValueFloat(uint32_t indexChannel);
    analogIn_type& operator=(analogIn_type other) noexcept
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

#ifndef SIMULATOR

    std::array<uint32_t, 4> getCurrentADC() const
    {
        return adcValue;
    };
#endif // !SIMULATOR
    void setPidParam(pidParam_type pidSet);
    pidParam_type getPidParam();
    void setActualValue(actualValue_type view_actualValue);
    actualValue_type getActualValue();
    void setSettingVar(settingVar_type setVar);
    settingVar_type getSettingVar();
    analogIn_type getAnalogIn();

protected:
    /**
     * Pointer to the currently active presenter.
     */
    ModelListener *modelListener;
#ifdef SIMULATOR
    uint32_t modelGetTick();
    uint32_t tickVal;
#endif // SIMULATOR

private:
#ifndef SIMULATOR
    u_pwm_dutyCycle_type dutyCycleVal;
    uint32_t *u32_adcPtr;
    std::array<uint32_t, 4> adcValue;
#endif // !SIMULATOR
};

class dummyClass_type
{
public:
    uint32_t myDummyVar;
    uint32_t myDummyVar2;
    uint32_t getVar()
    {
        return myDummyVar;
    }
};

#endif /* INCLUDE_GUI_MODEL_MODEL */
