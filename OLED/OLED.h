#ifndef __OLED_H
#define	__OLED_H

#include "MAIN.h"


#define  uchar unsigned char
#define  uint  unsigned int


/* OLED_GPIO数据方向寄存器 */
#define OLED_CS_GPIO_OUT       TRISBbits.TRISB1=0
#define OLED_RST_GPIO_OUT      TRISBbits.TRISB6=0
#define OLED_DC_GPIO_OUT       TRISBbits.TRISB2=0
#define OLED_SCL_GPIO_OUT      TRISBbits.TRISB8=0
#define OLED_SDIN_GPIO_OUT     TRISBbits.TRISB7=0

/* OLED_GPIO锁存寄存器 */
#define OLED_CS      LATBbits.LATB1    //片选
#define OLED_RST     LATBbits.LATB6    //复位
#define OLED_DC      LATBbits.LATB2    //数据/命令控制
#define OLED_SCL     LATBbits.LATB8    //时钟 D0（SCLK)
#define OLED_SDIN    LATBbits.LATB7    //D1（MOSI） 数据

#define OLED_CMD  0	//写命令
#define OLED_DATA 1	//写数据
#define OLED_MODE 0

#define OLED_CS_L    OLED_CS=0
#define OLED_CS_H    OLED_CS=1

#define OLED_RST_L   OLED_RST=0
#define OLED_RST_H   OLED_RST=1

#define OLED_DC_L    OLED_DC=0
#define OLED_DC_H    OLED_DC=1

#define OLED_SCLK_L  OLED_SCL=0
#define OLED_SCLK_H  OLED_SCL=1

#define OLED_SDIN_L  OLED_SDIN=0
#define OLED_SDIN_H  OLED_SDIN=1;

#define SIZE          16
#define XLevelL		  0x02
#define XLevelH		  0x10
#define Max_Column	  128
#define Max_Row		  64
#define	Brightness	  0xFF
#define X_WIDTH 	  128
#define Y_WIDTH 	  64

void OLED_WR_Byte(uchar Data,uchar Cmd);
void OLED_Set_Pos(uchar X, uchar Y);
void OLED_Display_On(void);
void OLED_Display_Off(void);
void OLED_Clear(void);
void OLED_Display(uchar X,uchar Y,uchar n);
void OLED_GPIO_Init(void);
void OLED_Init(void);


#endif	/* OLED_H */

