#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string longest_substrings(const string, const string);

template<typename S, typename T>
void print(S str, T var) {
	cout << str << var << endl;
}

int main()
{
	string str = "SubOstaneSubstring", str2 = "Substring";
	/*string str = "abab", str2 = "cdcdcd";*/
	/*string str = "SubOstaneSubstring", str2 = "";*/

	print("String 1: ", str);
	print("String 2: ", str2);

	auto longest = longest_substrings;

	print("\nLongest substring: ", longest(str, str2));

	return 0;
}


string longest_substrings(const string str1, const string str2)
{
	if (str1.empty() || str2.empty()) return "There is no common substring.";

	string longest = "";

	// Ideja mi je da se ide kroz 1 string,rade substringovi postepeno i provjerava nalaze li se u drugom stringu
	// ako se nalaze provjerava se je li veci od proslog substringa ako ga ima ako ne longest ce bit prazan
	//npr. string -> s, st, str, stri, strin, string, t, tr, tri, ... 
	int str1Len = str1.length();
	for (int i = 0; i < str1Len; i++) {
		int firstPos = str2.find(str1[i], 0);

		while (firstPos != string::npos) {
			string temp = "";
			temp += str1[i];
			int str2Len = str2.length();

			for (int j = firstPos + 1; j < str2Len; j++) {
				temp += str2[j];
				int secPos = str1.find(temp, 0);

				if (secPos != string::npos) { 
					if (temp.length() > longest.length()) {
						longest = temp;
					}
					continue;
				}
				//break da ne radi nepotrebno dalje substring (ako nema abd nece biti ni abdc)
				break;
			}
			firstPos = str2.find(str1[i], firstPos + 1);
		}
	}
	return (longest.length() != 0) ? longest : "There is no common substring.";
}