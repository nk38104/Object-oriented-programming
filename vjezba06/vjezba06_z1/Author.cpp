#include "Author.h"


void Author::setFullName(const string first, const string last) {
	firstName = first, lastName = last;
}

void Author::setFirstName(const string fName) {
	firstName = fName;
}

void Author::setLastName(const string last) {
	lastName = last;
}

string Author::getFullName() const {
	return (firstName + " " + lastName);
}

string Author::getFirstName() const {
	return firstName;
}

string Author::getLastName() const {
	return lastName;
}

bool operator==(const Author& left, const Author& right) {
	return (lowercase(left.getFirstName()) == lowercase(right.getFirstName())
		&& lowercase(left.getLastName()) == lowercase(right.getLastName()));
}
