/*
 * Uart_int.h
 *
 *  Created on: Jul 2, 2020
 *      Author: mdmad
 */

#ifndef UART_INT_H_
#define UART_INT_H_

void Uart_vidInit(void);

void Uart_vidSendByte(u8 Byte);

u8 Uart_u8ReciveByte(void);

#endif /* UART_INT_H_ */
