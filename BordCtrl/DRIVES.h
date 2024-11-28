#ifndef __DRIVES_H
#define __DRIVES_H

#include "STC8H.h"
#include "PWM.h"
void Timer0_Init(void);
void breaks(unsigned char NUM);
void ServoA(unsigned char  angle);
void ServoB(unsigned char  angle);
void ServoC(unsigned char  angle);
void ServoD(unsigned char  angle);

#endif