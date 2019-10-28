#include "OLED.H"

/*
*********************************************************************************************************
*	函 数 名: OLED_WR_Byte
*	功能说明: OLED写数据-命令
*	形    参：Data->数据
*           Cmd ->命令
*	返 回 值: 无
*********************************************************************************************************
*/
void OLED_WR_Byte(uchar Data,uchar Cmd)
{
	uchar i;
	
	if(Cmd==1)
	  OLED_DC_H;
	else
	  OLED_DC_L;
	  
	OLED_CS_L;
	
	for(i=0;i<8;i++)
	{
		OLED_SCLK_L;
		
		if(Data&0x80)
			{
		   OLED_SDIN_H;
			}
    else
		  {
		   	OLED_SDIN_L;
		  }
		  
		OLED_SCLK_H;
		Data<<=1;
	}
	
	OLED_CS_H;
	OLED_DC_H;
}

/*
*********************************************************************************************************
*	函 数 名: OLED_Set_Pos
*	功能说明: 设置行列地址
*	形    参：X->行地址
*           Y->列地址
*	返 回 值: 无
*********************************************************************************************************
*/
void OLED_Set_Pos(uchar X, uchar Y)
{
	OLED_WR_Byte(0xb0+Y,OLED_CMD);
	OLED_WR_Byte(((X&0xf0)>>4)|0x10,OLED_CMD);
	OLED_WR_Byte((X&0x0f)|0x01,OLED_CMD);
}

/*
*********************************************************************************************************
*	函 数 名: OLED_Display_On
*	功能说明: OLED显示-开启
*	形    参：无
*	返 回 值: 无
*********************************************************************************************************
*/
void OLED_Display_On(void)
{
	OLED_WR_Byte(0X8D,OLED_CMD);  //SET DCDC命令
	OLED_WR_Byte(0X14,OLED_CMD);  //DCDC ON
	OLED_WR_Byte(0XAF,OLED_CMD);  //显示-开启
}

/*
*********************************************************************************************************
*	函 数 名: OLED_Display_Off
*	功能说明: OLED显示-关闭
*	形    参：无
*	返 回 值: 无
*********************************************************************************************************
*/
void OLED_Display_Off(void)
{
	OLED_WR_Byte(0X8D,OLED_CMD);  //SET DCDC命令
	OLED_WR_Byte(0X10,OLED_CMD);  //DCDC OFF
	OLED_WR_Byte(0XAE,OLED_CMD);  //显示-关闭
}

/*
*********************************************************************************************************
*	函 数 名: OLED_Clear
*	功能说明: OLED-清屏
*	形    参：无
*	返 回 值: 无
*********************************************************************************************************
*/
void OLED_Clear(void)
{
	uchar i,n;
	
	for(i=0;i<8;i++)
	{
		OLED_WR_Byte (0xb0+i,OLED_CMD);  //设置页地址（0~7）
		OLED_WR_Byte (0x00,OLED_CMD);    //设置显示位置?列低地址
		OLED_WR_Byte (0x10,OLED_CMD);    //设置显示位置?列高地址
		for(n=0;n<128;n++)
		{
			OLED_WR_Byte(0,OLED_DATA);
		}
	} 
}
/**************************实现函数********************************************
*函数原型:		disn(unsigned char X,unsigned char Y,unsigned char n);
*功　　能:		数字。
*******************************************************************************/
/*
*********************************************************************************************************
*	函 数 名: OLED_Clear
*	功能说明: OLED-清屏
*	形    参：无
*	返 回 值: 无
*********************************************************************************************************
*/
void OLED_Display(uchar X,uchar Y,uchar n)
{
	uchar m;
	
	OLED_WR_Byte(0xb7-(Y<<1),OLED_CMD);
	if(X%2)
		OLED_WR_Byte(0x08,OLED_CMD);
	else
		OLED_WR_Byte(0x00,OLED_CMD);
		
	OLED_WR_Byte(0x10+(X>>1),OLED_CMD);
	for(m=0;m<=15;m+=2)
	{
		OLED_WR_Byte(*(FONT16X16[n-0x20]+m),OLED_DATA);
  }
  
	OLED_WR_Byte(0xb7-(Y<<1)-1,OLED_CMD);
	if(X%2)
		OLED_WR_Byte(0x08,OLED_CMD);
	else
		OLED_WR_Byte(0x00,OLED_CMD);
	OLED_WR_Byte(0x10+(X>>1),OLED_CMD);
	for(m=1;m<=15;m+=2)
	{
		OLED_WR_Byte(*(FONT16X16[n-0x20]+m),OLED_DATA);
	}
}

