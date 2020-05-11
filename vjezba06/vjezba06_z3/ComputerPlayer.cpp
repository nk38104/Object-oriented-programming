#include "ComputerPlayer.h"


ComputerPlayer::ComputerPlayer(string name) {
	playerName = name;
}

string ComputerPlayer::getPlayerName() const {
	return playerName;
}

void ComputerPlayer::chooseSign() {

	int choice = rand() % 2;

	cout << "Choices: 1.Even 2.Uneven\n" << playerName << " chose sign number " << choice + 1 << "." << endl;

	playerSign = signs(choice);
}

void ComputerPlayer::setPlayerSign(const signs sign) {
	playerSign = sign;
}

signs ComputerPlayer::getPlayerSign() const {
	return playerSign;
}

void ComputerPlayer::chooseNumber() {
	int choice = rand() % 5;
	cout << playerName << " chose number " << choice << "." << endl;

	chosenNumber = choice;
}

int ComputerPlayer::getPlayerNumber() const {
	return chosenNumber;
}
void ComputerPlayer::addPlayerPoints(const int) {
	++playerPoints;
}

int ComputerPlayer::getPlayerPoints() const {
	return playerPoints;
}

