#include <algorithm>
#include <fstream>
#include <vector>
#include <iterator>

#include "Errors.h"


void readFile(vector<int>&);
bool checkGreater(int);
void countGreaterThan(vector<int>);
void minMaxElement(vector<int>);
bool isLower(int);
void deleteLowerThan300(vector<int>&);
void sortDescending(vector<int>&);

int main() {
	vector<int> numbers;

	try {
		// 1. Throw exception if file dont exist, 2. Fill vector with ints from file
		readFile(numbers);
		// 3. Count all numbers higher than 500
		countGreaterThan(numbers);
		// 4. Min and max vector element
		minMaxElement(numbers);
		// 5. Delete all numbers lower than 300
		cout << endl << "Before deleting: " << numbers.size();
		deleteLowerThan300(numbers);
		cout << "    After: " << numbers.size() << endl;
		// 6. Remaining numbers sort in descending order
		sortDescending(numbers);
		// Print vector
		cout << endl << "Numbers: ";
		ostream_iterator<int> os(cout, ",");
		copy(numbers.begin(), numbers.end(), os);
	}
	catch (FileNotFoundException error) {
		error.ShowError();
	}

	return 0;
}

void readFile(vector<int>& nums) {
	ifstream inFile("numbers.txt");

	// 1. Throw exception if file dont exist
	if (inFile.is_open() == false) {
		inFile.close();
		throw FileNotFoundException();
	}
	// 2. Fill vector with ints from file
	istream_iterator<int> inStream(inFile), eos;
	copy(inStream, eos, back_inserter(nums));
}

bool checkGreater(int num) {
	return (num > 500);
}

void countGreaterThan(vector<int> nums) {
	cout << "There are " << count_if(nums.begin(), nums.end(), checkGreater) << " numbers greater than 500." << endl;
}

void minMaxElement(vector<int> nums) {
	auto result = minmax_element(nums.begin(), nums.end());

	cout << endl << "Min: " << *result.first << "    Max: " << *result.second << endl;
}

bool isLower(int i) {
	return (i < 300);
}

void deleteLowerThan300(vector<int>& nums) {
	nums.erase(remove_if(nums.begin(), nums.end(), isLower), nums.end());
}

void sortDescending(vector<int>& nums) {
	sort(nums.begin(), nums.end(), greater<int>());
}