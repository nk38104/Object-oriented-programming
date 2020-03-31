#include <iostream>
#include <ctime>

#include "Player.h"

#define ERROR -1

void get_player_count(unsigned int&);
void create_players(vector<Player>&, Deck&, int);
void result(vector<Player>);

int main() {
	srand(unsigned(time(NULL)));

	Deck deck;
	deck.shuffle(); // Comment out this part to check adding starting points for OneOfAKind and Napolitana

	unsigned int playerCount;
	get_player_count(playerCount);

	if (playerCount == ERROR) { return 0; }

	vector<Player> players;
	create_players(players, deck, playerCount);

	result(players);

	return 0;
}

void get_player_count(unsigned int& pCount)
{
	do {
		cout << "Enter number of players(2 or 4): ";
		cin >> pCount;
		if (cin.fail()) {
			cin.clear();
			pCount = ERROR;
			cout << endl << "ERROR: Input was not a number. Please, enter a positive number as player count." << endl;
			return;
		}
	} while (pCount != 2 && pCount != 4);
	cout << endl;
}

void create_players(vector<Player>& pVect, Deck& deck, int pCount)
{
	for (int i = 0; i < pCount; i++) {
		Player player(deck);
		pVect.push_back(player);
	}
}

void result(const vector<Player> players)
{
	for (vector<Player>::const_iterator it = players.begin(); it != players.end(); it++) {
		it->playerInfo();
	}
}