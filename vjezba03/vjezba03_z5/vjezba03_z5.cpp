#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

void create_vector(vector<string>&);
void modify_sentence(string&);
string modify_word(string);
bool is_vowel(const char);
int count_consonants(const string);
bool check_punctuation(const char);

template<typename S, typename V>
void print(const S str, const V var) {
	cout << str << var << endl;
}

int main()
{
	srand(time(NULL));
	vector<string> strVect;

	create_vector(strVect);

	if (strVect.size() == 0) { return 0; } // In case user inputs quit first so there is no sentences

	int sentenceID = rand() % strVect.size();

	print("\nRandom sentence: ", strVect[sentenceID]);

	modify_sentence(strVect[sentenceID]);
	
	print("Random sentence: ", strVect[sentenceID]);

	return 0;
}

void create_vector(vector<string>& sVect)
{
	string sentence;

	while (true) {
		do {
			cout << "Enter sentence(type quit to exit): ";
			getline(cin, sentence);
		} while (sentence.size() < 1);

		if (sentence == "quit") {
			break;
		}

		sVect.push_back(sentence);
	}
}

void modify_sentence(string& sVect)
{
	string newSentence = "", word = "";

	for (char x: sVect){
		if (x == ' ') {
			newSentence += modify_word(word);
			word.clear();
		}
		else {
			word += x;
		}
	}

	sVect = newSentence += modify_word(word);
}

string modify_word(string word)
{
	string punct = "";
	const string vowelEnd = "hay", consEnd = "ay"; 

	while (check_punctuation(word.back()) == true) {
		punct += word.back();
		reverse(punct.begin(), punct.end());  // In case of "how are you?...", it prints ?... in correct order
		word.pop_back();
	}

	if (is_vowel(tolower(word.front()))) {
		return word += (punct.empty()) ? vowelEnd + " "  : vowelEnd +  punct + " ";  // In case there is punctuation in a word
	}
	
	int fronConsLen = count_consonants(word);
	string fPart = word.substr(0, fronConsLen);

	word.erase(0, fronConsLen);

	return word += (punct.empty()) ?  fPart + consEnd + " " : fPart += consEnd + punct + " ";
}

bool is_vowel(const char c)
{
	return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int count_consonants(const string word)
{
	int cnt = 1;  // We already know 1st char is consonant

	while (is_vowel(tolower(word[cnt])) == false) { cnt++; } // Increment untill vowel
	
	return cnt;
}

bool check_punctuation(const char c)
{
	return !isalnum(c);
}
