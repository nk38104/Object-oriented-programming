#pragma once

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


class Author
{
private:
	string firstName, lastName;
public:
	Author() {};
	Author(string first, string last = "") : firstName(first), lastName(last) {}; // In case author has just one name you don't need to pass last name default will be empty string

	void setFullName(const string, const string);
	void setFirstName(const string);
	void setLastName(const string);
	string getFullName() const;
	string getFirstName() const;
	string getLastName() const;
	friend bool operator==(const Author&, const Author&);

	~Author() {};
};

template <typename T>
T lowercase(T str)
{
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	return str;
}