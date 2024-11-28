#ifndef __PWM_H
#define __PWM_H

#include <STC8H.h>
#include "INTRINS.h"

#define PWM1_1      0x00	//P1.0P P1.1N
#define PWM1_2      0x01	//P2.0P P2.1N
#define PWM1_3      0x02	//P6.0P P6.1N
//#define PWM1_4    0x03    //-----------

#define PWM2_1      0x00	//P1.2P P1.3N
#define PWM2_2      0x04	//P2.2P P2.3N
#define PWM2_3      0x08	//P6.2P P6.3N
//#define PWM3_4    0x0C	//-----------

#define PWM3_1      0x00	//P1.4P P1.5N
#define PWM3_2      0x10	//P2.4P P2.5N
#define PWM3_3      0x20	//P6.4P P6.5N
//#define PWM3_4    0x30	//-----------

#define PWM4_1      0x00	//P1.6P P1.7N
#define PWM4_2      0x40	//P2.6P P2.7N
#define PWM4_3      0x80	//P6.6P P6.7N
//#define PWM4_4    0xC0	//-----------
 
#define PWM5_1      0x00	//P2.0
#define PWM5_2      0x01	//P1.7
#define PWM5_3      0x02	//P0.0
#define PWM5_4      0x03	//P7.4

#define PWM6_1      0x00	//P2.1
#define PWM6_2      0x04	//P5.4
#define PWM6_3      0x08	//P0.1
#define PWM6_4      0x0C	//P7.5
 
#define PWM7_1      0x00	//P2.2
#define PWM7_2      0x10	//P3.3
#define PWM7_3      0x20	//P0.2
#define PWM7_4      0x30	//P7.6

#define PWM8_1      0x00	//P2.2
#define PWM8_2      0x40	//P3.3
#define PWM8_3      0x60	//P0.2
#define PWM8_4      0xC0	//P7.6

#define ENO1P       0x01
#define ENO2P       0x04
#define ENO3P       0x10
#define ENO4P       0x40 
#define ENO5P       0x01
#define ENO6P       0x04
#define ENO7P       0x10
#define ENO8P       0x40
 
#define PWMA_PERIOD  1024    //设置周期值
#define PWMB_PERIOD  65535    //设置周期值

void PWMAconfig();
void PWMBconfig();
void PWM1(unsigned int Duty);
void PWM2(unsigned int Duty);
void PWM3(unsigned int Duty);
void PWM4(unsigned int Duty);
void PWM5(unsigned int Duty);
void PWM6(unsigned int Duty);
void PWM7(unsigned int Duty);
void PWM8(unsigned int Duty);



#endif