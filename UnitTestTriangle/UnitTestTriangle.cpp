#include "pch.h"
#include "CppUnitTest.h"

extern "C" char* analyzeTriangle(int, int, int);


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestTriangle
{
	TEST_CLASS(UnitTestTriangle)
	{
	public:
		
		TEST_METHOD(TestTriangle01)
		{//testing the analyzeTriangle function using 0 for all sides
			int side1 = 0;
			int side2 = 0; 
			int side3 = 0; 
			char* expected = "Not a Triangle";

			char* result = analyzeTriangle(side1, side2, side3); 
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(TestTriangle02)
		{//testing the analyzeTriangle function using the same length for all sides
			int side1 = 3;
			int side2 = 3;
			int side3 = 3;
			char* expected = "Equilateral Triangle";

			char* result = analyzeTriangle(side1, side2, side3);
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(TestTriangle03)
		{//testing the analyzeTriangle function using the same length for 2 sides
			int side1 = 3;
			int side2 = 3;
			int side3 = 5;
			char* expected = "Isosceles Triangle";

			char* result = analyzeTriangle(side1, side2, side3);
			Assert::AreEqual(expected, result);
		
		}
	};
}
