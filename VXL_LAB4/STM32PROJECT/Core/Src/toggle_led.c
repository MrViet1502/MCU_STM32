/*
 * Toggle_led.c
 *
 *  Created on: Nov 20, 2023
 *      Author: Quoc Viet
 */

#include <toggle_led.h>


int order = 0;
long int counter = 0;

void toggle_led1(){
	HAL_GPIO_TogglePin(GPIOA, LED1_Pin);
	order =1;
}
void toggle_led2(){
	HAL_GPIO_TogglePin(GPIOA, LED2_Pin);
	order =2;
}
void toggle_led3(){
	HAL_GPIO_TogglePin(GPIOA, LED3_Pin);
	order =3;
}
void toggle_led4(){
	HAL_GPIO_TogglePin(GPIOA, LED4_Pin);
	order =4;
}
void toggle_led5(){
	HAL_GPIO_TogglePin(GPIOA, LED5_Pin);
	order = 5;
}
