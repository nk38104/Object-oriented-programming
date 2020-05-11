#include "Money.h"


int main() {
	// Menu
	Money soup(11, 30), becki(15, 50), salad(10), beer(15), babic(16, 40);
	// Guest order
	Money receit = soup + becki + salad + beer;
	// Beer cancellation
	receit -= beer;
	// Add another item
	receit += babic;

	cout << "Receit total: " << receit << endl;

	double total = receit;

	cout << "Receit conversion to double: " << total << endl;

	return 0;
}