/*
 * rtc.cpp
 *
 *  Created on: 14 juil. 2018
 *      Author: Administrator
 */

#include "rtc.h"
#include "i2c.h"
#include "assert.h"

#define CLOCK_CALENDER_REG (0x10)
#define TIMER_COUNTER_REG  (0x1B)
#define EXTENSION_REG      (0x1D)
#define FLAG_REG           (0x1E)
#define CONTROL_REG        (0x1F)
#define IRQ_CONTROL_REG    (0x32)
#define RTC_RETRY_NUM  10
void rtc_power_on_config(void){
	// wait 40 ms
	flags_reg_t flags_reg = {0};
	rtc_get_flags(flags_reg);
	int retry = RTC_RETRY_NUM;
	while (flags_reg.bits.VLF && retry>RTC_RETRY_NUM){
		// wait 40 ms
		flags_reg.bits.VLF = 0;
		rtc_set_flags(flags_reg);
		// wait 10 ms
		rtc_get_flags(flags_reg);
		retry--;
	}
	assert(!flags_reg.bits.VLF);
	rtc_init();
}

void rtc_init(void){
	extension_reg_t extension_reg;
	int ret = i2c_read_byte(EXTENSION_REG, extension_reg.all);
	assert(ret);
	extension_reg.bits.TE = 0;
	ret = i2c_write_byte(EXTENSION_REG, extension_reg.all);
	assert(ret);
	control_reg_t control_reg;
	ret = i2c_read_byte(CONTROL_REG, control_reg.all);
	control_reg.bits.TEST = 0;
	control_reg.bits.AIE = 0;
	control_reg.bits.TIE = 0;
	control_reg.bits.UIE = 0;
	//set present time
	//set alarm function
	//set timer function
	//set update function
}


void rtc_get_flags(flags_reg_t& flags_reg){
	int ret = i2c_read_byte(FLAG_REG, flags_reg.all);
	assert(ret);
}

void rtc_set_flags(flags_reg_t flags_reg){
	int ret = i2c_write_byte(FLAG_REG, flags_reg.all);
	assert(ret);
}

