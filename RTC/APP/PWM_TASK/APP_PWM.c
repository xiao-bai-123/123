#include "APP_PWM.h"
#include "timer.h"
//�����ջ��С	
#define START_PWM_STK_SIZE 		50
//������
TaskHandle_t START_PWM_Handler;



static void PWM_INIT()
{	
	TIM3_PWM_Init(3599,0);	 //����Ƶ��PWMƵ��=72000000/3600=20Khz
}



static void start_PWM_task(void *pvParameters)
{
	static u16 pwmval=3500;//ռ�ձ� ����3599 
		PWM_INIT();
	
    while(1)
    {
			
TIM_SetCompare2(TIM3,pwmval);
        vTaskDelay(999);
    }
}




void PWM_TaskCreat (UBaseType_t Prio)
{
    //����TASK1����
    xTaskCreate((TaskFunction_t )start_PWM_task,             
                (const char*    )"start_PWM_task",           
                (uint16_t       )START_PWM_STK_SIZE,        
                (void*          )NULL,                  
                (UBaseType_t    )Prio,        
                (TaskHandle_t*  )&START_PWM_Handler);  

}


