8-9. The knapsack problem is as follows: given a set of integers M = {s1,s2,...,sn}, and a given target number T, find a subset of S that 
adds up exactly to T. For example, within M = {1,2,5,9,10} there is a subset that adds up to T= 22 but not T = 23. Give a correct 
programming algorithm for knapsack that runs in O(nT) time.   
.   
***Solution***
If you have solved the previous coins problem then this should seem somewhat familiar. Indeed, we are solving a simpler instance 
of the minimum amount of coins to get change for an amount T in that we don't care what the minimum is, only that a value exists. Another difference is that we are only
allowed to use at most one of any denomination. With this realization we will apply a somewhat similar recursion. First we will ask does there
exist a subset whose index of the last element (wrt the original set) in it is at most j? 
If so does it include the element at index j? (This latter question
will be needed to reconstruct the subset). Notice we are unfortunately asking two questions, necessitating that at each box we hold two booleans,
one for the existence of the subset and one for whether it includes that jth element or not. With that being said we will use the following recursion:   
S[i][j].exists = S[i-s_j][j-1] || S[i][j-1]   
S[i][j].is_in = S[i-s_j][j-1] From this it is clear our run time achieves O(nT). The code that uses this idea is given below.   
```c++
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

struct bpair {//boolean pair
	bool exists{ false };
	bool is_in{ false };
};

void print_subset(const vector<vector<bpair>>& matrix, const vector<int>& set, int target) {
	vector<int> subset;

	//start from the target row and largest index, if .exists is false then there does not exist a subset
	int row = target;
	int index = matrix[target].size()-1;

	//determins if the subset exists or not
	if (matrix[row][index].exists == false) row = 0; //skip the while loop and print empty subset

	while (row > 0 && index >= 0) {

		while (!matrix[row][index].is_in) --index; //find element of largest index which IS in the subset 
		subset.push_back(set[index]);
		row -= set[index];
		--index; //move 1 left in matrix

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
```
