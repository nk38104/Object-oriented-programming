#include "Player.h"

Player::Player(Deck& deck)
{
	cout << "Enter player name: ";
	cin >> this->name;

	this->hand = deck.deal();
	checkPoints();
}

void Player::playerInfo() const
{
	cout << endl << "NAME: " << this->name << endl;
	printHand();
	cout << "POINTS: " << this->points << endl;
}

void Player::printHand() const
{
	cout << "HAND: ";
	for (vector<Card>::const_iterator it = hand.begin(); it != hand.end() - 1; it++) {
		cout << it->value << it->suit << ", ";
	}
	cout << hand.back().value << hand.back().suit << endl;
}

void Player::checkPoints()
{
	this->points += countOfAKind() + countNapolitana() * 3;
}

int Player::countOfAKind() const
{
	int ofAKind[3] = { 0, 0, 0 }; // Counters for 1,2,3 as array
	// Check if any element is 1,2 or 3, if it is increment his counters(-1 cuz of indexes)
	for (vector<Card>::const_iterator it = hand.begin(); it != hand.end(); it++) {
		if (checkOneOfAKind(it->value)) { ofAKind[(it->value) - 1]++; }
	}

	int points = 0;
	// Go through array of counters and check if any is 3 <= cnt <= 4, if it is than player has a combination so add 
	// right amount of points
	for_each(begin(ofAKind), end(ofAKind), [&](int& i) {  if (i >= 3) points += i; });

	return points;
}

bool Player::checkOneOfAKind(int value) const
{
	return (value == 1 || value == 2 || value == 3);
}

int Player::countNapolitana() const
{
	int napolitana[4] = { 0, 0, 0, 0 };

	for (vector<Card>::const_iterator it = hand.begin(); it != hand.end(); it++) {
		// Check every suit with value, we need 1B, 2B, 3B, 1D, 2D, 3D,... to have a combination
		// So is counts how many distinct values(1,2,3) are of a same suit(B,D,K,S) 
		for (int i = 0; i < 4; i++) {
			if (checkNapolitana(it->value, it->suit, Deck::cardSuits[i])) { napolitana[i]++;  break; }
		}
	}
	return count(begin(napolitana), end(napolitana), 3);
}

bool Player::checkNapolitana(int value, char suit, char s) const
{
	return ((value == 1 || value == 2 || value == 3) && suit == s);
}