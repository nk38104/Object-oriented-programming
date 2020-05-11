#pragma once
#include <ctime>
#include <random>

#include "Player.h"


class ComputerPlayer : virtual public Player
{
public:
	ComputerPlayer(string);

	string getPlayerName() const override;
	void chooseSign() override;
	void setPlayerSign(const signs) override;
	signs getPlayerSign() const override;
	void chooseNumber() override;
	int getPlayerNumber() const override;
	void addPlayerPoints(const int) override;
	int getPlayerPoints() const override;
};

