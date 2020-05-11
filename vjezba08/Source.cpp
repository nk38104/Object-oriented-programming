#include "Money.h"


int main() {
	// Menu
	Money soup(11, 30), becki(15, 50), salad(10), beer(15), babic(16, 40);
	// Guest order
	Money receipt = soup + becki + salad + beer;
	// Beer cancellation
	receipt -= beer;
	// Add another item
	receipt += babic;

	cout << "Receit total: " << receipt << endl;

	double total = receipt;
	cout << "Receit conversion to double: " << total << endl;


	return 0;
}