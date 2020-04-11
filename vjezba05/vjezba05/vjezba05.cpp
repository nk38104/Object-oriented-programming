#include <string>
#include <limits>
#include <ctime>

#define DECKSIZE 40

#include "Player.h"
#include "Errors.h"

void make_card_combinations(vector<Card>&);
void get_player_count(unsigned int&);
void create_players(vector<Player>&, Deck&, unsigned int);
void result(vector<Player>);


int main() {
	srand(unsigned(time(NULL)));

	vector<Card> cards;
	make_card_combinations(cards);

	Deck deck(cards);
	deck.shuffle(); // Comment out this part to check adding starting points for OneOfAKind and Napolitana

	unsigned int playerCount;
	get_player_count(playerCount);

	vector<Player> players;
	create_players(players, deck, playerCount);

	result(players);

	return 0;
}

void make_card_combinations(vector<Card>& cards) {
	Card card;

	for (int i = 0; i < VALUENUM; ++i) {
		for (int j = 0; j < SUITNUM; ++j) {
			card.setValue(card.cardValues[i]);
			card.setSuit(card.cardSuits[j]);
			cards.push_back(card);
		}
	}
}

void get_player_count(unsigned int& pCount)
{
	do {
		try {
			cout << "Enter number of players(2 or 4): ";
			cin >> pCount;
			if (cin.fail()) { 
				throw WrongInputType(); 
			}
		} 
		catch(WrongInputType err) {
			pCount = 0;
			err.HandleError();
			err.ShowError();
		}
	} while (pCount != 2 && pCount != 4);
	cout << endl;
}

void create_players(vector<Player>& pVect, Deck& deck,unsigned int pCount)
{
	for (unsigned int i = 0; i < pCount; i++) {
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