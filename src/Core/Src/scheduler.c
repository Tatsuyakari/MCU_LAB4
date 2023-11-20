/*
 * scheduler.c
 *
 *  Created on: Nov 20, 2023
 *      Author: kenng
 */
#include "scheduler.h"
sTasks SCH_tasks_G[SCH_MAX_TASKS];
uint8_t current_index_task = 0;

void SCH_Init(void)
{
}
void SCH_Add_Task(void (*pFunction)(), uint32_t DELAY, uint32_t PERIOD)
{
    SCH_tasks_G[current_index_task].pTask = pFunction;
    SCH_tasks_G[current_index_task].Delay = DELAY;
    SCH_tasks_G[current_index_task].Period = PERIOD;
    SCH_tasks_G[current_index_task].RunMe = 0;
    SCH_tasks_G[current_index_task].TaskID = current_index_task;
    current_index_task++;
}
void SCH_Update(void)
{
    for (int i = 0; i < current_index_task; i++)
    {
        if (SCH_tasks_G[i].Delay > 0)
        {
            SCH_tasks_G[i].Delay--;
        }
        else
        {
            SCH_tasks_G[i].Delay = SCH_tasks_G[i].Period;
            SCH_tasks_G[i].RunMe += 1;
        }
    }
}
void SCH_Dispatch_Tasks(void)
{
    for (int i = 0; i < current_index_task; i++)
    {
        if (SCH_tasks_G[i].RunMe > 0)
        {
            (*SCH_tasks_G[i].pTask)();
            SCH_tasks_G[i].RunMe -= 1;
        }
    }
}
