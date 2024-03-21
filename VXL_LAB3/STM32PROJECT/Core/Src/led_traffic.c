/*
 * led_traffic.c
 *
 *  Created on: Nov 5, 2023
 *      Author: Quoc Viet
 */

#include <led_traffic.h>

void turn_on_traffic_led_1(){
	switch(state_led_traffic_1){
		case RED:
			HAL_GPIO_WritePin(GPIOA, LED_RED_1_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, LED_YELLOW_1_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, LED_GREEN_1_Pin, SET);
			break;
		case YELLOW:
			HAL_GPIO_WritePin(GPIOA, LED_RED_1_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, LED_YELLOW_1_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, LED_GREEN_1_Pin, SET);
			break;
		case GREEN:
			HAL_GPIO_WritePin(GPIOA, LED_RED_1_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, LED_YELLOW_1_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, LED_GREEN_1_Pin, RESET);
			break;
		default:
			break;
	}
}
void turn_on_traffic_led_2(){
	switch(state_led_traffic_2){
		case RED:
			HAL_GPIO_WritePin(GPIOA, LED_RED_2_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, LED_YELLOW_2_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, LED_GREEN_2_Pin, SET);
			break;
		case YELLOW:
			HAL_GPIO_WritePin(GPIOA, LED_RED_2_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, LED_YELLOW_2_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, LED_GREEN_2_Pin, SET);
			break;
		case GREEN:
			HAL_GPIO_WritePin(GPIOA, LED_RED_2_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, LED_YELLOW_2_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, LED_GREEN_2_Pin, RESET);
			break;
		default:
			break;
	}
}

void blinkind_led_traffic_1(){
	switch(state_led_traffic_1){
		case RED:
			HAL_GPIO_TogglePin(GPIOA, LED_RED_1_Pin);
			HAL_GPIO_WritePin(GPIOA, LED_YELLOW_1_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, LED_GREEN_1_Pin, SET);
			break;
		case YELLOW:
			HAL_GPIO_WritePin(GPIOA, LED_GREEN_1_Pin, SET);
			HAL_GPIO_TogglePin(GPIOA, LED_YELLOW_1_Pin);
			HAL_GPIO_WritePin(GPIOA, LED_RED_1_Pin, SET);
			break;
		case GREEN:
			HAL_GPIO_WritePin(GPIOA, LED_YELLOW_1_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, LED_RED_1_Pin, SET);
			HAL_GPIO_TogglePin(GPIOA, LED_GREEN_1_Pin);
			break;
		default:
			break;
		}
}

void blinkind_led_traffic_2(){
	switch(state_led_traffic_2){
			case RED:
				HAL_GPIO_TogglePin(GPIOA, LED_RED_2_Pin);
				HAL_GPIO_WritePin(GPIOA, LED_YELLOW_2_Pin, SET);
				HAL_GPIO_WritePin(GPIOA, LED_GREEN_2_Pin, SET);
			break;
			case YELLOW:
				HAL_GPIO_WritePin(GPIOA, LED_GREEN_2_Pin, SET);
				HAL_GPIO_TogglePin(GPIOA, LED_YELLOW_2_Pin);
				HAL_GPIO_WritePin(GPIOA, LED_RED_2_Pin, SET);
			break;
			case GREEN:
				HAL_GPIO_WritePin(GPIOA, LED_YELLOW_2_Pin, SET);
				HAL_GPIO_WritePin(GPIOA, LED_RED_2_Pin, SET);
				HAL_GPIO_TogglePin(GPIOA, LED_GREEN_2_Pin);
			break;
			default:
			break;
		}
}

