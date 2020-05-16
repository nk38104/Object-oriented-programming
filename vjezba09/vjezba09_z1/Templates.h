#pragma once

#include <iostream>

using namespace std;


template <typename T> 
void sort(T* items, int count) {
	for (int i = 1; i < count; ++i) {
		for (int j = count - 1; j >= i; --j) {
			if (items[j - 1] > items[j]) {
				swap(items[j - 1], items[j]);
			}
		}	
	}
}

template <> 
void sort(char* items, int count) {
	for (int i = 1; i < count; ++i) {
		for (int j = count - 1; j >= i; --j) {
			if (tolower(items[j - 1]) > tolower(items[j])) {
				swap(items[j - 1], items[j]);
			}
		}
	}
}

template<size_t I = 0, typename... Tp>
void sort(tuple<Tp...>& t, int count) {

	sort(get<I>(t), count);

	if constexpr (I + 1 != sizeof...(Tp))
		sort<I + 1>(t, count);
}

template<typename T> 
void print(T obj, int count, string str) {
	cout << str;
	for (int i = 0; i < count - 1; ++i) {
		cout << obj[i] << " ";
	}
	cout << obj[count - 1] << endl;
}

template<size_t I = 0, typename... Tp>
void print(tuple<Tp...> & t, int count, string str) {
	cout << str;
	for (int i = 0; i < count - 1; ++i) {
		cout << get<I>(t)[i] << " ";
	}
	cout << get<I>(t)[count - 1] << endl;

	if constexpr (I + 1 != sizeof...(Tp))
		print<I + 1>(t, count, str);
}

