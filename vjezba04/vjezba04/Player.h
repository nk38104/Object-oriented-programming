#pragma once

#include "Deck.h"

class Player : protected Deck
{
	private:
		void printHand() const;
		void checkPoints();
		int countOfAKind() const;
		bool checkOneOfAKind(int) const;
		int countNapolitana() const;
		bool checkNapolitana(int, char, char) const;
	public:
		string name;
		int points;
		vector<Card> hand;

		Player(Deck&);
		void playerInfo() const;
		~Player() {}
};

