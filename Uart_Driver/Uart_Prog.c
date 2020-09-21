/*
 * Uart_Prog.c
 *
 *  Created on: Jul 2, 2020
 *      Author: mdmad
 */


#include "../Lib/Std_types.h"
#include "../Lib/Bit_math.h"

#include "Uart_int.h"
#include "Uart_priv.h"
#include "Uart_cfg.h"

void Uart_vidInit(void)
{
	/* Temprory variable to write UCSRC register */
	u8 Temp_u8UcsrcData;
	/* clear any rubbish value in the variable */
	Temp_u8UcsrcData = 0;

	/* enable Rx and Tx */
	SET_BIT(UCSRB,4);
	SET_BIT(UCSRB,3);
	/* asynchronous mode */
	CLR_BIT(UCSRB,3);
	/* Disable parity checking */
	CLR_BIT(Temp_u8UcsrcData,5);
	CLR_BIT(Temp_u8UcsrcData,4);
	/* select one bit stop */
	CLR_BIT(Temp_u8UcsrcData,3);

	/* select 8 bit character size */
	CLR_BIT(UCSRB,2);
	CLR_BIT(Temp_u8UcsrcData,2);
	CLR_BIT(Temp_u8UcsrcData,1);

	/* update UCSRC reg with temp Data */
	UCSRC = Temp_u8UcsrcData;


	/* configure "9600" Baudrate */
	CLR_BIT(UCSRA,1);

	UBRRH = 0;
	UBRRL = 51;

}

void Uart_vidSendByte(u8 Byte)
{
	/* Waiting till UDR reg is empty */
	while(GET_BIT(UCSRA,5) == 0);

	/* Update UDR reg with data needs to be sent */
	UDR = Byte;


}

u8 Uart_u8ReciveByte(void)
{
	/* Waiting till RxC flag raise */
	while(GET_BIT(UCSRA,7) == 0);

	/* return the recived Byte */
	return UDR;
}
