/*
 * software_timer.c
 *
 *  Created on: Dec 15, 2023
 *      Author: Quoc Viet
 */

#include "software_timer.h"

int TIME_CYCLE; // Time cycle

// Khoi tao cac mang timer_counter va timer_flag voi so luong phan tu moi mang bang NUM_OF_TIMERS
int timer_counter[NUM_OF_TIMERS] = {0};
int timer_flag[NUM_OF_TIMERS] = {0};

// setTimer (index: Timer duoc xet toi; duration: Thoi gian setTimer (don vi: ms))
void setTimer(int index, int duration) {
	timer_counter[index] = duration / TIME_CYCLE;
	timer_flag[index] = 0;
}

// clearTimer (timer_flag[index] = 0, timer_counter[index] = 0)
void clearTimer(int index) {
	timer_counter[index] = 0;
	timer_flag[index] = 0;
}

// timerRun
void timerRun(){
	// Dung vong lap "for" de xet doi voi tung Timer
	// Voi moi Timer, so chu ki timer_counter se dem nguoc, neu timer_counter == 0 thi timer da dem nguoc ve 0, khi do timer_flag se bao gia tri bang 1
	for (int i = 0; i < NUM_OF_TIMERS; i++) {
		if (timer_counter[i] > 0){
			timer_counter[i]--;
			if (timer_counter[i] <= 0){
				timer_flag[i] = 1;
			}
		}
	}
}
