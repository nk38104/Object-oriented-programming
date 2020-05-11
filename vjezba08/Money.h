#pragma once
//+=, -=, +, -, <<
#include <iostream>

using namespace std;


class Money
{
private:
	int kuna, lipa;
public:

	Money(int = 0, int = 0);

	void setKuna(const int);
	int getKuna() const;
	void setLipa(const int);
	int getLipa() const;

	Money operator+(const Money&);
	Money operator-(const Money&);
	Money& operator+=(const Money&);
	Money& operator-=(const Money&);
	friend ostream& operator<<(ostream&, const Money&);
	Money& operator++();
	Money operator++(int);
	Money& operator--();
	Money operator--(int);

	operator double() const;
};

