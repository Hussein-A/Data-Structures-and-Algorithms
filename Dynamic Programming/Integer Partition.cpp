/*
Problem to solve the integer partition problem. That is given a sequence of integers of size
n and a number k, divide the sequence into k partitions in such a way as to minimize the
sum of all the numbers contained in a partition. Note that the functions print_partition, and construct_partition were
based upon the implementation as found in Skiena's Algorithm Design Manual, 2ed. pg 297

Ex. {1,3,2,4} with just 2 partitions (or ranges) the best would be {1,3 | 2,4}
*/
#include<vector>
#include<iostream>
#include<algorithm> //std::min

void cheapest(int row, int clmn, std::vector<std::vector<int>>& table, std::vector<std::vector<int>>& path) {
	table[row][clmn] = INT_MAX;
	int sum = table[0][clmn];
	//int minimum = std::max(table[row][0], sum);
	for (int x = 0; x < clmn; ++x) {
		int cost = std::max(table[row-1][x], sum - table[0][x]);
		if (cost < table[row][clmn]) {
			table[row][clmn] = cost;
			path[row][clmn] = x;
		}
	}

}

void print_partition(int start, int end, std::vector<int> seq) {
	std::cout << "{ ";
	for (int i = start; i <= end; ++i) std::cout << seq[i] << " ";
	std::cout << "} ";
}

void construct_partition(int end, int k, const std::vector<int>& seq, const std::vector<std::vector<int>>& path) {
	if (k == 0) {
		print_partition(0, end, seq);
	}
	else {
		construct_partition(path[k][end], k - 1, seq, path);
		print_partition(path[k][end] + 1, end, seq);
	}
}

int opt_partition(const std::vector<int>& seq, int k) {
	int n = seq.size();
	std::vector<std::vector<int>> table(k, std::vector<int>(n));
	std::vector<std::vector<int>> path = table; //used to reconstruct the partition

	//init
	table[0][0] = seq[0];
	for (int j = 1; j < n; ++j) table[0][j] = table[0][j - 1] +seq[j]; //first row (k = 1), here represented as 0;
	for (int i = 0; i < k; ++i) table[i][0] = seq[0];

	for (int row = 1; row < k; ++row) {
		for (int clmn = 1; clmn < n; ++clmn) {
			cheapest(row, clmn, table, path);
		}
	}

	construct_partition(n - 1, k - 1, seq, path);
	std::cout << "\n";
	return table[k - 1][n - 1];
}


int main() {
	std::ios_base::sync_with_stdio(false);

	std::cout << "COST: " << opt_partition(std::vector<int>{1,2,3,4,5,6,7,8,9}, 3);
}