/*
 * Button.cpp
 *
 *  Created on: 7 ott 2026
 *      Author: Alex
 */

#include <Button.h>

Button::Button(GPIO_TypeDef *port, uint16_t pin) :
		port(port), pin(pin)
{
}

// According to the schematic, the button is active-low
bool Button::isPressed() const
{
	return !HAL_GPIO_ReadPin(port, pin);
}

