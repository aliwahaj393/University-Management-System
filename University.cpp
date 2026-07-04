#include<iostream>
using namespace std;
#include"UTILLITY.h"
#include"Date.h"
#include"MyString.h"
#include"Course.h"
#include"Person.h"
#include"Student.h"
#include"Teacher.h"
#include"Degree.h"
#include "University.h"

// Deep copy function for Degree array.
Degree* deepCopy(const int& _noOfDegrees, const Degree* _degrees)
{
	if (_degrees == nullptr)
	{
		return nullptr;
	}
	Degree* tempDegrees = new Degree[_noOfDegrees]{};
	for (int i = 0; i < _noOfDegrees; i++)
	{
		tempDegrees[i] = _degrees[i];
	}
	return tempDegrees;
}
// Compare two arrays of Degree objects for equality.
bool compareDegrees(const int& noOfDegrees, const Degree* const& degrees1, const Degree* const& degrees2)
{
	for (int i = 0; i < noOfDegrees; i++)
	{
		if (!(degrees1[i] == degrees2[i]))
		{
			return false;
		}
	}
	return true;
}
// Constructor for the University class.
University::University(const MyString& _name, const MyString& _address, const Date& _dateOfFormation, const MyString& _phoneNo, const MyString& _email,
	const MyString& _website, const int& _noOfDegrees, const Degree* _degrees) : name(_name), address(_address), dateOfFormation(_dateOfFormation),
	phoneNo(_phoneNo), email(_email), website(_website)
{
	this->noOfDegrees = checkValue(_noOfDegrees);
	this->degrees = deepCopy(this->noOfDegrees, _degrees);
}
// Copy constructor for the University class.
University::University(const University& uni) : name(uni.name), address(uni.address), dateOfFormation(uni.dateOfFormation),
phoneNo(uni.phoneNo), email(uni.email), website(uni.website)
{
	this->noOfDegrees = uni.noOfDegrees;
	this->degrees = deepCopy(this->noOfDegrees, uni.degrees);
}
void University::setNoOfDegrees(const int & _noOfDegrees)
{
	this->noOfDegrees = checkValue(_noOfDegrees);
}
// Setter for the faculties of the University class.
void University::setDegrees(const Degree* _faculties)
{
	delete[] this->degrees, this->degrees = nullptr;
	this->degrees = deepCopy(this->noOfDegrees, _faculties);
}
// Equality operator for the University class.
bool University::operator==(const University& uni)
{
	if (this->name != uni.name || this->address != uni.address || this->website != uni.website || !(this->dateOfFormation == uni.dateOfFormation)
		|| this->email != uni.email || this->phoneNo != uni.phoneNo || this->noOfDegrees != uni.noOfDegrees)
	{
		return false;
	}
	if (!(compareDegrees(this->noOfDegrees, this->degrees, uni.degrees)))
	{
		return false;
	}
	return true;
}
// Assignment operator for the University class.
University& University::operator=(const University& uni)
{
	if (this == &uni)
	{
		return *this;
	}
	this->setName(uni.name);
	this->setAddress(uni.address);
	this->setEmail(uni.email);
	this->setWebsite(uni.website);
	this->setPhoneNo(uni.phoneNo);
	this->setDateOfFormation(uni.dateOfFormation);
	this->setNoOfDegrees(uni.noOfDegrees);
	this->setDegrees(uni.degrees);
	return *this;
}
// Overloaded input stream operator for the University class.
istream& operator>>(istream& input, University& uni)
{
	uni.Read(input);
	return input;
}
// Overloaded output stream operator for the University class.
ostream& operator<<(ostream& output, const University& uni)
{
	uni.Write(output);
	return output;
}
// Read function for the University class to read from console or file
void University::Read(istream& input)
{
	if (&input == &cin)
	{
		int value;
		cout << "Enter Name : ";
		input >> this->name;
		cout << "Enter Address : ";
		input >> this->address;
		cout << "Enter Date Of Formation(dd/mm/yy) : ";
		input >> this->dateOfFormation;
		cout << "Enter Phone Number : ";
		input >> this->phoneNo;
		cout << "Enter Email : ";
		input >> this->email;
		cout << "Enter Website : ";
		input >> this->website;
		cout << "\nEnter Degrees Information\n";
		cout << "Enter No Of Degrees : ";
		input >> value;
		input.ignore();
		value = checkValue(value);
		if (value == 0)
		{
			cout << "No of Degrees cannot be negative.\nSaving Zero to No of Faculties\n";
		}
		this->setNoOfDegrees(value);
		Degree* tempDegrees = new Degree[this->noOfDegrees];
		for (int i = 0; i < this->noOfDegrees; i++)
		{
			cout << "Enter Degree" << i + 1 << " Info\n";
			input >> tempDegrees[i];
		}
		this->setDegrees(tempDegrees);
		delete[] tempDegrees;
		tempDegrees = nullptr;
	}
	else
	{
		int value;
		input.ignore(100, '\n');
		input.ignore(100, ':');
		input.ignore();
		input >> this->name;
		input.ignore(100, ':');
		input.ignore();
		input >> this->address;
		input.ignore(100, ':');
		input.ignore();
		input >> this->dateOfFormation;
		input.ignore(100, ':');
		input.ignore();
		input >> this->phoneNo;
		input.ignore(100, ':');
		input.ignore();
		input >> this->email;
		input.ignore(100, ':');
		input.ignore();
		input >> this->website;
		input.ignore(100, '\n');
		input.ignore(100, '\n');
		input.ignore(100, ':');
		input.ignore();
		input >> value;
		input.ignore();
		value = checkValue(value);
		this->setNoOfDegrees(value);
		Degree* tempDegrees = new Degree[this->noOfDegrees];
		for (int i = 0; i < this->noOfDegrees; i++)
		{
			input.ignore(100, '\n');
			input.ignore(100, '\n');
			input >> tempDegrees[i];
		}
		this->setDegrees(tempDegrees);
		delete[] tempDegrees;
		tempDegrees = nullptr;
	}
}
// Write function for the University class to write from console or file
void University::Write(ostream& output) const
{
	output << "University Information\n";
	output << "Name : " << this->name << endl;
	output << "Address : " << this->address << endl;
	output << "Date Of Formation : " << this->dateOfFormation << endl;
	output << "Phone Number : " << this->phoneNo << endl;
	output << "Email : " << this->email << endl;
	output << "Website : " << this->website << endl;
	output << "\nDegrees Information\n";
	output << "No Of Degrees : " << this->noOfDegrees << endl;
	for (int i = 0; i < this->noOfDegrees; i++)
	{
		output << "\nDegree" << i + 1 << " Info\n";
		output << this->degrees[i];
	}
}

