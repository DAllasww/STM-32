#include "key.h"
#include "stm32f10x.h"

void KEY_Init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOE,ENABLE);//使能	 
	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_4|GPIO_Pin_3;//端口配置
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;//上拉输出
	GPIO_Init(GPIOE,&GPIO_InitStructure);//初始化
	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPD;//下拉输出
	GPIO_Init(GPIOA,&GPIO_InitStructure);
}






//mode:0,不支持连续按；1,支持连续按；
//0,没有任何按键按下
//1,KEY0按下
//2,KEY1按下
//3,KEY2按下
//4,WK_UP按下
//注意此函数有响应优先级:KKEY0>KEY1>KEY2>WK_UP
u8 KEY_Scan(u8 mode)
{
	static u8 key_up = 1;//按键松开标志
	if(mode == 1)key_up = 1;//支持连续按下
	if(key_up&&(KEY0 == 0||KEY1 == 0||WK_UP == 1))
	{
		delay_ms(10);//去抖动
		key_up = 0;
		if(KEY0 == 0)return KEY0_PRES;
		else if(KEY1 == 0)return KEY1_PRES;
		else if(WK_UP == 1)return WKUP_PRES;
	}else if(KEY0 == 1&&KEY1 == 1&&WK_UP == 0)key_up = 1;
	return 0;//无按键按下
}

