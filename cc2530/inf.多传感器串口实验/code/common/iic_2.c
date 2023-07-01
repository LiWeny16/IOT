#include "iic_2.h"
#include "ioCC2530.h"
/*
�������ܣ�IIC�ӿڳ�ʼ��
Ӳ�����ӣ�
SDA��P1.3
SCL��P1.2
*/
void IIC_Init2(void)
{
    P1SEL &= ~(1<<3); //����ͨ��GPIO��ģʽ
    P1SEL &= ~(1<<2); 
    P1DIR |= (1<<3);    //����Ϊ���ģʽ
    P1DIR |= (1<<2);
}

/*
�������ܣ�IIC������ʼ�ź�
*/
void IIC_Start2(void)
{
    IIC_SDA_OUTMODE2(); //��ʼ��SDAΪ���ģʽ
    IIC_SDA_OUT2=1; 	//����������
    IIC_SCL2=1;          //ʱ���� ����
    delayUsIn32Mhz(4);        //��ƽ����ʱ��
    IIC_SDA_OUT2=0;     //����������
    delayUsIn32Mhz(4);        //��ƽ����ʱ��
    IIC_SCL2=0;     	//ʱ��������
}


/*
�������ܣ�IIC����ֹͣ�ź�
*/
void IIC_Stop2(void)
{
      IIC_SDA_OUTMODE2(); //��ʼ��SDAΪ���ģʽ
      IIC_SDA_OUT2=0; 		 //����������
      IIC_SCL2=0;     		 //ʱ��������
      delayUsIn32Mhz(4);        //��ƽ����ʱ��
      IIC_SCL2=1;     		 //ʱ��������
      delayUsIn32Mhz(4);        //��ƽ����ʱ��
      IIC_SDA_OUT2=1; 	        //����������
      delayUsIn32Mhz(4);   
}

/*
�������ܣ���ȡӦ���ź�
�� �� ֵ��1��ʾʧ�ܣ�0��ʾ�ɹ�
*/
uint8_t IIC_GetACK2(void)
{
    uint8_t cnt=0;
    IIC_SDA_INPUTMODE2();//��ʼ��SDAΪ����ģʽ
    IIC_SCL2=1;     		  //ʱ�������ߣ����ߴӻ����������ڿ�ʼ��ȡ����
    while(IIC_SDA_IN2)   //�ȴ��ӻ�Ӧ���ź�
    {
        cnt++;
        if(cnt>250)return 1;
    }
    IIC_SCL2=0;     		  //ʱ�������ͣ����ߴӻ���������Ҫ����
    return 0;
}

/*
�������ܣ�������ӻ�����Ӧ���ź�
�����βΣ�0��ʾӦ��1��ʾ��Ӧ��
*/
void IIC_SendACK2(uint8_t stat)
{
      IIC_SDA_OUTMODE2(); //��ʼ��SDAΪ���ģʽ
      IIC_SCL2=0;     		 //ʱ�������ͣ����ߴӻ���������Ҫ��������
      if(stat)IIC_SDA_OUT2=1; //���������ߣ����ͷ�Ӧ���ź�
      else IIC_SDA_OUT2=0; 	 //���������ͣ�����Ӧ���ź�
      delayUsIn32Mhz(2);            //��ƽ����ʱ�䣬�ȴ�ʱ�����ȶ�
      IIC_SCL2=1;     		     //ʱ�������ߣ����ߴӻ����������ݷ������
      delayUsIn32Mhz(2);            //��ƽ����ʱ�䣬�ȴ��ӻ���������
      IIC_SCL2=0;     		  	 //ʱ�������ͣ����ߴӻ���������Ҫ����
}


/*
�������ܣ�IIC����1���ֽ�����
�����βΣ���Ҫ���͵�����
*/
void IIC_WriteOneByteData2(uint8_t data)
{
      uint8_t i, txd;
      IIC_SDA_OUTMODE2(); //��ʼ��SDAΪ���ģʽ
      IIC_SCL2=0;     		 //ʱ�������ͣ����ߴӻ���������Ҫ��������
      for(i=0;i<8;i++)
      {
        txd=(data&0x80)>>7;  
        data<<=1;
        if(txd)IIC_SDA_OUT2=1; //���������ߣ�����1
        else IIC_SDA_OUT2=0; 	 //���������ͣ�����0
        delayUsIn32Mhz(2);
        IIC_SCL2=1;     		     //ʱ�������ߣ����ߴӻ����������ݷ������
        delayUsIn32Mhz(2);            //��ƽ����ʱ�䣬�ȴ��ӻ���������
        IIC_SCL2=0;     		 		 //ʱ�������ͣ����ߴӻ���������Ҫ��������
        delayUsIn32Mhz(2);            //��ƽ����ʱ�䣬�ȴ�ʱ�����ȶ�
      }
}


/*
�������ܣ�IIC����1���ֽ�����
�� �� ֵ���յ�������
*/
uint8_t IIC_ReadOneByteData2(void)
{
    uint8_t i,data;
    IIC_SDA_INPUTMODE2();//��ʼ��SDAΪ����ģʽ
    for(i=0;i<8;i++)
    {
        IIC_SCL2=0;     		  //ʱ�������ͣ����ߴӻ���������Ҫ����
        delayUsIn32Mhz(2);         //��ƽ����ʱ�䣬�ȴ��ӻ���������
        IIC_SCL2=1;     		  //ʱ�������ߣ����ߴӻ��������������ڶ�ȡ����
        data<<=1;           
        if(IIC_SDA_IN2)data|=0x01;
        delayUsIn32Mhz(2);         //��ƽ����ʱ�䣬�ȴ�ʱ�����ȶ�
    }
    IIC_SCL2=0;     		  		//ʱ�������ͣ����ߴӻ���������Ҫ���� (�������ͣ����򽫻�ʶ��Ϊֹͣ�ź�)
    return data;
}