#include <iostream>

using namespace std;

int* create_array(int&);
void print_array(int*, const int);
int& increment_element(int*, int, int);


int main()
{
	int size, index;

	int* arr = create_array(size);

	cout << endl;
	do {
		cout << "Enter element index you want to increment(1-size): ";
		cin >> index;
	} while (index < 1 || index > size);
	cout << endl;

	print_array(arr, size);
	cout << endl;

	increment_element(arr, size, index)++;

	print_array(arr, size);

	cout << endl;
	delete[] arr;
	arr = NULL;

	return 0;
}

int* create_array(int& size)
{
	do {
		cout << "Enter number of array elements(greater than 0): ";
		cin >> size;
	} while (size <= 0);

	int* array = new int[size];

	cout << endl;
	for (int i = 0; i < size; i++) {
		cout << "Enter element: ";
		cin >> array[i];
	}

	return array;
}

void print_array(int* array, const int size)
{
	cout << "Array: ";
	for (int i = 0; i < size; i++) {
		cout << array[i] << " ";
	}
}

int& increment_element(int* arr, int len, int index)
{
	return arr[index-1];
}


