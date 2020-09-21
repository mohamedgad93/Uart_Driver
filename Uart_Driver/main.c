/*
 * main.c
 *
 *  Created on: Jul 2, 2020
 *      Author: mdmad
 */


#include "../Lib/Std_types.h"
#include "../Lib/Bit_math.h"

#include "Uart_int.h"
#include "Led_int.h"

int main(void)
{
	/* declare variable to save received data via Uart*/
	u8 App_u8ReceivedData;
	/*Initialize Uart communication protocol*/

	Uart_vidInit();

	/*initialize led*/
	Led_vidInit(LED_1);

	while(1)
	{
		/* receive new data from Uart */
		App_u8ReceivedData = Uart_u8ReciveByte();

		/* check if the received byte is 'a' and turn on led */
		if(App_u8ReceivedData == 'a')
		{
			Led_vidTurnOn(LED_1);
			Uart_vidSendByte('o');
			Uart_vidSendByte('n');
			Uart_vidSendByte('\r'); //return cersor to home
			Uart_vidSendByte('\n'); //new line
		}
		/* check if the received byte is 's' and turn off led */
		else if(App_u8ReceivedData == 's')
		{
			Led_vidTurnOff(LED_1);
			Uart_vidSendByte('o');
			Uart_vidSendByte('f');
			Uart_vidSendByte('f');
			Uart_vidSendByte('\r'); //return cersor to home
			Uart_vidSendByte('\n'); //new line
		}

	}

	return 0;
}
