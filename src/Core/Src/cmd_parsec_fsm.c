/*
 * cmd_parsec_fsm.c
 *
 *  Created on: Nov 20, 2023
 *      Author: kenng
 */

#include "string.h"
#include "stdio.h"
#include "cmd_parser_fsm.h"
#include "global.h"
#include "main.h"

/*
In this lab, a simple communication protocol is implemented as follows:
• From the console, user types !RST# to ask for a sensory data.
• The STM32 response the ADC_value, following a format !ADC=1234#, where
1234 presents for the value of ADC_value variable.
• The user ends the communication by sending !OK#
The timeout for waiting the !OK# at STM32 is 3 seconds. After this period, its packet
is sent again. The value is kept as the previous packet.*/
void command_parser_fsm()
{
    char current_char = buffer[index_buffer - 1];

    switch (status)
    {
    case INIT:
        if (current_char == 'R')
            status = input_R;
        else if (current_char == 'O')
            status = end_O;
        break;

    case input_R:
        if (current_char == 'R')
            status = input_R;
        else if (current_char == 'S')
            status = input_S;
        else
            status = INIT;
        break;

    case input_S:
        if (current_char == 'S')
            status = INIT;
        else if (current_char == 'T')
            status = input_T;
        else
            status = INIT;
        break;

    case input_T:
        command_flag = 1;
        status = INIT;
        break;

    case end_O:
        if (current_char == 'O')
            status = end_O;
        else if (current_char == 'K')
            status = end_K;
        else
            status = INIT;
        break;

    case end_K:
        command_flag = 2;
        status = INIT;
        break;

    default:
        break;
    }
}
