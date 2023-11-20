/*
 * fsm_automatic.c
 *
 *  Created on: Nov 6, 2023
 *      Author: kenng
 */

#include "fsm_automatic.h"
void LED_COUNDOWN_7SEG()
{
    if (timer2_flag == 1)
    {
        LED_COUNDOWN = LED_COUNDOWN - 1;
        LED_COUNDOWN_1 = LED_COUNDOWN_1 - 1;
        set_timer2(100);
    }
    if (timer1_flag == 1)
    {
        ledSystem0(LED_COUNDOWN, LED_COUNDOWN_1);
        set_timer1(25);
    }
}

void fsm_automatic()
{
    switch (status)
    {
    case INIT:
        status = AUTO_RED;
        set_timer3(RED_TIME);
        LED_COUNDOWN = RED_TIME / 100;

        break;
    case AUTO_RED:
        HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, GPIO_PIN_RESET);     // turn on red1 led
        HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, GPIO_PIN_SET); // turn off yellow1 led
        HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, GPIO_PIN_SET);   // turn off green1 led
        if (timer3_flag == 1)
        {
            status = AUTO_GREEN;
            set_timer3(GREEN_TIME);
            LED_COUNDOWN = GREEN_TIME / 100;
        }
        break;
    case AUTO_GREEN:
        HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, GPIO_PIN_SET);
        if (timer3_flag == 1)
        {
            status = AUTO_YELLOW;
            set_timer3(YELLOW_TIME);
            LED_COUNDOWN = YELLOW_TIME / 100;
        }
        break;

    case AUTO_YELLOW:
        HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, GPIO_PIN_SET);
        if (timer3_flag == 1)
        {
            status = AUTO_RED;
            set_timer3(RED_TIME);
            LED_COUNDOWN = RED_TIME / 100;
        }
        break;
    }
}

void fsm_automatic_2()
{
    switch (status1)
    {
    case INIT:
        status1 = AUTO_GREEN;  // Start with AUTO_GREEN state instead of AUTO_RED
        set_timer4(GREEN_TIME); // Set timer for GREEN_TIME
        LED_COUNDOWN_1 = GREEN_TIME / 100; // Set countdown for GREEN_TIME

        HAL_GPIO_WritePin(RED_GPIO_Port, RED_Pin, GPIO_PIN_SET);     // turn off red1 led
        HAL_GPIO_WritePin(YELLOW_GPIO_Port, YELLOW_Pin, GPIO_PIN_SET); // turn off yellow1 led
        HAL_GPIO_WritePin(GREEN_GPIO_Port, GREEN_Pin, GPIO_PIN_RESET);   // turn on green1 led
        break;

    case AUTO_GREEN:
        HAL_GPIO_WritePin(RED_GPIO_Port, RED_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GREEN_GPIO_Port, GREEN_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(YELLOW_GPIO_Port, YELLOW_Pin, GPIO_PIN_SET);
        if (timer4_flag == 1)
        {
            status1 = AUTO_YELLOW;
            set_timer4(YELLOW_TIME);
            LED_COUNDOWN_1 = YELLOW_TIME / 100;
        }
        break;

    case AUTO_YELLOW:
        HAL_GPIO_WritePin(GREEN_GPIO_Port, GREEN_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(YELLOW_GPIO_Port, YELLOW_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(RED_GPIO_Port, RED_Pin, GPIO_PIN_SET);
        if (timer4_flag == 1)
        {
            status1 = AUTO_RED;
            set_timer4(RED_TIME);
            LED_COUNDOWN_1 = RED_TIME / 100;
        }
        break;

    case AUTO_RED:
        HAL_GPIO_WritePin(RED_GPIO_Port, RED_Pin, GPIO_PIN_RESET);     // turn on red1 led
        HAL_GPIO_WritePin(YELLOW_GPIO_Port, YELLOW_Pin, GPIO_PIN_SET); // turn off yellow1 led
        HAL_GPIO_WritePin(GREEN_GPIO_Port, GREEN_Pin, GPIO_PIN_SET);   // turn off green1 led
        if (timer4_flag == 1)
        {
            status1 = AUTO_GREEN;
            set_timer4(GREEN_TIME);
            LED_COUNDOWN_1 = GREEN_TIME / 100;
        }
        break;
    }
}
