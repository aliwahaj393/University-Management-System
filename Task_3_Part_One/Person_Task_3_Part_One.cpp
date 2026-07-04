#include<iostream>
using namespace std;
#include"MyString.h"
#include"Date.h"
#include "Person.h"

Person::Person(const MyString & _firstName, const MyString & _lastName, const Date & _dateOfBirth,
	const MyString & _address):firstName(_firstName),lastName(_lastName),dateOfBirth(_dateOfBirth),address(_address)
{
}

Person::Person(const Person & person) : firstName(person.firstName), lastName(person.lastName), dateOfBirth(person.dateOfBirth),
	address(person.address)
{
}

void Person::setFirstName(const MyString & _firstName)
{
	this->firstName = _firstName;
}

void Person::setLastName(const MyString & _lastName)
{
	this->lastName = _lastName;
}

void Person::setDateOfBirth(const Date & _dateOfBirth)
{
	this->dateOfBirth = _dateOfBirth;
}

void Person::setAddress(const MyString & _address)
{
	this->address = _address;
}

int Person::calculateAge(const Date &_date)
{
	int age = _date.getYear() - this->dateOfBirth.getYear();
	if (age< 0)
	{
		return 0;
	}
	return age;
}

bool Person::operator==(const Person & person) const
{
	if (!(this->firstName == person.firstName) || !(this->lastName == person.lastName) ||
		!(this->dateOfBirth == person.dateOfBirth) || !(this->address == person.address))
	{
		return false;
	}
	return true;
}

const Person & Person::operator=(const Person & person)
{
	if (this == &person)
	{
		return *this;
	}
	this->setFirstName(person.firstName);
	this->setLastName(person.lastName);
	this->setDateOfBirth(person.dateOfBirth);
	this->setAddress(person.address);
	return *this;
}

void Person::Read(istream & input)
{
	if (&input == &cin)
	{
		cout << "Enter First Name : ";
		input >> this->firstName;
		cout << "Enter Last Name : ";
		input >> this->lastName;
		cout << "Enter Date of Birth in Format(dd/mm/yy) : ";
		input >> this->dateOfBirth;
		cout << "Enter Address : ";
		input >> this->address;
	}
	else
	{
		input.ignore(100, ':');
		input.ignore();
		input >> this->firstName;
		input.ignore(100, ':');
		input.ignore();
		input >> this->lastName;
		input.ignore(100, ':');
		input.ignore();
		input >> this->dateOfBirth;
		input.ignore(100, ':');
		input.ignore();
		input >> this->address;
	}
}

void Person::Write(ostream & output) const
{
	output << "First Name : " << this->firstName << endl;
	output << "Last Name : " << this->lastName << endl;
	output << "Date of Birth : " << this->dateOfBirth << endl;
	output << "Address : " << this->address << endl;
}

istream & operator>>(istream & input, Person & person)
{
	person.Read(input);
	return input;
}

ostream & operator<<(ostream & output, const Person & person)
{
	person.Write(output);
	return output;
}
