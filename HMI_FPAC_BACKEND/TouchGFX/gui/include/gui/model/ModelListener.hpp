#ifndef MODELLISTENER_HPP
#define MODELLISTENER_HPP

#include <gui/model/Model.hpp>
#include <array>
/**
 * ModelListener is the interface through which the Model can inform the currently
 * active presenter of events. All presenters should derive from this class.
 * It also provides a model pointer for the presenter to interact with the Model.
 *
 * The bind function is called automatically.
 *
 * Add the virtual functions Model should be able to call on the active presenter to this class.
 */
class ModelListener
{
public:
    ModelListener() : model(0) {}

    virtual ~ModelListener() {}

    /**
     * Sets the model pointer to point to the Model object. Called automatically
     * when switching screen.
     */
    void bind(Model *m)
    {
        model = m;
    }

    virtual void notifyADCChanged(std::array<uint32_t, 4> newTemperature) {}
    virtual void notifyDigitalInput(uint32_t registerVar) {}
    virtual void notifyDigitalIntputChanged_0(uint32_t registerVar) {}
    virtual void notifyDigitalIntputChanged_1(uint32_t registerVar) {}
    virtual void notifyDigitalIntputChanged_2(uint32_t registerVar) {}
    virtual void notifyDigitalIntputChanged_3(uint32_t registerVar) {}
    virtual void notifyDigitalIntputChanged_4(uint32_t registerVar) {}
    virtual void notifyDigitalIntputChanged_5(uint32_t registerVar) {}
    virtual void notifyDigitalIntputChanged_6(uint32_t registerVar) {}

protected:
    Model *model;
};

#endif /* MODELLISTENER_HPP */
