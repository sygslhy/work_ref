/*
 * Object.h
 *
 *  Created on: 27 juin 2018
 *      Author: Administrator
 */

#ifndef OBJECT_H_
#define OBJECT_H_
class Child {
public:
	Child();
	Child(int a, int b);
	~Child();
	int getX();
	int getY();
private:
	int x;
	int y;
};

class Object {
public:
	Object();
	Object(int a, int b, int c, int d);
	~Object();
	void display();
private:
	int x;
	int y;
	Child c;
};


#endif /* OBJECT_H_ */
