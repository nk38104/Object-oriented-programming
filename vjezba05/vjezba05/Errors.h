#pragma once
#include <iostream>

using namespace std;

class InputError {
public:
	virtual void ShowError() = 0;
	virtual void HandleError() = 0;
};

class WrongInputType : public InputError {
public:
	void ShowError() { cout << "Non-numeric input. Please, enter a number." << endl << endl; }
	void HandleError();
};
