#include "APP_LED.h"
#include "led.h"
//�����ջ��С	
#define START_LED_STK_SIZE 		50
//������
TaskHandle_t START_LED_Handler;

//�����ջ��С	
#define START_LED1_STK_SIZE 		50
//������
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
        taskENTER_CRITICAL();           //�����ٽ���
        printf("float_num��ֵΪ: %.4f\r\n",float_num);   /*���ڴ�ӡ���*/
				printf("times��ֵΪ: %d\r\n",xTaskGetTickCount());   /*���ڴ�ӡ���*/
        taskEXIT_CRITICAL();            //�˳��ٽ���
        vTaskDelay(999);
    }
}




void LED_TaskCreat (UBaseType_t Prio)
{
    //����TASK1����
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
    //����TASK1����
    xTaskCreate((TaskFunction_t )start_LED1_task,             
                (const char*    )"start_LED1_task",           
                (uint16_t       )START_LED1_STK_SIZE,        
                (void*          )NULL,                  
                (UBaseType_t    )Prio,        
                (TaskHandle_t*  )&START_LED1_Handler);  

}

