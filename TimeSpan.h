#ifndef TIMESPAN_H
#define TIMESPAN_H

#include <iostream>
#include <math.h>

using namespace std;

class TimeSpan
{
	friend ostream &operator<<(ostream &output, const TimeSpan var);
	friend istream &operator>>(istream &input, TimeSpan &var);

	public:
		TimeSpan();
		TimeSpan(double hr, double min, double sec);
		TimeSpan(double min, double sec);
		TimeSpan(double sec);
		~TimeSpan();
		
		

		int getHours()const;
		int getMinutes()const;
		int getSeconds()const;
		bool setTime(int hr = 0, int min = 0, int sec = 0);

		void operator=(const TimeSpan rightValue);

		bool operator==(const TimeSpan &rightValue)const;
		bool operator!=(const TimeSpan &rightValue)const;
		
		TimeSpan operator+(const TimeSpan &rightValue)const;
		TimeSpan &operator+=(const TimeSpan &rightValue);
		
		TimeSpan operator-(const TimeSpan &rightValue)const;
		TimeSpan &operator-=(const TimeSpan &rightValue);

		TimeSpan operator-();
		
		

		
		

	private:
		int hours;
		int minutes;
		int seconds;
		void reduceTime(double sec, double min = 0, double hr = 0);
		


};
#endif
