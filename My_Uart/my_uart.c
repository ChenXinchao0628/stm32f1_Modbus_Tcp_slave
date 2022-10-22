#include "main.h"
#include "usart.h"
//#include "cmsis_os.h"
#include "my_uart.h"



#if USART1_EN
unsigned char USART1_UserBuffer[USART1_RXBUF_LEN];
unsigned char USART1_Buffer[USART1_RXBUF_LEN];
struct UART_REC_TYPE Uart1;

/**************************************
函数名： uint8_t USART1_RecService(void)
说  明： 串口1接收服务程序，判断数据有没有接收完
参  数： 无
返回值： 1：接收完成		0：接收未完成或无数据
**************************************/
uint8_t USART1_RecService(void)		
{
	static uint16_t USART1_RecLen_Last=0; 
	if(Uart1.RecCount)					//串口已有接收,至少进入过一次串口接收中断
	{
//		#if Freertos_EN == 0		//等待2ms,波特率9600
//		HAL_Delay(2);
//		#endif
//		#if Freertos_EN == 1
//		osDelay(2);
//		#endif
		if(USART1_RecLen_Last == Uart1.RecCount)	//判断接收数据长度是否与上次循环相等，如果相等则代表接收完成
		{
			USART1_RecLen_Last=0;
			Uart1.LastLen = Uart1.RecCount;					//获取接收长度
			Uart1.RecCount = 0;											//重新从Buff[0]开始接收
			for(uint16_t i=0;i<Uart1.LastLen;i++)  USART1_UserBuffer[i] = USART1_Buffer[i];		//替换Buffer，接收Buffer仍然作为接收中断内使用			
			return 1;		
		}
		else USART1_RecLen_Last = Uart1.RecCount;
	}
	return 0;
}
#endif


#if USART2_EN
unsigned char USART2_UserBuffer[USART2_RXBUF_LEN];
unsigned char USART2_Buffer[USART2_RXBUF_LEN];
struct UART_REC_TYPE Uart2;

/**************************************
函数名： uint8_t USART2_RecService(void)
说  明： 串口2接收服务程序，判断数据有没有接收完
参  数： 无
返回值： 1：接收完成		0：接收未完成或无数据
**************************************/
uint8_t USART2_RecService(void)		
{
	static uint16_t USART2_RecLen_Last=0;
	if(Uart2.RecCount)					//串口已有接收,至少进入过一次串口接收中断
	{
//		#if Freertos_EN == 0		//等待2ms,波特率9600
//		HAL_Delay(2);
//		#endif
//		#if Freertos_EN == 1
//		osDelay(2);
//		#endif
		if(USART2_RecLen_Last == Uart2.RecCount)	//判断接收数据长度是否与上次循环相等，如果相等则代表接收完成
		{
			Uart2.LastLen = Uart2.RecCount;					//获取接收长度
			Uart2.RecCount = 0;											//重新从Buff[0]开始接收
			for(uint16_t i=0;i<Uart2.LastLen;i++)  USART2_UserBuffer[i] = USART2_Buffer[i];		//替换Buffer，接收Buffer仍然作为接收中断内使用			
			return 1;		
		}
		else USART2_RecLen_Last = Uart2.RecCount;
	}
	return 0;
}
#endif

#if USART3_EN
unsigned char USART3_UserBuffer[USART3_RXBUF_LEN];
unsigned char USART3_Buffer[USART3_RXBUF_LEN];
struct UART_REC_TYPE Uart3;

/**************************************
函数名： uint8_t USART3_RecService(void)
说  明： 串口3接收服务程序，判断数据有没有接收完
参  数： 无
返回值： 1：接收完成		0：接收未完成或无数据
**************************************/
uint8_t USART3_RecService(void)		
{
	static uint16_t USART3_RecLen_Last=0;
	if(Uart3.RecCount)					//串口已有接收,至少进入过一次串口接收中断
	{		
//		#if Freertos_EN == 0		//等待2ms,波特率9600
//		HAL_Delay(2);
//		#endif
//		#if Freertos_EN == 1
//		osDelay(2);
//		#endif
		if(USART3_RecLen_Last == Uart3.RecCount)	//判断接收数据长度是否与上次循环相等，如果相等则代表接收完成
		{
			Uart3.LastLen = Uart3.RecCount;					//获取接收长度
			Uart3.RecCount = 0;											//重新从Buff[0]开始接收
			for(uint16_t i=0;i<Uart3.LastLen;i++)  USART3_UserBuffer[i] = USART3_Buffer[i];		//替换Buffer，接收Buffer仍然作为接收中断内使用			
			return 1;		
		}
		else USART3_RecLen_Last = Uart3.RecCount;
	}
	return 0;
}
#endif

