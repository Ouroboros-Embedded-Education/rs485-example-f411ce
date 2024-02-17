/*
 * screen_main.c
 *
 *  Created on: Nov 11, 2023
 *      Author: pablo-jean
 */


#include "screen.h"


static lv_obj_t *screen;

static lv_obj_t *labelTitle, *labelIntVal, *labelExtVal, *labelStatus;
static lv_obj_t *imageCpu1, *imageCpu2, *ImageTwoArrows;

LV_IMG_DECLARE(cpu);
LV_IMG_DECLARE(two_arrows);

// custom fonts
extern lv_font_t ubuntu_4px;
extern lv_font_t ubuntu_24px;
extern lv_font_t ubuntu_16;
extern lv_font_t ubuntu_8px;

/* Callbacks */

uint32_t Minutes, Seconds, Mils;
uint8_t Couting = 0;

/* Initialize functions */

void _init_text(){
	labelTitle = lv_label_create(lv_scr_act());
	lv_obj_align(labelTitle, LV_ALIGN_TOP_MID, 0, 3);
	lv_label_set_text(labelTitle, "RS485 Comm");
	lv_obj_set_style_text_font(labelTitle, &lv_font_unscii_8, _LV_STYLE_STATE_CMP_SAME);

	labelIntVal = lv_label_create(lv_scr_act());
	lv_obj_align(labelIntVal, LV_ALIGN_TOP_LEFT, 4, 15);
	lv_label_set_text(labelIntVal, "In 00000");
	lv_obj_set_style_text_font(labelIntVal, &lv_font_unscii_8, _LV_STYLE_STATE_CMP_SAME);

	labelExtVal = lv_label_create(lv_scr_act());
	lv_obj_align(labelExtVal, LV_ALIGN_TOP_LEFT, 4, 27);
	lv_label_set_text(labelExtVal, "Ex 00000");
	lv_obj_set_style_text_font(labelExtVal, &lv_font_unscii_8, _LV_STYLE_STATE_CMP_SAME);

	labelStatus = lv_label_create(lv_scr_act());
	lv_obj_align(labelStatus, LV_ALIGN_TOP_LEFT, 4, 43);
	lv_label_set_text(labelStatus, "Status");
	lv_obj_set_style_text_font(labelStatus, &lv_font_unscii_8, _LV_STYLE_STATE_CMP_SAME);
}

void _init_imgs(){
	imageCpu1 = lv_img_create(lv_scr_act());
	lv_img_set_src(imageCpu1, &cpu);
	lv_obj_align(imageCpu1, LV_ALIGN_TOP_MID, 0, 40);

	imageCpu2 = lv_img_create(lv_scr_act());
	lv_img_set_src(imageCpu2, &cpu);
	lv_obj_align(imageCpu2, LV_ALIGN_TOP_MID, +50, 40);

	ImageTwoArrows = lv_img_create(lv_scr_act());
	lv_img_set_src(ImageTwoArrows, &two_arrows);
	lv_obj_align(ImageTwoArrows, LV_ALIGN_TOP_MID, +25, 40);
	lv_obj_add_flag(ImageTwoArrows, LV_OBJ_FLAG_HIDDEN);
}


lv_group_t* screen_main_init(){
	lv_group_t *group;

	screen = lv_disp_get_scr_act(NULL);
	lv_scr_load(screen);

	_init_text();
	_init_imgs();

	group = lv_group_create();

	return group;
}

void screen_upd_IntValue(uint32_t Value){
	char Text[10];

	sprintf(Text, "In %05lu", Value);
	lv_label_set_text(labelIntVal, Text);
}

void screen_upd_ExtValue(uint32_t Value){
	char Text[10];

	sprintf(Text, "Ex %05lu", Value);
	lv_label_set_text(labelExtVal, Text);
}

void screen_upd_Rs485_Status(screen_rs485_status_e e){
	switch (e){
	case SCREEN_RS485_ONLINE:
		lv_obj_clear_flag(ImageTwoArrows, LV_OBJ_FLAG_HIDDEN);
		break;
	default:
		lv_obj_add_flag(ImageTwoArrows, LV_OBJ_FLAG_HIDDEN);
		break;
	}
}
