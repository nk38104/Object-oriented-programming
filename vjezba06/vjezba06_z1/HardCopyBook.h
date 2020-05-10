#pragma once

#include "Book.h"


class HardCopyBook : virtual public Book
{
private:
	int numberOfPages;
public:
	HardCopyBook(Book, int);

	void printNumOfPages() const;
	void setNumberOfPages(const int);
	int getNumberOfPages() const;
	float getSizeInMB() const override;

	~HardCopyBook() {};
};

