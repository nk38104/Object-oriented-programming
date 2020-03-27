#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

#define ERROR "String is empty."

string erase_all_substrings(const string, const string);

template<typename S, typename T>
void print(const S str, const T val) {
	cout << str << val << endl;
}

int main()
{
	string str = "SubTheSubString", substring = "Sub";
	/*string str = "SubTheSubString", substring = "";*/
	/*string str = "", substring = "Sub";*/

	print("String: ", str);

	str = erase_all_substrings(str, substring);
	
	if (str.compare(ERROR) == 0) {
		print('\n', ERROR);
	}
	else {
		print("String: ", str);
	}

	return 0;
}

string  erase_all_substrings(const string str, const string subStr)
{
	if (str.empty()) {
		return ERROR;
	}

	if (subStr.empty()) {
		return str;
	}

	string newStr = str;
	int pos = string::npos;

	while ((pos = newStr.find(subStr)) != string::npos) {
		newStr.erase(pos, subStr.length());
	}

	return newStr;
}