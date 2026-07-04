#pragma once
class Student:public Person
{
public:
	//	Constructors
	Student();
	Student(const MyString&_firstName, const MyString&_lastName ,const Date&_dateOfBirth , const MyString&_address, const MyString& _regNum ,
		const int&_feesPerSemester, const Date&_admissionDate, const MyString&_batch,const float&_cgpa);
	Student(const Person&_person, const MyString& _regNum,const int&_feesPerSemester, const Date&_admissionDate, const MyString&_batch, const float&_cgpa);
	Student(const Student& student);
	//	Getters and Setters
	void setRegNum(const MyString&_regNum);
	void setFeesPerSemester(const int&_feesPerSemester);
	void setAdmissionDate(const Date&_admissionDate);
	void setBatch(const MyString&_batch);
	void setCgpa(const float&_cgpa);
	MyString getRegNum()const { return this->regNum; }
	int getFeesPerSemester()const { return this->feesPerSemester; }
	Date getAdmissionDate()const { return this->admissionDate; }
	MyString getBatch()const { return this->batch; }
	float getCgpa()const { return this->cgpa; }
	// Operators Overloaded
	bool operator==(const Student& student)const;
	const Student& operator=(const Student& student);
	void Read(istream& input);
	void Write(ostream& output)const;
	// Destructor
	~Student() {}
private:
	MyString regNum;
	int feesPerSemester;
	Date admissionDate;
	MyString batch;
	float cgpa;
};
istream& operator>>(istream& input, Student& student);
ostream& operator<<(ostream& output, const Student& student);
