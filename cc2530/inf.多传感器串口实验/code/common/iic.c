#include "iic.h"
#include "ioCC2530.h"
/*
�������ܣ�IIC�ӿڳ�ʼ��
Ӳ�����ӣ�
SDA��P0.7
SCL��P0.1
*/
void IIC_Init(void)
{
    P0SEL &= ~(1<<7); //����ͨ��GPIO��ģʽ
    P0SEL &= ~(1<<1); 
    P0DIR |= (1<<7);    //����Ϊ���ģʽ
    P0DIR |= (1<<1);
}

/*
�������ܣ�IIC������ʼ�ź�
*/
void IIC_Start(void)
{
    IIC_SDA_OUTMODE(); //��ʼ��SDAΪ���ģʽ
    IIC_SDA_OUT=1; 	//����������
    IIC_SCL=1;          //ʱ���� ����
    delayUsIn32Mhz(4);        //��ƽ����ʱ��
    IIC_SDA_OUT=0;     //����������
    delayUsIn32Mhz(4);        //��ƽ����ʱ��
    IIC_SCL=0;     	//ʱ��������
}


/*
�������ܣ�IIC����ֹͣ�ź�
*/
void IIC_Stop(void)
{
      IIC_SDA_OUTMODE(); //��ʼ��SDAΪ���ģʽ
      IIC_SDA_OUT=0; 		 //����������
      IIC_SCL=0;     		 //ʱ��������
      delayUsIn32Mhz(4);        //��ƽ����ʱ��
      IIC_SCL=1;     		 //ʱ��������
      delayUsIn32Mhz(4);        //��ƽ����ʱ��
      IIC_SDA_OUT=1; 		 //����������
}

/*
�������ܣ���ȡӦ���ź�
�� �� ֵ��1��ʾʧ�ܣ�0��ʾ�ɹ�
*/
uint8_t IIC_GetACK(void)
{
    uint8_t cnt=0;
    IIC_SDA_INPUTMODE();//��ʼ��SDAΪ����ģʽ
    IIC_SDA_OUT=1; 		  //����������
    delayUsIn32Mhz(2);         //��ƽ����ʱ��
    IIC_SCL=0;     		  //ʱ�������ͣ����ߴӻ���������Ҫ����
    delayUsIn32Mhz(2);         //��ƽ����ʱ�䣬�ȴ��ӻ���������
    IIC_SCL=1;     		  //ʱ�������ߣ����ߴӻ����������ڿ�ʼ��ȡ����
    while(IIC_SDA_IN)   //�ȴ��ӻ�Ӧ���ź�
    {
        cnt++;
        if(cnt>250)return 1;
    }
    IIC_SCL=0;     		  //ʱ�������ͣ����ߴӻ���������Ҫ����
    return 0;
}

/*
�������ܣ�������ӻ�����Ӧ���ź�
�����βΣ�0��ʾӦ��1��ʾ��Ӧ��
*/
void IIC_SendACK(uint8_t stat)
{
      IIC_SDA_OUTMODE(); //��ʼ��SDAΪ���ģʽ
      IIC_SCL=0;     		 //ʱ�������ͣ����ߴӻ���������Ҫ��������
      if(stat)IIC_SDA_OUT=1; //���������ߣ����ͷ�Ӧ���ź�
      else IIC_SDA_OUT=0; 	 //���������ͣ�����Ӧ���ź�
      delayUsIn32Mhz(2);            //��ƽ����ʱ�䣬�ȴ�ʱ�����ȶ�
      IIC_SCL=1;     		     //ʱ�������ߣ����ߴӻ����������ݷ������
      delayUsIn32Mhz(2);            //��ƽ����ʱ�䣬�ȴ��ӻ���������
      IIC_SCL=0;     		  	 //ʱ�������ͣ����ߴӻ���������Ҫ����
}


/*
�������ܣ�IIC����1���ֽ�����
�����βΣ���Ҫ���͵�����
*/
void IIC_WriteOneByteData(uint8_t data)
{
      uint8_t i;
      IIC_SDA_OUTMODE(); //��ʼ��SDAΪ���ģʽ
      IIC_SCL=0;     		 //ʱ�������ͣ����ߴӻ���������Ҫ��������
      for(i=0;i<8;i++)
      {
          if(data&0x80)IIC_SDA_OUT=1; //���������ߣ�����1
          else IIC_SDA_OUT=0; 	 //���������ͣ�����0
          IIC_SCL=1;     		     //ʱ�������ߣ����ߴӻ����������ݷ������
          delayUsIn32Mhz(2);            //��ƽ����ʱ�䣬�ȴ��ӻ���������
          IIC_SCL=0;     		 		 //ʱ�������ͣ����ߴӻ���������Ҫ��������
          delayUsIn32Mhz(2);            //��ƽ����ʱ�䣬�ȴ�ʱ�����ȶ�
          data<<=1;              //�ȷ���λ
      }
}


/*
�������ܣ�IIC����1���ֽ�����
�� �� ֵ���յ�������
*/
uint8_t IIC_ReadOneByteData(void)
{
    uint8_t i,data;
    IIC_SDA_INPUTMODE();//��ʼ��SDAΪ����ģʽ
    for(i=0;i<8;i++)
    {
        IIC_SCL=0;     		  //ʱ�������ͣ����ߴӻ���������Ҫ����
        delayUsIn32Mhz(2);         //��ƽ����ʱ�䣬�ȴ��ӻ���������
        IIC_SCL=1;     		  //ʱ�������ߣ����ߴӻ��������������ڶ�ȡ����
        data<<=1;           
        if(IIC_SDA_IN)data|=0x01;
        delayUsIn32Mhz(2);         //��ƽ����ʱ�䣬�ȴ�ʱ�����ȶ�
    }
    IIC_SCL=0;     		  		//ʱ�������ͣ����ߴӻ���������Ҫ���� (�������ͣ����򽫻�ʶ��Ϊֹͣ�ź�)
    return data;
}