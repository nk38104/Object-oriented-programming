#include "Player.h"


Player::Player(string name) {
	playerPoints = 0;
	playerGuess = 0;
	handSum = 0;
}

void Player::setName(const string name) {
	playerName = name;
}

string Player::getName() const {
	return playerName;
}

void Player::setGuess(const int num) {
	playerGuess = num;
}

int Player::getGuess() const {
	return playerGuess;
}

void Player::setHand(vector<int> choice) {
	playerHand = choice;
}

int Player::getPoints() const {
	return playerPoints;
}

void Player::setHandSum(const int sum) {
	handSum = sum;
}
int Player::getHandSum() const {
	return handSum;
}

void Player::addPoint(const int) {
	++playerPoints;
}