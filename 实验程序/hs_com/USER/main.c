#include "stm32f10x.h"

//void USART_Init(); //���ڳ�ʼ���������ʣ������ֳ�����żУ�飬Ӳ�������Լ��շ�ʹ��
//void USART_Cmd();//ʹ�ܴ���
//void USART_ITConfig();//ʹ������ж�

//void USART_SendData();//�������ݵ����ڣ�DR
//uint16_t USART_ReceiveData();//�������ݣ���DR��ȡ���ܵ�������

//FlagStatus USART_GetFlagStatus();//��ȡ״̬��־λ
//void USART_ClearFlag();//���״̬��־λ
//ITStatus USART_GetITStatus();//��ȡ�ж�״̬��־λ
//void USART_ClearITPendingBit();//����ж�״̬��־λ

//1������ʱ��ʹ�ܣ�GPIOʱ��ʹ��:RCC_APB2PeriphClockCmd();
//2�����ڸ�λ:USART_DeInit(); ��һ�����Ǳ����
//3��GPIO�˿�ģʽ����:GPIO_Init(); 
//4�����ڲ�����ʼ����USART_Init();
//5�������жϲ��ҳ�ʼ��NVIC�������Ҫ�����жϲ���Ҫ������裩
//      NVIC_Init();
//      USART_ITConfig();
//6��ʹ�ܴ���:USART_Cmd();
//7����д�жϴ�������USARTx_IRQHandler();
//8�����������շ���
//void USART_SendData();//�������ݵ����ڣ�DR
//uint16_t USART_ReceiveData();//�������ݣ���DR��ȡ���ܵ�������
//9�����ڴ���״̬��ȡ��
//FlagStatus USART_GetFlagStatus(USART_TypeDef* USARTx, uint16_t USART_FLAG);
//void USART_ClearITPendingBit(USART_TypeDef* USARTx, uint16_t USART_IT);



