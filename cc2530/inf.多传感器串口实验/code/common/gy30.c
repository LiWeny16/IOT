#include "gy30.h"
unsigned int Read_IIC_1_Data()
{
    unsigned char t0;
    unsigned char t1;
    unsigned int t;
    uint8_t r_s=0;
    IIC_Start(); //发送起始信号
    IIC_WriteOneByteData(0x46);
    r_s=IIC_GetACK();//获取应答
    IIC_WriteOneByteData(0x01);
    r_s=IIC_GetACK();//获取应答
    IIC_Stop(); //停止信号 
    
    IIC_Start(); //发送起始信号
    IIC_WriteOneByteData(0x46);
    r_s=IIC_GetACK();//获取应答
    IIC_WriteOneByteData(0x01);
    r_s=IIC_GetACK();//获取应答
    IIC_Stop(); //停止信号 
    
    IIC_Start(); //发送起始信号
    IIC_WriteOneByteData(0x46);
    r_s=IIC_GetACK();//获取应答
    IIC_WriteOneByteData(0x10);
    r_s=IIC_GetACK();//获取应答
    IIC_Stop(); //停止信号 
    
    delayUsIn32Mhz(300); //等待
    
    IIC_Start(); //发送起始信号
    IIC_WriteOneByteData(0x47);
    r_s=IIC_GetACK();//获取应答
    
    t0=IIC_ReadOneByteData(); //接收数据
    IIC_SendACK(0); //发送应答信号
    t1=IIC_ReadOneByteData(); //接收数据
    IIC_SendACK(1); //发送非应答信号
    IIC_Stop(); //停止信号
    
    t=(((t0<<8)|t1))*5/6;
    return t;  
}