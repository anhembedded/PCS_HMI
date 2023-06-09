#ifndef EC38B401_F98D_4D5F_BA4F_A085A6C4056F
#define EC38B401_F98D_4D5F_BA4F_A085A6C4056F

#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include <string>

#ifdef BACKEND
#include "FreeRTOS.h"
#include "queue.h"
#endif

template<typename T>
void debugPrint(const char* strMessage, T var)
{
#ifdef SIMULATOR

	touchgfx_printf(strMessage);
	touchgfx_printf(" :%d \n", var);

#endif // SIMULATOR //  
}

float cov1024to10Float(uint32_t _1024Var);


#endif /* EC38B401_F98D_4D5F_BA4F_A085A6C4056F */





