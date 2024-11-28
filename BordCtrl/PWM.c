#include "PWM.h"


void PWMAconfig()
{
	P_SW2 |= 0x80; //��չ�Ĵ���(XFR)����ʹ��
	P6M0 = 0x55; P6M1 = 0x00; 
	PWMA_CCER1 = 0x00; //д CCMRx ǰ���������� CCxE �ر�ͨ��
    PWMA_CCER2 = 0x00;
    PWMA_CCMR1 = 0x68; //ͨ��ģʽ����
    PWMA_CCMR2 = 0x68;
    PWMA_CCMR3 = 0x68;
    PWMA_CCMR4 = 0x68;
    PWMA_CCER1 = 0x33; //����ͨ�����ʹ�ܺͼ���
    PWMA_CCER2 = 0x33; 
    PWMA_ARRH = (unsigned char)(PWMA_PERIOD >> 8); //��������ʱ��
    PWMA_ARRL = (unsigned char)PWMA_PERIOD;
    PWMA_ENO = 0x00;
    PWMA_ENO |= ENO1P; //ʹ�����
    PWMA_ENO |= ENO2P; //ʹ�����
    PWMA_ENO |= ENO3P; //ʹ�����
    PWMA_ENO |= ENO4P; //ʹ�����
    PWMA_PS = 0x00;    //�߼� PWM ͨ�������ѡ��λ
    PWMA_PS |= PWM1_3; //ѡ�� PWM1_3 ͨ��
    PWMA_PS |= PWM2_3; //ѡ�� PWM2_3 ͨ��
    PWMA_PS |= PWM3_3; //ѡ�� PWM3_3 ͨ��
    PWMA_PS |= PWM4_3; //ѡ�� PWM4_3 ͨ��
    PWMA_BKR = 0x80;   //ʹ�������
    PWMA_CR1 |= 0x01;  //��ʼ��ʱ 
}
void PWMBconfig()
{
	P_SW2 |= 0x80; //��չ�Ĵ���(XFR)����ʹ��
	P7M0 = 0xf0; P7M1 = 0x00; 
	PWMB_CCER1 = 0x00; //д CCMRx ǰ���������� CCxE �ر�ͨ��
    PWMB_CCER2 = 0x00;
    PWMB_CCMR1 = 0x68; //ͨ��ģʽ����
    PWMB_CCMR2 = 0x68;
    PWMB_CCMR3 = 0x68;
    PWMB_CCMR4 = 0x68;
    PWMB_CCER1 = 0x33; //����ͨ�����ʹ�ܺͼ���
    PWMB_CCER2 = 0x33; 
    PWMB_ARRH = (unsigned char)(PWMB_PERIOD >> 8); //��������ʱ��
    PWMB_ARRL = (unsigned char)PWMB_PERIOD;
    PWMB_ENO = 0x00;
    PWMB_ENO |= ENO5P; //ʹ�����
    PWMB_ENO |= ENO6P; //ʹ�����
    PWMB_ENO |= ENO7P; //ʹ�����
    PWMB_ENO |= ENO8P; //ʹ�����
    PWMB_PS = 0x00;    //�߼� PWM ͨ�������ѡ��λ
    PWMB_PS |= PWM5_4; //ѡ�� PWM5_4 ͨ��
    PWMB_PS |= PWM6_4; //ѡ�� PWM6_4 ͨ��
    PWMB_PS |= PWM7_4; //ѡ�� PWM7_4 ͨ��
    PWMB_PS |= PWM8_4; //ѡ�� PWM8_4 ͨ��
    PWMB_BKR = 0x80;   //ʹ�������
    PWMB_CR1 |= 0x01;  //��ʼ��ʱ

}
void PWM1(unsigned int Duty)
{
 Duty=1024-Duty;
 PWMA_CCR1H = (unsigned char)(Duty >> 8); //����ռ�ձ�ʱ��
 PWMA_CCR1L = (unsigned char)(Duty);
}

void PWM2(unsigned int Duty)
{
 Duty=1024-Duty;
 PWMA_CCR2H = (unsigned char)(Duty >> 8); //����ռ�ձ�ʱ��
 PWMA_CCR2L = (unsigned char)(Duty);
}

void PWM3(unsigned int Duty)
{
 Duty=1024-Duty;
 PWMA_CCR3H = (unsigned char)(Duty >> 8); //����ռ�ձ�ʱ��
 PWMA_CCR3L = (unsigned char)(Duty);
}

void PWM4(unsigned int Duty)
{
 Duty=1024-Duty;
 PWMA_CCR4H = (unsigned char)(Duty >> 8); //����ռ�ձ�ʱ��
 PWMA_CCR4L = (unsigned char)(Duty);
}


void PWM5(unsigned int Duty)
{
 PWMB_CCR5H = (unsigned char)(Duty >> 8); //����ռ�ձ�ʱ��
 PWMB_CCR5L = (unsigned char)(Duty);
}

void PWM6(unsigned int Duty)
{
 PWMB_CCR6H = (unsigned char)(Duty >> 8); //����ռ�ձ�ʱ��
 PWMB_CCR6L = (unsigned char)(Duty);
}

void PWM7(unsigned int Duty)
{
 PWMB_CCR7H = (unsigned char)(Duty >> 8); //����ռ�ձ�ʱ��
 PWMB_CCR7L = (unsigned char)(Duty);
}

void PWM8(unsigned int Duty)
{
 PWMB_CCR8H = (unsigned char)(Duty >> 8); //����ռ�ձ�ʱ��
 PWMB_CCR8L = (unsigned char)(Duty);
}

