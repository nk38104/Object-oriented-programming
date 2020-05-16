#include <tuple>
#include "Templates.h"

#define SIZE 6
#define SORT "Sorted arr:"
#define NOTSRT "Not sorted arr: "

void simple_test(int*, float*, double*, char*, char*);
void tuple_test(int*, float*, double*, char*, char*);

int main() {

	int iArr[SIZE] = { 3, 5, 0, 2, 8, 5 };
	float fArr[SIZE] = { 3.1, 5.1, 0.3, 2.3, 5.5, 4.4 };
	double dArr[SIZE] = { 2.4, 1.6, 0.8, 2.3, 1.3 , 0.84 };
	char cArr[SIZE] = { 'o', 'b', 'j', 'e', 'c', 't' };
	char cuArr[SIZE] = { 'o', 'b', 'J', 'e', 'C', 'T' };

	simple_test(iArr, fArr, dArr, cArr, cuArr);

	//tuple_test(iArr, fArr, dArr, cArr, cuArr); // Repeating same function bugged me so I had to use multi type array, easiest way was tuple

	return 0;
}

void simple_test(int* iArr, float* fArr, double* dArr, char* cArr, char* cuArr) {

	print(iArr, SIZE,  NOTSRT);
	print(fArr, SIZE,  NOTSRT);
	print(dArr, SIZE,  NOTSRT);
	print(cArr, SIZE,  NOTSRT);
	print(cuArr, SIZE, NOTSRT);
	cout << endl;

	sort(iArr, SIZE);
	sort(fArr, SIZE);
	sort(dArr, SIZE);
	sort(cArr, SIZE);
	sort(cuArr, SIZE);

	print(iArr, SIZE, SORT);
	print(fArr, SIZE, SORT);
	print(dArr, SIZE, SORT);
	print(cArr, SIZE, SORT);
	print(cuArr, SIZE, SORT);
}
void tuple_test(int* iArr, float* fArr, double* dArr, char* cArr, char* cuArr) {

	tuple<int*, float*, double*, char*, char*> tArr(iArr, fArr, dArr, cArr, cuArr);

	print(tArr, SIZE, SORT);
	cout << endl;

	sort(tArr, SIZE);

	print(tArr, SIZE, NOTSRT);
}