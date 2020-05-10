#include "Game.h"


Game::Game() {
	gameScoreGoal = 0;
}

void Game::setPointGoal(const int num) {
	gameScoreGoal = num;
}

int Game::getPointGoal() const {
	return gameScoreGoal;
}

void Game::addPlayer(Player* player) {
	players.push_back(player);
}

vector<Player*> Game::getPlayers() const {
	return players;
}

void Game::playGame() {
	int totalHandSum;

	while (check_goal() == false) {
		for (vector<Player*>::const_iterator it = players.begin(); it != players.end(); ++it) {
			cout << (*it)->getPlayerName() << endl;
			(*it)->chooseCoins();
			(*it)->makeAGuess(players.size());
		}

		totalHandSum = 0;

		for (vector<Player*>::const_iterator it = players.begin(); it != players.end(); ++it) {
			totalHandSum += (*it)->getHandScore();
		}

		cout << "Total hand sum is " << totalHandSum << "." << " Guessed:";

		int flag = 0;
		for (vector<Player*>::const_iterator it = players.begin(); it != players.end(); ++it) {
			if (totalHandSum == (*it)->getPlayerGuess()) {
				flag = 1;
				cout << " " << (*it)->getPlayerName();
				(*it)->addPlayerPoints(GUESSPOINTREWARD);
			}
		}
		if (!flag) { cout << " Nobody guessed this round."; }
		cout << endl << endl;;
	}
}

bool Game::check_goal() {
	for (vector<Player*>::const_iterator it = players.begin(); it != players.end(); ++it) {
		if ((*it)->getPlayerScore() == gameScoreGoal) {
			cout << endl << "-------- Congratulations. Player " << (*it)->getPlayerName() << " WON!!!!!! --------" << endl;
			return true;
		}
	}
	return false;
}

Game::~Game() {
}