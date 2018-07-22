/*
 * Stack.hpp
 *
 *  Created on: 16 avr. 2018
 *      Author: Administrator
 */

#ifndef STACK_HPP_
#define STACK_HPP_

#define STACK_LENGTH 10

class Stack{
public:
	void Push(int num);
	int  ReadTop();
	void Pop();
	bool IsEmpty();
	Stack();
	~Stack();
private:
	int number[STACK_LENGTH];
	int index;
};



#endif /* STACK_HPP_ */
