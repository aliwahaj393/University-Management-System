#include<iostream>
using namespace std;
#include"UTILLITY.h"
#include"MyString.h"
#include "Course.h"

// Constructor for Course class, initializes the Course object with provided values,
Course::Course(const MyString& _title, const MyString& _code, const int& _creditHours, const MyString& _outline) : title(_title),
code(_code), outline(_outline)
{
	this->creditHours = checkValue(0, 6, _creditHours);
}
// Copy constructor for Course class, copies the values from another Course object.
Course::Course(const Course& course) : title(course.title), code(course.code), outline(course.outline)
{
	this->creditHours = course.creditHours;
}
// Set the title of the Course object.
void Course::setTitle(const MyString& _title)
{
	this->title = _title;
}
// Set the code of the Course object.
void Course::setCode(const MyString& _code)
{
	this->code = _code;
}
// Set the credit hours of the Course object
void Course::setCreditHours(const int& _creditHours)
{
	this->creditHours = checkValue(0, 6, _creditHours);
}
// Set the outline of the Course object.
void Course::setOutline(const MyString& _outline)
{
	this->outline = _outline;
}
// Check if two Course objects are equal.
bool Course::operator==(const Course& course) const
{
	if (this->title == course.title && this->creditHours == course.creditHours &&
		this->code == course.code && this->outline == course.outline)
	{
		return true;
	}
	return false;
}
// Assign the values of one Course object to another.
Course& Course::operator=(const Course& course)
{
	if (this == &course)
	{
		return *this;
	}
	this->setTitle(course.title);
	this->setCreditHours(course.creditHours);
	this->setCode(course.code);
	this->setOutline(course.outline);
	return *this;

}
// Overloaded input stream operator to read Course from console or file.
istream& operator>>(istream& input, Course& course)
{
	course.Read(input);
	return input;
}
// Overloaded output stream operator to write Course to console or file.
ostream& operator<<(ostream& output, const Course& course)
{
	course.Write(output);
	return output;
}
// Read Course values from console or file
void Course::Read(istream& input)
{
	if (&input == &cin)
	{
		//input from console.
		cout << "Enter Title : ";
		input >> this->title;
		cout << "Enter Code : ";
		input >> this->code;
		cout << "Enter Credit Hours : ";
		int value;
		input >> value;
		input.ignore();
		value = checkValue(0, 6, value);
		if (value == 0)
		{
			cout << "Invalid Credit Hours.\nSaving Zero to Credit Hours.\n";
		}
		this->creditHours = value;
		cout << "<Please Enter '$' to terminate input of Outline>\n";
		cout << "Enter Outline : ";
		this->outline.input(input, '$');
	}
	else
	{
		// File input.
		int value;
		input.ignore(100, ':');
		input.ignore();
		input >> this->title;
		input.ignore(100, ':');
		input.ignore();
		input >> this->code;
		input.ignore(100, ':');
		input.ignore();
		input >> value;
		input.ignore();
		this->setCreditHours(value);
		input.ignore(100, ':');
		input.ignore();
		this->outline.input(input, '$');
	}
}

// Write Course values to console or file
void Course::Write(ostream& output) const
{
	output << "Title : " << this->title << endl;
	output << "Code : " << this->code << endl;
	output << "Credit Hours : " << this->creditHours << endl;
	output << "Outline : " << this->outline;
	if (&output != &cout)
	{
		output << "$";
	}
}

