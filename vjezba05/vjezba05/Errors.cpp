#include "Errors.h"

void WrongInputType::HandleError() {
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	system("cls");
}