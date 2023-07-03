#include "gui/model/u_touchGfxUtilities.hpp"

float cov1024to10Float(float _1024floatVar)
{
	auto temp = _1024floatVar / 1023.0F;
	temp = 10.0F * temp;
	return (temp);
}
