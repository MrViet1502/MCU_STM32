/*
 * global.c
 *
 *  Created on: Dec 15, 2023
 *      Author: Quoc Viet
 */


#include "global.h"

// State init
int status_parser = INIT_STR;
int status_uart = WAIT_RST;

uint8_t temp = 0;
uint8_t buffer[MAX_BUFFER_SIZE];
uint8_t index_buffer = 0;
uint8_t buffer_flag = 0;

uint8_t command[MAX_BUFFER_SIZE];
uint8_t command_index = 0;
uint8_t command_flag = 0;

char str[50];
uint32_t ADC_value = 0;
