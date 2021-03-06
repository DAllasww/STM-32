#include "beep.h"
#include "stm32f10x.h"

void BEEP_Init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);//使能	 
	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_8;//端口配置
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;//推挽输出
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;//速度
	GPIO_Init(GPIOB,&GPIO_InitStructure);//初始化
	GPIO_ResetBits(GPIOB,GPIO_Pin_8);//输出0，关闭蜂鸣器输出
	
}
