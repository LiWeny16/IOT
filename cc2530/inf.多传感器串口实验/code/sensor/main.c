#include "hal_dht11.h"
#include "hal_delay.h"
#include "hal_adc.h"
#include "gy30.h"
#include "uart.h"
#include "iic.h"
#include "ioCC2530.h"
#include "cc2530_ioctl.h"
#include <string.h>
#include <stdio.h>

#define LED1   P1_0 //B1
#define LED2   P1_2 //R1
#define LED3   P1_3 //R2
#define LED4   P1_4 //B2
#define Human1   P0_0
#define Human2   P1_7
/*
static uint8_t mode='0';
static int com_num=0;
static uint8_t com_str[6];
*/
struct enableState{
  int en;
  int led1;
  int led2;
  int led3;
  int led4;
  int light;
  int temp;
  int humi;
  int human;
};

static struct enableState state;

void State_Init()
{
  state.en=1;
  state.led1=0;
  state.led2=0;
  state.led3=0;
  state.led4=0;
  state.light=1;
  state.temp=1;
  state.humi=1;
  state.human=1;
}

void IO_Init()
{
  CC2530_IOCTL(1, 0, CC2530_OUTPUT);
  CC2530_IOCTL(1, 2, CC2530_OUTPUT);
  CC2530_IOCTL(1, 3, CC2530_OUTPUT);
  CC2530_IOCTL(1, 4, CC2530_OUTPUT);
  CC2530_IOCTL(0, 0, CC2530_INPUT_PULLDOWN);
  CC2530_IOCTL(1, 7, CC2530_INPUT_PULLDOWN);
  LED1=0;
  delayMs(SYSCLK_32MHZ, 100);
  LED1=1;
  LED2=0;
  delayMs(SYSCLK_32MHZ, 100);
  LED2=1; 
  LED3=0;
  delayMs(SYSCLK_32MHZ, 100);
  LED3=1;
  LED4=0;
  delayMs(SYSCLK_32MHZ, 100);
  LED4=1;
  return;
}

void refreshLED(int light, long int temp, long int humi, int Human1, int Human2)
{
  if(!state.en)
  {
    LED1=1;
    LED2=1;
    LED3=1;
    LED4=1;
    return;
  }
  if(( light<83 || !state.light ) && ( Human1 || !state.human ) && ( temp>30 || !state.temp ) || state.led1)LED1=0;
  else LED1=1;
  if(( light<83 || !state.light ) && ( Human1 || !state.human ) && ( temp<=30 || !state.temp ) || state.led2)LED2=0;
  else LED2=1;
  if(( light<83 || !state.light ) && ( Human2 || !state.human ) && ( temp<=30 || !state.temp ) || state.led3)LED3=0;
  else LED3=1;
  if(( light<83 || !state.light ) && ( Human2 || !state.human ) && ( temp>30 || !state.temp ) || state.led4)LED4=0;
  else LED4=1;
  return;
}
#pragma vector = URX0_VECTOR
__interrupt void URX0_ISR(void)
{
    uint8_t rxChar;
    URX0IF = 0;
    rxChar = U0DBUF;
    printf("%c", rxChar);
    if(rxChar=='0')state.en=1-state.en;
    else if(rxChar=='1')
      state.led1=1-state.led1;
    else if(rxChar=='2')
      state.led2=1-state.led2;
    else if(rxChar=='3')
      state.led3=1-state.led3;
    else if(rxChar=='4')
      state.led4=1-state.led4;
    else if(rxChar=='5')
      state.light=1-state.light;
    else if(rxChar=='6')
      state.temp=1-state.temp;
    else if(rxChar=='7')
      state.humi=1-state.humi;
    else if(rxChar=='8')
      state.human=1-state.human;
}  

void main(void)
{          
    uint16_t lightDat;
    halDHT11Data_t dht11Dat;
    uint8_t dataStr[200];
    uint8_t stateStr[10];
    
    State_Init();
    initUart0(USART_BAUDRATE_9600);
    IIC_Init();
    halDHT11Init();
    IO_Init();
    
    setSystemClk32MHZ();
    
    int humanCount1=0, humanCount2=0, humanFlag1=0, humanFlag2=0;

    while(1)
    {
      lightDat = Read_IIC_1_Data();
      dht11Dat = halDHT11GetData();
      if(Human1)
      {
        humanFlag1=1;
        humanCount1=0;
      }
      else humanCount1++;
      if(Human2)
      {
        humanFlag2=1;
        humanCount2=0;
      }
      else humanCount2++;
      if(humanCount1>=10)humanFlag1=0;
      if(humanCount2>=10)humanFlag2=0;
      
      sprintf((char *)dataStr, "%d,%ld,%ld,%d,%d,%d%d%d%d%d%d%d%d%d?",
              lightDat, dht11Dat.temp, dht11Dat.humi, humanFlag1, humanFlag2,
              state.en, state.led1, state.led2, state.led3, state.led4,
              state.light, state.temp, state.humi, state.human);
      uart0Send((unsigned char *)&dataStr, strlen((const char *)&dataStr));    
      refreshLED(lightDat, dht11Dat.temp, dht11Dat.humi, humanFlag1, humanFlag2);
      delayMs(SYSCLK_32MHZ, 1000);
    }
}

