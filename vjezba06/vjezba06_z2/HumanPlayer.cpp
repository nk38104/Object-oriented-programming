#include "HumanPlayer.h"


HumanPlayer::HumanPlayer(string name) {
	Player::setName(name);
}

string HumanPlayer::getPlayerName() const {
	return Player::getName();
}

void HumanPlayer::chooseCoins() {
	vector<int> coins = { 1, 2, 5 }, hand;
	vector<int>::iterator pos;
	int coinCnt, choice, sum = 0;

	do {
		cout << "How many coins you want to pick? Enter number from 0 to 2(included): ";
		cin >> coinCnt;
	} while (coinCnt < 0 && coinCnt > 2);

	for (int i = 0; i < coinCnt; ++i) {
		do {
			cout << "Enter coin value you want to add to your hand (";
			for (auto it : coins) { cout << it << " "; }
			cout << "): ";
			cin >> choice;

			pos = find(coins.begin(), coins.end(), choice);
		} while (pos == coins.end());

		sum += choice;
		hand.push_back(choice);
		coins.erase(pos); // Delete picked coin
	}

	Player::setHandSum(sum);
	Player::setHand(hand);
}

void HumanPlayer::makeAGuess(const int playerCount) {
	int minTotalScore = 0, maxTotalScore = playerCount * 8, sumChoice;

	do {
		cout << "Make a guess what is total sum of coins in hands (from 0 to " << maxTotalScore << " (included): ";
		cin >> sumChoice;
	} while (sumChoice < minTotalScore && sumChoice >maxTotalScore);
	cout << endl;
	Player::setGuess(sumChoice);
}

int HumanPlayer::getHandScore() const {
	return Player::getHandSum();
}

int HumanPlayer::getPlayerGuess() const {
	return Player::getGuess();
}

void HumanPlayer::addPlayerPoints(const int pointQuant) {
	Player::addPoint(pointQuant);
}

int HumanPlayer::getPlayerScore() const {
	return Player::getPoints();
}
