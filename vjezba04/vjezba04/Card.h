#pragma once

class Card
{
	public:
		int value;
		char suit;

		Card(int v = 0, char s = '0') : value(v), suit(s) {}
		~Card() {}
};