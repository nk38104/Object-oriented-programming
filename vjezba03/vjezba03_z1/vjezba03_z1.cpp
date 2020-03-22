#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> create_vector();
void sum_elements(vector<int>, vector<int>&);
void print_min_max(vector<int>);

template<typename S, typename T>
void print(S str, T cont){
	cout << endl << str;
	for (auto x : cont) {
		cout << x << " ";
	}
	cout << endl;
}

int main()
{
	vector<int> vect = create_vector(), sumVect;

	print("Vector: ", vect);
	
	sum_elements(vect, sumVect);
	print("Vector: ", sumVect);

	print_min_max(sumVect);

	return 0;
}

vector<int> create_vector()
{
	int size, element;

	do {
		cout << "Enter how many elements(>1): ";
		cin >> size;
	} while (size < 2);

	vector<int> v;

	cout << endl;
	for (int i = 0; i < size; i++) {
		cout << "Enter element: ";
		cin >> element;
		v.push_back(element);
	}

	return v;
}

void sum_elements(vector<int> vect, vector<int>& sumVect)
{
	vector<int>::iterator it = vect.begin(), it2 = vect.end() - 1;

	while (it < it2 && it != it2) {
		sumVect.push_back((*it)+(*it2));
		it++;
		it2--;
	}
}

void print_min_max(vector<int> vect)
{
	sort(vect.begin(), vect.end());

	cout << endl << "Min. element: " << vect.front() << endl;
	cout << "Max. element: " << vect.back() << endl;
}