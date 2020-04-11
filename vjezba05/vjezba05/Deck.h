#pragma once
#include <algorithm>
#include <vector>
#include <iterator>

#include "Card.h"

using namespace std;

#define HANDSIZE 10

class Deck : public Card
{
private:
	vector<Card> deck;
	void size() { cout << deck.size(); }; // Used just to test if dealt cards are erased from deck
public:
	Deck() {}
	Deck(vector<Card> cards) { deck = cards; }
	void setDeck(vector<Card> cards) { deck = cards; }
	vector<Card> getDeck() { return deck; }
	void shuffle();
	vector<Card> deal();
	void print() const;
	~Deck() {}
};