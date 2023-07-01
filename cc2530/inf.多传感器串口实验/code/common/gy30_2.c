#include "gy30_2.h"
#include "ioCC2530.h"
SHTDATA Read_IIC_2_Data()
{
    uint16_t temp,humi;
    SHTDATA SHTDATA;
    uint8_t buff[6];
    IIC_Start2(); //发送起始信号
    IIC_WriteOneByteData2(0x44<<1|0);
    IIC_GetACK2();//获取应答
    IIC_WriteOneByteData2(0x24);
    IIC_GetACK2();//获取应答
    IIC_WriteOneByteData2(0x16);
    IIC_GetACK2();//获取应答
    IIC_Stop2(); //停止信号 

    delayUsIn32Mhz(50);
    
    IIC_Start2(); //发送起始信号
    IIC_WriteOneByteData2(0x44<<1|1);
    IIC_GetACK2();
    IIC_SDA_INPUTMODE2();
 
    buff[0]=IIC_ReadOneByteData2();    IIC_SendACK2(0);
    buff[1]=IIC_ReadOneByteData2();    IIC_SendACK2(0);
    buff[2]=IIC_ReadOneByteData2();    IIC_SendACK2(0);
    buff[3]=IIC_ReadOneByteData2();    IIC_SendACK2(0);
    buff[4]=IIC_ReadOneByteData2();    IIC_SendACK2(0);
    buff[5]=IIC_ReadOneByteData2();    IIC_SendACK2(1);
        
    IIC_Stop2();
    
    temp = ((buff[0]<<8)|buff[1]);
    humi = ((buff[3]<<8)|buff[4]);
    SHTDATA.temp = temp;
    SHTDATA.humi = humi;
    return SHTDATA;

}