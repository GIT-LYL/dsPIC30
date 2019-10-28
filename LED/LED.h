/* 
 * File:   LED.h
 * Author: slyvi
 *
 * Created on 2019年10月24日, 上午9:34
 */

#ifndef LED_H
#define	LED_H

#ifdef	__cplusplus
extern "C" {
#endif

#include"MAIN.h"

/* LED_GPIO锁存寄存器 */
#define LED1                LATEbits.LATE1      //LED1-PB1
#define LED2                LATEbits.LATE2      //LED2-PB2
#define LED3           		LATEbits.LATE3      //LED3-PB3
#define LED4           		LATEbits.LATE4      //LED4-PB4

/* LED_GPIO数据方向寄存器 */
#define LED1_GPIO_OUT       TRISEbits.TRISE1=0
#define LED2_GPIO_OUT       TRISEbits.TRISE2=0
#define LED3_GPIO_OUT       TRISEbits.TRISE3=0
#define LED4_GPIO_OUT       TRISEbits.TRISE4=0

#define LED1_ON        		LED1=0
#define LED1_OFF       		LED1=1
#define LED1_TOGGLE    		LED1=~LED1

#define LED2_ON        		LED2=0
#define LED2_OFF       		LED2=1
#define LED2_TOGGLE    		LED2=~LED2

#define LED3_ON        		LED3=0
#define LED3_OFF       		LED3=1
#define LED3_TOGGLE    		LED3=~LED3

#define LED4_ON        		LED4=0
#define LED4_OFF       		LED4=1
#define LED4_TOGGLE    		LED4=~LED4
    



#ifdef	__cplusplus
}
#endif

#endif	/* LED_H */

