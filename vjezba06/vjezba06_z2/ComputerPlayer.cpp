#include "ComputerPlayer.h"


ComputerPlayer::ComputerPlayer(string name) {
	Player::setName(name);
}

string ComputerPlayer::getPlayerName() const {
	return Player::getName();
}

void ComputerPlayer::chooseCoins() {
	srand(time(NULL));

	vector<int> coins = { 1, 2, 5 }, hand;
	int coinCnt, choice, choiceIndex, sum = 0;

	coinCnt = rand() % coins.size();

	for (int i = 0; i < coinCnt; ++i) {
		choiceIndex = (rand() % coins.size());
		choice = coins.at(choiceIndex);

		sum += choice;
		hand.push_back(choice);

		coins.erase(coins.begin() + choiceIndex);
	}
	cout << "Picked " << coinCnt << " coin/s. " << endl;

	Player::setHandSum(sum);
	Player::setHand(hand);
}

void ComputerPlayer::makeAGuess(const int playerCount) {
	int minTotalScore = 0, maxTotalScore = playerCount * 8, sumChoice;

	sumChoice = rand() % maxTotalScore + 1;
	cout << "Made a guess " << sumChoice << "." << endl << endl;

	Player::setGuess(sumChoice);
}

int ComputerPlayer::getHandScore() const {
	return Player::getHandSum();
}

int ComputerPlayer::getPlayerGuess() const {
	return Player::getGuess();
}

void ComputerPlayer::addPlayerPoints(const int pointQuant) {
	Player::addPoint(pointQuant);
}

int ComputerPlayer::getPlayerScore() const {
	return Player::getPoints();
}