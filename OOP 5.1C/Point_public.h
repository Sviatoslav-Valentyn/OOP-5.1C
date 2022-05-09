#pragma once
#include"Point.h"

class Point_public : public Point
{
public:
	Point_public();
	Point_public(double valueX, double valueY);
	Point_public(const Point_public&);
	~Point_public() {}

	Point_public& operator ++()throw(MyException);
	Point_public& operator --()throw(MyException);
	Point_public operator ++(int)throw(MyException);
	Point_public operator --(int)throw(MyException);

	friend bool operator == (const Point_public&, const Point_public&);
	friend bool operator != (const Point_public&, const Point_public&);

	double Angle();
	double Origin();
};