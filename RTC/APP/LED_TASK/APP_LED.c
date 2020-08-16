#include "APP_LED.h"
#include "led.h"
//任务堆栈大小	
#define START_LED_STK_SIZE 		50
//任务句柄
TaskHandle_t START_LED_Handler;

//任务堆栈大小	
#define START_LED1_STK_SIZE 		50
//任务句柄
TaskHandle_t START_LED1_Handler;

void LED_INIT()
{	
	
}



void start_LED_task(void *pvParameters)
{
    static float float_num=0.01;
		LED_INIT();
    while(1)
    {
			
        float_num+=0.01f;
        taskENTER_CRITICAL();           //进入临界区
        printf("float_num的值为: %.4f\r\n",float_num);   /*串口打印结果*/
				printf("times的值为: %d\r\n",xTaskGetTickCount());   /*串口打印结果*/
        taskEXIT_CRITICAL();            //退出临界区
        vTaskDelay(999);
    }
}




void LED_TaskCreat (UBaseType_t Prio)
{
    //创建TASK1任务
    xTaskCreate((TaskFunction_t )start_LED_task,             
                (const char*    )"start_LED_task",           
                (uint16_t       )START_LED_STK_SIZE,        
                (void*          )NULL,                  
                (UBaseType_t    )Prio,        
                (TaskHandle_t*  )&START_LED_Handler);  

}

void start_LED1_task(void *pvParameters)
{
		LED_INIT();
    while(1)
    {
        LED1=0;
        vTaskDelay(200);
        LED1=1;
        vTaskDelay(800);
    }
}


void LED1_TaskCreat (UBaseType_t Prio)
{
    //创建TASK1任务
    xTaskCreate((TaskFunction_t )start_LED1_task,             
                (const char*    )"start_LED1_task",           
                (uint16_t       )START_LED1_STK_SIZE,        
                (void*          )NULL,                  
                (UBaseType_t    )Prio,        
                (TaskHandle_t*  )&START_LED1_Handler);  

}

