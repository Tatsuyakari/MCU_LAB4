/*
 * uart_fsm.c
 *
 *  Created on: Nov 20, 2023
 *      Author: kenng
 */
#include "string.h"
#include "stdio.h"
#include "cmd_parser_fsm.h"
#include "global.h"
#include "main.h"
#include "sofware_timer.h"
#include "uart_fsm.h"

void uart_communication_fsm()
{
    switch (status1)
    {
        char strBuffer[50]; // Adjust the size as needed
    case RECEIVE:
        if (command_flag == 1)
        {
            ADC_value = HAL_ADC_GetValue(&hadc1) * 5 / 4096;
            status1 = TRANSMIT;
            command_flag = 0;
        }
        break;

    case TRANSMIT:
        sprintf(strBuffer, "ADC value = %d\r\n", ADC_value);
        HAL_UART_Transmit(&huart2, (uint8_t *)strBuffer, strlen(strBuffer), 1000);
        setTimer1(3000);
        status1 = END;
        break;

    case END:
        if (timer1_flag == 1)
            status1 = TRANSMIT;
        else if (command_flag == 2)
        {
            command_flag = 0;
            status1 = RECEIVE;
        }
        break;

    default:
        break;
    }
}