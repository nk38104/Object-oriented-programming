#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

void reverse_bit_stuffing(vector<int>&);

template<typename S, typename O>
void print(S str, O obj)
{
	cout << str;
	for (auto i : obj) {
		cout << i << " ";
	}
	cout << endl << endl;
}

int main()
{	
	vector<int> messageStuffed = { 0,0,1,1,1,0,1,1,1,1,1,0,1,1,0,0,0,1,1,1,1,1,0,1,1,0,1,1 };
	vector<int> message = { 0,0,1,1,1,0,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,0,1,1 };  // Just an example to compare if function works

	print("Message bit stuffed: ", messageStuffed);

	reverse_bit_stuffing(messageStuffed);

	if (equal(messageStuffed.begin(), messageStuffed.end(), message.begin())) {
		print("Bit stuffing reversed: ", messageStuffed);
	}
	else {
		cout << endl << "Reversing bit stuffing failed." << endl;
	}

	return 0;
}

void reverse_bit_stuffing(vector<int>& vect)
{
	int size = vect.size(), cntOne = 0;

	for (int i = 0; i < size; i++) {
		cntOne = (vect.at(i) == 1) ? cntOne + 1 : 0;

		if (cntOne == 5 && vect.at(i+2) == 1) {
			vect.erase(vect.begin() + (i+1));
			size--;
		}
	}
}