#include<iostream>
#include<fstream>
using namespace std;
#include"UTILLITY.h"
#include "MyString.h"
MyString::MyString(const char*const& s )
{
	this->str = copyStr(s);
}

MyString::MyString(const MyString& s) 
{
	this->str = copyStr(s.str);
}
MyString::~MyString()
{ 
	delete[] this->str;
	this->str = nullptr;
}
void display(const int& numOfString, const MyString* myString)
{
	for (int i = 0;i < numOfString;i++)
	{
		cout << myString[i] << " ";
	}
	cout << endl;
}
void MyString::setString(const char*const& s)
{
	delete[] this->str;
	this->str = nullptr;
	this->str = copyStr(s);
}
bool MyString::operator==(const MyString &myString)const
{
	return compareStr(this->str, myString.str);
}
bool isEqual(const MyString &str1, const MyString &str2)  // to check that MyStrings are equal or not
{
	int result = 0;
	result = str1.compare(str2.getString());
	if (!result)
	{
		return 1;
	}
	return 0;
}
int MyString::compare(const char *const &_str)const // to check c-string is equal or less or greater than c-string of MyString
{
	if (this->str == nullptr && _str == nullptr)
	{
		return 0;
	}
	else if (this->str == nullptr)
	{
		return -1;
	}
	else if (_str == nullptr)
	{
		return 1;
	}
	int i = 0;
	while (str[i] != '\0' && str[i] == _str[i])
	{
		++i;
	}
	int result = str[i] - _str[i];
	if (!result)
	{
		return 0;
	}
	else if (result > 0)
	{
		return 1;
	}
	return -1;
}
bool MyString::operator !=(const MyString& MyStr)const // != operator overload to compare two strings are not equal
{
	return !(isEqual(*this, MyStr));
}
MyString & MyString::operator=(const MyString &myString)
{
	if (this ==& myString)
	{
		return *this;	
	}
	this->setString(myString.str);
	return *this;
}
istream& operator>>(istream&input, MyString& myString)
{
	myString.read(input);
	return input;
}
ostream& operator<<(ostream& output, const MyString& myString)
{
	myString.write(output);
	return output;
}
void MyString::write(ostream &output) const
{
	if (this->str != nullptr)
	{
		output << this->str;
		return;
	}
}
void MyString::read(istream &input)
{
	int size = 1;
	char ch;
	char* temp = new char[size];
	int i = 0;
	while (input.get(ch))
	{
		if (ch!='\n')
		{
			temp[i++] = ch;
			reGrow(temp, size);
		}
		else
		{
			temp[i] = '\0';
			break;
		}
	}
	this->setString(temp);
	delete[] temp;
	temp = nullptr;
}
void MyString::input(istream&input, const char& terminatingChar) // inputs string to termminating char
{
	int size = 1;
	char ch;
	char* temp = new char[size];
	int i = 0;
	while (input.get(ch))
	{
		if (ch != terminatingChar)
		{
			temp[i++] = ch;
			reGrow(temp, size);
		}
		else
		{
			temp[i] = '\0';
			break;
		}
	}
	input.ignore();
	this->setString(temp);
	delete[]temp;
	temp = nullptr;
}