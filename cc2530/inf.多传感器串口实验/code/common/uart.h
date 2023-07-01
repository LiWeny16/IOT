#ifndef UART_H
#define UART_H

#ifdef __cplusplus
extern "C" {
#endif
  
/** @brief Baudrate in 32MHz
 */  
typedef enum {
  USART_BAUDRATE_2400 = 0, //!< 2400
  USART_BAUDRATE_4800,     //!< 4800
  USART_BAUDRATE_9600,     //!< 9600
  USART_BAUDRATE_14400,    //!< 14400
  USART_BAUDRATE_19200,    //!< 19200
  USART_BAUDRATE_28800,    //!< 28800
  USART_BAUDRATE_38400,    //!< 38400
  USART_BAUDRATE_57600,    //!< 57600
  USART_BAUDRATE_76800,    //!< 76800
  USART_BAUDRATE_115200,   //!< 115200
  USART_BAUDRATE_230400,   //!< 230400
} Usart_BaudrateIn32MHz_t; 


void initUart0(Usart_BaudrateIn32MHz_t baudrate);
void uart0Send(unsigned char *pMsg, unsigned int msgLen);

#ifdef __cplusplus
}
#endif

#endif /* #ifndef UART_H */
