#include "Point.h"

Point::Point()
{
	x = 0;
	y = 0;
}

Point::Point(double ValueX, double ValueY)
{
	if (abs(ValueX) > 100 || abs(ValueY) > 100)
		throw invalid_argument("value > 100 || value < 100");
	x = ValueX;
	y = ValueY;
}

Point::Point(const Point& a)
{
	x = a.x;
	y = a.y;
}

void Point::SetX(double value) throw(invalid_argument)
{
	if (abs(value) > 100)
		throw invalid_argument("value > 100 || value < 100");
	x = value;
}

void Point::SetY(double value) throw(invalid_argument)
{
	if (abs(value) > 100)
		throw invalid_argument("value > 100 || value < 100");
	y = value;
}

Point& Point::operator=(const Point& a)
{
	x = a.x;
	y = a.y;

	return *this;
}

Point::operator string() const
{
	stringstream ss;
	ss << "x = " << x << endl;
	ss << "y = " << y << endl;
	return ss.str();
}

ostream& operator<<(ostream& out, const Point& a)
{
	out << string(a);
	return out;
}

istream& operator>>(istream& in, Point& a) throw (MyDeliveredException)
{
	double valueX, valueY;
	cout << "x = "; in >> valueX;
	cout << "y = "; in >> valueY;
	cout << endl;

	if (abs(valueX) > 100 || abs(valueY) > 100)
		throw new MyDeliveredException();

	a.x = valueX;
	a.y = valueY;

	return in;
}