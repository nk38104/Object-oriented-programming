#pragma once
#include <algorithm>
#include <vector>
#include <iterator>
#include <windows.h>

#include "Player.h"

#define WINREWARD 1


class Game
{
private:
	vector<Player*> players;
	int gameScoreGoal;
	int handSum;
	void check_winner(const int);
	void display_current_state() const;
	bool check_goal();
public:
	Game();

	void setScoreGoal(const int);
	int getScoreGoal() const;
	void addPlayer(Player*);
	vector<Player*> getPlayers() const;
	void playGame();

	~Game();
};

