#pragma once
#include <string>
#include <iostream>

using namespace std;

class MyException
{
public:
	MyException() throw() : msg()
	{}
	string What() const throw() { return "Exception: MyException: " + msg; }
	MyException(const string& m) throw() : msg(m)
	{}
	virtual ~MyException() {}

private:
	string msg;
};