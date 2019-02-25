#include "stm32f10x.h"
#include "led.h"
#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "lcd.h"

 int main(void)
 { 
	u8 x = 0;
	u8 lcd_id[12];			//存放LCD ID字符串	
	 
	delay_init();	    	 //延时函数初始化	  
	uart_init(9600);	 	//串口初始化为9600
	LED_Init();		  		//初始化与LED连接的硬件接口
 	LCD_Init();
	 
	POINT_COLOR = RED; 
//	sprintf((char*)lcd_id,"LCD ID:%04X",lcddev.id);//将LCD ID打印到lcd_id数组。		
	LCD_Clear(WHITE);
	 
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
		
		LCD_DisplayOn();
		POINT_COLOR = RED;	  
		LCD_ShowString(0,0,200,24,16,"WangHuaishuai");	
// 		LCD_ShowString(30,110,200,16,16,lcd_id);		//显示LCD ID	      					 
	      					 
//	  x++;
//		if(x==12)x=0;
 
		delay_ms(3000);	
}

}
