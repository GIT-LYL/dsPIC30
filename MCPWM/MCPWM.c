#include "MCPWM.H"

/*
*********************************************************************************************************
*	函 数 名: MCPWM_Init
*	功能说明: MCPWM初始化
*	形    参：无
*	返 回 值: 无
*********************************************************************************************************
*/
void MCPWM_Init(void)
{
     /* PTCON时基控制寄存器 */
    PTCONbits.PTEN  =1;    //PWM使能
    PTCONbits.PTSIDL=0;    //CPU 空闲模式时 PWM 时基运行    
    PTCONbits.PTOPS =0;    //PWM时基输出后分频 1 : 1
    PTCONbits.PTCKPS=0;    //PWM 时基输入时钟周期为 1 TCY （1:1 预分频）
    PTCONbits.PTMOD =0x00; //PWM 时基工作在自由运行模式
    
    /* PTMR-PWM时基寄存器 */
    
    /* PTPER时基周期寄存器 */
    PTPER = 95;//调节PWM周期 PEPER = （ Fcy /（ Fpwm *   PTMR预分频比 ））-1  ->PTMR预分频比 PTCONbits.PTOPS  Fcy=系统时钟/4
    
    /* PWMCON1 */
    PWMCON1bits.PTMOD1=1;  //PWM1 : 1->PWM独立输出  0->PWM互补输出
    PWMCON1bits.PTMOD2=1;  //PWM2 : 1->PWM独立输出  0->PWM互补输出
    PWMCON1bits.PTMOD3=1;  //PWM3 : 1->PWM独立输出  0->PWM互补输出
    
    PWMCON1bits.PMOD1=1;   //PWM1 : 1->PWM独立输出  0->PWM互补输出                       
    PWMCON1bits.PMOD2=1;   //PWM2 : 1->PWM独立输出  0->PWM互补输出
    PWMCON1bits.PMOD3=1;   //PWM3 : 1->PWM独立输出  0->PWM互补输出
    
    PWMCON1bits.PEN1L=1;   //PWM1 : 1->PWM1L引脚使能为PWM输出  0->PWM1L引脚使能为普通IO输出
    PWMCON1bits.PEN1H=1;   //PWM1 : 1->PWM1H引脚使能为PWM输出  0->PWM1H引脚使能为普通IO输出   
    PWMCON1bits.PEN2L=1;   //PWM2 : 1->PWM2L引脚使能为PWM输出  0->PWM2L引脚使能为普通IO输出
    PWMCON1bits.PEN2H=1;   //PWM2 : 1->PWM2H引脚使能为PWM输出  0->PWM2H引脚使能为普通IO输出   
    PWMCON1bits.PEN3L=1;   //PWM3 : 1->PWM3L引脚使能为PWM输出  0->PWM3L引脚使能为普通IO输出
    PWMCON1bits.PEN3H=1;   //PWM3 : 1->PWM3H引脚使能为PWM输出  0->PWM3H引脚使能为普通IO输出
    
    /* PWMCON2 */
    PWMCON2bits.SEVOPS=0;  //PWM 特殊事件触发器输出后分频比-> 1 : 1
    PWMCON2bits.IUE   =0;  //对有效 PDC 寄存器的更新与 PWM 时基同步
    PWMCON2bits.OSYNC =0;  //输出改写同在下一个Tcy边沿发送
    PWMCON2bits.UDIS  =0;  //使能从占空比和周期缓冲寄存器更新
    
    /* DTCON1-死区控制寄存器1 */
    DTCON1bits.DTA=0;      //死区单元 A 的无符号 6 位死区值位
    DTCON1bits.DTAPS=0;    //死区单元 B 的时钟周期为 Tcy
    
    /* DTCON1-死区控制寄存器2 */
    //DTCON2=0x0000;       //全部由单元A提供死区时间
    
    /* FLTACON-故障A控制寄存器 */
    FLTACONbits.FAEN1=0;   //故障输入 A 不控制 PWM1H/PWM1L 这对引脚
    FLTACONbits.FAEN2=0;   //故障输入 A 不控制 PWM2H/PWM2L 这对引脚
    FLTACONbits.FAEN3=0;   //故障输入 A 不控制 PWM3H/PWM3L 这对引脚
    FLTACONbits.FLTAM=0;   //故障 A 输入引脚将所有控制引脚锁定为 FLTACON<15:8> 中编程的状态
    FLTACONbits.FAOV1L=0;  //PWM 输出引脚在发生外部故障输入事件时驱动为无效
    FLTACONbits.FAOV1H=0;  //PWM 输出引脚在发生外部故障输入事件时驱动为无效
    FLTACONbits.FAOV2L=0;  //PWM 输出引脚在发生外部故障输入事件时驱动为无效
    FLTACONbits.FAOV2H=0;  //PWM 输出引脚在发生外部故障输入事件时驱动为无效
    FLTACONbits.FAOV3L=0;  //PWM 输出引脚在发生外部故障输入事件时驱动为无效
    FLTACONbits.FAOV3H=0;  //PWM 输出引脚在发生外部故障输入事件时驱动为无效
    
    /* FLTBCON-故障B控制寄存器 */
    //FLTBCON = 0x0000;    //故障B控制寄存器
    
    /* OVDCON-改写控制寄存器 */
    OVDCONbits.POUT1L=1;   //在相应的 POVD1 位清零时， PWM1L I/O 引脚驱动为有效
    OVDCONbits.POUT1H=1;   //在相应的 POVD1 位清零时， PWM1H I/O 引脚驱动为有效
    OVDCONbits.POUT2L=1;   //在相应的 POVD2 位清零时， PWM2L I/O 引脚驱动为有效
    OVDCONbits.POUT2H=1;   //在相应的 POVD2 位清零时， PWM2H I/O 引脚驱动为有效
    OVDCONbits.POUT2L=1;   //在相应的 POVD3 位清零时， PWM3L I/O 引脚驱动为有效
    OVDCONbits.POUT2H=1;   //在相应的 POVD3 位清零时， PWM3H I/O 引脚驱动为有效
    
    OVDCONbits.POVD1L=1;   //PWM 发生器控制 PWM1L I/O 引脚上的输出
    OVDCONbits.POVD1H=1;   //PWM 发生器控制 PWM1H I/O 引脚上的输出
    OVDCONbits.POVD2L=1;   //PWM 发生器控制 PWM2L I/O 引脚上的输出
    OVDCONbits.POVD2H=1;   //PWM 发生器控制 PWM2H I/O 引脚上的输出
    OVDCONbits.POVD3L=1;   //PWM 发生器控制 PWM3L I/O 引脚上的输出
    OVDCONbits.POVD3H=1;   //PWM 发生器控制 PWM3H I/O 引脚上的输出
    
    
    
    PDC1 = 96;    //默认50% 占空比调节寄存器1(可以调节占空比)-数值0~PTPER  占空比=((PDC1/2)-DT)/(PTPER+1)
    PDC2 = 0x3fff;//占空比调节寄存器2
    PDC3 = 0x7fff;//占空比调节寄存器3
}