#if USART4_EN
unsigned char USART4_UserBuffer[USART4_RXBUF_LEN];
unsigned char USART4_Buffer[USART4_RXBUF_LEN];
struct UART_REC_TYPE Uart4;

/**************************************
函数名： uint8_t USART4_RecService(void)
说  明： 串口4接收服务程序，判断数据有没有接收完
参  数： 无
返回值： 1：接收完成		0：接收未完成或无数据
**************************************/
uint8_t USART4_RecService(void)		
{
	static uint16_t USART4_RecLen_Last=0;
	if(Uart4.RecCount)					//串口已有接收,至少进入过一次串口接收中断
	{		
//		#if Freertos_EN == 0		//等待1ms,波特率115200
//		HAL_Delay(2);
//		#endif
//		#if Freertos_EN == 1
//		osDelay(2);
//		#endif
		if(USART4_RecLen_Last == Uart4.RecCount)	//判断接收数据长度是否与上次循环相等，如果相等则代表接收完成
		{
			Uart4.LastLen = Uart4.RecCount;					//获取接收长度
			Uart4.RecCount = 0;											//重新从Buff[0]开始接收
			for(uint16_t i=0;i<Uart4.LastLen;i++)  USART4_UserBuffer[i] = USART4_Buffer[i];		//替换Buffer，接收Buffer仍然作为接收中断内使用			
			return 1;		
		}
		else USART4_RecLen_Last = Uart4.RecCount;
	}
	return 0;
}
#endif

#if USART5_EN
unsigned char USART5_UserBuffer[USART5_RXBUF_LEN];
unsigned char USART5_Buffer[USART5_RXBUF_LEN];
struct UART_REC_TYPE Uart5;

/**************************************
函数名： uint8_t USART5_RecService(void)
说  明： 串口5接收服务程序，判断数据有没有接收完
参  数： 无
返回值： 1：接收完成		0：接收未完成或无数据
**************************************/
uint8_t USART5_RecService(void)		
{
	static uint16_t USART5_RecLen_Last=0;
	if(Uart5.RecCount)					//串口已有接收,至少进入过一次串口接收中断
	{
//		#if Freertos_EN == 0		//等待1ms,波特率115200
//		HAL_Delay(2);
//		#endif
//		#if Freertos_EN == 1
//		osDelay(2);
//		#endif
		if(USART5_RecLen_Last == Uart5.RecCount)	//判断接收数据长度是否与上次循环相等，如果相等则代表接收完成
		{
			Uart5.LastLen = Uart5.RecCount;					//获取接收长度
			Uart5.RecCount = 0;											//重新从Buff[0]开始接收
			for(uint16_t i=0;i<Uart5.LastLen;i++)  USART5_UserBuffer[i] = USART5_Buffer[i];		//替换Buffer，接收Buffer仍然作为接收中断内使用			
			return 1;		
		}
		else	USART5_RecLen_Last = Uart5.RecCount;
	}
	return 0;
}
#endif

#if USART6_EN
unsigned char USART6_UserBuffer[USART2_RXBUF_LEN];
unsigned char USART6_Buffer[USART2_RXBUF_LEN];
struct UART_REC_TYPE Uart6;

