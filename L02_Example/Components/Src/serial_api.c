/**
  ******************************************************************************
  * @file		: serial_api.c
  * @author  	: AW		Adrian.Wojcik@put.poznan.pl
  * @version 	: 1.3.0
  * @date    	: Oct 19, 2022
  * @brief   	: Serial API: simple output control and input readout
  *
  ******************************************************************************
  */

/* Private includes ----------------------------------------------------------*/
#include <string.h>
#include <stdlib.h>
#include "serial_api.h"

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Public variables ----------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/* Public function prototypes ------------------------------------------------*/

/* Private functions ---------------------------------------------------------*/

/* Public functions ----------------------------------------------------------*/
/**
 * @brief Serial API LED control message reading
 * @param[in] 	  msg		: Input message
 * @param[in/out] leds		: Serial API LED control structure array
 * @param[in] 	  leds_n	: Serial API LED control structure array length
 */
void SERIAL_API_LED_ReadMsg(const char* msg, SERIAL_API_LED_TypeDef* leds, int leds_n)
{
	for(int i = 0; i < leds_n; i++)
	{
		/* Message structure: 3 character ID + state as 0/1 e.g. LD11 to turn LD1 on */
		if(strncmp(leds[i].Id, msg, 3) == 0)
			leds[i].State = strtol(&msg[3], NULL, 10);
	}
}