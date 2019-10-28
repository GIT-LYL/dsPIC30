#include "MCPWM.H"

/*
*********************************************************************************************************
*	�� �� ��: MCPWM_Init
*	����˵��: MCPWM��ʼ��
*	��    �Σ���
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void MCPWM_Init(void)
{
     /* PTCONʱ�����ƼĴ��� */
    PTCONbits.PTEN  =1;    //PWMʹ��
    PTCONbits.PTSIDL=0;    //CPU ����ģʽʱ PWM ʱ������    
    PTCONbits.PTOPS =0;    //PWMʱ��������Ƶ 1 : 1
    PTCONbits.PTCKPS=0;    //PWM ʱ������ʱ������Ϊ 1 TCY ��1:1 Ԥ��Ƶ��
    PTCONbits.PTMOD =0x00; //PWM ʱ����������������ģʽ
    
    /* PTMR-PWMʱ���Ĵ��� */
    
    /* PTPERʱ�����ڼĴ��� */
    PTPER = 95;//����PWM���� PEPER = �� Fcy /�� Fpwm *   PTMRԤ��Ƶ�� ����-1  ->PTMRԤ��Ƶ�� PTCONbits.PTOPS  Fcy=ϵͳʱ��/4
    
    /* PWMCON1 */
    PWMCON1bits.PTMOD1=1;  //PWM1 : 1->PWM�������  0->PWM�������
    PWMCON1bits.PTMOD2=1;  //PWM2 : 1->PWM�������  0->PWM�������
    PWMCON1bits.PTMOD3=1;  //PWM3 : 1->PWM�������  0->PWM�������
    
    PWMCON1bits.PMOD1=1;   //PWM1 : 1->PWM�������  0->PWM�������                       
    PWMCON1bits.PMOD2=1;   //PWM2 : 1->PWM�������  0->PWM�������
    PWMCON1bits.PMOD3=1;   //PWM3 : 1->PWM�������  0->PWM�������
    
    PWMCON1bits.PEN1L=1;   //PWM1 : 1->PWM1L����ʹ��ΪPWM���  0->PWM1L����ʹ��Ϊ��ͨIO���
    PWMCON1bits.PEN1H=1;   //PWM1 : 1->PWM1H����ʹ��ΪPWM���  0->PWM1H����ʹ��Ϊ��ͨIO���   
    PWMCON1bits.PEN2L=1;   //PWM2 : 1->PWM2L����ʹ��ΪPWM���  0->PWM2L����ʹ��Ϊ��ͨIO���
    PWMCON1bits.PEN2H=1;   //PWM2 : 1->PWM2H����ʹ��ΪPWM���  0->PWM2H����ʹ��Ϊ��ͨIO���   
    PWMCON1bits.PEN3L=1;   //PWM3 : 1->PWM3L����ʹ��ΪPWM���  0->PWM3L����ʹ��Ϊ��ͨIO���
    PWMCON1bits.PEN3H=1;   //PWM3 : 1->PWM3H����ʹ��ΪPWM���  0->PWM3H����ʹ��Ϊ��ͨIO���
    
    /* PWMCON2 */
    PWMCON2bits.SEVOPS=0;  //PWM �����¼�������������Ƶ��-> 1 : 1
    PWMCON2bits.IUE   =0;  //����Ч PDC �Ĵ����ĸ����� PWM ʱ��ͬ��
    PWMCON2bits.OSYNC =0;  //�����дͬ����һ��Tcy���ط���
    PWMCON2bits.UDIS  =0;  //ʹ�ܴ�ռ�ձȺ����ڻ���Ĵ�������
    
    /* DTCON1-�������ƼĴ���1 */
    DTCON1bits.DTA=0;      //������Ԫ A ���޷��� 6 λ����ֵλ
    DTCON1bits.DTAPS=0;    //������Ԫ B ��ʱ������Ϊ Tcy
    
    /* DTCON1-�������ƼĴ���2 */
    //DTCON2=0x0000;       //ȫ���ɵ�ԪA�ṩ����ʱ��
    
    /* FLTACON-����A���ƼĴ��� */
    FLTACONbits.FAEN1=0;   //�������� A ������ PWM1H/PWM1L �������
    FLTACONbits.FAEN2=0;   //�������� A ������ PWM2H/PWM2L �������
    FLTACONbits.FAEN3=0;   //�������� A ������ PWM3H/PWM3L �������
    FLTACONbits.FLTAM=0;   //���� A �������Ž����п�����������Ϊ FLTACON<15:8> �б�̵�״̬
    FLTACONbits.FAOV1L=0;  //PWM ��������ڷ����ⲿ���������¼�ʱ����Ϊ��Ч
    FLTACONbits.FAOV1H=0;  //PWM ��������ڷ����ⲿ���������¼�ʱ����Ϊ��Ч
    FLTACONbits.FAOV2L=0;  //PWM ��������ڷ����ⲿ���������¼�ʱ����Ϊ��Ч
    FLTACONbits.FAOV2H=0;  //PWM ��������ڷ����ⲿ���������¼�ʱ����Ϊ��Ч
    FLTACONbits.FAOV3L=0;  //PWM ��������ڷ����ⲿ���������¼�ʱ����Ϊ��Ч
    FLTACONbits.FAOV3H=0;  //PWM ��������ڷ����ⲿ���������¼�ʱ����Ϊ��Ч
    
    /* FLTBCON-����B���ƼĴ��� */
    //FLTBCON = 0x0000;    //����B���ƼĴ���
    
    /* OVDCON-��д���ƼĴ��� */
    OVDCONbits.POUT1L=1;   //����Ӧ�� POVD1 λ����ʱ�� PWM1L I/O ��������Ϊ��Ч
    OVDCONbits.POUT1H=1;   //����Ӧ�� POVD1 λ����ʱ�� PWM1H I/O ��������Ϊ��Ч
    OVDCONbits.POUT2L=1;   //����Ӧ�� POVD2 λ����ʱ�� PWM2L I/O ��������Ϊ��Ч
    OVDCONbits.POUT2H=1;   //����Ӧ�� POVD2 λ����ʱ�� PWM2H I/O ��������Ϊ��Ч
    OVDCONbits.POUT2L=1;   //����Ӧ�� POVD3 λ����ʱ�� PWM3L I/O ��������Ϊ��Ч
    OVDCONbits.POUT2H=1;   //����Ӧ�� POVD3 λ����ʱ�� PWM3H I/O ��������Ϊ��Ч
    
    OVDCONbits.POVD1L=1;   //PWM ���������� PWM1L I/O �����ϵ����
    OVDCONbits.POVD1H=1;   //PWM ���������� PWM1H I/O �����ϵ����
    OVDCONbits.POVD2L=1;   //PWM ���������� PWM2L I/O �����ϵ����
    OVDCONbits.POVD2H=1;   //PWM ���������� PWM2H I/O �����ϵ����
    OVDCONbits.POVD3L=1;   //PWM ���������� PWM3L I/O �����ϵ����
    OVDCONbits.POVD3H=1;   //PWM ���������� PWM3H I/O �����ϵ����
    
    
    
    PDC1 = 96;    //Ĭ��50% ռ�ձȵ��ڼĴ���1(���Ե���ռ�ձ�)-��ֵ0~PTPER  ռ�ձ�=((PDC1/2)-DT)/(PTPER+1)
    PDC2 = 0x3fff;//ռ�ձȵ��ڼĴ���2
    PDC3 = 0x7fff;//ռ�ձȵ��ڼĴ���3
}
