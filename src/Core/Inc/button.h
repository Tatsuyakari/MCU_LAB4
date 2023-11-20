/*
 * button.h
 *
 *  Created on: Nov 6, 2023
 *      Author: kenng
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_
#include "main.h"
#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

void getKeyInputs();
int isButton0Press();
int isButton1Press();
int isButton2Press();
int isButton0Hold();
int isButton1Hold();
int isButton2Hold();

#endif /* INC_BUTTON_H_ */
