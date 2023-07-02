#ifndef CORE_U_TASK_INC_U_APPDIGITALINPUT
#define CORE_U_TASK_INC_U_APPDIGITALINPUT
#include <stdint.h>
extern uint32_t u32_applicationInputState[8];
void u_appDigitalInputCreate();

void u_appDdigitalIn_resume();
void u_appDdigitalIn_suspend();
void u_appDigitalInput_Main();

#endif /* CORE_U_TASK_INC_U_APPDIGITALINPUT */
