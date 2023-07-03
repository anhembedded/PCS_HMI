#include "gui/model/u_touchGfxUtilities.hpp"

float cov1024to10Float(uint32_t _1024Var)
{
	auto temp = _1024Var / 1023.0F;
	temp = 10.0F * temp;
	return (temp);
}
