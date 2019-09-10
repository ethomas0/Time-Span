#include "TimeSpan.h"

TimeSpan::TimeSpan()
{
	hours = minutes = seconds = 0;
}

TimeSpan::TimeSpan(double hr, double min, double sec)
{
	reduceTime(sec, min, hr);
}

TimeSpan::TimeSpan(double min, double sec)
{
	reduceTime(sec, min);
}

TimeSpan::TimeSpan(double sec)
{
	reduceTime(sec);
}

TimeSpan::~TimeSpan()
{
	
}

bool TimeSpan::setTime(int hr, int min, int sec)
{
	reduceTime(sec, min, hr);	
	return true;
}

void TimeSpan::operator=(const TimeSpan rightValue)
{
	this->setTime(rightValue.hours, rightValue.minutes, rightValue.seconds);
}

int TimeSpan::getHours() const
{
	return hours;
}

int TimeSpan::getMinutes() const
{
	return minutes;
}

int TimeSpan::getSeconds() const
{
	return seconds;
}

bool TimeSpan::operator==(const TimeSpan &rightValue) const
{
	return(this->hours == rightValue.hours && this->minutes == rightValue.minutes && this->seconds == rightValue.seconds);
	
}

bool TimeSpan::operator!=(const TimeSpan &rightValue) const
{
	return(this->hours != rightValue.hours || this->minutes != rightValue.minutes || this->seconds != rightValue.seconds);
}

TimeSpan TimeSpan::operator+(const TimeSpan &rightValue) const
{
	return TimeSpan((this->hours + rightValue.hours), (this->minutes + rightValue.minutes),(this->seconds + rightValue.seconds));
}

TimeSpan & TimeSpan::operator+=(const TimeSpan & rightValue)
{
	this->setTime((this->hours + rightValue.hours), (this->minutes + rightValue.minutes), (this->seconds + rightValue.seconds));
	return *this;
}

TimeSpan TimeSpan::operator-(const TimeSpan & rightValue) const
{
	return TimeSpan ((this->hours - rightValue.hours), (this->minutes - rightValue.minutes), (this->seconds - rightValue.seconds));
}

TimeSpan & TimeSpan::operator-=(const TimeSpan & rightValue)
{
	this->setTime((this->hours - rightValue.hours), (this->minutes - rightValue.minutes), (this->seconds - rightValue.seconds));
	return *this;
}

TimeSpan TimeSpan::operator-()
{	
	this->hours = -hours;
	this->minutes = -minutes;
	this->seconds = -seconds;
	return *this;
}


void TimeSpan::reduceTime(double sec, double min, double hr)
{
	double tempHr(0), tempMin(0), tempSec(0);
	const int GCF = 60;

	double totalSecs = sec + (min * GCF) + ((hr * GCF) * GCF);
	
	tempMin = totalSecs / GCF;
	tempSec = round(fmod(totalSecs, GCF));
	tempHr = tempMin / GCF;
	tempMin = fmod(tempMin, GCF);
	
	this->hours = tempHr;
	this->minutes = tempMin;
	this->seconds = tempSec;
			
	
}

ostream & operator<<(ostream &output, const TimeSpan var)
{
	output << "Hours: " << var.hours << ", " << "Minutes: " << var.minutes << ", " << "Seconds: " << var.seconds << endl;
	return output;
}

istream &operator>>(istream &input, TimeSpan &var)
{
	double tempHr(0), tempMin(0), tempSec(0);
	input >> tempHr >> tempMin >> tempSec;
	var.reduceTime(tempSec, tempMin, tempHr);
	return input;
}
