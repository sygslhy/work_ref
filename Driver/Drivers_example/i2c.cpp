/*
 * i2c.cpp
 *
 *  Created on: 14 juil. 2018
 *      Author: Administrator
 */
#include "i2c.h"
typedef struct _reg_array_t_{
	uint8_t address;
	uint8_t reg;
} reg_array_t;

reg_array_t reg_array[] = {
		{0x1D, 0x00},
		{0x1E, 0x00},
		{0x1F, 0x00}
};


int i2c_read_byte (uint8_t address, uint8_t& reg){

	for (uint8_t i=0; i< sizeof(reg_array)/sizeof(reg_array[0]); i++){
		if(address ==reg_array[i].address){
			reg = reg_array[i].reg;
			return 1;
		}
	}
	return 0;
}
int i2c_write_byte(uint8_t address, uint8_t reg){

	for (uint8_t i=0; i< sizeof(reg_array)/sizeof(reg_array[0]); i++){
		if(address ==reg_array[i].address){
			reg_array[i].reg = reg;
			return 1;
		}
	}
	return 0;
}

int i2c_read (uint8_t address, uint8_t* reg,  uint8_t size){
	return 0;
}
int i2c_write(uint8_t address, uint8_t* reg,  uint8_t size){
	return 0;
}

