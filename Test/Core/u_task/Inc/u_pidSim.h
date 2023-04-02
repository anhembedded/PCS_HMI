#ifndef CORE_U_TASK_INC_U_PIDSIM
#define CORE_U_TASK_INC_U_PIDSIM
#include "stdint.h"
#include "pid.h"

extern PID_TypeDef TPID;

double systemFunctionTimeDomain_1(uint32_t controlSingle);
void u_pidSImCreate();

#endif /* CORE_U_TASK_INC_U_PIDSIM */
