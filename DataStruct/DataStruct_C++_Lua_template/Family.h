/*
 * Family.h
 *
 *  Created on: 28 juin 2018
 *      Author: Administrator
 */

#ifndef FAMILY_H_
#define FAMILY_H_

class Father{
public:
	Father();
	Father(int x, int y);
	Father(const Father& f);
	virtual ~Father();
	virtual void display();
private:
	int a;
	int b;
};

class Son : public Father{
public:
	Son();
	Son(int x, int y);
	Son(const Son& s);
	~Son();
	void display();
private:
	int c;
	int d;
};

class cmdHandler{
public:
	virtual void OnCommand(char* cmdline) = 0;
};

#endif /* FAMILY_H_ */
