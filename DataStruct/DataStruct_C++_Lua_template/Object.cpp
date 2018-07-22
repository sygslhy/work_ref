/*
 * Object.cpp
 *
 *  Created on: 27 juin 2018
 *      Author: Administrator
 */

#include "Object.h"
#include <iostream>

Child::Child():x(0), y(0){
	std::cout << "Child::constuctor" << std::endl;
}
Child::Child(int a, int b):x(a), y(b){
	std::cout << "Child::constuctor" << x << " " << y << std::endl;
}
Child::~Child(){
	std::cout << "Child::deconstuctor" << std::endl;
}
int Child::getX(){
	return x;
}
int Child::getY(){
	return y;
}

Object::Object():x(0), y(0){
	std::cout << "Object::constuctor" << std::endl;
}

Object::Object(int a, int b, int c, int d): x(a), y(b), c(c,d){
	std::cout << "Object::constuctor" << x << " " << y << std::endl;
}
Object::~Object(){
	std::cout << "Object::deconstuctor" << std::endl;
}
void Object::display(){
	std::cout << "Object x=" << x << " y=" << y << std::endl;
	std::cout << "Child  x=" << c.getX() << " y=" << c.getY() << std::endl;
}
