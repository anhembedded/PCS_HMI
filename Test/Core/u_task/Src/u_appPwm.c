#include "u_appPwm.h"
#include "u_pwm.h"


uint32_t u32_PwmCh0_10bit = 0;
uint32_t u32_PwmCh1_10bit = 0;

uint32_t u32_enablePwmCh0;
uint32_t u32_enablePwnCh1;




TaskHandle_t controlPWMHandle __attribute__((section(".touchgfxccmram")));
TaskHandle_t updatePwmCh0Handle __attribute__((section(".touchgfxccmram")));
TaskHandle_t updatePwmCh1Handle __attribute__((section(".touchgfxccmram")));

QueueHandle_t queue_updatePwmCh0Handle __attribute__((section(".touchgfxccmram")));
QueueHandle_t queue_updatePwmCh1Handle __attribute__((section(".touchgfxccmram")));
QueueHandle_t pwmDutyCycleQueueHandle __attribute__((section(".touchgfxccmram")));

static void controlPWM(void *param);
static void updatePwmChange0(void *param);
static void updatePwmChange1(void *param);

void u_appPwmCreate()
{
    BaseType_t status;
    pwmDutyCycleQueueHandle = xQueueCreate(1, sizeof(struct u_pwm_dutyCycle_type));
    queue_updatePwmCh0Handle = xQueueCreate(1, sizeof(uint32_t));
    queue_updatePwmCh1Handle = xQueueCreate(1, sizeof(uint32_t));

    status = xTaskCreate(updatePwmChange0, "updatePWMChange0Task", 200, NULL, 2, &updatePwmCh0Handle);
    configASSERT(status == pdPASS);
    status = xTaskCreate(updatePwmChange1, "updatePWMChange1Task", 200, NULL, 2, &updatePwmCh1Handle);
    configASSERT(status == pdPASS);
}

static void controlPWM(void *param)
{
    uint32_t u32_controlVal = 0;
    while (1)
    {
        if (u32_controlVal == pdTRUE)
        {
            /*Start PWM*/
            vTaskResume(updatePWMHandle);
        }
        else
        {
            vTaskSuspend(updatePWMHandle);
            /*
            todo: Stop PWM and Set digital output to low
            */
        }
    }
}

static void updatePwmChange0(void *param)
{
    uint32_t isReceive;
    uint32_t u32_pwmChange0Value;
    while (1)
    {
        isReceive = xQueueReceive(queue_updatePwmCh0Handle, &u32_pwmChange0Value, portMAX_DELAY);
        if (isReceive == pdTRUE)
        {
        	u32_PwmCh0_10bit = u32_pwmChange0Value;
            u32_pwmChange0Value = (u32_pwmChange0Value << 4) | 0xf;

            u_pwm_dutyCycleValue.u32_Channle0 = u32_pwmChange0Value;
        }
        else
        {
        	u32_PwmCh0_10bit = 0u;
            u_pwm_dutyCycleValue.u32_Channle0 = 0x00u;
        }
    }
}

static void updatePwmChange1(void *param)
{
    uint32_t isReceive;
    uint32_t u32_pwmChange1Value;
    while (1)
    {
        isReceive = xQueueReceive(queue_updatePwmCh1Handle, &u32_pwmChange1Value, portMAX_DELAY);
        if (isReceive == pdTRUE)
        {
        	u32_PwmCh1_10bit = u32_pwmChange1Value;
            u32_pwmChange1Value = (u32_pwmChange1Value << 4) | 0xf;
            u_pwm_dutyCycleValue.u32_Channle1 = u32_pwmChange1Value;
        }
        else
        {
        	u32_PwmCh1_10bit = 0u;
            u_pwm_dutyCycleValue.u32_Channle1 = 0x00u;
        }
    }
}
