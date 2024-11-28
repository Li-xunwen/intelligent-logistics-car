#include "IIC.h"

bit isda;      //设备地址标志
bit isma;      //储存地址标志
unsigned char addr;
unsigned char xdata buffer[64];
sbit SDA = P1^4;
sbit SCL = P1^5;
void IICsetup()
{
 P_SW2 |= 0x80; //使能访问 XFR
 I2CCFG = 0x81; //使能 I2C 从机模式
 I2CSLADR = 0x5A; //设置从机设备地址寄存器 I2CSLADR=0101_1010B
                  //即 I2CSLADR[7:1]=010_1101B,MA=0B。
                  //由于 MA 为 0,主机发送的的设备地址必须与
                  //I2CSLADR[7:1]相同才能访问此 I2C 从机设备。
                  //主机若需要写数据则要发送 5AH(0101_1010B)
                  //主机若需要读数据则要发送 5BH(0101_1011B)
 I2CSLST = 0x00;
 I2CSLCR = 0x78; //使能从机模式中断
 isda = 1; //用户变量初始化
 isma = 1;
 addr = 0;
 I2CTXD = buffer[addr];
 P1M0 = 0x30; P1M1 = 0x30; 
}

void I2C_Isr() interrupt 24 
{
 if (I2CSLST & 0x40)
 {
  I2CSLST &= ~0x40; //处理 START 事件
  isda = 1; //若为重复起始信号时必须作此设置
 }
 else if (I2CSLST & 0x20)
 {
   I2CSLST &= ~0x20; //处理 RECV 事件
   if (isda)
   { 
    isda = 0; //处理 RECV 事件（RECV DEVICE ADDR）
   }
   else if (isma)
   {
    isma = 0; //处理 RECV 事件（RECV MEMORY ADDR）
    addr = I2CRXD;
    I2CTXD = buffer[addr];
   }
   else
   {
    buffer[addr++] = I2CRXD; //处理 RECV 事件（RECV DATA）
   }
 }
  else if (I2CSLST & 0x10)
 {
   I2CSLST &= ~0x10; //处理 SEND 事件
   if (I2CSLST & 0x02)
   { 
    I2CTXD = 0xff; //接收到 NAK 则停止读取数据
   }
   else
   {
    I2CTXD = buffer[++addr]; //接收到 ACK 则继续读取数据
   }
 }
 else if (I2CSLST & 0x08)
 {
  I2CSLST &= ~0x08; //处理 STOP 事件
  isda = 1;
  isma = 1;
 }
}