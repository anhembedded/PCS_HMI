#ifndef EC38B401_F98D_4D5F_BA4F_A085A6C4056F
#define EC38B401_F98D_4D5F_BA4F_A085A6C4056F

#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include <string>

template<typename T>
void debugPrint(const char * strMessage, T var);


#endif /* EC38B401_F98D_4D5F_BA4F_A085A6C4056F */

template<typename T>
 void debugPrint(const char* strMessage, T var)
{
#ifdef SIMULATOR

	 touchgfx_printf(strMessage);
	 touchgfx_printf(" :%d \n", var);

#endif // SIMULATOR //  
}