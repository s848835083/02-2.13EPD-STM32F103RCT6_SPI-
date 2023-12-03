//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//�о�԰����
//���̵�ַ��http://shop73023976.taobao.com
//
//  �� �� ��   : main.c
//  �� �� ��   : v2.0
//  ��    ��   : HuangKai
//  ��������   : 2018-10-31
//  ����޸�   : 
//  ��������   : OLED I2C�ӿ���ʾ����(STM32F103ϵ��)
//              ˵��: 
//              ----------------------------------------------------------------
//              GND  ��Դ��
//              VCC  3.3v��Դ
//              D0   PA5��SCL��
//              D1   PA7��SDA��
//              RES  PD2
//              DC   PB5
//              CS   PA4  
//							BUSY PB6
//              ----------------------------------------------------------------
// �޸���ʷ   :
// ��    ��   : 
// ��    ��   : HuangKai
// �޸�����   : �����ļ�
//��Ȩ���У�����ؾ���
//Copyright(C) �о�԰����2018-10-31
//All rights reserved
//******************************************************************************/
#include "delay.h"
#include "sys.h"
#include "oled.h"
#include "bmp.h"

u8  Image_BW[4000];

//��Ļд������0ʱΪ��ɫ д������1ʱΪ��ɫ
//��Ļ�ֱ���Ϊ250X122 ����һ���ֽڿ���8�����ص�ĵ�����������OLED_WֵΪ128
//�ڰ׵���ֽ��Ļ֧�־ֲ�ˢ��;���Ǿֲ�ˢ����Ч�������ã����׳��ֲ�Ӱ;������ʹ��
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
	  OLED_ShowChinese(38,0,0,16,BLACK);//��
		OLED_ShowChinese(54,0,1,16,BLACK);//��
		OLED_ShowChinese(70,0,2,16,BLACK);//԰
		OLED_ShowChinese(86,0,3,16,BLACK);//��
		OLED_ShowChinese(102,0,4,16,BLACK);//��
		OLED_ShowChinese(118,0,5,16,BLACK);//��
		OLED_ShowChinese(134,0,6,16,BLACK);//��
		OLED_ShowChinese(150,0,7,16,BLACK);//��
		OLED_ShowChinese(166,0,8,16,BLACK);//��
		OLED_ShowChinese(182,0,9,16,BLACK);//��
		OLED_ShowChinese(198,0,10,16,BLACK);//˾
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

