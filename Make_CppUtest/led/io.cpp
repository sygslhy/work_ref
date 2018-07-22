#include "io.h"
#include <stdio.h>
void writeIO(uint16_t add, uint16_t val){
	printf("Real write IO\n");
}
void readIO(uint16_t add, uint16_t &val){
	printf("Real read IO\n");
}
