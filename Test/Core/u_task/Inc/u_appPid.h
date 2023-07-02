#ifndef CORE_U_TASK_INC_U_APPPID
#define CORE_U_TASK_INC_U_APPPID
#include "pid.h"
#include "stdint.h"
#include "queue.h"

extern QueueHandle_t u_pid_queue_feedbackHandle;
extern struct u_appPid_updateParam_type pidParam;
extern QueueHandle_t u_pid_queue_output;
void u_appPidCreate();

void u_appPidComputing_resume();
void u_appPidComputing_suspend();
void u_appPID_Main();

#endif /* CORE_U_TASK_INC_U_APPPID */
