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

Button onboardButton(GPIOC, GPIO_PIN_13, 40);

void AppInit()
{
	onboardLed.off();
}

void AppLoop()
{
	if (onboardButton.wasPressed())
	{
		onboardLed.toggle();
	}
}

extern "C" void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if (GPIO_Pin == GPIO_PIN_13)
	{
		onboardButton.handleInterrupt();
	}
}
