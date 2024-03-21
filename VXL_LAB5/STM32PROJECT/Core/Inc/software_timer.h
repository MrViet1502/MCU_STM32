/*
 * software_timer.h
 *
 *  Created on: Dec 15, 2023
 *      Author: Quoc Viet
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#define NUM_OF_TIMERS 	2  				// Number of Timers to use

extern int TIME_CYCLE;					// Time cycle

extern int timer_flag[NUM_OF_TIMERS];

void setTimer(int index, int duration);
void clearTimer(int index);
void timerRun();


#endif /* INC_SOFTWARE_TIMER_H_ */
