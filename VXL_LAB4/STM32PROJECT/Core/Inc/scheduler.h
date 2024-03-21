/*
 * scheduler.h
 *
 *  Created on: Nov 20, 2023
 *      Author: Quoc Viet
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include <stdint.h>
#include <stdio.h>
#include "main.h"
#include <string.h>
#include <toggle_led.h>

extern char str[50];

#define TICK 10
#define MAX_TASK 40
#define NORMAL 0
#define ERROR_SCHEDULER_TOO_MANY_TASK 1
#define ERROR_NO_TASK_TO_DELETE  2

typedef struct {
	void (*pfunction)(void);
	uint32_t Delay;
	uint32_t Period;
	uint8_t Runme;
	uint32_t Task_ID;
} Scheduler_Task;

void Scheduler_Init();
uint32_t Scheduler_Add_Task(void (*pfunction)(),uint32_t delay, uint32_t period);
void Scheduler_Update();
void Scheduler_Dispatch_Task();
uint32_t Scheduler_Delete_Task(uint32_t task_ID);

#endif /* INC_SCHEDULER_H_ */