/**************************************
函数名： uint8_t USART6_RecService(void)
说  明： 串口6接收服务程序，判断数据有没有接收完
参  数： 无
返回值： 1：接收完成		0：接收未完成或无数据
**************************************/
uint8_t USART6_RecService(void)		
{
	static uint16_t USART6_RecLen_Last=0;
	if(Uart6.RecCount)					//串口已有接收,至少进入过一次串口接收中断
	{
//		#if Freertos_EN == 0		//等待1ms,波特率115200
//		HAL_Delay(2);
//		#endif
//		#if Freertos_EN == 1
//		osDelay(2);
//		#endif
		if(USART6_RecLen_Last == Uart6.RecCount)	//判断接收数据长度是否与上次循环相等，如果相等则代表接收完成
		{
			Uart6.LastLen = Uart6.RecCount;					//获取接收长度
			Uart6.RecCount = 0;											//重新从Buff[0]开始接收
			for(uint16_t i=0;i<Uart6.LastLen;i++)  USART6_UserBuffer[i] = USART6_Buffer[i];		//替换Buffer，接收Buffer仍然作为接收中断内使用			
			return 1;		
		}
		else USART6_RecLen_Last = Uart6.RecCount;
	}
	return 0;
}
#endif

/**************************************
函数名： void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
说  明： 串口接收中断回调函数，不需要我们自己调用
				 当发生串口接收中断的时候，系统会自动调用这个函数
				 前提是要打开接收：	HAL_UART_Receive_IT();
参  数： *huart
返回值： 无
**************************************/
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	#if USART1_EN
	if(huart == &huart1)		//串口1的接收中断
	{
		//接收完的数据就可以在这里处理了	
		USART1_Buffer[Uart1.RecCount] = Uart1.RecOneByte;
		Uart1.RecCount++;
		if(Uart1.RecCount >= USART1_RXBUF_LEN)  Uart1.RecCount=0;		//不能大于接收数组的大小
		HAL_UART_Receive_IT(&huart1,&Uart1.RecOneByte,1);						//重新打开接收	
	}
	#endif
	
	#if USART2_EN
	if(huart == &huart2)		//串口2的接收中断
	{
		//接收完的数据就可以在这里处理了	
		USART2_Buffer[Uart2.RecCount] = Uart2.RecOneByte;
		Uart2.RecCount++;
		if(Uart2.RecCount >= USART2_RXBUF_LEN)  Uart2.RecCount=0;		//不能大于接收数组的大小
		HAL_UART_Receive_IT(&huart2,&Uart2.RecOneByte,1);						//重新打开接收	
	}
	#endif
	
	#if USART3_EN
	if(huart == &huart3)		//串口3的接收中断
	{
		//接收完的数据就可以在这里处理了	
		USART3_Buffer[Uart3.RecCount] = Uart3.RecOneByte;
		Uart3.RecCount++;
		if(Uart3.RecCount >= USART3_RXBUF_LEN)  Uart3.RecCount=0;		//不能大于接收数组的大小
		HAL_UART_Receive_IT(&huart3,&Uart3.RecOneByte,1);						//重新打开接收	
	}
	#endif
	
	#if USART4_EN
	if(huart == &huart4)		//串口4的接收中断
	{
		//接收完的数据就可以在这里处理了	
		USART4_Buffer[Uart4.RecCount] = Uart4.RecOneByte;
		Uart4.RecCount++;
		if(Uart4.RecCount >= USART4_RXBUF_LEN)	Uart4.RecCount=0;		//不能大于接收数组的大小
		HAL_UART_Receive_IT(&huart4,&Uart4.RecOneByte,1);						//重新打开接收	
	}
	#endif
	
	#if USART5_EN
	if(huart == &huart5)		//串口5的接收中断
	{
		//接收完的数据就可以在这里处理了	
		USART5_Buffer[Uart5.RecCount] = Uart5.RecOneByte;
		Uart5.RecCount++;
		if(Uart5.RecCount >= USART5_RXBUF_LEN)	Uart5.RecCount=0;		//不能大于接收数组的大小
		HAL_UART_Receive_IT(&huart5,&Uart5.RecOneByte,1);						//重新打开接收	
	}
	#endif
	
	#if USART6_EN
	if(huart == &huart6)		//串口6的接收中断
	{
		//接收完的数据就可以在这里处理了	
		USART6_Buffer[Uart6.RecCount] = Uart6.RecOneByte;
		Uart6.RecCount++;
		if(Uart6.RecCount >= USART6_RXBUF_LEN)	Uart6.RecCount=0;		//不能大于接收数组的大小
		HAL_UART_Receive_IT(&huart6,&Uart6.RecOneByte,1);						//重新打开接收	
	}
	#endif
}
