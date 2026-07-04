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
int main()
{
	University uni;
	/*cout << "Enter University Details \n";
	cin >> uni;
	ofstream fout("uniInfo.txt");
	fout << uni;
	fout.close();*/
	ifstream fin("uniInfo.txt");
	fin >> uni;
	fin.close();
	cout << uni;
	cout << "\nStudent Info whose Registration Number is 'L1F22BSCS0161'\n";
	uni.findStudentsInfoByRegNum("L1F22BSCS0161");
	cout << "\nTeacher Info whose Employee Id is '1002'\n";
	uni.findTeachersInfoByEmpID(1002);
	cout << "\nCourse Info whose Code is 'ITC-101'\n";
	uni.findCourseInfoByCourseCode("ITC-101");
	cout << "\nStudents Info whose Last Name is 'Soofi'\n";
	uni.findStudentsInfoByLastName("Soofi");
	cout << "\nStudents Info whose CGPA is '3.75'\n";
	uni.findStudentsByCGPA(3.75);
	University uni2 = uni;
	if (uni == uni2)
	{
		cout << "\nEqual\n";
	}
	else
	{
		cout << "\nUnequal\n";
	}
	return 0;
}
