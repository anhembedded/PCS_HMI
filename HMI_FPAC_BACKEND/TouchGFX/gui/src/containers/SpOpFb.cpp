#include <gui/containers/SpOpFb.hpp>

SpOpFb::SpOpFb()
{

}

void SpOpFb::initialize()
{
    SpOpFbBase::initialize();
}

void SpOpFb::drawLineProgressOutput(int outputVar)
{
   
    lineProgress_output.setValue(outputVar);
    lineProgress_output.invalidate();
}
