#pragma once
#include <ctime>
#include <random>

#include "Player.h"


class ComputerPlayer : virtual public Player
{
public:
	ComputerPlayer(string);

	string getPlayerName() const override;
	void chooseCoins() override;
	void makeAGuess(const int) override;
	int getHandScore() const override;
	int getPlayerGuess() const override;
	void addPlayerPoints(const int) override;
	int getPlayerScore() const override;
};

