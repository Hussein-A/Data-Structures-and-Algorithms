/*
This program's goal is to generate all possible subsets of an n element set of integers. This code
is based strongly on the implementation found in Skiena's Algorithm Design Manual, 2ed. pg. 234.
Changes were done to translate it into C++.
*/

#include<vector>
#include<iostream>
using namespace std;

bool is_solution(vector<bool> v, int k) {
	return v.size()-1 == k;
}

void process_solution(vector<bool> v, int input) {
	cout << '{';
	for (int i = 0; i < v.size(); ++i) {
		if (v[i]) cout << i;
	}
	cout << "}\n";
}

vector<bool> construct_candidates(vector<bool> curr, int k, int n) {
	vector<bool> candidates = { true, false };
	return candidates;
}

void backtrack(vector<bool> curr, int k, int input) {
	if (is_solution(curr, k)) process_solution(curr, input);
	else {
		++k;
		vector<bool> candidates = construct_candidates(curr, k, input);
		//cout << k << "\n";
		for (int i = 0; i < candidates.size(); ++i) {
			curr[k] = candidates[i];
			//make move here
			backtrack(curr, k, input);
			//unmake move here
		}
	}
}

void generate_subsets(int n) {
	vector<bool> soln(n+1);
	backtrack(soln, 0, n+1);
}

int main() {
	while (true){
		cout << "Enter size of subset." << endl;
		int n; cin >> n;
		generate_subsets(n);
		cout << endl;
	}
	
}