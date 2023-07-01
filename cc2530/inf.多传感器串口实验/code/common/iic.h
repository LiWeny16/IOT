#ifndef _IIC_H
#define _IIC_H

#include "hal_delay.h"

/*
硬件连接：
SDA：P0.7
SCL：P0.1
*/
#define IIC_SDA_OUTMODE() {P0DIR |= 1<<7;}
#define IIC_SDA_INPUTMODE() {P0DIR &= ~(1<<7);}
#define IIC_SDA_OUT P0_7  //数据线输出
#define IIC_SDA_IN P0_7  //数据线输入
#define IIC_SCL P0_1  //时钟线

void IIC_Init(void);
void IIC_Start(void);
void IIC_Stop(void);
uint8_t IIC_GetACK(void);
void IIC_SendACK(uint8_t stat);
void IIC_WriteOneByteData(uint8_t data);
uint8_t IIC_ReadOneByteData(void);
#endif