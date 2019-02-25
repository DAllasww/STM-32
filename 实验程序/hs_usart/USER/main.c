#include "stm32f10x.h"
#include "sys.h"

//void USART_Init(); //���ڳ�ʼ���������ʣ������ֳ�����żУ�飬Ӳ�������Լ��շ�ʹ��
//void USART_Cmd();//ʹ�ܴ���
//void USART_ITConfig();//ʹ������ж�

//void USART_SendData();//�������ݵ����ڣ�DR
//uint16_t USART_ReceiveData();//�������ݣ���DR��ȡ���ܵ�������

//FlagStatus USART_GetFlagStatus();//��ȡ״̬��־λ
//void USART_ClearFlag();//���״̬��־λ
//ITStatus USART_GetITStatus();//��ȡ�ж�״̬��־λ
//void USART_ClearITPendingBit();//����ж�״̬��־λ

void My_Usart1_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);//GPIOAʱ��ʹ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);//����ʱ��ʹ��
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;//�������
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;//������������������ǿ�ߵͣ�
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;//��������
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//�������루�����ǿ�ߵͣ�
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	USART_InitStructure.USART_BaudRate = 115200;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_Init(USART1, &USART_InitStructure);//���ڳ�ʼ��
	
	USART_Cmd(USART1, ENABLE);//����ʹ��
	
	USART_ITConfig(USART1,USART_IT_RXNE, ENABLE);//�򿪽����ж�
	
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&NVIC_InitStructure);//�ж����ȼ�����
}

void USART1_IRQHandler(void)//�жϷ�����
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

