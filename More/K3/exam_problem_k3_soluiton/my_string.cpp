#include "my_string.h"

#include <cassert>

void my_string::free() {
	delete[] data;
}

void my_string::copy_from(const my_string& other) {
	size_t other_data_length = strlen(other.data);
	data = new char[other_data_length + 1];
	strcpy_s(data, other_data_length + 1, other.data);
}

my_string::my_string() {
	data = new char[1];
	data[0] = '\0';
}

my_string::my_string(const char* string_data) {
	if (string_data == nullptr) {
		data = new char[1];
		data[0] = '\0';
	}
	else {
		size_t other_data_length = strlen(string_data);
		data = new char[other_data_length + 1];
		strcpy_s(data, other_data_length + 1, string_data);
	}
}

my_string::my_string(const my_string& other) {
	copy_from(other);
}

my_string& my_string::operator=(const my_string& other) {
	if (this != &other) {
		free();
		copy_from(other);
	}

	return *this;
}

my_string::~my_string() {
	free();
}

const char* my_string::c_str() const {
	return data;
}

size_t my_string::get_length() const {
	return strlen(data);
}

char& my_string::operator[](size_t index) {
	// index > size of string
	assert(index < get_length());	// -> if false: stop program

	return data[index];
}

char my_string::operator[](size_t index) const {
	assert(index < get_length());

	return data[index];
}

my_string& my_string::operator+=(const my_string& other) {
	// "Hello" += "Zero"
	// "HelloZero"
	
	size_t new_length = get_length() + other.get_length() + 1;

	char* new_data = new char[new_length];

	new_data[0] = '\0';

	strcat_s(new_data, new_length, data);
	strcat_s(new_data, new_length, other.data);

	free();
	data = new_data;

	return *this;
}

istream& operator>>(istream& in, my_string& str) {
	char buffer[1024];
	in.getline(buffer, 1024);

	size_t buffer_length = strlen(buffer);

	delete[] str.data;

	str.data = new char[buffer_length + 1];

	strcpy_s(str.data, buffer_length + 1, buffer);

	return in;
}

my_string operator+(const my_string& lhs, const my_string& rhs) {
	my_string result(lhs);

	result += rhs;
	
	return result;
}

ostream& operator<<(ostream& out, const my_string& str) {
	return out << str.c_str();
}

bool operator<(const my_string& lhs, const my_string& rhs) {
	return strcmp(lhs.c_str(), rhs.c_str()) < 0;
}

bool operator<=(const my_string& lhs, const my_string& rhs) {
	return strcmp(lhs.c_str(), rhs.c_str()) <= 0;
}
bool operator>=(const my_string& lhs, const my_string& rhs) {
	return strcmp(lhs.c_str(), rhs.c_str()) >= 0;
}
bool operator>(const my_string& lhs, const my_string& rhs) {
	return strcmp(lhs.c_str(), rhs.c_str()) > 0;
}
bool operator==(const my_string& lhs, const my_string& rhs) {
	return strcmp(lhs.c_str(), rhs.c_str()) == 0;
}
bool operator!=(const my_string& lhs, const my_string& rhs) {
	return strcmp(lhs.c_str(), rhs.c_str()) != 0;
}
