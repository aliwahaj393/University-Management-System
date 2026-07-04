class University
{
public:
	//  Constructors
	University(const MyString& _name = MyString{}, const MyString&_address = MyString{}, const Date&_dateOfFormation = Date{}, const MyString&_phoneNo = MyString{},
		const MyString&_email = MyString{}, const MyString&_website = MyString{}, const int&_noOfDegrees = 0, const Degree* _degrees = nullptr);
	University(const University&);
	//  Setters
	void setName(const MyString&_name) { this->name = _name; }
	void setAddress(const MyString&_address) { this->address = _address; }
	void setDateOfFormation(const Date&_dateOfFormation) { this->dateOfFormation = _dateOfFormation; }
	void setPhoneNo(const MyString&_phoneNo) { this->phoneNo = _phoneNo; }
	void setEmail(const MyString&_email) { this->email = _email; }
	void setWebsite(const MyString&_website) { this->website = _website; }
	void setNoOfDegrees(const int&_noOfDegrees);
	void setDegrees(const Degree*_degrees);
	//   Getters
	MyString getName()const { return this->name; }
	MyString getAddress()const { return this->address; }
	Date getDateOfFormation()const { return this->dateOfFormation; }
	MyString getPhoneNo()const { return this->phoneNo; }
	MyString getEmail()const { return this->email; }
	MyString getWebsite()const { return this->website; }
	int getNoOfDegrees()const { return this->noOfDegrees; }
	const Degree* getDegrees()const { return this->degrees; }
	//   Properties
	bool operator==(const University&);
	University& operator=(const University&);
	void Read(istream&);
	void Write(ostream&)const;
	void findStudentsInfoByLastName(const MyString & lastName) const;
	void findStudentsInfoByRegNum(const MyString & regNum) const;
	void findTeachersInfoByEmpID(const int & id) const;
	void findCourseInfoByCourseCode(const MyString & code) const;
	int calculateSalaries() const;
	void findAllStudentsInfoByDegree(const Degree & degree) const;
	void findStudentsByCGPA(const float & cgpa) const;
	//   Destructor
	~University() { delete[]this->degrees, this->degrees = nullptr; }
private:
	MyString name;
	MyString address;
	Date dateOfFormation;
	MyString phoneNo;
	MyString email;
	MyString website;
	int noOfDegrees;
	Degree* degrees;
};
Degree * deepCopy(const int & _noOfDegrees, const Degree * _degrees);
bool compareDegrees(const int & noOfDegrees, const Degree * const & degrees1, const Degree * const & degrees2);
istream& operator>>(istream& input, University& uni);
ostream& operator<<(ostream& output, const University& uni);