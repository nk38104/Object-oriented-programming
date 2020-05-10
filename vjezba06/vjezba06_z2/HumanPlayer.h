#pragma once

#include "Player.h"


class HumanPlayer : virtual public Player
{
public:
	HumanPlayer(string);

	string getPlayerName() const override;
	void chooseCoins() override;
	void makeAGuess(const int) override;
	int getHandScore() const override;
	int getPlayerGuess() const override;
	void addPlayerPoints(const int) override;
	int getPlayerScore() const override;
};

