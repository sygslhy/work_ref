/*
 * Swap.cpp
 *
 *  Created on: 26 juin 2018
 *      Author: Administrator
 */
#include "Swap.h"

template <typename T>
void swap(T &a, T&b){
	T temp;
	temp = a; a = b; b = temp;
}

