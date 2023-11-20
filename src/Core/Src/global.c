/*
 * global.c
 *
 *  Created on: Nov 7, 2023
 *      Author: kenng
 */
#include "global.h"
#include "cmd_parser_fsm.h"
#include "uart_fsm.h"   

uint8_t temp = 0;
uint8_t buffer[MAX_BUFFER_SIZE];
uint8_t index_buffer = 0;
uint8_t buffer_flag = 0;
uint8_t status;
uint8_t status1;
uint8_t command_flag = 0;
uint8_t ADC_value = 0;
uint8_t str[12];
