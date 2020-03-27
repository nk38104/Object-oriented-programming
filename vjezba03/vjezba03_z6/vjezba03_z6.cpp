#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

void create_list(list<int>&);
int modify_list(list<int>&);

template<typename S, typename T>
void print(const S str, const T cont) {
	cout << str;
	for (auto i : cont) {
		cout << i << " ";
	}
	cout << endl;
}

int main()
{
	list<int> userList;

	create_list(userList);

	print("List: ", userList);

	int elementsBetween = modify_list(userList);

	print("List: ", userList);
	
	if (elementsBetween == -1) {
		cout << endl << "There is no 0 and 1 to calculate distance between them." << endl;
		return 0;
	}

	cout << endl << "There is " << elementsBetween << " elements between first 0 and last 1." << endl;

	return 0;
}

void create_list(list<int>& uList)
{
	int size, input;

	do {
		cout << "Enter how many elements you want to input(>1): ";
		cin >> size;
	} while (size < 2);

	cout << endl;
	for (int i = 0; i < size; i++) {
		do {
			cout << "Enter " << i+1 << ".element(>0): ";
			cin >> input;
		} while (input < 1);

		uList.push_back(input);
	}
	cout << endl;
}

int modify_list(list<int>& uList)
{
	for (list<int>::iterator it = uList.begin(); it != uList.end(); it++) {
		if ((*it % 2) == 0) {
			uList.insert(it, 0);
			continue;
		}
		if (*it != 1) {
			advance(it, 1);
			uList.insert(it, 1);
			it--;
			continue;
		}
	}
	list<int> reverseList(uList);
	reverseList.reverse();

	list<int>::iterator first0 = find(uList.begin(), uList.end(), 0);
	list<int>::iterator last1 = find(reverseList.begin(), reverseList.end(), 1);

	if (first0 == uList.end() || last1 == reverseList.end()) { return -1; } // In case there is no 0 or 1 return

	int firstZeroPos = distance(uList.begin(), first0) + 1, lastOnePos = uList.size() - distance(reverseList.begin(), last1);

	return  abs(firstZeroPos - lastOnePos) - 1;
}

