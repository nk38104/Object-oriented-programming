#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

#define ERROR "String is empty."

string reverse_string(string str);

template<typename S, typename T>
void print(const S str, const T val) {
	cout << str << val << endl;
}

int main()
{
	string str = "Is string this reversed.";
	/*string str = "Is string this, reversed.";*/
	/*string str = "S";*/

	print("Not Yoda: ", str);

	str = reverse_string(str);

	if (str.compare(ERROR) == 0) {
		print('\n', ERROR);
	}
	else {
		print("Yoda: ", str);
	}

	return 0;
}

string reverse_string(string str)
{
	if (str.empty()) {
		return ERROR;
	}

	string temp, word;

	reverse(str.begin(), str.end()-1);

	stringstream ss(str);

	while (ss >> word) {
		int pos = word.find('.');
		if (pos != string::npos) {
			word[pos-1] = tolower(word[pos-1]);
			word.pop_back();
		}
		reverse(word.begin(), word.end());
		temp.append(word + " ");
	}

	temp[0] = toupper(temp[0]);
	temp.back() = '.';

	return temp;
}