void University::findStudentsInfoByLastName(const MyString & lastName) const
{
	if (this->degrees == nullptr)
	{
		cout << "No Information Found\n";
		return;
	}
	bool flag{};
	for (int i = 0;i < this->noOfDegrees;i++)
	{
		if (this->degrees + i == nullptr)
		{
			continue;
		}
		int noOfStudents = this->degrees[i].getNoOfStudents();
		for (int j = 0;j < noOfStudents;j++)
		{
			if (this->degrees[i].getStudents() + j == nullptr)
			{
				continue;
			}
			if (this->degrees[i].getStudents()[j].getLastName() == lastName)
			{
				flag = true;
				cout << this->degrees[i].getStudents()[j] << endl;
			}
		}
	}
	if (!flag)
	{
		cout << "No Students Found whose last name is '" << lastName << "'\n";
	}
}

void University::findStudentsInfoByRegNum(const MyString & regNum) const
{
	if (this->degrees == nullptr)
	{
		cout << "No Information Found\n";
		return;
	}
	for (int i = 0;i < this->noOfDegrees;i++)
	{
		if (this->degrees + i == nullptr)
		{
			continue;
		}
		int noOfStudents = this->degrees[i].getNoOfStudents();
		for (int j = 0;j < noOfStudents;j++)
		{
			if (this->degrees[i].getStudents() + j == nullptr)
			{
				continue;
			}
			if (this->degrees[i].getStudents()[j].getRegNum() == regNum)
			{
				cout << this->degrees[i].getStudents()[j];
				return;
			}
		}
	}
	cout << "No Student Found whose Registration Number is '" << regNum << "'\n";
}

