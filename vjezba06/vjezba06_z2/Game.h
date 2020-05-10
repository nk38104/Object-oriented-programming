#pragma once

#include "Player.h"

#define GUESSPOINTREWARD 1


class Game
{
private:
	vector<Player*> players;
	int gameScoreGoal;
	bool check_goal();
public:
	Game();

	void setPointGoal(const int);
	int getPointGoal() const;
	void addPlayer(Player*);
	vector<Player*> getPlayers() const;
	void playGame();

	~Game();
};

