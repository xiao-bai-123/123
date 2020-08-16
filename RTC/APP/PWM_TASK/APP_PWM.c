#include "APP_PWM.h"
#include "timer.h"
//任务堆栈大小	
#define START_PWM_STK_SIZE 		50
//任务句柄
TaskHandle_t START_PWM_Handler;



static void PWM_INIT()
{	
	TIM3_PWM_Init(3599,0);	 //不分频。PWM频率=72000000/3600=20Khz
}



static void start_PWM_task(void *pvParameters)
{
	static u16 pwmval=3500;//占空比 周期3599 
		PWM_INIT();
	
    while(1)
    {
			
TIM_SetCompare2(TIM3,pwmval);
        vTaskDelay(999);
    }
}




void PWM_TaskCreat (UBaseType_t Prio)
{
    //创建TASK1任务
    xTaskCreate((TaskFunction_t )start_PWM_task,             
                (const char*    )"start_PWM_task",           
                (uint16_t       )START_PWM_STK_SIZE,        
                (void*          )NULL,                  
                (UBaseType_t    )Prio,        
                (TaskHandle_t*  )&START_PWM_Handler);  

}


