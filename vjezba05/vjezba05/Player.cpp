#include "Player.h"

Player::Player(Deck& deck)
{
	cout << "Enter player name: ";
	cin >> name;

	hand = deck.deal();
	checkPoints();
}

void Player::checkPoints()
{
	points += countOfAKind() + countNapolitana() * 3;
}

int Player::countOfAKind() const
{
	int ofAKind[3] = { 0, 0, 0 }; // Counters for 1,2,3 as array
	// Check if any element is 1,2 or 3, if it is increment his counters(-1 cuz of indexes)
	for (vector<Card>::const_iterator it = hand.begin(); it != hand.end(); it++) {
		if (checkOneOfAKind(it->getValue())) { ofAKind[(it->getValue()) - 1]++; }
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
			if (checkNapolitana(it->getValue(), it->getSuit(), Card::cardSuits[i])) { napolitana[i]++;  break; }
		}
	}
	return count(begin(napolitana), end(napolitana), 3);
}

bool Player::checkNapolitana(int value, char suit, char s) const
{
	return ((value == 1 || value == 2 || value == 3) && suit == s);
}

void Player::playerInfo() const
{
	ostream_iterator<Card> os(cout, " ");
	cout << endl << "NAME: " << name << endl << "HAND: ";
	copy(hand.begin(), hand.end(), os);
	cout << endl << "POINTS: " << points << endl;
}

