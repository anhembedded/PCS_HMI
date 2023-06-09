#ifndef CORE_U_TASK_INC_U_APPDIGITALOUTPUT
#define CORE_U_TASK_INC_U_APPDIGITALOUTPUT

#include "u_appMain.h"
#include "u_gpio.h"
#include "u_firmwareDefination.h"
#include "u_pwm.h"
#include "queue.h"


enum
{
    numberOfDigitalOuput = 8
};

struct u_appDigitalOutputUpdate_type
{
    uint8_t isUpdate;
    uint8_t digitalState[8];
};

extern uint32_t u_appDigitalOut_array[4];

extern struct u_appDigitalOutputUpdate_type u_appDigitalVar;
extern QueueHandle_t u_app_queue_digitalOutput;

void u_appDigitalOutputCreate();

void u_appDigitalOut_resume();
void u_appDigitalOut_suspend();
void u_appDigitalOutput_main();

#endif /* CORE_U_TASK_INC_U_APPDIGITALOUTPUT */
