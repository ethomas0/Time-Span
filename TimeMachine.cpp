#include "TimeSpan.h"
#include <iostream>
#include <math.h>

using namespace std;


int main()
{
	//Testing constructors with values in range (positive and negative inputs) *All if statements also cover .get functions
	int test1Hr(1), test1Min(40), test1Sec(30);
	double test2Hr(-3), test2Min(-42), test2Sec(-55);
	float test3Sec(11.3);
	TimeSpan test1, test2(test1Hr, test1Min, test1Sec), test3(test2Hr, test2Min, test2Sec), test4(23, 44), test5(-36, -59), test6(test3Sec), test7(-14.7);

	if (test1.getHours() == 0 && test1.getMinutes() == 0 && test1.getSeconds() == 0)
	{
		cout << "Default constructor is working properly" << endl;
	}
	else
	{
		cout << "Default constructor has an error" << endl;
	}

	if (test2.getHours() == 1 && test2.getMinutes() == 40 && test2.getSeconds() == 30)
	{
		cout << "3 parameter constructor with in range positive ints is working properly" << endl;
	}
	else
	{
		cout << "3 parameter constructor with in range positive ints has an error" << endl;
	}

	if (test3.getHours() == -3 && test3.getMinutes() == -42 && test3.getSeconds() == -55)
	{
		cout << "3 parameter constructor with in range negative doubles is working properly" << endl;
	}
	else
	{
		cout << "3 parameter constructor with in range negative doubles has an error" << endl;
	}

	if (test4.getHours() == 0 && test4.getMinutes() == 23 && test4.getSeconds() == 44)
	{
		cout << "2 parameter constructor with in range positive inputs is working properly" << endl;
	}
	else
	{
		cout << "2 parameter constructor with in range positive inputs has an error" << endl;
	}

	if (test5.getHours() == 0 && test5.getMinutes() == -36 && test5.getSeconds() == -59)
	{
		cout << "2 parameter constructor with in range negative inputs is working properly" << endl;
	}
	else
	{
		cout << "2 parameter constructor with in range negative inputs has an error" << endl;
	}

	if (test6.getHours() == 0 && test6.getMinutes() == 0 && test6.getSeconds() == 11)
	{
		cout << "1 parameter constructor and rounding down with in range positive float is working properly" << endl;
	}
	else
	{
		cout << "1 paramter constructor or rounding down with an in range positive float has an error" << endl;
	}

	if (test7.getHours() == 0 && test7.getMinutes() == 0 && test7.getSeconds() == -15)
	{
		cout << "1 parameter constructor and rounding up with in range negative input is working properly" << endl;
	}
	else
	{
		cout << "1 parameter constructor or rounding up with in range negative input has an error" << endl;
	}

	//Testing setTime() w/ values out of range and using different combinations of values
	
	test1.setTime(-5, 400, 600);
	test2.setTime(30, -62, -78);
	test3.setTime(30, 72, -64);
	test4.setTime(-1, -71, 700);
	test5.setTime(23, -66, -84);
	test6.setTime(-23, -66, -84);

	if (test1.getHours() == 1 && test1.getMinutes() == 50 && test1.getSeconds() == 0)
	{
		cout << "setTime() with (-,+,+) inputs is working properly" << endl;
	}
	else
	{
		cout << "setTime() with (-,+,+) inputs has an error" << endl;
	}
	
	if (test2.getHours() == 28 && test2.getMinutes() == 56 && test2.getSeconds() == 42)
	{
		cout << "setTime() with (+,-,-) inputs is working properly" << endl;
	}
	else
	{
		cout << "setTime() with (+,-,-) inputs has an error" << endl;
	}

	if (test3.getHours() == 31 && test3.getMinutes() == 10 && test3.getSeconds() == 56)
	{
		cout << "setTime() with (+,+,-) inputs is working properly" << endl;
	}
	else
	{
		cout << "setTime() with (+,+,-) inputs has an error" << endl;
	}
	
	if (test4.getHours() == -1 && test4.getMinutes() == -59 && test4.getSeconds() == -20)
	{
		cout << "setTime() with (-,-,+) inputs is working properly" << endl;
	}
	else
	{
		cout << "setTime() with (-,-,+) inputs has an error" << endl;
	}
	
	if (test5.getHours() == 21 && test5.getMinutes() == 52 && test5.getSeconds() == 36)
	{
		cout << "setTime() with (+,-,-) inputs is working properly" << endl;
	}
	else
	{
		cout << "setTime() with (+,-,-) inputs has an error" << endl;
	}

	if (test6.getHours() == -24 && test6.getMinutes() == -7 && test6.getSeconds() == -24)
	{
		cout << "setTime() with (-,-,-) inputs is working properly" << endl;
	}
	else
	{
		cout << "setTime() with (-,-,-) inputs has an error" << endl;
	}

	//Testing math and comparison operators

	test3 = test1 + test2;
	if (test3.getHours() == 30 && test3.getMinutes() == 46 && test3.getSeconds() == 42)
	{
		cout << "Addition and equal operator working properly" << endl;
	}
	else
	{
		cout << "Addition or equal operator has an error" << endl;
	}
	
	test1 += test4;
	if (test1.getHours() == 0 && test1.getMinutes() == -9 && test1.getSeconds() == -20)
	{
		cout << "Addition and assignment operator working properly" << endl;
	}
	else
	{
		cout << "Addition and assignment operator has an error" << endl;
	}

	test3 = test4 - test6;
	if (test3.getHours() == 22 && test3.getMinutes() == 8 && test3.getSeconds() == 4)
	{
		cout << "Subtraction and equal operator working properly" << endl;
	}
	else
	{
		cout << "Subtraction or equal operator has an error" << endl;
	}
	test4 -= test6;

	if (test3 == test4)
	{
		cout << "Subtraction and assignment operator and equal comparison operator working properly" << endl;
	}
	else
	{
		cout << "Subtraction and assignment operator or equal comparison operator has an error" << endl;
	}

	-test6;
	if (test6.getHours() == 24 && test6.getMinutes() == 7 && test6.getSeconds() == 24 && test6 != test4)
	{
		cout << "Unary negation and is not equal comparison operator working properly" << endl;
	}
	else
	{
		cout << "Unary negation or is not equal comparison operator has an error" << endl;
	}

	//IOstream testing

	cout << test6 << endl;
	cin >> test6;
	cout << test6 << endl;
	
	

	
	

	
	
	return 0;
}

