//#include <iostream>
//#include<fstream>
//using namespace std;
//#include"MyString.h"
//#include"Date.h"
//#include"Person.h"
//#include"Student.h"
//#include"Teacher.h"
//int main1()
//{
//	Date dateOfBirth1(20, 12, 1970);
//	Date dateOfBirth2(20, 12, 2000);
//	Date dateOfAdmission(22, 7, 2022);
//	Date dateOfJoing(22, 7, 2007);
//	//Person person1("Ali", "Wahaj", dateOfBirth2, "H#22");
//	Student student1("Ali", "Wahaj", dateOfBirth2, "H#22", "L1F22BSCS0161", 50000, dateOfAdmission, "Fall-2022", 3.5);
//	Teacher teacher1("Dr Ahmad", "Shabbar Kazmi", dateOfBirth1, "H#23", 500000, "Phd", "Ex-Dean", dateOfJoing);
//	cout << "\nStudent1 Details\n";
//	cout << student1 << endl;
//	cout << "\nTeacher1 Details\n";
//	cout << teacher1 << endl;
//	cout << "\nEnter Student1 Details\n";
//	cin >> student1;
//	cout << "\nEnter Teacher1 Details\n";
//	cin >> teacher1;
//	ofstream fout("a4TaskOneData.txt");
//	fout << student1;
//	fout << teacher1;
//	fout.close();
//	Student student2;
//	Teacher teacher2;
//	ifstream fin("a4TaskOneData.txt");
//	fin >> student2;
//	fin >> teacher2;
//	fin.close();
//	cout << "\nStudent1 Details After reading from File\n";
//	cout << student2 << endl;
//	cout << "\nTeacher2 Details After reading from File\n";
//	cout << teacher2 << endl;
//	if (student1 == student2)
//	{
//		cout << "\nStudent's are equal\n";
//	}
//	if (teacher1 == teacher2)
//	{
//		cout << "\nTeacher's are equal\n";
//	}
//	Date todayDate(23, 1, 2024);
//	cout <<"Age : "<< student1.calculateAge(todayDate) << endl;
//	return 0;
//}
