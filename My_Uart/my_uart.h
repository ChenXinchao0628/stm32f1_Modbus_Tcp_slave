#ifndef __MY_USART_H_
#define __MY_USART_H_	



//特别注意：
//1.CubeMX配置时要打开串口中断
//2.在主循环需要调用	HAL_UART_Receive_IT(&huartx,&Uartx.RecOneByte,1)	才能进入中断	
//3.波特率低于9600时（或调用函数的间隔太短/小于1ms），需要做另外调整
//4.CubeMX配置时，NVIC - select for init sequence ordering 要打开

//API: 
//HAL_UART_Receive_IT(&huartx,&Uartx.RecOneByte,1);		//开启一次接收，需要放在串口初始化后，循环开始前
//uint8_t USART1_RecService(void);										//串口服务函数，用于查询串口接收是否完成，应该放在循环查询，且查询间隔不能小于1ms(见特别注意第三点)	
//用户可使用的参数：		Uartx.LastLen: 接收数据的长度		USART1_UserBuffer[]: 存放接收数据的数组

#define Freertos_EN			0			//使用FreeRTOS：1		不使用：0  
#define USART1_EN				1			//使用串口：1				不使用：0
#define USART2_EN				0			//使用串口：1				不使用：0
#define USART3_EN				0			//使用串口：1				不使用：0
#define USART4_EN				0			//使用串口：1				不使用：0
#define USART5_EN				0			//使用串口：1				不使用：0
#define USART6_EN				0			//使用串口：1				不使用：0
		
#define USART1_RXBUF_LEN 100	//定义串口接收Buffer长度
#define USART2_RXBUF_LEN 100
#define USART3_RXBUF_LEN 50
#define USART4_RXBUF_LEN 50
#define USART5_RXBUF_LEN 100
#define USART6_RXBUF_LEN 100

extern unsigned char USART1_Buffer[USART1_RXBUF_LEN];
extern unsigned char USART1_UserBuffer[USART1_RXBUF_LEN];

extern unsigned char USART2_UserBuffer[USART2_RXBUF_LEN];
extern unsigned char USART2_Buffer[USART2_RXBUF_LEN];

extern unsigned char USART3_Buffer[USART3_RXBUF_LEN];
extern unsigned char USART3_UserBuffer[USART3_RXBUF_LEN];

extern unsigned char USART4_Buffer[USART4_RXBUF_LEN];
extern unsigned char USART4_UserBuffer[USART4_RXBUF_LEN];

extern unsigned char USART5_Buffer[USART5_RXBUF_LEN];
extern unsigned char USART5_UserBuffer[USART5_RXBUF_LEN];

extern unsigned char USART6_Buffer[USART6_RXBUF_LEN];
extern unsigned char USART6_UserBuffer[USART6_RXBUF_LEN];

unsigned char USART1_RecService(void);
unsigned char USART2_RecService(void);
unsigned char USART3_RecService(void);	
unsigned char USART4_RecService(void);		
unsigned char USART5_RecService(void);
unsigned char USART6_RecService(void);

struct UART_REC_TYPE
{
	unsigned char  RecOneByte;		//用于中断接收
	unsigned short int RecCount;	//数据长度
	unsigned short int LastLen;		//上一次的数据长度用于判断接收完成
};

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);

extern struct UART_REC_TYPE Uart1,Uart2,Uart3,Uart4,Uart5,Uart6;

#endif
