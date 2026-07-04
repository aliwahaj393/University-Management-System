#include<iostream>
using namespace std;
#include"UTILLITY.h"
#include"MyString.h"
#include"Date.h"
#include"Person.h"
#include "Teacher.h"

Teacher::Teacher():EMPLOYEE_ID(this->setEMPLOYEE_ID())
{
	this->salary = 0;
}

Teacher::Teacher(const Person & _person, const int & _salary, const MyString & _finalDegree, const MyString & _designation, 
	const Date & _dateOfJoining): Person(_person), finalDegree(_finalDegree), designation(_designation), dateOfJoining(_dateOfJoining), EMPLOYEE_ID(this->setEMPLOYEE_ID())
{
	this->salary = checkValue(_salary);
}

Teacher::Teacher(const MyString & _firstName, const MyString & _lastName, const Date & _dateOfBirth,const MyString&_address, const int & _salary,
	const MyString & _finalDegree,const MyString & _designation,const Date & _dateOfJoining):Person(_firstName, _lastName, _dateOfBirth, _address),	
	finalDegree(_finalDegree),designation(_designation),dateOfJoining(_dateOfJoining), EMPLOYEE_ID(this->setEMPLOYEE_ID())
{
	this->salary = checkValue(_salary);
}

Teacher::Teacher(const Teacher & teacher):Person(teacher),finalDegree(teacher.finalDegree),
	designation(teacher.designation),dateOfJoining(teacher.dateOfJoining), EMPLOYEE_ID(this->setEMPLOYEE_ID())
{
	this->salary = checkValue(teacher.salary);
}

int Teacher::setEMPLOYEE_ID()
{
	static int uniqueId = 999;
	return ++uniqueId;
}

void Teacher::setSalary(const int & _salary)
{
	this->salary = checkValue(_salary);
}

void Teacher::setFinalDegree(const MyString & _finalDegree)
{
	this->finalDegree = _finalDegree;
}

void Teacher::setDesignation(const MyString & _designation)
{
	this->designation = _designation;
}

void Teacher::setDateOfJoining(const Date & _dateOfJoining)
{
	this->dateOfJoining = _dateOfJoining;
}

bool Teacher::operator==(const Teacher & teacher) const
{
	if (!(Person::operator==(teacher)) || !(this->finalDegree == teacher.finalDegree) || this->salary != teacher.salary ||
		!(this->designation == teacher.designation) || !(this->dateOfJoining == teacher.dateOfJoining))
	{
		return false;
	}
	return true;
}

const Teacher & Teacher::operator=(const Teacher & teacher)
{
	if (this == &teacher)
	{
		return *this;
	}
	Person::operator=(teacher);
	this->setSalary(teacher.salary);
	this->setFinalDegree(teacher.finalDegree);
	this->setDesignation(teacher.designation);
	this->setDateOfJoining(teacher.dateOfJoining);
	return *this;
}

void Teacher::Read(istream & input)
{
	Person::Read(input);
	if (&input == &cin)
	{
		int temp;
		cout << "Enter Salary : ";
		input >> temp;
		input.ignore();
		this->setSalary(temp);
		cout << "Final Degree : ";
		input >> this->finalDegree;
		cout << "Designation : ";
		input >> this->designation;
		cout << "Date Of Joining in Format(dd/mm/yy) : ";
		input >> this->dateOfJoining;
	}
	else
	{
		int temp;
		input.ignore(100, '\n');
		input.ignore(100, '$');
		input >> temp;
		input.ignore();
		this->setSalary(temp);
		input.ignore(100, ':');
		input.ignore();
		input >> this->finalDegree;
		input.ignore(100, ':');
		input.ignore();
		input >> this->designation;
		input.ignore(100, ':');
		input.ignore();
		input >> this->dateOfJoining;
	}
}

void Teacher::Write(ostream & output) const
{
	Person::Write(output);
	output << "Employee Id : " << this->EMPLOYEE_ID << endl;
	output << "Salary : $" << this->salary << endl;
	output << "Final Degree : " << this->finalDegree << endl;
	output << "Designation : " << this->designation << endl;
	output << "Date of Joining : " << this->dateOfJoining << endl;
}

istream & operator>>(istream & input, Teacher & teacher)
{
	teacher.Read(input);
	return input;
}

ostream & operator<<(ostream & output, const Teacher & teacher)
{
	teacher.Write(output);
	return output;
}
