#include <STC8H.H>
#include "IIC.h"
#include "IAP.h"
#include "PWM.h"
#include "DRIVES.h"
sbit LED=P7^0;
extern unsigned char xdata buffer[64];

void main()
{
 unsigned char i;
 P7M0 = 0x01; 
 P7M1 = 0x00;   
 IapIdle();
 IICsetup();
 buffer[0]=1;
 for(i=0;i<64;i++) buffer[i]=IapRead(i);
 EA = 1;
 PWMAconfig();
 PWMBconfig();
 Timer0_Init();
 while(1)

{
 LED = buffer[0];
 ServoA(buffer[1]);
 ServoB(buffer[2]);
 ServoC(buffer[3]);
 ServoD(buffer[4]);
 for(i=0;i<64;i++) IapProgram(i,buffer[i]);
}

}
