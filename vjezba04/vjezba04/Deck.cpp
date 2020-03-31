#include "Deck.h"

Deck::Deck()
{
	Card card;

	for (int i = 0; i < VALUENUM; i++) {
		for (int j = 0; j < SUITNUM; j++) {
			card.value = this->cardValues[i];
			card.suit = this->cardSuits[j];
			this->deck.push_back(card);
		}
	}
}

void Deck::shuffle()
{
	for (int i = 0; i < 2; i++)
		random_shuffle(deck.begin(), deck.end());
}

vector<Card> Deck::deal()
{
	vector<Card> hand(HANDSIZE);

	hand.assign(deck.begin(), deck.begin() + 10); // Deal first 10 cards to a player
	deck.erase(deck.begin(), deck.begin() + 10); // Erase those first 10 dealt cards from a deck

	return hand;
}

void Deck::print() const
{
	cout << "DECK: ";
	for (vector<Card>::const_iterator it = deck.begin(); it != deck.end() - 1; it++) {
		cout << it->value << it->suit << ", ";
	}
	cout << deck.back().value << deck.back().suit << endl;
}