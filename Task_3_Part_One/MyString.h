class MyString
{
public:
	// Constructors
	MyString(const char*const& s = nullptr);
	MyString(const MyString& );   // Copy Constructor

	// Setters And Getters
	void setString(const char*const&);
	const char* getString()const { return this->str; }

	// Logical Operator
	bool operator==(const MyString&)const;
	bool operator !=(const MyString&)const;
	// Assignment Operator Overload
	MyString& operator=(const MyString&);
	// Read and Write 
	void write(ostream&)const;
	void read(istream&);
	void input(istream&, const char&);

	int compare(const char *const&)const;

	// Destructor
	~MyString(); 
private:
	char* str;
};
istream& operator>>(istream&, MyString& );
ostream& operator<<(ostream&, const MyString&);