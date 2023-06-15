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

void u_appDigitalOutputCreate();

#endif /* CORE_U_TASK_INC_U_APPDIGITALOUTPUT */
