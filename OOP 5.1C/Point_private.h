#pragma once
#include"Point.h"
class Point_private : private Point
{
public:

	Point_private();
	Point_private(double x, double y);
	Point_private(const Point_private& a);
	~Point_private() {}

	Point_private& operator ++() throw(MyException);
	Point_private& operator --() throw(MyException);
	Point_private operator ++(int) throw(MyException);
	Point_private operator --(int) throw(MyException);

	friend bool operator == (const Point_private&, const Point_private&);
	friend bool operator != (const Point_private&, const Point_private&);

	double Angle();
	double Origin();

	friend ostream& operator << (ostream&, const Point_private&);
	friend istream& operator >> (istream&, Point_private&) throw (MyDeliveredException);

};