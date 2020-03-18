#include <iostream>
#include <algorithm>

using namespace std;

int* create_array(int&);
void print_array(int*, const int);
void min_max_element(int*, int, int&, int&);


int main()
{
	int size, min, max;

	int* arr = create_array(size);

	min_max_element(arr, size, min, max);
	
	print_array(arr, size);

	cout << endl << endl << "Min. element:" << min << endl << "Max. element: " << max << endl;

	delete[] arr;
	arr = NULL;

	return 0;
}

int* create_array(int& size)
{
	do{
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
	cout << endl << "Array: ";
	for (int i = 0; i < size; i++) {
		cout << array[i] << " ";
	}
}

void min_max_element(int* arr, int size, int& min, int& max)
{
	sort(arr, arr + size);

	min = arr[0], max = arr[size - 1];
}