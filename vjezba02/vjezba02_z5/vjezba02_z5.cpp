#include <iostream>

using namespace std;

int* create_array(int&, int&);
void print_array(int*, const int);
int* enlarge_array(int *, int);


int main()
{
	int size = 10, enteredCnt = 0;

	int* arr = create_array(size, enteredCnt);

	cout << endl;
	print_array(arr, enteredCnt);
	cout << endl;

	delete[] arr;
	arr = NULL;

	return 0;
}

void print_array(int* array, const int size)
{
	cout << "Array: ";
	for (int i = 0; i < size; i++) {
		cout << array[i] << " ";
	}
}

int* create_array(int& size, int& enterCnt)
{
	int* array = new int[size];
	int input;

	while(1){
		do {
			cout << "Enter positive number: ";
			cin >> input;
		} while (input < 0);

		if (input == 0) {
			break;
		}
		
		if (enterCnt == size-1) {
			size *= 2;
			int *new_array = enlarge_array(array, size);
			delete[] array;
			array = new_array;
		}
		array[enterCnt] = input;
		enterCnt++;
	}

	return array;
}

int* enlarge_array(int* array, int size)
{
	int* new_array = new int[size];
	int old_size = size / 2;

	for (int i = 0; i < old_size; i++) {
		new_array[i] = array[i];
	}

	return new_array;
}


