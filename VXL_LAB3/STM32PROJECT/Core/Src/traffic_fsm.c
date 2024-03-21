/*
 * traffic_fsm.c
 *
 *  Created on: Nov 5, 2023
 *      Author: Quoc Viet
 */


#include "traffic_fsm.h"


void fsm_traffic_1_run(){
	switch(state_led_traffic_1){

		case RED:

			turn_on_traffic_led_1();
			//STATE STRANSION
			// time out, RED-->GREEN
			if(is_timer_timeout(4)){
				state_led_traffic_1 =GREEN;
				set_timer(4,duration_time_of_GREEN);
			}
		break;

		case YELLOW:

			turn_on_traffic_led_1();
			//STATE STRANSION
			// time out, YELLOW --> RED
			if(is_timer_timeout(4)){
				state_led_traffic_1 = RED;
				set_timer(4,duration_time_of_RED);
			}
		break;

		case GREEN:

			turn_on_traffic_led_1();
			//STATE STRANSION
			// timeout, GREEN-->YELLOW
			if(is_timer_timeout(4)){
				state_led_traffic_1 = YELLOW;
				set_timer(4,duration_time_of_YELLOW);
			}
		break;
		default:
		break;
	}
}


void fsm_traffic_2_run(){
	switch(state_led_traffic_2){
		case RED:

			turn_on_traffic_led_2();
			//STATE STRANSION
			// time out, RED-->GREEN
			if(is_timer_timeout(5)){
				state_led_traffic_2 = GREEN;
				set_timer(5,duration_time_of_GREEN);
			}
		break;
		case YELLOW:

			turn_on_traffic_led_2();
			//STATE STRANSION
			// time out, YELLOW --> RED
			if(is_timer_timeout(5)){
				state_led_traffic_2 = RED;
				set_timer(5,duration_time_of_RED);
			}
		break;
		case GREEN:

			turn_on_traffic_led_2();
			//STATE STRANSION
			// timeout, GREEN-->YELLOW
			if(is_timer_timeout(5)){
				state_led_traffic_2 = YELLOW;
				set_timer(5,duration_time_of_YELLOW);
			}
		break;
		default:
		break;
	}
}


void fsm_system_run(){
	switch(mode){
		case INIT_SYSTEM:

			state_led_traffic_1 = RED;
			state_led_traffic_2 = GREEN;
			set_timer(3, 500);
			set_timer(4, duration_time_of_RED);
			set_timer(5, duration_time_of_GREEN);
			//STATE STRANSITION
			mode = NORMAL_MODE;
		break;
		case NORMAL_MODE:

			fsm_traffic_1_run();
			fsm_traffic_2_run();
			update_2_buffer_led_7seg_left(get_time_of_counter(4));
			update_2_buffer_led_7seg_right(get_time_of_counter(5));
			//STATE STRANSITION
			//button 0 is pressed,  NORMAl_MODE -> MODIFY_RED_MODE
			if(is_pressed(0)){
				clear_timer(4);
				clear_timer(5);
				state_led_traffic_1 = RED;
				state_led_traffic_2 = RED;
				set_timer(6, 500);
				turn_on_traffic_led_1();
				turn_on_traffic_led_2();
				buffer_duration_time = duration_time_of_RED;
				mode = MODIFY_RED_MODE;
			}
		break;
		case MODIFY_RED_MODE:

			update_2_buffer_led_7seg_left(mode*1000);
			update_2_buffer_led_7seg_right(buffer_duration_time);
			//blinking every 500ms
			if(is_timer_timeout(6)){
				blinkind_led_traffic_1();
				blinkind_led_traffic_2();
				set_timer(6, 500);
			}
			//button 1 is pressed, buffer_duration_time increase 1, if buffer exceed 99, buffer = 0;
			if(is_pressed(1)){
				buffer_duration_time = (buffer_duration_time +1000)% (100*1000);
			}
			//button 2 is pressed,  duration time of system = buffer_duration_time;
			if(is_pressed(2)){
				duration_time_of_RED = buffer_duration_time;
			}
			//STATE STRANSITION
			//button 0 is pressed, MODIFY_RED_MODE -> MODIFY_YELLOW_MODE
			if(is_pressed(0)){
				state_led_traffic_1 = YELLOW;
				state_led_traffic_2 = YELLOW;
				set_timer(6, 500);
				turn_on_traffic_led_1();
				turn_on_traffic_led_2();
				buffer_duration_time = duration_time_of_YELLOW;
				mode = MODIFY_YELLOW_MODE;
			}
		break;
		case MODIFY_YELLOW_MODE:

			update_2_buffer_led_7seg_left(mode*1000);
			update_2_buffer_led_7seg_right(buffer_duration_time);
			//blinking every 500ms
			if(is_timer_timeout(6)){
				blinkind_led_traffic_1();
				blinkind_led_traffic_2();
				set_timer(6, 500);
			}
			//button 1 is pressed, buffer_duration_time increase 1, if buffer exceed 99, buffer = 0;
			if(is_pressed(1)){
				buffer_duration_time = (buffer_duration_time +1000)% (100*1000);
			}
			//button 2 is pressed,  duration time of system = buffer_duration_time;
			if(is_pressed(2)){
				duration_time_of_YELLOW = buffer_duration_time;
			}

			//STATE STRANSITION
			//button 0 is pressed,MODIFY_YELLOW_MODE  ->  MODIFY_GREEN_MODE
			if(is_pressed(0)){
				state_led_traffic_1 = GREEN;
				state_led_traffic_2 = GREEN;
				set_timer(6, 500);
				turn_on_traffic_led_1();
				turn_on_traffic_led_2();
				buffer_duration_time = duration_time_of_GREEN;
				mode = MODIFY_GREEN_MODE;
			}
		break;
		case MODIFY_GREEN_MODE:

			update_2_buffer_led_7seg_left(mode*1000);
			update_2_buffer_led_7seg_right(buffer_duration_time);
			//blinking every 500ms
			if(is_timer_timeout(6)){
				blinkind_led_traffic_1();
				blinkind_led_traffic_2();
				set_timer(6, 500);
			}
			//button 1 is pressed, buffer_duration_time increase 1, if buffer exceed 99, buffer = 0;
			if(is_pressed(1)){
				buffer_duration_time = (buffer_duration_time +1000)% (100*1000);
			}
			//button 2 is pressed,  duration time of system = buffer_duration_time;
			if(is_pressed(2)){
				duration_time_of_GREEN = buffer_duration_time;
			}

			//STATE STRANSITION
			//button 0 is pressed, MODIFY_GREEN_MODE -> NORMAL_MODE
			if(is_pressed(0)){
				clear_timer(6);
				state_led_traffic_1 = RED;
				state_led_traffic_2 = GREEN;
				set_timer(4, duration_time_of_RED);
				set_timer(5, duration_time_of_GREEN);
				mode = NORMAL_MODE;
			}
		break;
		default:
		break;
	}
}
