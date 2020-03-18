#include <iostream>

using namespace std;

void print_array(int*, const int);
int* fibonacci(int);

int main()
{
	int size;

	do {
		cout << "Enter number for fibonacci size(greater than 0): ";
		cin >> size;
	} while (size <= 0);

	int* arr = fibonacci(size);

	print_array(arr, size);

	return 0;
}

void print_array(int* array, const int size)
{
	cout << endl << "Array: ";
	for (int i = 0; i < size; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}

int* fibonacci(int size)
{
	int* arr = new int[size];

	for (int i = 0; i < size; i++) {
		if (i < 2) {
			arr[i] = 1;
		}
		else {
			arr[i] = arr[i - 1] + arr[i - 2];
		}
	}

	return arr;
}
