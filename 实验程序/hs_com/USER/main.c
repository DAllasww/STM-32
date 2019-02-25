#include "stm32f10x.h"

//void USART_Init(); //串口初始化：波特率，数据字长，奇偶校验，硬件流控以及收发使能
//void USART_Cmd();//使能串口
//void USART_ITConfig();//使能相关中断

//void USART_SendData();//发送数据到串口，DR
//uint16_t USART_ReceiveData();//接受数据，从DR读取接受到的数据

//FlagStatus USART_GetFlagStatus();//获取状态标志位
//void USART_ClearFlag();//清除状态标志位
//ITStatus USART_GetITStatus();//获取中断状态标志位
//void USART_ClearITPendingBit();//清除中断状态标志位

//1、串口时钟使能，GPIO时钟使能:RCC_APB2PeriphClockCmd();
//2、串口复位:USART_DeInit(); 这一步不是必须的
//3、GPIO端口模式设置:GPIO_Init(); 
//4、串口参数初始化：USART_Init();
//5、开启中断并且初始化NVIC（如果需要开启中断才需要这个步骤）
//      NVIC_Init();
//      USART_ITConfig();
//6、使能串口:USART_Cmd();
//7、编写中断处理函数：USARTx_IRQHandler();
//8、串口数据收发：
//void USART_SendData();//发送数据到串口，DR
//uint16_t USART_ReceiveData();//接受数据，从DR读取接受到的数据
//9、串口传输状态获取：
//FlagStatus USART_GetFlagStatus(USART_TypeDef* USARTx, uint16_t USART_FLAG);
//void USART_ClearITPendingBit(USART_TypeDef* USARTx, uint16_t USART_IT);



