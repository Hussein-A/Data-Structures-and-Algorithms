/*
Program to solve the target sum problem. That is given a set of positive integers {s_1,...,s_n} and a target T output the subset the sum of whose values
is T.

This is problem 8-9 in Skiena's Algorithm Design Manual, 2ed.

We use DP technique as by noting that S[i][j] = S[i-s_j][j-1] || S[i][j-1] (ie. does there exist a subset that either includes me or doesnt that adds up to T?)
with a slight modification to help us keep track of which of the two options, if any, are true.
*/

#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

struct bpair {//boolean pair
	bool exists{ false };
	bool is_in{ false };
};

void print_subset(const vector<vector<bpair>>& matrix, const vector<int>& set, int target) {
	std::vector<int> subset;

	int row = target;
	int index = matrix[target].size()-1;

	while (row > 0 && index >= 0) {
		if (matrix[row][index].exists == false) break;
		
		while (!matrix[row][index].is_in) --index; //find element of largest index which is in the subset
		subset.push_back(set[index]);
		row -= set[index];
		--index;
	}

	cout << '{';
	for (int x : subset) cout << x << " ";
	cout << "}\n";
}

void find_subset_target(vector<int> set, int target) {
	if (set.empty() && target != 0) { cout << "Not possible!\n"; return;}

	//target+1 x set.size() matrix which holds a pair of booleans at each box. First is does a subset exist with max index val j, second is does it include set[j]?
	vector<vector<bpair>> subset (target + 1, vector<bpair>(set.size())); 
	
	//init
	if (set[0] <= target) { subset[set[0]][0].exists = true; subset[set[0]][0].is_in = true; }
	for (int clmn = 0; clmn < set.size(); ++clmn) subset[0][clmn].exists = true; //empty subset always adds up to 0

	for (int T = 1; T <= target; ++T) {
		for (int index = 1; index < set.size(); ++index) {
			int val = set[index];
			int newTarget = T - val;
			subset[T][index].exists = (newTarget >= 0 && subset[T - val][index - 1].exists) || subset[T][index-1].exists; //does a subset exist that whose largest index value is index?
			subset[T][index].is_in = (newTarget >= 0 && subset[T - val][index - 1].exists); //if so does it include me (s[index])?
		}
	}
	print_subset(subset, set, target);
}


int main() {
	vector<int> set{ 5,2,10,1,9 };
	int target = 6;
	find_subset_target(set, target);
}