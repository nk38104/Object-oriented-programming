#pragma once

#include "Deck.h"

class Player : public Deck
{
private:
	string name;
	int points;
	vector<Card> hand;
	void checkPoints();
	int countOfAKind() const;
	bool checkOneOfAKind(int) const;
	int countNapolitana() const;
	bool checkNapolitana(int, char, char) const;
public:

	Player(Deck&);
	void playerInfo() const;
	void setName(string n) { name = n; }
	string getName() const { return name; }
	void setPoints(int p) { points = p; }
	int getPoints() const { return points; }
	void setHand(vector<Card> h) { hand = h; }
	~Player() {}
};



