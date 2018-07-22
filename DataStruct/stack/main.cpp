/*
 * main.cpp
 *
 *  Created on: 16 avr. 2018
 *      Author: Administrator
 */



#include "Stack.hpp"
#include <iostream>
using namespace std;

int main(){
	Stack stk;
	stk.Push(10);
	stk.Push(12);
	stk.Push(14);
	stk.Push(14);
	stk.Push(14);
	stk.Push(14);
	stk.Push(14);
	stk.Push(14);
	stk.Push(14);
	stk.Push(14);
	stk.Push(14);
	cout << stk.ReadTop() << endl;
	stk.Pop();
	cout << stk.ReadTop() << endl;
	return 0;
}
