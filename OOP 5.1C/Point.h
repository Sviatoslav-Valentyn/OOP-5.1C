#pragma once
#include<iostream>
#include <string>
#include <sstream>
#include <exception>
#include "MyException.h"
#include "MyDeliveredException.h"

using namespace std;

class Point
{
private:
	double x;
	double y;

public:
	Point();
	Point(double, double) throw (invalid_argument);
	Point(const Point&);
	~Point() {}

	double GetX() const { return x; };
	double GetY() const { return y; };
	void SetX(double value) throw(invalid_argument);
	void SetY(double value) throw(invalid_argument);

	Point& operator = (const Point&);
	operator string() const;
	friend ostream& operator << (ostream&, const Point&);
	friend istream& operator >> (istream&, Point&) throw (MyDeliveredException);
};
