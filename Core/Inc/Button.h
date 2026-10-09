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

		uint32_t const debounce_ms;
		uint32_t lastTime;
		bool lastState;
		bool stableState;

	public:
		Button(GPIO_TypeDef *port, uint16_t pin, uint32_t debounce_ms);
		bool isPressed() const;
		bool wasPressed();
};

#endif /* INC_BUTTON_H_ */
