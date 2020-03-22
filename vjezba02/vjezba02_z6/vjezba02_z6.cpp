#include <iostream>
#include <vector>

using namespace std;

//typedef struct _Vector {
//	int capacity, size;
//	int *elements;
//} Vector;
//
//void print_vector(Vector* vector);
//Vector* vector_new();
//void vector_delete(Vector*);
//int* enlarge_array(int*, int);
//void vector_push_back(Vector*, int);
//void vector_pop_back(Vector*);
//int& vector_front(Vector*);
//int& vector_back(Vector*);
//int vector_size(Vector*);
//
//int main()
//{
//	Vector *vector = vector_new();
//
//	cout << "(push_back)";
//	vector_push_back(vector, 10);
//	vector_push_back(vector, 20);
//	vector_push_back(vector, 30);
//	vector_push_back(vector, 40);
//	vector_push_back(vector, 50);
//
//	print_vector(vector);
//
//	vector_pop_back(vector);
//	cout << "(pop_back)";
//	 print_vector(vector);
//
//	cout << endl << "Vector size: " << vector_size(vector) << endl;
//
//	cout << endl << "Vector front: " << vector_front(vector) << endl;
//	cout << "Vector back: " << vector_back(vector) << endl << endl;
//
//	vector_front(vector) += vector_back(vector);
//	vector_back(vector) -= vector_front(vector);
//	
//	print_vector(vector);
//
//	vector_delete(vector);
//
//	return 0;
//}
//
//void print_vector(Vector* vector)
//{
//	cout << "Vector: ";
//	for(int i = 0; i < vector->size; i++){
//		cout << vector->elements[i] << " ";
//	}
//	cout << endl;
//}
//
//Vector* vector_new()
//{
//	Vector* new_vector = new Vector;
//	new_vector->capacity = 0;
//	new_vector->size = 0;
//	new_vector->elements = new int;
//
//	return new_vector;
//}
//
//void vector_delete(Vector* vector)
//{
//	delete[] vector->elements;
//	delete[] vector;
//	vector = NULL;
//}
//
//int* enlarge_array(int* array, int size)
//{
//	int* new_array = new int[size];
//	int old_size = size / 2;
//
//	for (int i = 0; i < old_size; i++) {
//		new_array[i] = array[i];
//	}
//
//	return new_array;
//}
//
//void vector_push_back(Vector *vector, int element)
//{
//	if (vector->capacity == 0) {
//		vector->capacity = 1;
//		int* temp = new int[1];
//		delete[] vector->elements;
//		vector->elements = temp;
//	}
//	if (vector->size == vector->capacity) {
//		vector->capacity *= 2;
//		int* temp = enlarge_array(vector->elements, vector->capacity);
//		delete[] vector->elements;
//		vector->elements = temp;
//	}
//
//	vector->elements[vector->size] = element;
//	(vector->size)++;
//}
//
//void vector_pop_back(Vector *vector)
//{
//	vector->elements[vector->size] = 0;
//	(vector->size)--;
//}
//
//int& vector_front(Vector *vector)
//{
//	return vector->elements[0];
//}
//
//int& vector_back(Vector *vector)
//{
//	return vector->elements[(vector->size)-1];
//}
//
//int vector_size(Vector *vector)
//{
//	return vector->size;
//}
void fun(vector<int>& a)

{

	for (int i = 0; i < a.size() - 1; i++)
		a[i] = a[i] / a[i + 1];
}

void print_vector(vector<int> a)

{
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << " ";
}

int main()

{

	vector<int> a = { 3, 2, 1, 2, 3 };
	fun(a);
	print_vector(a);
}