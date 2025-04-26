#include <iostream>

using namespace std;

class my_string {
	char* data = nullptr;

	void free();
	void copy_from(const my_string& other);

public:
	my_string();
	my_string(const char* string_data);
	my_string(const my_string& other);
	my_string& operator=(const my_string& other);
	~my_string();

	const char* c_str() const;
	size_t get_length() const;

	char& operator[](size_t index);
	char operator[](size_t index) const;

	my_string& operator+=(const my_string& other);

	friend my_string operator+(const my_string& lhs, const my_string& rhs);
	friend istream& operator>>(istream& in, my_string& str);
};

ostream& operator<<(ostream& out, const my_string& str);
bool operator<(const my_string& lhs, const my_string& rhs);
bool operator<=(const my_string& lhs, const my_string& rhs);
bool operator>=(const my_string& lhs, const my_string& rhs);
bool operator>(const my_string& lhs, const my_string& rhs);
bool operator==(const my_string& lhs, const my_string& rhs);
bool operator!=(const my_string& lhs, const my_string& rhs);
