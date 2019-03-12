/**
	|--------------------------------- Copyright --------------------------------|
	|                                                                            |
	|                      (C) Copyright 2019,����ƽͷ��,                         |
	|           1 Xuefu Rd, Huadu Qu, Guangzhou Shi, Guangdong Sheng, China      |
	|                           All Rights Reserved                              |
	|                                                                            |
	|           By(GCU The wold of team | ����������ѧ����ѧԺ������Ұ�Ƕ�)         |
	|                    https://github.com/GCUWildwolfteam                      |
	|----------------------------------------------------------------------------|
	|--FileName    : debug_by_keil.c                                              
	|--Version     : v1.0                                                          
	|--Author      : ����ƽͷ��                                                     
	|--Date        : 2019-02-23             
	|--Libsupports : 
	|--Description :                                                     
	|--FunctionList                                                     
	|-------1. ....                                                     
	|          <version>:                                                     
	|     <modify staff>:                                                       
	|             <data>:                                                       
	|      <description>:                                                        
	|-------2. ...                                                       
	|-----------------------------declaration of end-----------------------------|
 **/
#include "debug_by_keil.h" 
#ifdef DEBUG_BY_KEIL
#define PRINTFTASKSTATUS 
 extern UART_HandleTypeDef huart2;//����1
 extern UART_HandleTypeDef huart7;
debugByKeilStruct pdebug_t;
osThreadId startDebugByKeilTaskHandle; 
void StartDebugByKeilTask(void const *argument);
	/**
		* @Data    2019-02-23 15:46
		* @brief   ��ȡ�ֲ������ĵ�ַ������keilӲ������
		* @param   void
		* @retval  void
		*/
		void DebugByKeilInit(void)
		{
			/* -------- keilӲ����������ʾ���� --------- */
			 osThreadDef(debugByKeilTask, StartDebugByKeilTask, osPriorityBelowNormal, 0,1024);
       startDebugByKeilTaskHandle = osThreadCreate(osThread(debugByKeilTask), NULL); 
//			 DebugClassInit();      
       pdebug_t.d_rc = GetRcStructAdd();
       pdebug_t.d_chassis_t = GetChassisStructAdd();
      
		}
/**
  * @Data    2019-02-23 15:46
  * @brief   keilӲ�����������Ӻ���
  * @param   void
  * @retval  void
  */
void StartDebugByKeilTask(void const *argument)
{
#ifdef PRINTFTASKSTATUS
     uint8_t pcWriteBuffer[500];
#endif
  uint8_t aa=1;
		for(;;)
		{
#ifdef PRINTFTASKSTATUS
        vTaskList((char *)&pcWriteBuffer);
        printf("��������\t����״̬\t���ȼ�\tʣ���ջ\t�������\r\n");
        printf("-------------------------------------------------\r\n");
        printf("%s\r\n", pcWriteBuffer); 
        printf("-------------------------------------------------\r\n");
        printf("B : ����, R : ����, D : ɾ��, S : ��ͣ\r\n");
//        memset(pcWriteBuffer, 0, 500);
//        printf("��������\t���м���\tʹ����\r\n");
//        printf("-------------------------------------------------\r\n");
//        vTaskGetRunTimeStats((char *)&pcWriteBuffer);
//        printf("%s\r\n", pcWriteBuffer);
         osDelay(500);      
#endif
//      HAL_UART_Transmit(&huart7,&aa,1,0);
//      osDelay(5);
      
		}
}
//	/**
//	* @Data    2019-01-18 11:31
//	* @brief   led����ʾ�����Ӻ���
//	* @param   argument: Not used
//	* @retval  void
//	*/
//	void StartLedTask(void const *argument)
//	{
//    uint16_t i=0;
////uint32_t s[1000] = {0};

//    //    printf("led����ʾ�����ʼ�����\r\n");
////     uint8_t pcWriteBuffer[500];
//		for(;;)
//		{
////      if(task_on_off == ENABLE)
////      {
//  #if BINGE_BOARD
//        if(parse_task_status == 1)
//          FlashingLed(LED_GPIO, LED_1, 2, 100);
//				else if(rc_chassis_task_status == 1)
//				  FlashingLed(LED_GPIO, LED_2, 2, 50);
//			  else if(auto_chassis_task_status == 1)
//				  FlashingLed(LED_GPIO, LED_3, 2, 50);
//        else osDelay(1);
//  #elif RM_OLD_BOARD
//        (void)parse_task_status;
//  #endif 
////        vTaskList((char *)&pcWriteBuffer);
////        printf("������      ����״̬ ���ȼ�   ʣ��ջ �������\r\n");
////        printf("%s\r\n", pcWriteBuffer); 
////        osDelay(500);
//        if(i<4500)
//        {
//					
//					;
//           Debug_t.uint32(&huart2,((uint32_t)((1500*sin(0.00419*i))+1500)));
//          i++;
//        }
//        osDelay(10);
////      }
////      else osDelay(1);
//		}
//    
//	}
#endif
/*-----------------------------------file of end------------------------------*/

