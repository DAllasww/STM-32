#include "led.h"
#include "stm32f10x.h"

void LED_Init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);//ʹ��	 
	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_8;//�˿�����
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;//�������
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;//�ٶ�
	GPIO_Init(GPIOB,&GPIO_InitStructure);//��ʼ��
	GPIO_SetBits(GPIOA,GPIO_Pin_8);
	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOE,&GPIO_InitStructure);
	GPIO_SetBits(GPIOD,GPIO_Pin_2);
	
}













//void LED_Init(void)
//{
//	RCC->APB2ENR |= 1<<3; 
//	RCC->APB2ENR |= 1<<6;

//  GPIOB->CRL &= 0xff0fffff;//��Ҫ�ı��4λ�Ƚ�����0
//	GPIOB->CRL |= 0x00300000;//���Ž�����Ҫ�ı��4λ���и�ֵ
//	GPIOB->ODR |= 1<<5;
//	
//	GPIOE->CRL &= 0xff0fffff;//��Ҫ�ı��4λ�Ƚ�����0
//	GPIOE->CRL |= 0x00300000;//���Ž�����Ҫ�ı��4λ���и�ֵ
//	GPIOE->ODR |= 1<<5;
//}

