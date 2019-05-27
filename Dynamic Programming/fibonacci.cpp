/*
Program to calculate the nth Fibonacci using dynamic programming techniques. 
*/

#include<vector>
#include<iostream>

long long int fib(int n) {
	long long int first = 0;
	long long int second = 1;
	long long int next = 1;

	if (n == 0) return first;
	for (int i = 2; i <= n; ++i) {
		next = second + first;
		first = second;
		second = next;
	}

	return next;
}

int main() {
	std::ios_base::sync_with_stdio(false);

	while (true) {
		std::cout << "Please enter which nth fibonacci number you wish to find.\n";
		int ans; std::cin >> ans;
		std::cout << fib(ans) << "\n\n";
	}
}