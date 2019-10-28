#include"AD_10bits.h"

uint ADC_Data;
/*
*********************************************************************************************************
*	函 数 名: ADC_Init
*	功能说明: dsPIC30-ADC转换
*	形    参：无
*	返 回 值: 无
*********************************************************************************************************
*/
void ADC_Init(void)
{
    TRISBbits.TRISB0 = 1;   //PB0设置成输入
         
    ADCON1bits.FORM  = 0;   //无符号整数格式
    ADCON1bits.SSRC  = 7;   //内部计数器结束采样并开始转换（自动转换）   
    ADCON1bits.ASAM  = 1;   //自动采样,上次转换结束后开始
    
    ADCON2bits.VCFG  = 0;   //参考电压配置AVDD,AVSS
    ADCON2bits.SMPI  = 0;   //一个采样/转换序列时完成后产生中断
    ADCON2bits.CHPS  = 2;   //转换CH0和CH1和CH2和CH3  0->转换CH0  1->转换CH0和CH1  2或3->转换CH0和CH1和CH2和CH3
    
    ADCON3bits.SAMC  = 31;  //相邻两次采样之间的时间间隔为31Tad
    ADCON3bits.ADRC  = 0;   //AD时钟由系统时钟产生
    ADCON3bits.ADCS  = 3;   //AD转换时钟2Tcy
    
    ADCHSbits.CH0NA  = 0;   //通道0负输入是Vref-
    ADCHSbits.CH0SA  = 0;   //通道0负正输入是AN0
    
    ADPCFGbits.PCFG0 = 0;   //AN0模拟输入引脚处于模拟模式，禁止端口读输入,A/D采样引脚电压
    
    ADCSSLbits.CSSL0 = 0;   //输入扫描时跳过AN0
    
    IPC2bits.ADIP    = 7;   //设置AD转换中断优先级为7
    IEC0bits.ADIE    = 1;   //使能AD转换完成中断
    
    ADCON1bits.ADON  = 1;   //启动ADC
}

/*
*********************************************************************************************************
*	函 数 名: ADCInterrupt
*	功能说明: ADC转换完成中断
*	形    参：无
*	返 回 值: 无
*********************************************************************************************************
*/
void __attribute__((interrupt, no_auto_psv)) _ADCInterrupt (void)
{
    IFS0bits.ADIF=0;    //清AD转换中断标志位
    ADC_Data = ADCBUF0;
}