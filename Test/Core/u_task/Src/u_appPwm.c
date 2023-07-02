#include "u_appPwm.h"
#include "u_pwm.h"
#include "u_appPid.h"
#include "u_appUtilities.h"

uint32_t u32_PwmCh0_10bit = 0;
uint32_t u32_PwmCh1_10bit = 0;

uint32_t u32_enablePwmCh0;
uint32_t u32_enablePwnCh1;

TaskHandle_t updatePwmCh0Handle __attribute__((section(".touchgfxccmram")));
TaskHandle_t updatePwmCh1Handle __attribute__((section(".touchgfxccmram")));

QueueHandle_t queue_updatePwmCh0Handle
    __attribute__((section(".touchgfxccmram")));
QueueHandle_t queue_updatePwmCh1Handle
    __attribute__((section(".touchgfxccmram")));

static void controlPWM(void *param);
static void updatePwmChange0(void *param);
static void updatePwmChange1(void *param);
static void updatePwm(void *param);

void u_appPwmCreate() {
  BaseType_t status;
  queue_updatePwmCh0Handle = xQueueCreate(1, sizeof(uint32_t));
  queue_updatePwmCh1Handle = xQueueCreate(1, sizeof(uint32_t));

  status = xTaskCreate(updatePwmChange0, "PWMCH0", 200, NULL, 2,
                       &updatePwmCh0Handle);
  configASSERT(status == pdPASS);
  status = xTaskCreate(updatePwmChange1, "PWMCH1", 200, NULL, 2,
                       &updatePwmCh1Handle);
  configASSERT(status == pdPASS);
}

void u_appPWM_resumeUpdatePwmCh()
{
    if(isTaskSuspended(updatePwmCh0Handle))
    {
        vTaskResume(updatePwmCh0Handle);
    }
    if(isTaskSuspended(updatePwmCh0Handle))
    {
        vTaskResume(updatePwmCh1Handle);
    }
    u_pwm_startCounter();
}

void u_appPWM_suspendUpdatePwmCh() 
{
    if(isTaskRunOrReady(updatePwmCh0Handle))
    {
        vTaskSuspend(updatePwmCh0Handle);
    }
    if(isTaskRunOrReady(updatePwmCh1Handle))
    {
        vTaskSuspend(updatePwmCh1Handle);
    }
    u_pwm_stopCounter();
    u_pwm_dutyCycleValue.u32_Channle0 = 0x00U;
    u_pwm_dutyCycleValue.u32_Channle1 = 0x00U;
    u_pwm_setDutyCycleISR(u_pwm_dutyCycleValue);
}

static void updatePwmChange0(void *param) {
  uint32_t isReceive;
  uint32_t u32_pwmChange0Value;
  while (1) {
    isReceive = xQueueReceive(queue_updatePwmCh0Handle, &u32_pwmChange0Value,
                              portMAX_DELAY);
    if (isReceive == pdTRUE) {
      u32_PwmCh0_10bit = u32_pwmChange0Value;
      u32_pwmChange0Value = ((u32_pwmChange0Value << 4) | 0xf) * 4;

      u_pwm_dutyCycleValue.u32_Channle0 = u32_pwmChange0Value;
    } else {
      u32_PwmCh0_10bit = 0u;
      u_pwm_dutyCycleValue.u32_Channle0 = 0x00u;
    }
  }
}

static void updatePwmChange1(void *param) {
  uint32_t isReceive;
  uint32_t u32_pwmChange1Value;
  while (1) {
    isReceive = xQueueReceive(queue_updatePwmCh1Handle, &u32_pwmChange1Value,
                              portMAX_DELAY);
    if (isReceive == pdTRUE) {
      u32_PwmCh1_10bit = u32_pwmChange1Value;
      u32_pwmChange1Value = ((u32_pwmChange1Value << 4) | 0xf) * 4;
      u_pwm_dutyCycleValue.u32_Channle1 = u32_pwmChange1Value;
    } else {
      u32_PwmCh1_10bit = 0u;
      u_pwm_dutyCycleValue.u32_Channle1 = 0x00u;
    }
  }
}
static void updatePwmForPid(void *param) {
  uint32_t u32_isReceive = 0;
  uint32_t u32_pwmValue;
  while (1) {
    u32_isReceive = xQueueReceive(u_pid_queue_output,&u32_pwmValue,portMAX_DELAY);
    if(u32_isReceive == pdTRUE)
    {
       u_pwm_dutyCycleValue.u32_Channle0 = ((u32_pwmValue << 4) | 0xf) * 4;
    }
  }
}