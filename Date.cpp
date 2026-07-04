#include<iostream>
using namespace std;
#include"UTILLITY.h"
#include "Date.h"

// Set the day of the Date object
void Date::setDay(const int& d)
{
	this->day = checkValue(1, 31, d);
}

// Set the month of the Date object
void Date::setMonth(const int& m)
{
	this->month = checkValue(1, 12, m);
}

// Set the year of the Date object
void Date::setYear(const int& y)
{
	this->year = checkValue(1, 2024, y);
}

// Constructor for Date class, initializes the Date object with the provided values
Date::Date(const int& d, const int& m, const int& y)
{
	this->day = checkValue( 1, 31,d);
	this->month = checkValue( 1, 12,m);
	this->year = checkValue( 1, 2024,y);
}

// Check if two Date objects are equal.
bool Date::operator ==(const Date& date) const
{
	return ((this->day == date.day && this->month == date.month && this->year == date.year));
}

// Assign the values of one Date object to another.
Date& Date::operator =(const Date& date)
{
	if (this == &date)
	{
		return *this;
	}
	this->day = date.day;
	this->month = date.month;
	this->year = date.year;
	return *this;
}

// Overloaded input stream operator to read Date from console or file
istream& operator>>(istream& input, Date& date)
{
	date.Read(input);
	return input;
}

// Overloaded output stream operator to write Date to console or file
ostream& operator<<(ostream& output, const Date& date)
{
	date.Write(output);
	return output;
}

// Read Date values from file or console
void Date::Read(istream& input)
{
	int value;
	input >> value;
	input.ignore();
	this->day = checkValue(1, 31, value);

	input >> value;
	input.ignore();
	this->month = checkValue(1, 12, value);

	input >> value;
	input.ignore();
	this->year = checkValue(1, 2024, value);
}

// Write Date values to file or console in the format "day/month/year".
void Date::Write(ostream& output) const
{
	output << this->day << "/" << this->month << "/" << this->year;
}
