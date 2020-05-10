#pragma once

#include "Book.h"


class EBook : virtual public Book
{
private:
	string file;
	float sizeInMB;
public:
	EBook(Book, string, float);

	void printFileName() const;
	void setFileName(const string);
	string getFileName() const;
	void printSizeInMB() const;
	void setSizeInMB(const float);
	float getSizeInMB() const override;

	~EBook() {};
};

