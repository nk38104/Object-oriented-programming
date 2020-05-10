#include "Book.h"


Book::Book(vector<Author> authors, string title, int year = 0) {
	bookAuthors = authors;
	bookTitle = title;
	publicationYear = year;
}

void Book::changeAuthor(const string firstName, const string lastName = "") {
	int size = bookAuthors.size();

	if (size == 1) {
		bookAuthors.at(0).setFullName(firstName, lastName);
	}
	else {
		int pos;
		Book::printAuthors();

		do {
			cout << endl << "Enter authors number you want to change: ";
			cin >> pos;
		} while (pos <= 0 || pos > size);

		bookAuthors.at(pos - 1).setFullName(firstName, lastName);
	}
}

void Book::setTitle(const string title) {
	bookTitle = title;
}

void Book::setPublicationYear(const int year) {
	publicationYear = year;
}

vector<Author> Book::getAuthors() const {
	return bookAuthors;
}

string Book::getTitle() const {
	return bookTitle;
}

int Book::getPublicationYear() const {
	return publicationYear;
}

void Book::printAuthors() const {
	cout << endl << "Authors: " << endl;

	for (int i = 0, size = bookAuthors.size(); i < size; ++i) {
		cout << i + 1 << "." + (bookAuthors.at(i)).getFullName() << endl;
	}
}

void Book::addAuthor(const string fName, const string lName) {
	Author author(fName, lName);
	bookAuthors.push_back(author);
}

