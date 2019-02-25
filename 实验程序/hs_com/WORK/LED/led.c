#include "stm32f10x.h"
#include "led.h"

void LED_Init()
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOD,ENABLE);//ʹ��GPIOA��GPIODʱ��
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;//��������������ǿ�ߵͣ�
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	GPIO_SetBits(GPIOA,GPIO_Pin_8);

	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;//��������������ǿ�ߵͣ�
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOD,&GPIO_InitStructure);
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

