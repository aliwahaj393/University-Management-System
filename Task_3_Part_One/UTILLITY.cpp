#include<iostream>
using namespace std;
#include"UTILLITY.h"
float checkValue(const float& lowerLimit, const float& upperLimit, const float& value)// to check int value for given range
{
	if (value < lowerLimit || value > upperLimit)
	{
		return 0;
	}
	return value;
}
int checkValue(const int& lowerLimit, const int& upperLimit, const int& value)// to check int value for given range
{
	if (value < lowerLimit || value > upperLimit)
	{
		return 0;
	}
	return value;
}
int lengthStr(const char*source)
{
	int length = 0;
	for (; source[length] != '\0'; length++)
	{
		;
	}
	return length + 1;
}
char* copyStr(const char*source)
{
	if (source == nullptr)
	{
		return nullptr;
	}
	int l = lengthStr(source);
	char* temp = new char[l];
	for (int i = 0; i < l; i++)
	{
		temp[i] = source[i];
	}
	return temp;
}
void reGrow(char*&_str, const int& size)
{
	if (_str == nullptr)
	{
		return;
	}
	int l = lengthStr(_str);
	char* temp = new char[l + size];
	for (int i = 0; i < l; i++)
	{
		temp[i] = _str[i];
	}
	delete[]_str;
	_str = temp;
}
bool compareStr(const char*_str1, const char*_str2)
{
	if (_str1 == nullptr && _str2 == nullptr)
	{
		return 1;
	}
	if (_str1 == nullptr || _str2 == nullptr)
	{
		return 0;
	}
	int i = 0;
	while (_str1[i] != '\0' && _str1[i] == _str2[i])
	{
		++i;
	}
	return _str1[i] == _str2[i];
}
double checkValue(const double& value)
{
	if (value < 0)
	{
		cout << "Invalid value saving zero\n";
		return 0;
	}
	return value;
}
int checkValue(const int& value)
{
	if (value < 0)
	{
		cout << "Invalid value saving zero\n";
		return 0;
	}
	return value;
}
long double checkValue(const long double& value)
{
	if (value < 0)
	{
		return 0;
	}
	return value;
}
void inputString(istream& input,char*& str)
{
	int size = 1;
	str = new char[size];
	char temp;
	while (input.get(temp))
	{
		if (temp != '\n')
		{
			str[size - 1] = temp;
			reGrow(str, size);
			++size;
		}
		else
		{
			str[size - 1] = '\0';
			break;
		}
	}
}