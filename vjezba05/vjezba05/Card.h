#pragma once
#include <iostream>

#define VALUENUM 10 
#define SUITNUM 4

class Card
{
private:
	int value;
	char suit;
public:
	int cardValues[VALUENUM] = { 1, 2, 3, 4, 5, 6, 7, 11 ,12, 13 };
	char cardSuits[SUITNUM] = { 'B', 'D', 'K', 'S' };
	Card(int v = 0, char s = '0') : value(v), suit(s) {}
	void setValue(int v) { value = v; }
	int getValue() const { return value; }
	void setSuit(char s) { suit = s; }
	char getSuit() const { return suit; }
	~Card() {}
};

template<typename S, typename O>
S& operator<<(S& os, const O& card)
{
	return os << card.getValue() << card.getSuit();
}



