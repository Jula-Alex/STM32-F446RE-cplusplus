/*
 * Led.cpp
 *
 *  Created on: 6 ott 2026
 *      Author: Alex
 */

#include "Led.h"

Led::Led(GPIO_TypeDef *port, uint16_t pin) :
		port(port), pin(pin), state(false)
{
}

void Led::on()
{
	HAL_GPIO_WritePin(port, pin, GPIO_PIN_SET);
	state = true;
}

void Led::off()
{
	HAL_GPIO_WritePin(port, pin, GPIO_PIN_RESET);
	state = false;
}

void Led::toggle()
{
	HAL_GPIO_TogglePin(port, pin);
	state = !state;
}

bool Led::isOn() const
{
	return state;
}

