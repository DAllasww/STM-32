#include "stm32f10x.h"
#include "sys.h"

//void USART_Init(); //串口初始化：波特率，数据字长，奇偶校验，硬件流控以及收发使能
//void USART_Cmd();//使能串口
//void USART_ITConfig();//使能相关中断

//void USART_SendData();//发送数据到串口，DR
//uint16_t USART_ReceiveData();//接受数据，从DR读取接受到的数据

//FlagStatus USART_GetFlagStatus();//获取状态标志位
//void USART_ClearFlag();//清除状态标志位
//ITStatus USART_GetITStatus();//获取中断状态标志位
//void USART_ClearITPendingBit();//清除中断状态标志位

void My_Usart1_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);//GPIOA时钟使能
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);//串口时钟使能
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;//串口输出
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;//复用推挽输出（可输出强高低）
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;//串口输入
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//浮空输入（可输出强高低）
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	USART_InitStructure.USART_BaudRate = 115200;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_Init(USART1, &USART_InitStructure);//串口初始化
	
	USART_Cmd(USART1, ENABLE);//串口使能
	
	USART_ITConfig(USART1,USART_IT_RXNE, ENABLE);//打开接收中断
	
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&NVIC_InitStructure);//中断优先级设置
}

void USART1_IRQHandler(void)//中断服务函数
{
	u8 res;
	
  if(USART_GetITStatus(USART1, USART_IT_RXNE))
	{
	  res = USART_ReceiveData(USART1);
		USART_SendData(USART1, res);
	}
}

int main(void)
{
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	My_Usart1_Init();
	
	while(1);
	
}

