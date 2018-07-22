/*
 * Point.cpp
 *
 *  Created on: 25 juin 2018
 *      Author: Administrator
 */

#include "Point.h"


Point::Point(int x=0, int y=0){
	this->x = x;
	this->y = y;
}

Point::Point(const Point& p){
	this->x = p.x;
	this->y = p.y;
}
Point::~Point(){

}

int Point::getX(){
	return x;
}

int Point::getY(){
	return y;
}

/*
bool  Point::operator >  (const Point& p){
	return (this->x>p.x && this->y>p.y);
}

bool  Point::operator <  (const Point& p){
	return (this->x<p.x && this->y<p.y);
}

bool  Point::operator ==  (const Point& p){
	return (this->x == p.x && this->y == p.y);
}
*/
Point operator +  (const Point& p1,const Point& p2){
	Point p3(p1);
	p3.x = p1.x + p2.x;
	p3.y = p1.y + p2.y;
	return p3;
}

std::istream& operator >> (std::istream& in,  Point& p){
	return in >> p.x >> p.y;
}

std::ostream& operator << (std::ostream& out, Point& p){
	return out << "("<< p.x << "," << p.y << ")";
}
