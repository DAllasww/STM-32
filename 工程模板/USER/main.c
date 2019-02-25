#include "stm32f10x.h"
#include "led.h"
#include "delay.h"
//#include "beep.h"
//#include "key.h"

int main(void)
{
	LED_Init();
	delay_init();
//	BEEP_Init();
//	KEY_Init();
	
	while(1)
	{
//		GPIO_ResetBits(GPIOB,GPIO_Pin_5);
//		delay_ms(100);
//		GPIO_ResetBits(GPIOE,GPIO_Pin_5);
//		delay_ms(100);
//		GPIO_SetBits(GPIOB,GPIO_Pin_5);
//		delay_ms(100);
//		GPIO_SetBits(GPIOE,GPIO_Pin_5);
//		delay_ms(100);
		
//		GPIOB->ODR |= 1<<5;
//		GPIOE->ODR |= 1<<5;
//		delay_ms(100);
//		
//		GPIOB->ODR |=~ (1<<5);
//		GPIOE->ODR |=~ (1<<5);
//		delay_ms(100);

		PAout(8) = 1;
		PDout(2) = 1;
//		BEEP = 1;
		delay_ms(500);
		
		PAout(8) = 0;
		PDout(2) = 0;
//		BEEP = 1;
		delay_ms(500);
	}
}

