#include "IAP.h"


void IapIdle()
{
IAP_CONTR = 0; //关闭 IAP 功能
IAP_CMD = 0; //清除命令寄存器
IAP_TRIG = 0; //清除触发寄存器
IAP_ADDRH = 0x80; //将地址设置到非 IAP 区域
IAP_ADDRL = 0;
IAP_TPS=12;
}

char IapRead(int addr)
{
char dat;
IAP_CONTR = 0x80; //使能 IAP
IAP_TPS = 12; //设置等待参数 12MHz
IAP_CMD = 1; //设置 IAP 读命令
IAP_ADDRL = addr; //设置 IAP 低地址
IAP_ADDRH = addr >> 8; //设置 IAP 高地址
IAP_TRIG = 0x5a; //写触发命令(0x5a)
IAP_TRIG = 0xa5; //写触发命令(0xa5)
_nop_();
dat = IAP_DATA; //读 IAP 数据
IapIdle(); //关闭 IAP 功能
return dat;
}

void IapProgram(int addr, char dat)
{
IAP_CONTR = 0x80; //使能 IAP
IAP_TPS = 12; //设置等待参数 12MHz
IAP_CMD = 2; //设置 IAP 写命令
IAP_ADDRL = addr; //设置 IAP 低地址
IAP_ADDRH = addr >> 8; //设置 IAP 高地址
IAP_DATA = dat; //写 IAP 数据
IAP_TRIG = 0x5a; //写触发命令(0x5a)
IAP_TRIG = 0xa5; //写触发命令(0xa5)
_nop_();
IapIdle(); //关闭 IAP 功能
}


void IapErase(int addr)
{
IAP_CONTR = 0x80; //使能 IAP
IAP_TPS = 12; //设置等待参数 12MHz
IAP_CMD = 3; //设置 IAP 擦除命令
IAP_ADDRL = addr; //设置 IAP 低地址
IAP_ADDRH = addr >> 8; //设置 IAP 高地址
IAP_TRIG = 0x5a; //写触发命令(0x5a)
IAP_TRIG = 0xa5; //写触发命令(0xa5)
_nop_(); //
IapIdle(); //关闭 IAP 功能
}

