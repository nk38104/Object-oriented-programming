#pragma once
#include <iostream>

using namespace std;


enum signs { even, uneven };

class Player
{

public:
	Player(string = "");

	string playerName;
	signs playerSign;
	int chosenNumber;
	int playerPoints;

	virtual string getPlayerName() const = 0;
	virtual void chooseSign() = 0;
	virtual void setPlayerSign(const signs) = 0;
	virtual signs getPlayerSign() const = 0;
	virtual void chooseNumber() = 0;
	virtual int getPlayerNumber() const = 0;
	virtual void addPlayerPoints(const int) = 0;
	virtual int getPlayerPoints() const = 0;

	virtual ~Player() {};
};

