#include "uart.h"
#include "hal_delay.h"
#include "hal_adc.h"
#include "cc2530_ioctl.h"
#include <string.h>
#include <stdio.h>

void main(void)
{
    uint8_t adcVal;
    char adcStr[10] = {0};
  
    setSystemClk32MHZ();
    
    initUart0(USART_BAUDRATE_115200);
    
    CC2530_IOCTL(0, 7, CC2530_INPUT_PULLUP);
    HalAdcInit();
  
    while(1) {
        adcVal = HalAdcRead(HAL_ADC_CHN_AIN7, HAL_ADC_RESOLUTION_8);
        sprintf(adcStr, "%d\r\n", adcVal);
        uart0Send((unsigned char *)adcStr, strlen(adcStr));        
        delayMs(SYSCLK_32MHZ, 2000);
    }
}
