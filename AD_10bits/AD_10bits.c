#include"AD_10bits.h"

uint ADC_Data;
/*
*********************************************************************************************************
*	�� �� ��: ADC_Init
*	����˵��: dsPIC30-ADCת��
*	��    �Σ���
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void ADC_Init(void)
{
    TRISBbits.TRISB0 = 1;   //PB0���ó�����
         
    ADCON1bits.FORM  = 0;   //�޷���������ʽ
    ADCON1bits.SSRC  = 7;   //�ڲ�������������������ʼת�����Զ�ת����   
    ADCON1bits.ASAM  = 1;   //�Զ�����,�ϴ�ת��������ʼ
    
    ADCON2bits.VCFG  = 0;   //�ο���ѹ����AVDD,AVSS
    ADCON2bits.SMPI  = 0;   //һ������/ת������ʱ��ɺ�����ж�
    ADCON2bits.CHPS  = 2;   //ת��CH0��CH1��CH2��CH3  0->ת��CH0  1->ת��CH0��CH1  2��3->ת��CH0��CH1��CH2��CH3
    
    ADCON3bits.SAMC  = 31;  //�������β���֮���ʱ����Ϊ31Tad
    ADCON3bits.ADRC  = 0;   //ADʱ����ϵͳʱ�Ӳ���
    ADCON3bits.ADCS  = 3;   //ADת��ʱ��2Tcy
    
    ADCHSbits.CH0NA  = 0;   //ͨ��0��������Vref-
    ADCHSbits.CH0SA  = 0;   //ͨ��0����������AN0
    
    ADPCFGbits.PCFG0 = 0;   //AN0ģ���������Ŵ���ģ��ģʽ����ֹ�˿ڶ�����,A/D�������ŵ�ѹ
    
    ADCSSLbits.CSSL0 = 0;   //����ɨ��ʱ����AN0
    
    IPC2bits.ADIP    = 7;   //����ADת���ж����ȼ�Ϊ7
    IEC0bits.ADIE    = 1;   //ʹ��ADת������ж�
    
    ADCON1bits.ADON  = 1;   //����ADC
}

/*
*********************************************************************************************************
*	�� �� ��: ADCInterrupt
*	����˵��: ADCת������ж�
*	��    �Σ���
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void __attribute__((interrupt, no_auto_psv)) _ADCInterrupt (void)
{
    IFS0bits.ADIF=0;    //��ADת���жϱ�־λ
    ADC_Data = ADCBUF0;
}