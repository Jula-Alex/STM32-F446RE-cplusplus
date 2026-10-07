/*
 * App.cpp
 *
 *  Created on: 6 ott 2026
 *      Author: Alex
 */

#include "App.h"
#include "Led.h"

Led onboardLed(GPIOA, GPIO_PIN_5);

void AppInit()
{
	onboardLed.off();
}

void AppLoop()
{
	onboardLed.toggle();
	HAL_Delay(500);
}
