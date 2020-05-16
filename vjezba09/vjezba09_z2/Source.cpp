#include "Stack.cpp"
#include <type_traits>

#define SIZE 2

void print_stacks(Stack<int>&, Stack<double>&, Stack<char>&);

int main() {

	Stack<int> iStk(SIZE);
	Stack<double> dStk(SIZE);
	Stack<char> cStk(SIZE);

	iStk.push(1);
	iStk.push(4);
	dStk.push(8.32);
	dStk.push(2.56);
	cStk.push('o');
	cStk.push('k');

	print_stacks(iStk, dStk, cStk);

	iStk.pop();
	cStk.pop();

	iStk.pop();
	iStk.pop();

	print_stacks(iStk, dStk, cStk);

	return 0;
}

void print_stacks(Stack<int>& is, Stack<double>& ds, Stack<char>& cs) {
	is.print();
	ds.print();
	cs.print();
}