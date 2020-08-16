#include "APP_CHECK.h"
#include "adc.h"



//�����ջ��С	
#define START_CHECK_STK_SIZE 		50
//������
TaskHandle_t START_CHECK_Handler;



static void CHECK_INIT()
{	
	Adc_Init();		  		//ADC��ʼ��
}



static void start_CHECK_task(void *pvParameters)
{
static u16 adcx1,adcx2;
		CHECK_INIT();
    while(1)
    {
			
			adcx1=Get_Adc_Average(ADC_Channel_1,10);//PA1
			adcx2=Get_Adc_Average(ADC_Channel_2,10);//PA2
        vTaskDelay(999);
    }
}




void CHECK_TaskCreat (UBaseType_t Prio)
{
    //����TASK1����
    xTaskCreate((TaskFunction_t )start_CHECK_task,             
                (const char*    )"start_CHECK_task",           
                (uint16_t       )START_CHECK_STK_SIZE,        
                (void*          )NULL,                  
                (UBaseType_t    )Prio,        
                (TaskHandle_t*  )&START_CHECK_Handler);  

}


