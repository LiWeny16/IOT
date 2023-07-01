#include "gy30.h"
unsigned int Read_IIC_1_Data()
{
    unsigned char t0;
    unsigned char t1;
    unsigned int t;
    uint8_t r_s=0;
    IIC_Start(); //������ʼ�ź�
    IIC_WriteOneByteData(0x46);
    r_s=IIC_GetACK();//��ȡӦ��
    IIC_WriteOneByteData(0x01);
    r_s=IIC_GetACK();//��ȡӦ��
    IIC_Stop(); //ֹͣ�ź� 
    
    IIC_Start(); //������ʼ�ź�
    IIC_WriteOneByteData(0x46);
    r_s=IIC_GetACK();//��ȡӦ��
    IIC_WriteOneByteData(0x01);
    r_s=IIC_GetACK();//��ȡӦ��
    IIC_Stop(); //ֹͣ�ź� 
    
    IIC_Start(); //������ʼ�ź�
    IIC_WriteOneByteData(0x46);
    r_s=IIC_GetACK();//��ȡӦ��
    IIC_WriteOneByteData(0x10);
    r_s=IIC_GetACK();//��ȡӦ��
    IIC_Stop(); //ֹͣ�ź� 
    
    delayUsIn32Mhz(300); //�ȴ�
    
    IIC_Start(); //������ʼ�ź�
    IIC_WriteOneByteData(0x47);
    r_s=IIC_GetACK();//��ȡӦ��
    
    t0=IIC_ReadOneByteData(); //��������
    IIC_SendACK(0); //����Ӧ���ź�
    t1=IIC_ReadOneByteData(); //��������
    IIC_SendACK(1); //���ͷ�Ӧ���ź�
    IIC_Stop(); //ֹͣ�ź�
    
    t=(((t0<<8)|t1))*5/6;
    return t;  
}