/*
*********************************************************************************************************
*	函 数 名: OLED_GPIO_Init
*	功能说明: 初始化OLED的驱动IO
*	形    参：无
*	返 回 值: 无
*********************************************************************************************************
*/
void OLED_GPIO_Init(void)
{
   OLED_CS_GPIO_OUT;
   OLED_RST_GPIO_OUT;
   OLED_DC_GPIO_OUT;
   OLED_SCL_GPIO_OUT;
   OLED_SDIN_GPIO_OUT;
}

/*
*********************************************************************************************************
*	函 数 名: OLED_Init
*	功能说明: 初始化LED驱动芯片-SSD1306
*	形    参：无
*	返 回 值: 无
*********************************************************************************************************
*/
void OLED_Init(void)
{
    OLED_GPIO_Init();
    
    OLED_RST_H;
	Delay_ms(100);
	OLED_RST_L;
	Delay_ms(100);
	OLED_RST_H;
	
	OLED_WR_Byte(0xAE,OLED_CMD);//--turn off oled panel
	OLED_WR_Byte(0x00,OLED_CMD);//---set low column address
	OLED_WR_Byte(0x10,OLED_CMD);//---set high column address
	OLED_WR_Byte(0x40,OLED_CMD);//--set start line address  Set Mapping RAM Display Start Line (0x00~0x3F)
	OLED_WR_Byte(0x81,OLED_CMD);//--set contrast control register
	OLED_WR_Byte(0xCF,OLED_CMD); // Set SEG Output Current Brightness
	OLED_WR_Byte(0xA1,OLED_CMD);//--Set SEG/Column Mapping     0xa0左右反置 0xa1正常
	OLED_WR_Byte(0xC0,OLED_CMD);//Set COM/Row Scan Direction   0xc0上下反置 0xc8正常
	OLED_WR_Byte(0xA6,OLED_CMD);//--set normal display
	OLED_WR_Byte(0xA8,OLED_CMD);//--set multiplex ratio(1 to 64)
	OLED_WR_Byte(0x3f,OLED_CMD);//--1/64 duty
	OLED_WR_Byte(0xD3,OLED_CMD);//-set display offset	Shift Mapping RAM Counter (0x00~0x3F)
	OLED_WR_Byte(0x00,OLED_CMD);//-not offset
	OLED_WR_Byte(0xd5,OLED_CMD);//--set display clock divide ratio/oscillator frequency
	OLED_WR_Byte(0x80,OLED_CMD);//--set divide ratio, Set Clock as 100 Frames/Sec
	OLED_WR_Byte(0xD9,OLED_CMD);//--set pre-charge period
	OLED_WR_Byte(0xF1,OLED_CMD);//Set Pre-Charge as 15 Clocks & Discharge as 1 Clock
	OLED_WR_Byte(0xDA,OLED_CMD);//--set com pins hardware configuration
	OLED_WR_Byte(0x12,OLED_CMD);
	OLED_WR_Byte(0xDB,OLED_CMD);//--set vcomh
	OLED_WR_Byte(0x40,OLED_CMD);//Set VCOM Deselect Level
	OLED_WR_Byte(0x20,OLED_CMD);//-Set Page Addressing Mode (0x00/0x01/0x02)
	OLED_WR_Byte(0x02,OLED_CMD);//
	OLED_WR_Byte(0x8D,OLED_CMD);//--set Charge Pump enable/disable
	OLED_WR_Byte(0x14,OLED_CMD);//--set(0x10) disable
	OLED_WR_Byte(0xA4,OLED_CMD);// Disable Entire Display On (0xa4/0xa5)
	OLED_WR_Byte(0xA6,OLED_CMD);// Disable Inverse Display On (0xa6/a7)
	OLED_WR_Byte(0xAF,OLED_CMD);//--turn on oled panel

	OLED_WR_Byte(0xAF,OLED_CMD); /*display ON*/
	OLED_Clear();
	OLED_Set_Pos(0,0);
}

