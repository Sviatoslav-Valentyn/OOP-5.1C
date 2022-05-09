#include "Point_public.h"

Point_public::Point_public()
	:Point_public(0, 0)
{}

Point_public::Point_public(double valueX, double valueY)
{
	SetX(valueX);
	SetY(valueY);
}

Point_public::Point_public(const Point_public& p)
{
	SetX(p.GetX());
	SetY(p.GetY());
}

Point_public& Point_public::operator++() throw(MyException)
{
	if ((GetX() + 1) == 101)
		throw MyException("x > 100");
	SetX(GetX() + 1);
	return *this;
}

Point_public& Point_public::operator--() throw(MyException)
{
	if ((GetX() - 1) == -101)
		throw MyException("x < -100");
	SetX(GetX() - 1);
	return *this;
}

Point_public Point_public::operator++(int) throw(MyException)
{
	Point_public a(*this);

	if ((GetY() + 1) == 101)
		throw MyException("y > 100");
	SetY(GetY() + 1);
	return a;
}

Point_public Point_public::operator--(int) throw(MyException)
{
	Point_public a(*this);

	if ((GetY() - 1) == -101)
		throw MyException("y < -100");
	SetY(GetY() - 1);
	return a;
}

double Point_public::Angle()
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

double Point_public::Origin()
{
	double z;
	z = sqrt((GetX() * GetX()) + (GetY() * GetY()));
	return z;
}

bool operator==(const Point_public& a, const Point_public& b)
{

	return a.GetX() == b.GetX() && a.GetY() == b.GetY();
}

bool operator!=(const Point_public& a, const Point_public& b)
{
	return !(a == b);
}