#include "IIC.h"

bit isda;      //�豸��ַ��־
bit isma;      //�����ַ��־
unsigned char addr;
unsigned char xdata buffer[64];
sbit SDA = P1^4;
sbit SCL = P1^5;
void IICsetup()
{
 P_SW2 |= 0x80; //ʹ�ܷ��� XFR
 I2CCFG = 0x81; //ʹ�� I2C �ӻ�ģʽ
 I2CSLADR = 0x5A; //���ôӻ��豸��ַ�Ĵ��� I2CSLADR=0101_1010B
                  //�� I2CSLADR[7:1]=010_1101B,MA=0B��
                  //���� MA Ϊ 0,�������͵ĵ��豸��ַ������
                  //I2CSLADR[7:1]��ͬ���ܷ��ʴ� I2C �ӻ��豸��
                  //��������Ҫд������Ҫ���� 5AH(0101_1010B)
                  //��������Ҫ��������Ҫ���� 5BH(0101_1011B)
 I2CSLST = 0x00;
 I2CSLCR = 0x78; //ʹ�ܴӻ�ģʽ�ж�
 isda = 1; //�û�������ʼ��
 isma = 1;
 addr = 0;
 I2CTXD = buffer[addr];
 P1M0 = 0x30; P1M1 = 0x30; 
}

void I2C_Isr() interrupt 24 
{
 if (I2CSLST & 0x40)
 {
  I2CSLST &= ~0x40; //���� START �¼�
  isda = 1; //��Ϊ�ظ���ʼ�ź�ʱ������������
 }
 else if (I2CSLST & 0x20)
 {
   I2CSLST &= ~0x20; //���� RECV �¼�
   if (isda)
   { 
    isda = 0; //���� RECV �¼���RECV DEVICE ADDR��
   }
   else if (isma)
   {
    isma = 0; //���� RECV �¼���RECV MEMORY ADDR��
    addr = I2CRXD;
    I2CTXD = buffer[addr];
   }
   else
   {
    buffer[addr++] = I2CRXD; //���� RECV �¼���RECV DATA��
   }
 }
  else if (I2CSLST & 0x10)
 {
   I2CSLST &= ~0x10; //���� SEND �¼�
   if (I2CSLST & 0x02)
   { 
    I2CTXD = 0xff; //���յ� NAK ��ֹͣ��ȡ����
   }
   else
   {
    I2CTXD = buffer[++addr]; //���յ� ACK �������ȡ����
   }
 }
 else if (I2CSLST & 0x08)
 {
  I2CSLST &= ~0x08; //���� STOP �¼�
  isda = 1;
  isma = 1;
 }
}