#include "HardCopyBook.h"


HardCopyBook::HardCopyBook(Book book, int num) : Book(book) {
	numberOfPages = num;
}

void HardCopyBook::printNumOfPages() const {
	cout << "Numer of pages: " << numberOfPages << endl;
}

void HardCopyBook::setNumberOfPages(const int num) {
	numberOfPages = num;
}
int HardCopyBook::getNumberOfPages() const {
	return numberOfPages;
}

float HardCopyBook::getSizeInMB() const {
	return 0;
}

