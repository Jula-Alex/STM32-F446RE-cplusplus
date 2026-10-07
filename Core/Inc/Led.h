/*
 * Led.h
 *
 *  Created on: 6 ott 2026
 *      Author: Alex
 */

#ifndef INC_LED_H_
#define INC_LED_H_

#include "stm32f4xx_hal.h"

class Led
{
	private:
		GPIO_TypeDef *const port;
		const uint16_t pin;
		bool state;

	public:
		Led(GPIO_TypeDef *const port, const uint16_t pin);
		void on();
		void off();
		void toggle();
		bool isOn() const;
};

#endif /* INC_LED_H_ */
