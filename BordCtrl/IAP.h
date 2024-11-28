#ifndef __IAP_H
#define __IAP_H

#include "STC8H.h"
#include "INTRINS.h"
void IapIdle();
char IapRead(int addr);
void IapProgram(int addr, char dat);
void IapErase(int addr);





#endif