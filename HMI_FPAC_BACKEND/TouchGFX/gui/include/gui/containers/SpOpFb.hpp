#ifndef SPOPFB_HPP
#define SPOPFB_HPP

#include <gui_generated/containers/SpOpFbBase.hpp>

class SpOpFb : public SpOpFbBase
{
public:
    SpOpFb();
    virtual ~SpOpFb() {}

    virtual void initialize();
    void drawtextAreaSetpoint(float setpointVar);
    void drawtextAreaFeedback(float feedbackVar);
    void drawLineProgressOutput(int outputVar);
protected:
};

#endif // SPOPFB_HPP
