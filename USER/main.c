//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//中景园电子
//店铺地址：http://shop73023976.taobao.com
//
//  文 件 名   : main.c
//  版 本 号   : v2.0
//  作    者   : HuangKai
//  生成日期   : 2018-10-31
//  最近修改   : 
//  功能描述   : OLED I2C接口演示例程(STM32F103系列)
//              说明: 
//              ----------------------------------------------------------------
//              GND  电源地
//              VCC  3.3v电源
//              D0   PA5（SCL）
//              D1   PA7（SDA）
//              RES  PD2
//              DC   PB5
//              CS   PA4  
//							BUSY PB6
//              ----------------------------------------------------------------
// 修改历史   :
// 日    期   : 
// 作    者   : HuangKai
// 修改内容   : 创建文件
//版权所有，盗版必究。
//Copyright(C) 中景园电子2018-10-31
//All rights reserved
//******************************************************************************/
#include "delay.h"
#include "sys.h"
#include "oled.h"
#include "bmp.h"

u8  Image_BW[4000];

//屏幕写入数据0时为黑色 写入数据1时为白色
//屏幕分辨率为250X122 由于一个字节控制8个像素点的点亮所以设置OLED_W值为128
//黑白电子纸屏幕支持局部刷新;但是局部刷屏的效果不够好，容易出现残影;不建议使用
int main()
{
	u8 t=' ';
  delay_init();
	OLED_GUIInit();
  Paint_NewImage(Image_BW,OLED_W,OLED_H,0,WHITE); 
  OLED_Clear(WHITE);	
	while(1)
	{
	  OLED_GUIInit();
		OLED_ShowPicture(0,0,250,122,gImage_2,BLACK);	
		OLED_Display(Image_BW);
		delay_ms(1000);		
		delay_ms(1000);		
		delay_ms(1000);
		OLED_Clear(WHITE);	
		OLED_GUIInit();
	  OLED_ShowChinese(38,0,0,16,BLACK);//中
		OLED_ShowChinese(54,0,1,16,BLACK);//景
		OLED_ShowChinese(70,0,2,16,BLACK);//园
		OLED_ShowChinese(86,0,3,16,BLACK);//电
		OLED_ShowChinese(102,0,4,16,BLACK);//子
		OLED_ShowChinese(118,0,5,16,BLACK);//技
		OLED_ShowChinese(134,0,6,16,BLACK);//术
		OLED_ShowChinese(150,0,7,16,BLACK);//有
		OLED_ShowChinese(166,0,8,16,BLACK);//限
		OLED_ShowChinese(182,0,9,16,BLACK);//公
		OLED_ShowChinese(198,0,10,16,BLACK);//司
		OLED_ShowString(85,20,"2014/05/01",16,BLACK);
		OLED_ShowString(57,40,"ASCII:",16,BLACK);  
		OLED_ShowString(134,40,"CODE:",16,BLACK);
		OLED_ShowChar(108,40,t,16,BLACK); 
		OLED_ShowNum(175,40,t,3,16,BLACK);
		t++;
		if(t>'~')t=' ';	
		OLED_ShowString(10,56,"Welcome to 2.13-inch E-paper",16,BLACK);		
		OLED_ShowString(26,73,"with 250 x 122 resolution",16,BLACK);	
    OLED_DrawLine(1,89,250,89,BLACK);		
		OLED_ShowString(30,90,"Zhongjingyuan Electronic",16,BLACK);
		OLED_ShowString(52,106,"Technology Co.,Ltd.",16,BLACK);		
		OLED_Display(Image_BW);
		delay_ms(1000);		
		delay_ms(1000);		
		delay_ms(1000);
		OLED_GUIInit();
    OLED_DrawRectangle(1,1,250,122,BLACK,0);
		OLED_Display(Image_BW);
		delay_ms(1000);		
		delay_ms(1000);		
		delay_ms(1000);
		OLED_Clear(WHITE);	
	}
}

