#include "Point_private.h"

Point_private::Point_private()
	:Point_private(0, 0)
{}

Point_private::Point_private(double valueX, double valueY)
{
	SetX(valueX);
	SetY(valueY);
}

Point_private::Point_private(const Point_private& p)
{
	SetX(p.GetX());
	SetY(p.GetY());
}

Point_private& Point_private::operator++() throw(MyException)
{
	SetX(GetX() + 1);
	if (GetX() == 101)
		throw MyException("x > 100");
	return *this;
}

Point_private& Point_private::operator--() throw(MyException)
{
	SetX(GetX() - 1);
	if (GetX() == 101)
		throw MyException("x < -100");
	return *this;
}

Point_private Point_private::operator++(int) throw(MyException)
{
	Point_private a(*this);
	SetY(GetY() + 1);
	if (GetY() == 101)
		throw MyException("y > 100");
	return a;
}

Point_private Point_private::operator--(int) throw(MyException)
{
	Point_private a(*this);
	SetY(GetY() - 1);
	if (GetY() == 101)
		throw MyException("y < -100");
	return a;
}

bool operator==(const Point_private& a, const Point_private& b)
{
	return a.GetX() == b.GetX() && a.GetY() == b.GetY();
}

bool operator!=(const Point_private& a, const Point_private& b)
{
	return !(a == b);
}

double Point_private::Angle()
{
	double Pi = 4. * atan(1);
	if ((GetX() == 0) && (GetY() == 0))
		return -1;
	if (GetX() == 0)
		return ((GetY() > 0) ? 90 : 270);
	double theta = atan(GetY() / GetX());
	theta *= 360 / (2 * Pi);
	if (GetX() > 0)
	{
		return ((GetY() >= 0) ? theta : 360 + theta);
	}
	else
	{
		return (180 + theta);
	}
}

double Point_private::Origin()
{
	double z;
	z = sqrt((GetX() * GetX()) + (GetY() * GetY()));
	return z;
}

ostream& operator<<(ostream& out, const Point_private& a)
{
	out << string(a);
	return out;
}

istream& operator>>(istream& in, Point_private& a) throw (MyDeliveredException)
{
	int valueX, valueY;
	cout << "x = "; in >> valueX;
	cout << "y = "; in >> valueY;
	cout << endl;

	if (abs(valueX) > 100 || abs(valueY) > 100)
		throw MyDeliveredException();

	a.SetX(valueX);
	a.SetY(valueY);

	return in;
}