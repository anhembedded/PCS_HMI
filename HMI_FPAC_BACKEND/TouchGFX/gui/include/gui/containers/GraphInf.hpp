#ifndef GRAPHINF_HPP
#define GRAPHINF_HPP

#include <gui_generated/containers/GraphInfBase.hpp>
#include <cstdint>

class GraphInf : public GraphInfBase
{
public:
    GraphInf();
    virtual ~GraphInf() {}

    virtual void initialize();
    void updateValue(uint32_t var);
protected:
};

#endif // GRAPHINF_HPP
