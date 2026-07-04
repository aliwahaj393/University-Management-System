#include<iostream>
using namespace std;
#include"UTILLITY.h"
#include"MyString.h"
#include"Date.h"
#include"Person.h"
#include "Student.h"

Student::Student()
{
	this->cgpa = 0;
	this->feesPerSemester = 0;
}

Student::Student(const MyString & _firstName, const MyString & _lastName, const Date & _dateOfBirth, const MyString & _address,
	const MyString & _regNum, const int & _feesPerSemester, const Date & _admissionDate, const MyString & _batch,
	const float & _cgpa) :Person(_firstName, _lastName, _dateOfBirth, _address), regNum(_regNum),admissionDate(_admissionDate), batch(_batch)
{
	this->feesPerSemester = checkValue(_feesPerSemester);
	this->cgpa = checkValue(0.0f, 4.0f, _cgpa);
}

Student::Student(const Person & _person, const MyString & _regNum, const int & _feesPerSemester, const Date & _admissionDate, const MyString & _batch,
	const float & _cgpa):Person(_person), regNum(_regNum),admissionDate(_admissionDate), batch(_batch)
{
	this->feesPerSemester = checkValue(_feesPerSemester);
	this->cgpa = checkValue(0.0f, 4.0f, _cgpa);
}

Student::Student(const Student & student) : Person(student), regNum(student.regNum), feesPerSemester(student.feesPerSemester),
admissionDate(student.admissionDate), batch(student.batch), cgpa(student.cgpa)
{
}

void Student::setRegNum(const MyString & _regNum)
{
	this->regNum = _regNum;
}

void Student::setFeesPerSemester(const int & _feesPerSemester)
{
	this->feesPerSemester = checkValue(_feesPerSemester);
}

void Student::setAdmissionDate(const Date & _admissionDate)
{
	this->admissionDate = _admissionDate;
}

void Student::setBatch(const MyString & _batch)
{
	this->batch = _batch;
}

void Student::setCgpa(const float & _cgpa)
{
	this->cgpa = checkValue(0.0f, 4.0f, _cgpa);
}

bool Student::operator==(const Student & student) const
{
	if (!(Person::operator==(student)) || !(this->regNum == student.regNum) || !(this->cgpa == student.cgpa) ||
		!(this->feesPerSemester == student.feesPerSemester) || !(this->admissionDate == student.admissionDate) ||
		!(this->batch == student.batch))
	{
		return false;
	}
	return true;
}

const Student & Student::operator=(const Student & student)
{
	if (this == &student)
	{
		return *this;
	}
	Person::operator=(student);
	this->setRegNum(student.regNum);
	this->setFeesPerSemester(student.feesPerSemester);
	this->setAdmissionDate(student.admissionDate);
	this->setBatch(student.batch);
	this->setCgpa(student.cgpa);
	return *this;
}

void Student::Read(istream & input)
{
	Person::Read(input);
	if (&input == &cin)
	{
		int tempInt;
		float tempFloat;
		cout << "Enter Registration Number : ";
		input >> this->regNum;
		cout << "Enter Fees per Semester : ";
		input >> tempInt;
		input.ignore();
		this->setFeesPerSemester(tempInt);
		cout << "Enter Admission Date in Format(dd/mm/yy) : ";
		input >> this->admissionDate;
		cout << "Enter Batch : ";
		input >> this->batch;
		cout << "Enter CGPA : ";
		input >> tempFloat;
		input.ignore();
		this->setCgpa(tempFloat);
	}
	else
	{
		int tempInt;
		float tempFloat;
		input.ignore(100, ':');
		input.ignore();
		input >> this->regNum;
		input.ignore(100, ':');
		input.ignore();
		input >> tempInt;
		input.ignore();
		this->setFeesPerSemester(tempInt);
		input.ignore(100, ':');
		input.ignore();
		input >> this->admissionDate;
		input.ignore(100, ':');
		input.ignore();
		input >> this->batch;
		input.ignore(100, ':');
		input.ignore();
		input >> tempFloat;
		input.ignore();
		this->setCgpa(tempFloat);
	}
}

void Student::Write(ostream & output) const
{
	Person::Write(output);
	output << "Registration Number : " << this->regNum << endl;
	output << "Fees Per Semester : " << this->feesPerSemester << endl;
	output << "Admission Date : " << this->admissionDate << endl;
	output << "Batch : " << this->batch << endl;
	output << "CGPA : " << this->cgpa << endl;
}

istream & operator>>(istream & input, Student & student)
{
	student.Read(input);
	return input;
}

ostream & operator<<(ostream & output, const Student & student)
{
	student.Write(output);
	return output;
}
