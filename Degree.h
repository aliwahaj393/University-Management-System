class Degree
{
public:
	//  Constructors
	Degree(const MyString& _name = MyString{}, const int& _duration = 0, const int&_noOfCourses = 0, const Course*_courses = nullptr,
		const int&_noOfStudents = 0, const Student*_students = nullptr,const int&_noOfTeachers=0,const Teacher*_teacher=nullptr);
	Degree(const Degree&);
	// Setters
	void setName(const MyString& n) { this->name = n; }
	void setDuration(const int&);
	void setNoOfCourses(const int&_noOfCourses);
	void setCourses(const Course*);
	void setNoOfStudents(const int&_noOfStudents);
	void setStudents(const Student*);
	void setNoOfTeachers(const int&_noOfTeachers);
	void setTeachers(const Teacher*);
	//  Getters
	MyString getName()const { return this->name; }
	int getDuration()const { return this->duration; }
	int getNoOfCourses()const { return this->noOfCourses; }
	const Course* getCourses()const { return this->courses; }
	int getNoOfStudents()const { return this->noOfStudents; }
	const Student* getStudents()const { return this->students; }
	int getNoOfTeachers()const { return this->noOfTeachers; }
	const Teacher* getTeachers()const { return this->teachers; }
	//  Properties
	Degree& operator =(const Degree&);
	bool operator ==(const Degree&)const;
	void Read(istream&);
	void Write(ostream&)const;
	//   Destructor
	~Degree();
private:
	MyString name;
	int duration;
	int noOfCourses;
	Course* courses;
	int noOfStudents;
	Student* students;
	int noOfTeachers;
	Teacher* teachers;
};
istream& operator>>(istream& input, Degree& uni);
ostream& operator<<(ostream& output, const Degree& uni);
Course* deepCopy(const int&_noOfCourses, const Course*_courses);
bool compareCourses(const int&noOfCourses, const Course*const& courses1, const Course*const& courses2);
Student* deepCopy(const int& _noOfStudents, const Student* _students);
bool compareStudents(const int& noOfStudents, const Student* const& students1, const Student* const& students2);
Teacher* deepCopy(const int& _noOfTeachers, const Teacher* _teachers);
bool compareTeachers(const int & noOfTeachers, const Teacher * const & teachers1, const Teacher * const & teachers2);
