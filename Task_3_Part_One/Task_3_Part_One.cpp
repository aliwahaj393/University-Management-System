#include <iostream>
#include <fstream>
using namespace std;
#include"Date.h"
#include"MyString.h"
#include"Course.h"
#include"Person.h"
#include"Student.h"
#include"Teacher.h"
#include"Degree.h"
#include "University.h"
int main3()
{
	Date dob(1, 5, 2000);
	Student student("Ali", "Wahaj", dob, "H#22", "L1F22BSCS0161", 50000, dob, "FALL-2022", 3.0);
	Teacher teacher("Dr Ahmad", "Shabbar Kazmi", dob, "H#23", 500000, "PHD", "Dr", dob);
	Person*p[2] = { &student,&teacher };
	for (int i = 0;i < 2;++i)
	{
		cout << *(p[i]) << endl;
	}
	return 0;
}