void University::findTeachersInfoByEmpID(const int & id) const
{
	if (this->degrees == nullptr)
	{
		cout << "No Information Found\n";
		return;
	}
	for (int i = 0;i < this->noOfDegrees;i++)
	{
		if (this->degrees + i == nullptr)
		{
			continue;
		}
		int noOfTeachers = this->degrees[i].getNoOfTeachers();
		for (int j = 0;j < noOfTeachers;j++)
		{
			if (this->degrees[i].getTeachers() + j == nullptr)
			{
				continue;
			}
			if (this->degrees[i].getTeachers()[j].EMPLOYEE_ID == id)
			{
				cout << this->degrees[i].getTeachers()[j];
				return;
			}
		}

	}
	cout << "No Teacher Found whose Employee ID is '" << id << "'\n";
}

void University::findCourseInfoByCourseCode(const MyString & code) const
{
	if (this->degrees == nullptr )
	{
		cout << "No Information Found\n";
		return;
	}
	for (int i = 0;i < this->noOfDegrees;i++)
	{
		if (this->degrees + i == nullptr)
		{
			continue;
		}
		int noOfCourses = this->degrees[i].getNoOfCourses();
		for (int j = 0;j < noOfCourses;j++)
		{
			if (this->degrees[i].getCourses() + j == nullptr)
			{
				continue;
			}
			if (this->degrees[i].getCourses()[j].getCode() == code)
			{
				cout << this->degrees[i].getCourses()[j] << endl;
				return;
			}
		}
	}
	
	cout << "No Course Found which Code is '" << code << "'\n";
}

int University::calculateSalaries() const
{
	if (this->degrees == nullptr)
	{
		cout << "No Information Found\n";
		return 0;
	}
	int totalSalaries{};
	for (int i = 0;i < this->noOfDegrees;i++)
	{
		if (this->degrees+ i == nullptr)
		{
			continue;
		}
		int noOfTeachers = this->degrees[i].getNoOfTeachers();
		for (int j = 0;j < noOfTeachers;j++)
		{
			if (this->degrees[i].getTeachers() + j == nullptr)
			{
				continue;
			}
			totalSalaries += this->degrees[i].getTeachers()[j].getSalary();
		}
	}
	return totalSalaries;
}

void University::findAllStudentsInfoByDegree(const Degree & degree) const
{
	if (this->degrees == nullptr)
	{
		cout << "No Information Found\n";
		return;
	}
	bool flag{};
	for (int i = 0;i < this->noOfDegrees;i++)
	{
		if (this->degrees + i == nullptr)
		{
			continue;
		}
		if (this->degrees[i] == degree)
		{
			int noOfStudents = this->degrees[i].getNoOfStudents();
			for (int j = 0;j < noOfStudents;j++)
			{
				if (this->degrees[i].getStudents() + j == nullptr)
				{
					continue;
				}
				flag = true;
				cout << this->degrees[i].getStudents()[j] << endl;
			}
		}
	}
	if (!flag)
	{
		cout << "No Students Found whose Degree is '" << degree.getName() << "'\n";
	}
}

void University::findStudentsByCGPA(const float & cgpa) const
{
	if (this->degrees == nullptr )
	{
		cout << "No Information Found\n";
		return;
	}
	bool flag{};
	for (int i = 0;i < this->noOfDegrees;i++)
	{
		if (this->degrees + i == nullptr)
		{
			continue;
		}
		int noOfStudents = this->degrees[i].getNoOfStudents();
		for (int j = 0;j < noOfStudents;j++)
		{
			if (this->degrees[i].getStudents() + j == nullptr)
			{
				continue;
			}
			if (this->degrees[i].getStudents()[j].getCgpa() == cgpa)
			{

				flag = true;
				cout << this->degrees[i].getStudents()[j] << endl;
			}
		}
	}
	if (!flag)
	{
		cout << "No Students Found whose CGPA is '" << cgpa << "'\n";
	}
}
