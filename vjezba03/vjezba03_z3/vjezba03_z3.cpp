#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

#define ERROR "String is empty."

string erase_all_substrings(string, string);

template<typename S, typename T>
void print(S str,T val) {
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

string erase_all_substrings(string str, string subStr)
{
	if (str.empty()) {
		return ERROR;
	}
	if (subStr.empty()) {
		return str;
	}

	string temp = subStr;
	int pos = string::npos;

	while ((pos = str.find(subStr)) != string::npos) {
		str.erase(pos, subStr.length());
	}
	return temp;
}