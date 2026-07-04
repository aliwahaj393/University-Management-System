#pragma once
class Teacher:public Person
{
public:
	// Constructors
	Teacher();
	Teacher(const Person&_person, const int&_salary,const MyString&_finalDegree, const MyString&_designation, const Date&_dateOfJoining);
	Teacher(const MyString&_firstName, const MyString&_lastName,const Date&_dateOfBirth, const MyString&_address, const int&_salary,
		const MyString&_finalDegree , const MyString&_designation,const Date&_dateOfJoining);
	Teacher(const Teacher& teacher);
	//  Setters
	void setSalary(const int&_salary);
	void setFinalDegree(const MyString&_finalDegree);
	void setDesignation(const MyString&_designation);
	void setDateOfJoining(const Date&_dateOfJoining);
	//	Getters
	int getSalary()const { return this->salary; }
	MyString getFinalDegree()const { return this->finalDegree; }
	MyString getDesignation()const { return this->designation; }
	Date getDateOfJoining()const { return this->dateOfJoining; }
	// Operators Overloaded
	bool operator==(const Teacher& teacher)const;
	const Teacher& operator=(const Teacher& teacher);
	void Read(istream& input);
	void Write(ostream& output)const;
	//   Destructor
	~Teacher() {}
	// Attribute
	const int EMPLOYEE_ID;
private:
	int salary;
	MyString finalDegree;
	MyString designation;
	Date dateOfJoining;
	int setEMPLOYEE_ID();
};
istream& operator>>(istream& input, Teacher& teacher);
ostream& operator<<(ostream& output, const Teacher& teacher);
