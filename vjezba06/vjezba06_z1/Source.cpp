#include <fstream>

#include "EBook.h"
#include "HardCopyBook.h"
#include "Library.h"

void loadLibrary(Library&);
void displayTitlesFrom(const Library, const string, const string);
void displaySizeOfEBooksFrom(const Library, const string, const string);
void searchTitlesWith(const Library);
void print(string);

int main()
{
	Library library;

	try {
		loadLibrary(library);
	}
	catch (...) {
		cout << endl << "Error: Could'nt open file. Make sure file is in current directory and that file name is correctly written." << endl;
		return 0;
	}
	displayTitlesFrom(library, "aldous", "Huxley");
	displaySizeOfEBooksFrom(library, "Allen", "Holub");
	searchTitlesWith(library);

	return 0;
}

void loadLibrary(Library& library) {
	ifstream booksFile;

	booksFile.open("books.txt");

	if (booksFile.is_open() == false) {
		booksFile.close();
		throw 13;
	}

	string fileLine, splittedPart, name;
	string firstName = "", lastName = "", title = "", fileName = "";
	float fileSizeInMB = 0;
	int year = 0, pageCount = 0;

	while (getline(booksFile, fileLine)) {
		string::size_type classMembSepPos = fileLine.find(';'), multipleSepPos, spacePos;

		// Part of splitted line with authors
		vector<Author> authors;
		splittedPart.assign(fileLine.begin(), fileLine.begin() + classMembSepPos);

		// Keep spliting in case there are multiple Authors ',' is separator bewtween
		if (splittedPart.find(',') != string::npos) {
			while ((multipleSepPos = splittedPart.find(',')) != string::npos) {
				name.assign(splittedPart.begin(), splittedPart.begin() + multipleSepPos);

				spacePos = splittedPart.find(' ');

				firstName.assign(name.begin(), name.begin() + splittedPart.find(' '));
				lastName = name.substr(spacePos + 1);

				Author author(firstName, lastName);
				authors.push_back(author);

				splittedPart.erase(splittedPart.begin(), splittedPart.begin() + multipleSepPos + 2);
			}
		}

		spacePos = splittedPart.find(' ');
		firstName.assign(splittedPart.begin(), splittedPart.begin() + spacePos);
		lastName = splittedPart.substr(spacePos + 1);

		Author author(firstName, lastName);
		authors.push_back(author);
		// Delete from line author part, cuz we handled them now parse rest
		fileLine.erase(fileLine.begin(), fileLine.begin() + classMembSepPos + 2);

		// Split title part
		classMembSepPos = fileLine.find(';');
		splittedPart.assign(fileLine.begin(), fileLine.begin() + classMembSepPos);
		title = splittedPart;
		// Delete title part
		fileLine.erase(fileLine.begin(), fileLine.begin() + classMembSepPos + 2);

		// Split year part
		classMembSepPos = fileLine.find(';');
		splittedPart.assign(fileLine.begin(), fileLine.begin() + classMembSepPos);
		year = stoi(splittedPart);
		// Delete year part
		fileLine.erase(fileLine.begin(), fileLine.begin() + classMembSepPos + 2);

		Book book(authors, title, year);

		// Here I differentiate EBook and HardCopy book

		// If splitted part has  . than it's EBook if not than it's HCbook (File pattern), file and size is in my pattern a requirement 
		// My logic is it's E-Book so it must have file and size
		if (fileLine.find('.') != string::npos) {
			classMembSepPos = fileLine.find(';');
			splittedPart.assign(fileLine.begin(), fileLine.begin() + classMembSepPos);
			fileName = splittedPart;
			// Delete 
			fileLine.erase(fileLine.begin(), fileLine.begin() + classMembSepPos + 2);

			// Remained part is size part so we need to get rid of MB
			/*splittedPart.assign(fileLine.begin(), fileLine.begin() + classMembSepPos);*/
			fileLine.erase(fileLine.end() - 3, fileLine.end());
			fileSizeInMB = stof(fileLine);

			EBook* eBook = new EBook(book, fileName, fileSizeInMB);
			library.addBook(eBook);
		}
		// Continue as HCBook
		else {
			pageCount = stoi(fileLine);
			// No need to delete cuz it's last info in row

			HardCopyBook* hcBook = new HardCopyBook(book, pageCount);
			//HardCopyBook hcBook(book.pageCount);
			library.addBook(hcBook);
		}
	}
}

void displayTitlesFrom(const Library library, const string firstName, const string lastName) {
	vector<string> titles(library.getTitlesFrom(firstName, lastName));

	cout << "Titles from author " << firstName << " " << lastName << ": " << endl;
	for_each(titles.begin(), titles.end(), print);
}

void displaySizeOfEBooksFrom(const Library lib, const string firstName, const string lastName) {
	cout << endl << "Size of ebooks from " + firstName + " " + lastName + " is " << lib.getSizeOfEBooksFrom(firstName, lastName) << "MB" << endl;
}

void searchTitlesWith(const Library library) {
	string searchWord;

	cout << endl << "Enter a word in title for search: ";  // use "Guide" to check my file or else make yours, but make sure you follow my file pattern
	cin >> searchWord;

	if (searchWord.empty()) {
		library.printAllBooks();
	}
	else {
		vector<string> books(library.getTitlesIncluding(searchWord));

		if (books.empty()) {
			cout << endl << "There are no book titles including " << searchWord << "." << endl;
		}
		else {
			cout << endl << "Books with " << searchWord << " in title: " << endl;
			for_each(books.begin(), books.end(), print);
		}
	}
}

void print(string it) {
	cout << it << endl;
}

