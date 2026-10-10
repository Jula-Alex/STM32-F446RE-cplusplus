/*
 * Button.h
 *
 *  Created on: 7 ott 2026
 *      Author: Alex
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "stm32f4xx_hal.h"

class Button
{
	private:
		GPIO_TypeDef *const port;
		uint16_t const pin;

		// Button debouncing
		uint32_t const debounce_ms;
		uint32_t lastTime;
		bool lastState;
		bool stableState;

		// Volatile because its state is changed by an interrupt
		volatile bool interruptFlag;

		// Read only function for read the button state
		bool isPressed() const;
		
		// Activate debounce process
		bool debounceActive;

	public:
		Button(GPIO_TypeDef *port, uint16_t pin, uint32_t debounce_ms);

		// Check for a valid button press and handle debounce
		bool wasPressed();

		// Set the interrupt flag to trigger button processing
		void handleInterrupt();
};

#endif /* INC_BUTTON_H_ */
