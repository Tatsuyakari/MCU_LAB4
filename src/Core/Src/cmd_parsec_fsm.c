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
