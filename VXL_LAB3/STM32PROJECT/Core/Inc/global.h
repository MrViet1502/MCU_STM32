/*
 * global.h
 *
 *  Created on: Nov 5, 2023
 *      Author: Quoc Viet
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

//mode of system
extern int mode;

#define INIT_SYSTEM	0
#define NORMAL_MODE	1
#define MODIFY_RED_MODE 2
#define MODIFY_YELLOW_MODE 3
#define MODIFY_GREEN_MODE 4
//state of led traffic
#define RED	10
#define YELLOW 11
#define GREEN 12




//Timer
#define TIME_CYCLE 10 //(10ms)
#define NUMBER_OF_TIMER	10

//SINGLE LED OF TRAFFIC

extern int duration_time_of_RED;
extern int duration_time_of_YELLOW;
extern int duration_time_of_GREEN;

extern int buffer_duration_time;

extern int state_led_traffic_1;
extern int state_led_traffic_2;

// BUTTON
#define NUMBER_OF_BUTTON 3

#define BUTTON_IS_PRESSED GPIO_PIN_RESET
#define BUTTON_IS_RELEASED GPIO_PIN_SET

#define BUTTON_RELEASED	20
#define BUTTON_PRESSED 21
#define BUTTON_PRESSED_3S 22



#endif /* INC_GLOBAL_H_ */
