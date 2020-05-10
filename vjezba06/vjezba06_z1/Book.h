#pragma once

#include <vector>
#include <iterator>

#include "Author.h"


using namespace std;

class Book : public Author
{
private:
	vector<Author> bookAuthors;
	string bookTitle;
	int publicationYear;
public:
	Book(vector<Author>, string, int);

	void addAuthor(const string, const string);
	void changeAuthor(const string, const string);
	void setTitle(const string);
	void setPublicationYear(const int);
	vector<Author> getAuthors() const;
	string getTitle() const;
	int getPublicationYear() const;
	void printAuthors() const;

	virtual float getSizeInMB() const { return 0; }

	virtual	~Book() {};
};

