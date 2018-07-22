/*
 * main.cpp
 *
 *  Created on: 25 juin 2018
 *      Author: Administrator
 */
#include "Point.h"
#include <iostream>


int main(int argc, char** args){
	Point p1(3,4);

	std::cout << p1 << std::endl;
	Point p2(p1);
	std::cout << p2 << std::endl;

	//std::cout << p2+p1 << std::endl;
	//std::cout << p2 << std::endl;

	return 0;
}

