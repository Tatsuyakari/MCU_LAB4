/*
 * global.h
 *
 *  Created on: Nov 6, 2023
 *      Author: kenng
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_
#define INIT 1
#define AUTO_RED 2
#define AUTO_GREEN 3
#define AUTO_YELLOW 4

#include "main.h"
#include "sofware_timer.h"
#include "button.h"
#include "7SEG.h"
extern int status;
extern int status1;
extern int RED_TIME;
extern int GREEN_TIME;
extern int YELLOW_TIME;
extern int LED_COUNDOWN;
extern int LED_COUNDOWN_1;

#endif /* INC_GLOBAL_H_ */
