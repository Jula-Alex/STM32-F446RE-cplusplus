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

		// Static array of Button pointers for interrupt instances
		// The Button class owns this array, and each object that uses interrupts will be registered in it
		// The array has 16 elements because there are 16 EXTI lines
		static Button *instances[16];

		// Function that extracts the bit index of the set bit from the GPIO bitmask
		static uint8_t pinToIndex(uint16_t gpioPin);

	public:
		Button(GPIO_TypeDef *port, uint16_t pin, uint32_t debounce_ms);

		// Check for a valid button press and handle debounce
		bool wasPressed();

		// Set the interrupt flag to trigger button processing
		void handleInterrupt();

		// Handle the interrupt and select the correct object to call
		static void dispatchInterrupt(uint16_t gpioPin);
};

#endif /* INC_BUTTON_H_ */
