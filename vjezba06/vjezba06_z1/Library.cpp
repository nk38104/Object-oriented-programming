#include "Library.h"


Library::Library() {
}

void Library::setBooks(const vector<Book*> b) {
	books = b;
}

vector<Book*> Library::getBooks() const {
	return books;
}

void Library::printAllBooks() const {
	for (vector<Book*>::const_iterator it = books.begin(); it != books.end(); ++it) {
		cout << (*it)->getTitle() << endl;
	}
}

void Library::addBook(Book* book) {
	books.push_back(book);
}

vector<string> Library::getTitlesFrom(string fName, string lName = "") const {
	Author author(fName, lName);

	vector<string> bookTitles;
	vector<Author> bookAuthors;

	for (vector<Book*>::const_iterator it = books.begin(); it != books.end(); ++it) {
		bookAuthors = (*it)->getAuthors();

		for (vector<Author>::const_iterator aIt = bookAuthors.begin(); aIt != bookAuthors.end(); ++aIt) {
			if ((*aIt) == author) {
				bookTitles.push_back((*it)->getTitle());
				break;
			}
		}
	}

	return bookTitles;
}

float Library::getSizeOfEBooksFrom(string fName, string lName = "") const {
	float sumOfSizesInMB = 0;
	Author author(fName, lName);
	vector<Author> bookAuthors;

	for (vector<Book*>::const_iterator it = books.begin(); it != books.end(); ++it) {
		bookAuthors = (*it)->getAuthors();

		for (vector<Author>::const_iterator aIt = bookAuthors.begin(); aIt != bookAuthors.end(); ++aIt) {
			if ((*aIt) == author) {
				sumOfSizesInMB += (*it)->getSizeInMB();
			}
		}
	}

	return sumOfSizesInMB;
}

vector<string> Library::getTitlesIncluding(string partOfTitle) const {
	vector<string> bookTitles;
	string title, lowerTitle;

	for (vector<Book*>::const_iterator it = books.begin(); it != books.end(); ++it) {
		title = ((*it)->getTitle());

		if ((lowercase(title)).find(lowercase(partOfTitle)) != string::npos) {
			bookTitles.push_back(title);
		}
	}

	return bookTitles;
}

Library::~Library() {
}

