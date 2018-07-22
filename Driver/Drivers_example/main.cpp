/*
 * main.cpp
 *
 *  Created on: 7 juil. 2018
 *      Author: Administrator
 */
#include "GPIO.h"
#include "rtc.h"
#include <iostream>
/**
 * 初始化一个IO口分为三步：使能时钟、赋值结构体参数、使用上一步设置的结构体参数初始化IO。
 *
 */


int main(int argc, char* args[]){
	GPIO_InitTypeDef GPIO_InitStructure;
	/** step 1  设置使能时钟  */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOE, ENABLE); //使能 PB,PE 端口时钟

	/** step 2  设置指定GPIO模式  */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	rtc_power_on_config();
	flags_reg_t flags_reg;
	rtc_get_flags(flags_reg);
	std::cout << "Flags:" << (int)flags_reg.all << std::endl;
	flags_reg.bits.AF = 1;
	flags_reg.bits.TF = 1;
	flags_reg.bits.UF = 1;
	rtc_set_flags(flags_reg);
	rtc_get_flags(flags_reg);
	std::cout << "Flags:" << (int)flags_reg.all << std::endl;

	return 0;
}


