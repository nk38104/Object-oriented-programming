#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

#include "Card.h"

using namespace std;

#define VALUENUM 10 
#define SUITNUM 4
#define DECKSIZE 40
#define HANDSIZE 10

class Deck
{
	protected:
		void size() { cout << deck.size(); }; // Used jsut to test if dealt cards are erased from deck
		int cardValues[VALUENUM] = { 1, 2, 3, 4, 5, 6, 7, 11 ,12, 13 };
		char cardSuits[SUITNUM] = { 'B', 'D', 'K', 'S' };

	public:
		vector<Card> deck;

		Deck();
		void shuffle();
		vector<Card> deal();
		void print() const;
		~Deck() {}
};