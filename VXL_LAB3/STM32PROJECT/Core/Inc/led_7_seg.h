/*
 * led_7_seg.h
 *
 *  Created on: Nov 5, 2023
 *      Author: Quoc Viet
 */

#ifndef INC_LED_7_SEG_H_
#define INC_LED_7_SEG_H_

#include "global.h"
#include "main.h"
#include "software_timer.h"


//LED 7 SEGMENT
extern int led_7_seg_buffer[4];
extern int index_led_7_seg;



//turn_on_led_7seg control the ENi pin
void turn_on_led_7seg(int index);

//display_led_7seg display led 7 segment (0 - 9);
void display_led_7seg(int number);

//update value of buffer of led 7 seg at index 0 and  index 1
//number1 will update buffer[0] and buffer[1]
void update_2_buffer_led_7seg_left(int number1);


//update value of buffer of led 7 seg at index 2 and  index 3
//number2 will update buffer[2] and buffer[3]
void update_2_buffer_led_7seg_right(int number2);

// running in while(1), display led 7 segment 0  to 3 and repeat this index(0 - 1 - 2 - 3 - 0 - 1 -....).
void led_7seg_run();


#endif /* INC_LED_7_SEG_H_ */
