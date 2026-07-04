#pragma once
class Person
{
public:
	// Default Parameterized Constructor
	Person(const MyString&_firstName = MyString{}, const MyString&_lastName = MyString{},
		const Date&_dateOfBirth = Date{}, const MyString&_address = MyString{});
	//  Copy Constructor
	Person(const Person& person);
	// Setters
	void setFirstName(const MyString& _firstName);
	void setLastName(const MyString& _lastName);
	void setDateOfBirth(const Date& _dateOfBirth);
	void setAddress(const MyString& _address);
	//  Getters
	MyString getFirstName()const { return this->firstName; }
	MyString getLastName()const { return this->lastName; }
	Date getDateOfBirth()const { return this->dateOfBirth; }
	MyString getAddress()const { return this->address; }
	// Properties
	int calculateAge(const Date&);
	// Operators overloaded
	bool operator==(const Person& person)const;
	const Person& operator=(const Person& person);
	// To read and Write
	virtual void Read(istream& input)=0;
	virtual void Write(ostream& output)const=0;
	// Destructor
	~Person() {}
private:
	MyString firstName;
	MyString lastName;
	Date dateOfBirth;
	MyString address;
};
istream& operator>>(istream& input, Person& person);
ostream& operator<<(ostream& output, const Person& person);
