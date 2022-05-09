#include "pch.h"
#include "CppUnitTest.h"
#include "../OOP 5.1C/Point_public.h"
#include "../OOP 5.1C/Point_public.cpp"
#include "../OOP 5.1C/Point_private.h"
#include "../OOP 5.1C/Point_private.cpp"
#include "../OOP 5.1C/Point.h"
#include "../OOP 5.1C/Point.cpp"



using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			Point_public a(2, 2);
			Assert::AreEqual(45., a.Angle());
		}
	};
}
