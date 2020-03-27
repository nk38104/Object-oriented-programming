#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#define ERROR -1

void fill_vector(vector<int>&, int&);
void bit_stuffing(vector<int>&);

template<typename S, typename O>
void print(S str, O obj)
{
	cout << str;
	for (auto i : obj) {
		cout << i << " ";
	}
	cout << endl;
}

int main()
{
	vector<int> vect;
	int error = 1;

	fill_vector(vect, error);

	if (error == ERROR) {
		cout << endl << "Error: Cannot enter string instead of number." << endl;
		return 0;
	}

	print("Without bit stuffing: ", vect);

	bit_stuffing(vect);
	print("With bit stuffing: ", vect);

	return 0;
}

void fill_vector(vector<int>& vect, int& error)
{
	int input;

	while (true) {
		cout << "Enter 0 or 1(exit with anything else): ";
		cin >> input;

		while (cin.fail()) {
			cin.clear();
			error = ERROR;
			return;
		}

		if (input != 0 && input != 1) {
			break;
		}

		vect.push_back(input);
	};
}

void bit_stuffing(vector<int>& vect)
{
	int size = vect.size(), cntOne = 0;

	for (int i = 0; i < size; i++) {
		cntOne = (vect.at(i) == 1) ? cntOne + 1 : 0;

		if (cntOne == 6) {
			vect.insert(vect.begin() + i, 0);
		}
	}
}