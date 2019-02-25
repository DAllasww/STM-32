#include "stm32f10x.h"
#include "delay.h"
#include "led.h"
#include "beep.h"
#include "key.h"
#include "lcd.h"
#include "sys.h"
#include "usart.h"


int main(void)
{	
//  uint8_t t=0;
  u8 x = 0; 
  u8 lcd_id[12];//存放LCD的ID字符串
 	
  //LED_Init();
	//BEEP_Init();
	//KEY_Init();
	LCD_Init();
  delay_init();
	uart_init(9600);	 	//串口初始化为9600
	
	LCD_DisplayOn();
//	LCD_Clear(RED);
	POINT_COLOR = RED;
	sprintf((char*)lcd_id,"LCD ID:%04X",lcddev.id);//将LCD ID打印到lcd_id数组。
	
	while(1)
	{
	  switch(x)
		{
			case 0:LCD_Clear(WHITE);break;
			case 1:LCD_Clear(BLACK);break;
			case 2:LCD_Clear(BLUE);break;
			case 3:LCD_Clear(RED);break;
			case 4:LCD_Clear(MAGENTA);break;
			case 5:LCD_Clear(GREEN);break;
			case 6:LCD_Clear(CYAN);break;

			case 7:LCD_Clear(YELLOW);break;
			case 8:LCD_Clear(BRRED);break;
			case 9:LCD_Clear(GRAY);break;
			case 10:LCD_Clear(LGRAY);break;
			case 11:LCD_Clear(BROWN);break;
		}
		POINT_COLOR = RED;		
    x++;		
		if(x>11)x=0;
//		LCD_ShowString(30,40,200,24,24,"WangHuaishuai");
    LCD_ShowString(30,110,200,16,16,lcd_id);		//显示LCD ID		
		delay_ms(500);	
	}

	
//  while(1)
//	{
//	  GPIO_ResetBits(GPIOA,GPIO_Pin_8);
//	  GPIO_ResetBits(GPIOD,GPIO_Pin_2);
//		PAout(8) = 0;
//		PDout(2) = 0;
//		PCout(5) = 0;
//		delay_ms(500);
//		GPIO_SetBits(GPIOA,GPIO_Pin_8);
//		GPIO_SetBits(GPIOD,GPIO_Pin_2);
//		PAout(8) = 1;
//		PDout(2) = 1;
//		PCout(5) = 1;
//		delay_ms(500);
//	}
	
	
//	while(1)
//	{
//		t=KEY_Scan(1);		//得到键值
//		switch(t)
//		{				 
//			case KEY0_PRES:
//				PAout(8) = 0;
//			  delay_ms(300);
//				PAout(8) = 1;
//				break;
//			case KEY1_PRES:
//				PDout(2) = 0;
//			  delay_ms(300);
//			  PDout(2) = 1;
//				break;
//			case WKUP_PRES:				
//	      PAout(8) = 0;
//	      PDout(2) = 0;
//			  delay_ms(500);
//				PAout(8) = 1;
//	      PDout(2) = 1;
//				break;
//			default:
//				delay_ms(10);	
//		} 
//	}		 
 }

