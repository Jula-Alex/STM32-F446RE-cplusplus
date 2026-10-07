/*
 * App.cpp
 *
 *  Created on: 6 ott 2026
 *      Author: Alex
 */

#include "App.h"
#include "Led.h"
#include "Button.h"

Led onboardLed(GPIOA, GPIO_PIN_5);

Button onboardButton(GPIOC, GPIO_PIN_13);

void AppInit()
{
	onboardLed.off();
}

void AppLoop()
{
	if (onboardButton.isPressed())
	{
		onboardLed.toggle();
	}
}
