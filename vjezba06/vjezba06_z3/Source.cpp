#include <string>

#include "Game.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"

#define MIXMODE 1
#define PERSONSMODE 2

void create_players(Game&);
void all_human_mode(Game&, int);
void mix_mode(Game&, int);

int main() {
	srand(time(NULL));
	Game game;

	game.setScoreGoal(3);

	create_players(game);
	game.playGame();

	return 0;
}

void create_players(Game& game) {
	int mode = MIXMODE;
	string name = "";

	do {
		cout << "How you want to play: \n1.Person vs Computer\n2.Person vs Person\nEnter your choice: ";
		cin >> mode;
	} while (mode < PERSONSMODE && mode > MIXMODE);
	cout << endl;

	if (mode == PERSONSMODE) {
		all_human_mode(game, mode);
	}
	else {
		mix_mode(game, mode);
	}
}

void all_human_mode(Game& game, int mode = PERSONSMODE) {
	int personCnt = (mode == PERSONSMODE) ? 2 : 1;
	string name = "";

	for (int i = 0; i < personCnt; ++i) {
		do {
			cout << "Enter " << i + 1 << ".player name: ";
			cin >> name;
		} while (name.length() == 0);

		HumanPlayer* hPlayer = new HumanPlayer(name);
		game.addPlayer(hPlayer);
	}
	cout << endl;
}

void mix_mode(Game& game, int mode) {
	all_human_mode(game, MIXMODE);

	for (int i = 0; i < MIXMODE; ++i) {
		ComputerPlayer* cPlayer = new ComputerPlayer("Comp" + to_string(i + 1));

		game.addPlayer(cPlayer);
	}
}