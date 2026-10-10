/*
 * App.h
 *
 *  Created on: 6 ott 2026
 *      Author: Alex
 */

#ifndef INC_APP_H_
#define INC_APP_H_

// Here is the bridge between C and C++

#ifdef __cplusplus
extern "C"
{
#endif

// For now, it only turns off the LED(s)
void AppInit();

// Moves the main loop logic from main.c to C++ in App.cpp
void AppLoop();

#ifdef __cplusplus
}
#endif

#endif /* INC_APP_H_ */
