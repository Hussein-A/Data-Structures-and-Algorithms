/*
Program to compute the n choose m function using dynamic programming techniques
*/

#include<vector>
#include<iostream>

int choose(int n, int m) {
	if (m > n) { std::cout << "ERROR! 2nd int cannot be greater than first!\n"; return -1; }
	std::vector<int> prev_row{ 1, 1 };
	std::vector<int> curr_row{ 1, 1 };

	for (int i = 2; i <= n; ++i) {
		curr_row.push_back(1);
		for (int j = 1; j < i; ++j) {
			curr_row[j] = prev_row[j] + prev_row[j - 1];
		}
		prev_row = curr_row;
	}
	for (int x : curr_row) std::cout << x << " ";
	std::cout << "\n";
	return curr_row[m];
}

int main() {
	while (true) {
		std::cout << "Enter n choose m.\n";
		int n; std::cin >> n;
		int m; std::cin >> m;
		std::cout << choose(n, m) << "\n";
	}
}