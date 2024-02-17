/*
 * screen.h
 *
 *  Created on: Nov 11, 2023
 *      Author: pablo-jean
 */

#ifndef SCREEN_SCREEN_H_
#define SCREEN_SCREEN_H_

#include <string.h>
#include <stdio.h>

#include "lvgl.h"

typedef enum{
	SCREEN_RS485_OFFLINE,
	SCREEN_RS485_ONLINE,
}screen_rs485_status_e;

lv_group_t* screen_main_init();

void screen_upd_IntValue(uint32_t Value);

void screen_upd_ExtValue(uint32_t Value);

void screen_upd_Rs485_Status(screen_rs485_status_e e);

#endif /* SCREEN_SCREEN_H_ */
