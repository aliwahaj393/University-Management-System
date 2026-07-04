#include<iostream>
using namespace std;
#include"UTILLITY.h"
#include"Date.h"
#include"MyString.h"
#include"Course.h"
#include"Person.h"
#include"Student.h"
#include"Teacher.h"
#include "Degree.h"

Course* deepCopy(const int&_noOfCourses, const Course*_courses) // deep Copies of Courses pointer 
{
	if (_courses == nullptr)
	{
		return nullptr;
	}
	Course* tempCourses = new Course[_noOfCourses]{};
	for (int i = 0;i < _noOfCourses;i++)
	{
		tempCourses[i] = _courses[i];
	}
	return tempCourses;
}
bool compareCourses(const int&noOfCourses, const Course*const& courses1, const Course*const& courses2)// Compares two Courses Pointers
{
	for (int i = 0;i < noOfCourses;i++)
	{
		if (!(courses1[i] == courses2[i]))
		{
			return false;
		}
	}
	return true;
}
// Deep copy function for Student array.
Student* deepCopy(const int& _noOfStudents, const Student* _students)
{
	if (_students == nullptr)
	{
		return nullptr;
	}
	Student* tempStudents = new Student[_noOfStudents]{};
	for (int i = 0; i < _noOfStudents; i++)
	{
		tempStudents[i] = _students[i];
	}
	return tempStudents;
}
// Compare two arrays of Student objects for equality.
bool compareStudents(const int& noOfStudents, const Student* const& students1, const Student* const& students2)
{
	for (int i = 0; i < noOfStudents; i++)
	{
		if (!(students1[i] == students2[i]))
		{
			return false;
		}
	}
	return true;
}
Teacher* deepCopy(const int& _noOfTeachers, const Teacher* _teachers)
{
	if (_teachers == nullptr)
	{
		return nullptr;
	}
	Teacher* tempTeachers = new Teacher[_noOfTeachers]{};
	for (int i = 0; i < _noOfTeachers; i++)
	{
		tempTeachers[i] = _teachers[i];
	}
	return tempTeachers;
}
// Function to compare two arrays of Teacher objects for equality.
bool compareTeachers(const int& noOfTeachers, const Teacher* const& teachers1, const Teacher* const& teachers2)
{
	for (int i = 0; i < noOfTeachers; i++)
	{
		if (!(teachers1[i] == teachers2[i]))
		{
			return false;
		}
	}
	return true;
}
// Constructor for Degree class, initializes the Degree object with provided values
Degree::Degree(const MyString& _name , const int& _duration , const int&_noOfCourses , const Course*_courses ,const int&_noOfStudents ,
	const Student*_students , const int&_noOfTeachers , const Teacher*_teacher ) : name(_name)
{
	this->duration = checkValue(0, 5, _duration);
	this->noOfCourses = checkValue(_noOfCourses);
	this->courses = deepCopy(this->noOfCourses, _courses);
	this->noOfStudents = checkValue(_noOfStudents);
	this->students = deepCopy(this->noOfStudents, _students);
	this->noOfTeachers = checkValue(_noOfTeachers);
	this->teachers = deepCopy(this->noOfTeachers, _teacher);
}
// Copy constructor for Degree class, copies the values from another Degree object.
Degree::Degree(const Degree& degree) : name(degree.name)
{
	this->duration = degree.duration;
	this->noOfCourses = degree.noOfCourses;
	this->courses = deepCopy(this->noOfCourses, degree.courses);
	this->noOfStudents = degree.noOfStudents;
	this->students = deepCopy(this->noOfStudents, degree.students);
	this->noOfTeachers = checkValue(degree.noOfTeachers);
	this->teachers = deepCopy(this->noOfTeachers,degree.teachers);
}
// Set the duration of the Degree object
void Degree::setDuration(const int& duration)
{
	this->duration = checkValue(1, 6, duration);
}
void Degree::setNoOfCourses(const int & _noOfCourses)
{
	this->noOfCourses = checkValue(_noOfCourses);
}
// Set the courses of the Degree object
void Degree::setCourses(const Course* _courses)
{
	delete[] this->courses, this->courses = nullptr;
	this->courses = deepCopy(this->noOfCourses, _courses);
}
void Degree::setNoOfStudents(const int & _noOfStudents)
{
	this->noOfStudents = checkValue(_noOfStudents);
}
// Set the students of the Degree object
void Degree::setStudents(const Student* _students)
{
	delete[] this->students, this->students = nullptr;
	this->students = deepCopy(this->noOfStudents, _students);
}
void Degree::setNoOfTeachers(const int & _noOfTeachers)
{
	this->noOfTeachers = checkValue(_noOfTeachers);
}
void Degree::setTeachers(const Teacher *teacher)
{
	delete[] this->teachers, this->teachers = nullptr;
	this->teachers = deepCopy(this->noOfTeachers, teacher);
}
// Assignment operator for Degree class, assigns the values of one Degree object to another.
Degree& Degree::operator=(const Degree& degree)
{
	if (this == &degree)
	{
		return *this;
	}
	this->setName(degree.name);
	this->setDuration(degree.duration);
	this->setNoOfCourses(degree.noOfCourses);
	this->setCourses(degree.courses);
	this->setNoOfStudents(degree.noOfStudents);
	this->setStudents(degree.students);
	this->setNoOfTeachers(degree.noOfTeachers);
	this->setTeachers(degree.teachers);
	return *this;
}
// Equality operator for Degree class, checks if two Degree objects are equal.
bool Degree::operator==(const Degree& degree) const
{
	if (this->noOfCourses != degree.noOfCourses || this->noOfStudents != degree.noOfStudents || this->noOfTeachers != degree.noOfTeachers)
	{
		return false;
	}
	if (!(this->name== degree.name) || this->duration != degree.duration)
	{
		return false;
	}
	if (!(compareCourses(this->noOfCourses, this->courses, degree.courses)) || !(compareStudents(this->noOfStudents, this->students, degree.students)) ||
		!(compareTeachers(this->noOfTeachers, this->teachers, degree.teachers)))
	{
		return false;
	}
	return true;
}
// Overloaded input stream operator to read Degree from console or File.
istream& operator>>(istream& input, Degree& degree)
{
	degree.Read(input);
	return input;
}
// Overloaded output stream operator to write Degree to console or File.
ostream& operator<<(ostream& output, const Degree& degree)
{
	degree.Write(output);
	return output;
}
// Read Degree values from console or File
void Degree::Read(istream& input)
{
	if (&input == &cin)
	{
		int value;
		cout << "Enter Name : ";
		input >> this->name;
		cout << "Enter Duration(in years) : ";
		input >> value;
		value = checkValue(0, 6, value);
		if (value == 0)
		{
			cout << "Invalid Duration.\nSaving Zero to Duration\n";
		}
		this->duration = value;
		cout << "\nEnter Courses Information\n";
		cout << "Enter No Of Courses : ";
		input >> value;
		input.ignore();
		value = checkValue(value);
		if (value == 0)
		{
			cout << "No Of Courses cannot be negative.\nSaving Zero to No Of Courses\n";
		}
		this->noOfCourses = value;
		Course* tempCourses = new Course[this->noOfCourses];
		for (int i = 0; i < this->noOfCourses; i++)
		{
			cout << "Enter Course" << i + 1 << " Info\n";
			input >> tempCourses[i];
		}
		this->setCourses(tempCourses);
		delete[] tempCourses;
		tempCourses = nullptr;
		cout << "\nEnter Students Information\n";
		cout << "Enter No Of Students : ";
		input >> value;
		input.ignore();
		value = checkValue(value);
		if (value == 0)
		{
			cout << "No Of Students cannot be negative.\nSaving Zero to No Of Students\n";
		}
		this->noOfStudents = value;
		Student* tempStudents = new Student[this->noOfStudents];
		for (int i = 0; i < this->noOfStudents; i++)
		{
			cout << "Enter Student" << i + 1 << " Information\n";
			input >> tempStudents[i];
		}
		this->setStudents(tempStudents);
		delete[] tempStudents;
		tempStudents = nullptr;
		cout << "\nEnter Teachers Information\n";
		cout << "Enter No Of Teachers : ";
		input >> value;
		input.ignore();
		value = checkValue(value);
		if (value == 0)
		{
			cout << "No Of Teachers cannot be negative.\nSaving Zero to No Of Students\n";
		}
		this->noOfTeachers = value;
		Teacher* tempTeacher = new Teacher[this->noOfTeachers];
		for (int i = 0; i < this->noOfTeachers; i++)
		{
			cout << "Enter Teacher" << i + 1 << " Information\n";
			input >> tempTeacher[i];
		}
		this->setTeachers(tempTeacher);
		delete[] tempTeacher;
		tempTeacher = nullptr;
	}
	else
	{
		int value;
		input.ignore(100, ':');
		input.ignore();
		input >> this->name;
		input.ignore(100, ':');
		input >> value;
		input.ignore();
		this->setDuration(value);
		input.ignore(100, '\n');
		input.ignore(100, '\n');
		input.ignore(100, ':');
		input.ignore();
		input >> value;
		this->setNoOfCourses(value);
		input.ignore();
		Course* tempCourses = new Course[this->noOfCourses];
		for (int i = 0; i < this->noOfCourses; i++)
		{
			input.ignore(100, '\n');
			input.ignore(100, '\n');
			input >> tempCourses[i];
		}
		this->setCourses(tempCourses);
		delete[] tempCourses;
		tempCourses = nullptr;
		input.ignore(100, '\n');
		input.ignore(100, '\n');
		input.ignore(100, ':');
		input.ignore();
		input >> value;
		this->setNoOfStudents(value);
		input.ignore();
		Student* tempStudents = new Student[this->noOfStudents];
		for (int i = 0; i < this->noOfStudents; i++)
		{
			input.ignore(100, '\n');
			input.ignore(100, '\n');
			input >> tempStudents[i];
		}
		this->setStudents(tempStudents);
		delete[] tempStudents;
		tempStudents = nullptr;
		input.ignore(100, '\n');
		input.ignore(100, '\n');
		input.ignore(100, ':');
		input.ignore();
		input >> value;
		this->setNoOfTeachers(value);
		input.ignore();
		Teacher* tempTeachers = new Teacher[this->noOfTeachers];
		for (int i = 0; i < this->noOfTeachers; i++)
		{
			input.ignore(100, '\n');
			input.ignore(100, '\n');
			input >> tempTeachers[i];
		}
		this->setTeachers(tempTeachers);
		delete[] tempTeachers;
		tempTeachers = nullptr;
	}
}
// Write Degree values to console or File
void Degree::Write(ostream& output) const
{
	output << "Name : " << this->name << endl;
	output << "Duration : " << this->duration << " years" << endl;
	output << "\nCourses Information\n";
	output << "No of Courses : " << this->noOfCourses << endl;
	if (this->courses != nullptr)
	{
		for (int i = 0; i < this->noOfCourses; i++)
		{
			output << "\nCourse" << i + 1 << "Info\n";
			output << this->courses[i] << endl;
		}
	}
	output << "\nStudents Information\n";
	output << "No of Students : " << this->noOfStudents << endl;
	if (this->students != nullptr)
	{
		for (int i = 0; i < this->noOfStudents; i++)
		{
			output << "\nStudent" << i + 1 << "Info\n";
			output << this->students[i] << endl;
		}
	}
	output << "\nTeachers Information\n";
	output << "No of Teachers : " << this->noOfTeachers << endl;
	if (this->teachers != nullptr)
	{
		for (int i = 0; i < this->noOfTeachers; i++)
		{
			output << "\nTeacher" << i + 1 << "Info\n";
			output << this->teachers[i] << endl;
		}
	}

}

Degree::~Degree()
{
	delete[]this->students, this->students = nullptr;
	delete[]this->teachers, this->teachers = nullptr;
	delete[]this->courses, this->courses = nullptr;
}
