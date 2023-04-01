#include <gui/containers/GraphInf.hpp>

GraphInf::GraphInf()
{

}

void GraphInf::initialize()
{
    GraphInfBase::initialize();
}

void GraphInf::updateValue(uint32_t var)
{
    Unicode::snprintf(textArea1Buffer, TEXTAREA1_SIZE, "%i", var);
    invalidate();
}
