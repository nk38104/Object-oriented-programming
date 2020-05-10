#include "EBook.h"


EBook::EBook(Book book, string fileName, float size = 0) : Book(book) {
	file = fileName;
	sizeInMB = size;
}

void EBook::printFileName() const {
	cout << "File: " << file << endl;
}

void EBook::setFileName(const string fileName) {
	file = fileName;
}

string EBook::getFileName() const {
	return file;
}

void EBook::printSizeInMB() const {
	cout << "Size in MB: " << sizeInMB << endl;
}

void EBook::setSizeInMB(const float size) {
	sizeInMB = size;
}

float EBook::getSizeInMB() const {
	return sizeInMB;
}

