class Date
{
public:
	//  Constructors
	Date(const int& d = 0, const int& m = 0, const int& y = 0);
	Date(const Date& date) : day{ date.day }, month{ date.month }, year{ date.year }{}
	// Setters And Getters
	void setDay(const int&);
	void setMonth(const int&);
	void setYear(const int&);
	int getDay()const { return this->day; }
	int getMonth()const { return this->month; }
	int getYear()const { return this->year; }
	// Properties
	Date& operator =(const Date&);
	bool operator ==(const Date&)const;
	void Read(istream&);
	void Write(ostream&)const;
	//  Destructors
	~Date() {};
private:
	int day;
	int month;
	int year;
};
istream& operator>>(istream& input, Date& date);
ostream& operator<<(ostream& output, const Date& date);