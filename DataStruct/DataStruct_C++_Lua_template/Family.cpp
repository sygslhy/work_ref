/*
 * Family.cpp
 *
 *  Created on: 28 juin 2018
 *      Author: Administrator
 */

#include "Family.h"
#include <iostream>

Father::Father():a(0), b(0){
	std::cout << "Father()" << std::endl;
}

Father::Father(int x, int y):a(x), b(y){}

Father::Father(const Father& f){
	a = f.a;
	b = f.b;
}

Father::~Father(){
	std::cout << "~Father()" << std::endl;
}

void Father::display(){
	std::cout << "a=" << a << " b=" << b << std::endl;
}

Son::Son():c(0), d(0){
	std::cout << "Son()" << std::endl;
}

Son::Son(int x, int y):c(x), d(y){}

Son::Son(const Son& s){
	c = s.c;
	d = s.d;
}

Son::~Son(){
	std::cout << "~Son()" << std::endl;
}

void Son::display(){
	Father::display();
	std::cout << "c=" << c << " d=" << d << std::endl;
}

