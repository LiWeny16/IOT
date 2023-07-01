#ifndef _GY30_2_H
#define _GY30_2_H
#include "hal_delay.h"
#include "iic_2.h"
#include "uart.h"

typedef struct  {
    unsigned  int temp; //!< Temperature, 0~50.
    unsigned  int humi; //!< Humidity, 20~95.
} SHTDATA;
SHTDATA Read_IIC_2_Data(void);
#endif