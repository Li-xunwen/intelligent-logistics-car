#include "PWM.h"


void PWMAconfig()
{
	P_SW2 |= 0x80; //扩展寄存器(XFR)访问使能
	P6M0 = 0x55; P6M1 = 0x00; 
	PWMA_CCER1 = 0x00; //写 CCMRx 前必须先清零 CCxE 关闭通道
    PWMA_CCER2 = 0x00;
    PWMA_CCMR1 = 0x68; //通道模式配置
    PWMA_CCMR2 = 0x68;
    PWMA_CCMR3 = 0x68;
    PWMA_CCMR4 = 0x68;
    PWMA_CCER1 = 0x33; //配置通道输出使能和极性
    PWMA_CCER2 = 0x33; 
    PWMA_ARRH = (unsigned char)(PWMA_PERIOD >> 8); //设置周期时间
    PWMA_ARRL = (unsigned char)PWMA_PERIOD;
    PWMA_ENO = 0x00;
    PWMA_ENO |= ENO1P; //使能输出
    PWMA_ENO |= ENO2P; //使能输出
    PWMA_ENO |= ENO3P; //使能输出
    PWMA_ENO |= ENO4P; //使能输出
    PWMA_PS = 0x00;    //高级 PWM 通道输出脚选择位
    PWMA_PS |= PWM1_3; //选择 PWM1_3 通道
    PWMA_PS |= PWM2_3; //选择 PWM2_3 通道
    PWMA_PS |= PWM3_3; //选择 PWM3_3 通道
    PWMA_PS |= PWM4_3; //选择 PWM4_3 通道
    PWMA_BKR = 0x80;   //使能主输出
    PWMA_CR1 |= 0x01;  //开始计时 
}
void PWMBconfig()
{
	P_SW2 |= 0x80; //扩展寄存器(XFR)访问使能
	P7M0 = 0xf0; P7M1 = 0x00; 
	PWMB_CCER1 = 0x00; //写 CCMRx 前必须先清零 CCxE 关闭通道
    PWMB_CCER2 = 0x00;
    PWMB_CCMR1 = 0x68; //通道模式配置
    PWMB_CCMR2 = 0x68;
    PWMB_CCMR3 = 0x68;
    PWMB_CCMR4 = 0x68;
    PWMB_CCER1 = 0x33; //配置通道输出使能和极性
    PWMB_CCER2 = 0x33; 
    PWMB_ARRH = (unsigned char)(PWMB_PERIOD >> 8); //设置周期时间
    PWMB_ARRL = (unsigned char)PWMB_PERIOD;
    PWMB_ENO = 0x00;
    PWMB_ENO |= ENO5P; //使能输出
    PWMB_ENO |= ENO6P; //使能输出
    PWMB_ENO |= ENO7P; //使能输出
    PWMB_ENO |= ENO8P; //使能输出
    PWMB_PS = 0x00;    //高级 PWM 通道输出脚选择位
    PWMB_PS |= PWM5_4; //选择 PWM5_4 通道
    PWMB_PS |= PWM6_4; //选择 PWM6_4 通道
    PWMB_PS |= PWM7_4; //选择 PWM7_4 通道
    PWMB_PS |= PWM8_4; //选择 PWM8_4 通道
    PWMB_BKR = 0x80;   //使能主输出
    PWMB_CR1 |= 0x01;  //开始计时

}
void PWM1(unsigned int Duty)
{
 Duty=1024-Duty;
 PWMA_CCR1H = (unsigned char)(Duty >> 8); //设置占空比时间
 PWMA_CCR1L = (unsigned char)(Duty);
}

void PWM2(unsigned int Duty)
{
 Duty=1024-Duty;
 PWMA_CCR2H = (unsigned char)(Duty >> 8); //设置占空比时间
 PWMA_CCR2L = (unsigned char)(Duty);
}

void PWM3(unsigned int Duty)
{
 Duty=1024-Duty;
 PWMA_CCR3H = (unsigned char)(Duty >> 8); //设置占空比时间
 PWMA_CCR3L = (unsigned char)(Duty);
}

void PWM4(unsigned int Duty)
{
 Duty=1024-Duty;
 PWMA_CCR4H = (unsigned char)(Duty >> 8); //设置占空比时间
 PWMA_CCR4L = (unsigned char)(Duty);
}


void PWM5(unsigned int Duty)
{
 PWMB_CCR5H = (unsigned char)(Duty >> 8); //设置占空比时间
 PWMB_CCR5L = (unsigned char)(Duty);
}

void PWM6(unsigned int Duty)
{
 PWMB_CCR6H = (unsigned char)(Duty >> 8); //设置占空比时间
 PWMB_CCR6L = (unsigned char)(Duty);
}

void PWM7(unsigned int Duty)
{
 PWMB_CCR7H = (unsigned char)(Duty >> 8); //设置占空比时间
 PWMB_CCR7L = (unsigned char)(Duty);
}

void PWM8(unsigned int Duty)
{
 PWMB_CCR8H = (unsigned char)(Duty >> 8); //设置占空比时间
 PWMB_CCR8L = (unsigned char)(Duty);
}

