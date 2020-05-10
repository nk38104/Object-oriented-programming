#pragma once

#include "Book.h"


class Library
{
private:
	vector<Book*> books;
public:
	Library();

	void setBooks(const vector<Book*>);
	vector<Book*> getBooks() const;
	void printAllBooks() const;
	void addBook(Book*);

	vector<string> getTitlesFrom(string, string) const;
	float getSizeOfEBooksFrom(string, string) const;
	vector<string> getTitlesIncluding(string) const;

	~Library();
};
