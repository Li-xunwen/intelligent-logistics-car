#include "DRIVES.h"
extern unsigned char xdata buffer[64];
unsigned char Time=0;
unsigned int MotorA1=0;
unsigned int MotorA2=0;
unsigned int MotorB1=0;
unsigned int MotorB2=0;
void Timer0_Isr(void) interrupt 1
{
 if(buffer[9]>0) { breaks(buffer[9]); return ;  }                     
 if(MotorA1<=buffer[5]*4)PWM1(MotorA1++);else PWM1(MotorA1=buffer[5]*4);
 if(MotorA2<=buffer[6]*4)PWM2(MotorA2++);else PWM2(MotorA2=buffer[6]*4);
 if(MotorB1<=buffer[7]*4)PWM3(MotorB1++);else PWM3(MotorB1=buffer[7]*4);
 if(MotorB2<=buffer[8]*4)PWM4(MotorB2++);else PWM4(MotorB2=buffer[8]*4);
 
}



void Timer0_Init(void)		//4000微秒@12.000MHz
{
	AUXR &= 0x7F;			//定时器时钟12T模式
	TMOD &= 0xF0;			//设置定时器模式
	TL0 = 0x60;				//设置定时初始值
	TH0 = 0xF0;				//设置定时初始值
	TF0 = 0;				//清除TF0标志
	TR0 = 1;				//定时器0开始计时
	ET0 = 1;				//使能定时器0中断
}


void breaks(unsigned char NUM)
{
 PWM1(255-NUM);
 PWM2(255-NUM);
 PWM3(255-NUM);
 PWM4(255-NUM);
}
void ServoA(unsigned char  angle)
{
 PWM5(256*angle);
 
}
void ServoB(unsigned char  angle)
{
 PWM6(256*angle);
 
}
void ServoC(unsigned char  angle)
{
 PWM7(256*angle);
 
}
void ServoD(unsigned char  angle)
{
 PWM8(256*angle);
 
}