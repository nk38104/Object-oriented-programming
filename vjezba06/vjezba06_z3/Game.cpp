#include "Game.h"


Game::Game() {
	gameScoreGoal = 0;
}

void Game::setScoreGoal(const int num) {
	gameScoreGoal = num;
}

int Game::getScoreGoal() const {
	return gameScoreGoal;
}

void Game::addPlayer(Player* player) {
	players.push_back(player);
}

vector<Player*> Game::getPlayers() const {
	return players;
}

void Game::playGame() {  // Showing choices is just for seing what's going on and that it's working :D
	int handSum, turn = 0, another = 1, round = 1;

	while (check_goal() == false) {
		Sleep(1000);
		cout << "-------- ROUND " << round << " --------" << endl << endl;
		players.front()->chooseSign();

		if ((players.front())->getPlayerSign() == even) {
			(players.back())->setPlayerSign(uneven);
		}
		else {
			(players.back())->setPlayerSign(even);
		}
		cout << endl;

		handSum = 0;

		for (vector<Player*>::const_iterator it = players.begin(); it != players.end(); ++it) {
			(*it)->chooseNumber();
			handSum += (*it)->getPlayerNumber();
		}

		check_winner(handSum);
		display_current_state();

		iter_swap(players.begin(), players.begin() + 1);
		++round;
	}
}

void Game::check_winner(const int handSum) {
	cout << endl << "Total sum is " << handSum << ". ";
	for (vector<Player*>::const_iterator it = players.begin(); it != players.end(); ++it) {
		if ((*it)->getPlayerSign() == (handSum % 2)) {
			cout << endl << (*it)->getPlayerName() << " won this round.";
			(*it)->addPlayerPoints(WINREWARD);
		}
	}
	cout << endl;
}

void Game::display_current_state() const {
	cout << "CURRENT POINT SITUATION  ";
	for (vector<Player*>::const_iterator it = players.begin(); it != players.end(); ++it) {
		cout << "| " << (*it)->getPlayerName() << " = " << (*it)->getPlayerPoints();
	}
	cout << endl << endl;
}


bool Game::check_goal() {
	for (vector<Player*>::const_iterator it = players.begin(); it != players.end(); ++it) {
		if ((*it)->getPlayerPoints() == gameScoreGoal) {
			cout << endl << "-------- Congratulations. Player " << (*it)->getPlayerName() << " WON!!!!!! --------" << endl;
			return true;
		}
	}
	return false;
}

Game::~Game() {
}