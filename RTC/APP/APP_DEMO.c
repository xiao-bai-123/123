#include "TASK_APP.h"
#include "FreeRTOS.h"
#include "task.h"
//任务堆栈大小	
#define START_APP_STK_SIZE 		128
//任务控制块
OS_TCB Start_APP_TaskTCB;
//任务堆栈	
CPU_STK START_APP_TASK_STK[START_APP_STK_SIZE];
//任务函数

void APP_INIT()
{	
	
}



void start_APP_task(void *pvParameters)
{
	APP_INIT();
	

		while(1)
	{	
		vTaskDelay(1000);

	}
}




void ADC_TaskCreat (OS_PRIO Prio)
{
		OS_ERR err;	
	OSTaskCreate((OS_TCB 	* )&Start_APP_TaskTCB,		
								 (CPU_CHAR	* )"Start_ADC", 		
                 (OS_TASK_PTR )start_APP_task, 			
                 (void		* )0,					
                 (OS_PRIO	  )Prio,     
                 (CPU_STK   * )&START_APP_TASK_STK[0],	
                 (CPU_STK_SIZE)START_APP_STK_SIZE/10,	
                 (CPU_STK_SIZE)START_APP_STK_SIZE,		
                 (OS_MSG_QTY  )0,					
                 (OS_TICK	  )0,					
                 (void   	* )0,					
                 (OS_OPT      )OS_OPT_TASK_STK_CHK|OS_OPT_TASK_STK_CLR,
                 (OS_ERR 	* )&err);			

}