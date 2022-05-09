#include"Point_private.h"
#include"Point_public.h"
#include <Windows.h>

using namespace std;

void _unexpected_to_bad()
{
	cerr << "bad_exception" << endl;
	throw;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	set_unexpected(_unexpected_to_bad);
	set_terminate(_unexpected_to_bad);

	Point_private a,b;

	try
	{
		cout << "A:\n";
		cin >> a;
		++a;
		cout << "++a" << endl;
		cout << a << endl;
		cout << "Angle = " << a.Angle() << endl;
		cout << "Origin = " << a.Origin() << endl;
	}
	catch (MyDeliveredException x)
	{
		cerr << x.What() << endl;
	}

	cout << "============================================" << endl;

	try
	{
		cout << "B:\n";
		cin >> b;
		++b;
		cout << "++b" << endl;
		cout << b << endl;
		cout << "Angle = " << b.Angle() << endl;
		cout << "Origin = " << b.Origin() << endl;
		if (a == b)
		{
			cout << "Äâà îáºêòè º ð³âí³\n";
		}
		if (a != b)
		{
			cout << "Äâà îáºêòè íå º ð³âí³\n";
		}
	}
	catch (MyDeliveredException x)
	{
		cerr << x.What() << endl;
	}
	cout << "============================================" << endl;
	try
	{
		Point_public x(2, 2);
		cout << x << endl;
		cout << "Angle = " << x.Angle() << endl;
		cout << "Origin = " << x.Origin() << endl;
	}
	catch (MyDeliveredException* a)
	{
		cerr << a->What() << endl;
	}
	catch (MyException& x)
	{
		cerr << x.What() << endl;
	}
	cout << "============================================" << endl;
	try
	{
		Point_public y(2, 2);
		cout << y << endl;
		cout << "Angle = " << y.Angle() << endl;
		cout << "Origin = " << y.Origin() << endl;
	}
	catch (MyDeliveredException* a)
	{
		cerr << a->What() << endl;
	}
	catch (MyException& x)
	{
		cerr << x.What() << endl;
	}
	cout << "============================================" << endl;
	return 0;
}