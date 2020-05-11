#include "HumanPlayer.h"


HumanPlayer::HumanPlayer(string name) {
	playerName = name;
}

string HumanPlayer::getPlayerName() const {
	return playerName;
}

void HumanPlayer::chooseSign() {
	int choice;

	do {
		cout << "Choices: 1.Even 2.Uneven" << endl << playerName << " enter number of sign you want to pick: ";
		cin >> choice;
	} while (choice < 1 || choice > 2);

	playerSign = signs(choice - 1);
}

void HumanPlayer::setPlayerSign(const signs sign) {
	playerSign = sign;
}

signs HumanPlayer::getPlayerSign() const {
	return playerSign;
}

void HumanPlayer::chooseNumber() {
	int choice;

	do {
		cout << playerName << " enter one number from 0 to 5(included): ";
		cin >> choice;
	} while (choice < 0 || choice > 5);

	chosenNumber = choice;
}

int HumanPlayer::getPlayerNumber() const {
	return chosenNumber;
}
void HumanPlayer::addPlayerPoints(const int) {
	++playerPoints;
}

int HumanPlayer::getPlayerPoints() const {
	return playerPoints;
}
