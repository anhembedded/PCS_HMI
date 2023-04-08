#include <gui/containers/SpOpFb.hpp>

SpOpFb::SpOpFb()
{

}

void SpOpFb::initialize()
{
    SpOpFbBase::initialize();
}

void SpOpFb::drawtextAreaSetpoint(float setpointVar)
{
    Unicode::snprintfFloat(textArea_setPointBuffer , TEXTAREA_SETPOINT_SIZE, "%3.2f", static_cast<float>(setpointVar));
    textArea_setPoint.invalidate();
}

void SpOpFb::drawtextAreaFeedback(float feedbackVar)
{
    Unicode::snprintfFloat(textArea_feedbackBuffer, TEXTAREA_FEEDBACK_SIZE, "%3.2f", static_cast<float>(feedbackVar));
    textArea_feedback.invalidate();
}

void SpOpFb::drawLineProgressOutput(int outputVar)
{
    lineProgress_output.setValue(outputVar);
    lineProgress_output.invalidate();
}
