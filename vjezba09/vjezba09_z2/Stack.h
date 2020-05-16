#pragma once
#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

#define MAXSIZE 50 // max stack size

template<typename T>
class Stack
{
public:
	 T* arr; 
	 unsigned int capacity;
	 int top;
public:
	Stack(unsigned int = MAXSIZE);

	void push(T);
	void pop();
	void get_top() const;
	bool is_empty() const;
	bool is_full() const;
	void print() const;

	~Stack();
};

