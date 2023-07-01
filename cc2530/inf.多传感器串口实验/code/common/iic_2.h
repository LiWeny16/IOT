#ifndef _IIC_2_H
#define _IIC_2_H

#include "hal_delay.h"

/*
硬件连接：
SDA：P1.3
SCL：P1.2
*/
#define IIC_SDA_OUTMODE2() {P1DIR |= 1<<3;}
#define IIC_SDA_INPUTMODE2() {P1DIR &= ~(1<<3);}
#define IIC_SDA_OUT2 P1_3  //数据线输出
#define IIC_SDA_IN2 P1_3  //数据线输入
#define IIC_SCL2 P1_2  //时钟线

void IIC_Init2(void);
void IIC_Start2(void);
void IIC_Stop2(void);
uint8_t IIC_GetACK2(void);
void IIC_SendACK2(uint8_t stat);
void IIC_WriteOneByteData2(uint8_t data);
uint8_t IIC_ReadOneByteData2(void);
#endif