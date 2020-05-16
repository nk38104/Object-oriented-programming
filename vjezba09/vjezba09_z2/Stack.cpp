#include "Stack.h"

template<typename T> Stack<T>::Stack(unsigned int cap) {
	arr = new T[cap];
	capacity = cap;
	top = -1;
}

template<typename T> void Stack<T>::push(T item) {

	if (is_full()) {
		cout << "Can't add element. Stack is full. " << endl;
	}
	else {
		arr[++top] = item;
	}
}

template<typename T> void Stack<T>::pop() {
	if (is_empty()) { 
		cout << "Can't pop element. Stack is empty." << endl; 
	}
	else {
		--top;
	}
}

template <typename T> void Stack<T>::get_top() const {
	if (is_empty() == false) {
		cout << arr[top] << endl;
	}
}

template<typename T> bool Stack<T>::is_empty() const {
	return (top == -1);
}

template<typename T> bool Stack<T>::is_full() const {
	return (top == capacity - 1);
}

template<typename T> void Stack<T>::print() const {
	if (is_empty()) { 
		cout << "Stack is empty." << endl;
	}
	else {
		for (int i = 0; i <= top; ++i) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
}

template<typename T> Stack<T>::~Stack() {
	delete[] arr;
}