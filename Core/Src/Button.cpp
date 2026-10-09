/*
 * Button.cpp
 *
 *  Created on: 7 ott 2026
 *      Author: Alex
 */

#include <Button.h>

Button::Button(GPIO_TypeDef *port, uint16_t pin, uint32_t debounce_ms) :
		port(port), pin(pin), debounce_ms(debounce_ms), lastTime(0), lastState(false), stableState(false)
{
}

// According to the schematic, the button is active-low
bool Button::isPressed() const
{
	return !HAL_GPIO_ReadPin(port, pin);
}

bool Button::wasPressed()
{
	uint32_t currentTime = HAL_GetTick();

	bool currentState = isPressed();

	if (currentState != lastState)
	{
		lastState = currentState;
		lastTime = currentTime;
	}

	if (currentTime - lastTime >= debounce_ms && (lastState != stableState))
	{
		stableState = lastState;

		if (stableState)
		{
			return true;
		}
	}
	return false;
}

