/*
 * software_timer.c
 *
 *  Created on: Oct 9, 2023
 *      Author: kenng
 */
#include "sofware_timer.h"
#include "scheduler.h"
#include "main.h"
#define TICK 10

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    // SCH_Update();
    timer_run();
}

int timer1_flag = 0;
int timer1_counter = 0;
int timer2_flag = 0;
int timer2_counter = 0;

void setTimer1(int duration)
{
    timer1_counter = duration / TICK;
    timer1_flag = 0;
}
void setTimer2(int duration)
{
    timer2_counter = duration / TICK;
    timer2_flag = 0;
}

void timer_run()
{
    if (timer1_counter > 0)
    {
        timer1_counter--;
        if (timer1_counter == 0)
            timer1_flag = 1;
    }
    if (timer2_counter > 0)
    {
        timer2_counter--;
        if (timer2_counter == 0)
            timer2_flag = 1;
    }
}