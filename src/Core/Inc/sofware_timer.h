/*
 * sofware_timer.h
 *
 *  Created on: Oct 9, 2023
 *      Author: kenng
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_
#include "main.h"
extern int timer1_flag;
extern int timer2_flag;

void setTimer1(int);
void setTimer2(int);
void timer_run(void);

#endif /* INC_TIMER_H_ */
