/*
 * Stack.cpp
 *
 *  Created on: 16 avr. 2018
 *      Author: Administrator
 */
#include "Stack.hpp"
#include <iostream>
#include <cstring>
using namespace std;
Stack::Stack(){
	memset(number, 0, sizeof(number));
	index = 0;
}

Stack::~Stack(){
	// empty
}

bool Stack::IsEmpty(){
	return index==0;
}

void Stack::Push(int num){
	if (index==STACK_LENGTH){
		cerr << "Stack overflow" << endl;
	}else{
		number[index]=num;
		index++;
	}
}

int Stack::ReadTop(){
	if (this->IsEmpty()){
		cerr << "Stack overflow" << endl;
		return -1;
	}else{
		return number[index-1];
	}
}

void Stack::Pop(){
	if (index==0){
		cerr << "Stack empty" << endl;
	}else{
		number[index] = 0;
		index--;
	}
}


