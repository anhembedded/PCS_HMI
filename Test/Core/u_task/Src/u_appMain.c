#include "u_appMain.h"
#include "queue.h"
#include "u_firmwareDefination.h"
#include "u_gpio.h"
#include "u_pwm.h"
#include "u_appPwm.h"
#include "gui/model/u_type.h"

uint8_t u_appMain_tasksArray[NumbOfTasks];
enum systemState_type u_appMain_systemState;
QueueHandle_t u_appMain_queue_taskState
    __attribute__((section(".touchgfxccmram")));
QueueHandle_t u_appMain_queue_systemState
    __attribute__((section(".touchgfxccmram")));

uint32_t u32_applicationSampleFrequency
    __attribute__((section(".touchgfxccmram")));

TaskHandle_t blinkLed_GreenHandle __attribute__((section(".touchgfxccmram")));
TaskHandle_t blinkOrange_OrangeHandle
    __attribute__((section(".touchgfxccmram")));

TaskHandle_t mainApplicationHandle __attribute__((section(".touchgfxccmram")));

static void mainApplication(void *param);
static void blinkLed_Green(void *param);
static void blinkLed_Orange(void *param);

void u_app_pidGraph_entry()
{
  u_appAdc_resume();
  u_appDdigitalIn_resume();
  u_appAdc_resume();
  u_appPwm_updatePwmFromPid_resume();
}
void u_app_pidGraph_exit()
{
 // u_appAdc_suspend();
 // u_appDdigitalIn_suspend();
 // u_appAdc_suspend();
}
void u_app_pidGraphRun_entry()
{
 /// u_appAdc_resume();
 /// u_appDdigitalIn_resume();
  u_appPidComputing_resume();
  u_appPwm_updatePwmFromPid_resume();
}
void u_app_pidGraphRun_exit()
{
 // u_appAdc_suspend();
 // u_appDdigitalIn_suspend();
  u_appPidComputing_suspend();
  u_appPwm_updatePwmFromPid_suspend();
}
void u_app_systemStartup_entry()
{
 // u_appAdc_suspend();
 // u_appDdigitalIn_suspend();
  u_appPWM_updatePwmCh_suspend();
  u_appPidComputing_suspend();
}
void u_app_settingVarState_entry()
{
 // u_appAdc_resume();
 // u_appDdigitalIn_resume();
  u_appPWM_updatePwmCh_resume();
}

void u_app_settingVarState_exit()
{
 // u_appAdc_suspend();
 // u_appDdigitalIn_suspend();
  u_appPWM_updatePwmCh_suspend();
}

void u_appMainCreate()
{
  BaseType_t status;
  status = xTaskCreate(mainApplication, "mainApp", 200, NULL, 1,
                       &mainApplicationHandle);
  configASSERT(status == pdPASS);
  status = xTaskCreate(blinkLed_Green, "blinkGreen", 200, NULL, 2,
                       &blinkLed_GreenHandle);
  configASSERT(status == pdPASS);
  status = xTaskCreate(blinkLed_Orange, "blinkOrange", 200, NULL, 2,
                       &blinkOrange_OrangeHandle);
  configASSERT(status == pdPASS);
  u_appMain_queue_taskState = xQueueCreate(
      sizeof(u_appMain_tasksArray) / sizeof(uint8_t), sizeof(uint8_t));
  u_appMain_queue_systemState =
      xQueueCreate(sizeof(uint32_t) / sizeof(uint8_t), sizeof(uint32_t));
  u_appDigitalInputCreate();
  u_appDigitalOutputCreate();
  u_appPwmCreate();
  u_appAdcCreate();
  u_appPidCreate();
  /* SystemState::SystemStartup  */
  u_app_systemStartup_entry();
}

static void mainApplication(void *param)
{
  portBASE_TYPE isRec = 0;
  while (1)
  {
    isRec = xQueueReceive(u_appMain_queue_systemState, (void *)&u_appMain_systemState,
                          portMAX_DELAY);

    // if(u_appMain_systemState == eSETTING_VAR)
    // {
    //   settingVarState_entry();
    // }else if ()
    // {

    // }
  }
}

static void blinkLed_Green(void *param)
{
  TickType_t xLastWakeTime;
  xLastWakeTime = xTaskGetTickCount();
  while (1)
  {
    u_gpio_togglePin(LED_GREEN_PORT, LED_GREEN_PIN);
    vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(1050 - u32_PwmCh0_10bit));
  }
}
static void blinkLed_Orange(void *param)
{
  TickType_t xLastWakeTime;
  xLastWakeTime = xTaskGetTickCount();
  while (1)
  {
    u_gpio_togglePin(LED_ORANGE_PORT, LED_ORANGE_PIN);
    vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(1050 - u32_PwmCh1_10bit));
  }
}
