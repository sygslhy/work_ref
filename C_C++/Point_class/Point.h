/*
 * Point.h
 *
 *  Created on: 25 juin 2018
 *      Author: Administrator
 */

#ifndef POINT_H_
#define POINT_H_

#include <iostream>

class Point {

public:
	Point(int x, int y);
	Point(const Point& p);
	~Point();
	int getX();
	int getY();
	/*
	bool  operator >  (const Point& p);
	bool  operator <  (const Point& p);
	bool  operator == (const Point& p);
	*/
private:
	int x;
	int y;
	friend Point operator + (const Point& p1, const Point& p2);
	friend std::istream& operator >> (std::istream& in,  Point& p);
	friend std::ostream& operator << (std::ostream& out, Point& p);
};


#endif /* POINT_H_ */
