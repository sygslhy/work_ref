#include "sample.h"
#include "io.h"
#if 0
void led_power_on_config(void){
	uint16_t address, value;
	writeIO(address, value);
}

void led_init(){
	uint16_t address, value;
	writeIO(address, value);
}

void led_turn_on(int number){
	uint16_t address, value;
	writeIO(address, value);
}

void led_turn_off(int number){
	uint16_t address, value;
	writeIO(address, value);
}

int led_get_status(int number){
	uint16_t address, value;
	readIO(address, value);
}
#endif
int add(int a, int b){
	uint16_t address, value;
	writeIO(address, value);
	return a+b;
}

int sub(int a, int b){
	uint16_t address, value;
	readIO(address, value);
	return a-b;
}
