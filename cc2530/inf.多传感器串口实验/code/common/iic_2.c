#include "iic_2.h"
#include "ioCC2530.h"
/*
函数功能：IIC接口初始化
硬件连接：
SDA：P1.3
SCL：P1.2
*/
void IIC_Init2(void)
{
    P1SEL &= ~(1<<3); //配置通用GPIO口模式
    P1SEL &= ~(1<<2); 
    P1DIR |= (1<<3);    //配置为输出模式
    P1DIR |= (1<<2);
}

/*
函数功能：IIC总线起始信号
*/
void IIC_Start2(void)
{
    IIC_SDA_OUTMODE2(); //初始化SDA为输出模式
    IIC_SDA_OUT2=1; 	//数据线拉高
    IIC_SCL2=1;          //时钟线 拉高
    delayUsIn32Mhz(4);        //电平保持时间
    IIC_SDA_OUT2=0;     //数据线拉低
    delayUsIn32Mhz(4);        //电平保持时间
    IIC_SCL2=0;     	//时钟线拉低
}


/*
函数功能：IIC总线停止信号
*/
void IIC_Stop2(void)
{
      IIC_SDA_OUTMODE2(); //初始化SDA为输出模式
      IIC_SDA_OUT2=0; 		 //数据线拉低
      IIC_SCL2=0;     		 //时钟线拉低
      delayUsIn32Mhz(4);        //电平保持时间
      IIC_SCL2=1;     		 //时钟线拉高
      delayUsIn32Mhz(4);        //电平保持时间
      IIC_SDA_OUT2=1; 	        //数据线拉高
      delayUsIn32Mhz(4);   
}

/*
函数功能：获取应答信号
返 回 值：1表示失败，0表示成功
*/
uint8_t IIC_GetACK2(void)
{
    uint8_t cnt=0;
    IIC_SDA_INPUTMODE2();//初始化SDA为输入模式
    IIC_SCL2=1;     		  //时钟线拉高，告诉从机，主机现在开始读取数据
    while(IIC_SDA_IN2)   //等待从机应答信号
    {
        cnt++;
        if(cnt>250)return 1;
    }
    IIC_SCL2=0;     		  //时钟线拉低，告诉从机，主机需要数据
    return 0;
}

/*
函数功能：主机向从机发送应答信号
函数形参：0表示应答，1表示非应答
*/
void IIC_SendACK2(uint8_t stat)
{
      IIC_SDA_OUTMODE2(); //初始化SDA为输出模式
      IIC_SCL2=0;     		 //时钟线拉低，告诉从机，主机需要发送数据
      if(stat)IIC_SDA_OUT2=1; //数据线拉高，发送非应答信号
      else IIC_SDA_OUT2=0; 	 //数据线拉低，发送应答信号
      delayUsIn32Mhz(2);            //电平保持时间，等待时钟线稳定
      IIC_SCL2=1;     		     //时钟线拉高，告诉从机，主机数据发送完毕
      delayUsIn32Mhz(2);            //电平保持时间，等待从机接收数据
      IIC_SCL2=0;     		  	 //时钟线拉低，告诉从机，主机需要数据
}


/*
函数功能：IIC发送1个字节数据
函数形参：将要发送的数据
*/
void IIC_WriteOneByteData2(uint8_t data)
{
      uint8_t i, txd;
      IIC_SDA_OUTMODE2(); //初始化SDA为输出模式
      IIC_SCL2=0;     		 //时钟线拉低，告诉从机，主机需要发送数据
      for(i=0;i<8;i++)
      {
        txd=(data&0x80)>>7;  
        data<<=1;
        if(txd)IIC_SDA_OUT2=1; //数据线拉高，发送1
        else IIC_SDA_OUT2=0; 	 //数据线拉低，发送0
        delayUsIn32Mhz(2);
        IIC_SCL2=1;     		     //时钟线拉高，告诉从机，主机数据发送完毕
        delayUsIn32Mhz(2);            //电平保持时间，等待从机接收数据
        IIC_SCL2=0;     		 		 //时钟线拉低，告诉从机，主机需要发送数据
        delayUsIn32Mhz(2);            //电平保持时间，等待时钟线稳定
      }
}


/*
函数功能：IIC接收1个字节数据
返 回 值：收到的数据
*/
uint8_t IIC_ReadOneByteData2(void)
{
    uint8_t i,data;
    IIC_SDA_INPUTMODE2();//初始化SDA为输入模式
    for(i=0;i<8;i++)
    {
        IIC_SCL2=0;     		  //时钟线拉低，告诉从机，主机需要数据
        delayUsIn32Mhz(2);         //电平保持时间，等待从机发送数据
        IIC_SCL2=1;     		  //时钟线拉高，告诉从机，主机现在正在读取数据
        data<<=1;           
        if(IIC_SDA_IN2)data|=0x01;
        delayUsIn32Mhz(2);         //电平保持时间，等待时钟线稳定
    }
    IIC_SCL2=0;     		  		//时钟线拉低，告诉从机，主机需要数据 (必须拉低，否则将会识别为停止信号)
    return data;
}