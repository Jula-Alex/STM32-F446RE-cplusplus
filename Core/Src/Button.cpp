/*
 * Button.cpp
 *
 *  Created on: 7 ott 2026
 *      Author: Alex
 */

#include <Button.h>

Button::Button(GPIO_TypeDef *port, uint16_t pin, uint32_t debounce_ms) :
		port(port), pin(pin), debounce_ms(debounce_ms), lastTime(0), lastState(false), stableState(false), interruptFlag(false), debounceActive(false)
{
}

// According to the schematic, the button is active-low
bool Button::isPressed() const
{
	// Invert the pin state to normalize the active-low input
	return !HAL_GPIO_ReadPin(port, pin);
}

bool Button::wasPressed()
{
	// If an interrupt occurs, check whether the state has changed and set the debounceActive flag
	if (interruptFlag)
	{
		uint32_t currentTime = HAL_GetTick();
		interruptFlag = false;

		bool currentState = isPressed();

		// If true, start the debounce process
		if (currentState != lastState)
		{
			lastState = currentState;
			lastTime = currentTime;
			debounceActive = true;
		}
	}

	// If true, pool the button
	if (debounceActive)
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
				debounceActive = false;
				return true;
			}
		}
	}

	return false;
}

void Button::handleInterrupt()
{
	interruptFlag = true;
}
