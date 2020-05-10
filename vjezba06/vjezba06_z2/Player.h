#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

#define COINCNT 3

class Player
{
private:
	string playerName;
	int playerPoints;
	int handSum;
	vector<int> playerHand;
	int playerGuess;
public:
	Player(string = "");

	void setName(const string);
	string getName() const;
	void setGuess(const int);
	int getGuess() const;
	void setHand(vector<int>);
	int getPoints() const;
	void setHandSum(const int);
	int getHandSum() const;
	void addPoint(const int);

	virtual string getPlayerName() const = 0;
	virtual void chooseCoins() = 0;
	virtual void makeAGuess(const int) = 0;
	virtual int getHandScore() const = 0;
	virtual int getPlayerGuess() const = 0;
	virtual void addPlayerPoints(const int) = 0;
	virtual int getPlayerScore() const = 0;

	virtual ~Player() {};
};

