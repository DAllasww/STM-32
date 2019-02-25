#include "stm32f10x.h"
#include "led.h"

void LED_Init()
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOD,ENABLE);//使能GPIOA和GPIOD时钟
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;//推挽输出（可输出强高低）
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	GPIO_SetBits(GPIOA,GPIO_Pin_8);

	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;//推挽输出（可输出强高低）
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOD,&GPIO_InitStructure);
	GPIO_SetBits(GPIOD,GPIO_Pin_2);
}









//void LED_Init(void)
//{
//	RCC->APB2ENR |= 1<<3; 
//	RCC->APB2ENR |= 1<<6;

//  GPIOB->CRL &= 0xff0fffff;//需要改变的4位先进行清0
//	GPIOB->CRL |= 0x00300000;//接着将这需要改变的4位进行赋值
//	GPIOB->ODR |= 1<<5;
//	
//	GPIOE->CRL &= 0xff0fffff;//需要改变的4位先进行清0
//	GPIOE->CRL |= 0x00300000;//接着将这需要改变的4位进行赋值
//	GPIOE->ODR |= 1<<5;
//}

