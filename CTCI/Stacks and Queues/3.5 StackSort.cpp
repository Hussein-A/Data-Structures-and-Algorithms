/*
Program to sort a stack using only the stack operations and at most one additional
stack. 3.5 in CTCI
*/

#include<stack>
#include<random> //for test case
#include<iostream>

void print_stack(std::stack<int> stack) {
	while (!stack.empty()) {
		std::cout << stack.top() << "\n";  stack.pop();
	}
	std::cout << "\n\n";
}

void stacksort(std::stack<int>& stack) {
	std::stack<int> tempstack;
	bool find_max = true;
	bool sorted = false;

	while (!sorted) {
		sorted = true;

		while(!stack.empty()){
			int x = stack.top(); stack.pop();
			if (stack.empty()) { //only 1 elem left check
				tempstack.push(x);
				continue;
			}
			int y = stack.top();
			if (y > x) sorted = false;
			
			if (find_max) {
				if (y < x) tempstack.push(x);
				else {
					tempstack.push(y);
					stack.pop();
					stack.push(x);
				}
			}
			else {
				if (y >= x) tempstack.push(x);
				else {
					tempstack.push(y);
					stack.pop();
					stack.push(x);
				}
			}

		}
		find_max = find_max ? false : true;
		stack.swap(tempstack);
	}
}

int main() {
	constexpr int max_size = 1000;
	std::random_device r;
	std::mt19937 rng(r());
	std::uniform_int_distribution<int> dist(-max_size, max_size);

	std::stack<int> mystack;
	for (int i = 0; i < max_size; ++i)
		mystack.push(dist(rng));
	

	std::cout << "The stack is: \n";
	std::stack<int> copy = mystack;


	copy = mystack;
	stacksort(copy);
	std::cout << "\nAfter sorting: \n";
	while (!copy.empty()) {
		std::cout << copy.top() << "\n"; copy.pop();
	}
}