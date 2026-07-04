class Course
{
public:
	//  Constructors
	Course(const MyString& _title = MyString{}, const MyString& _code = MyString{}, const int& _creditHours = 0, const MyString&_outline = MyString{});
	Course(const Course&);
	//   Setters And Getters
	void setTitle(const MyString&_title);
	void setCode(const MyString&_code);
	void setCreditHours(const int&);
	void setOutline(const MyString&_outline);
	MyString getTitle()const { return this->title; }
	MyString getCode()const { return this->code; }
	int getCreditHours()const { return this->creditHours; }
	MyString getOutline()const { return this->outline; }
	//  Properties
	bool operator==(const Course&)const;
	Course& operator=(const Course&);
	void Read(istream&);
	void Write(ostream&)const;
	//   Destructor
	~Course() {}
private:
	MyString title;
	MyString code;
	int creditHours;
	MyString outline;
};
istream& operator>>(istream& input, Course& uni);
ostream& operator<<(ostream& output, const Course& uni);