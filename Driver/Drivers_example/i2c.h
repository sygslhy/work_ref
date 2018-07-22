/*
 * i2c.h
 *
 *  Created on: 14 juil. 2018
 *      Author: Administrator
 */

#ifndef I2C_H_
#define I2C_H_

typedef unsigned char uint8_t;

int i2c_read_byte (uint8_t address, uint8_t& reg);
int i2c_write_byte(uint8_t address, uint8_t reg);

int i2c_read (uint8_t address, uint8_t* reg,  uint8_t size);
int i2c_write(uint8_t address, uint8_t* reg,  uint8_t size);


#endif /* I2C_H_ */
