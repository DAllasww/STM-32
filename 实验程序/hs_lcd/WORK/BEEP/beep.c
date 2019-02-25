#include "stm32f10x.h"
#include "beep.h"

void BEEP_Init()
{
  GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);//使能GPIOA和GPIOD时钟
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;//推挽输出（可输出强高低）
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC,&GPIO_InitStructure);
	
	GPIO_ResetBits(GPIOC,GPIO_Pin_1);//输出0，关闭蜂鸣器输出
}

