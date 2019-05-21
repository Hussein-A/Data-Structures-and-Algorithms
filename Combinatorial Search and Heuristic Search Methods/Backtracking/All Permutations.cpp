/*
This program's goal is to generate all possible permutations of an n element set of integers. This code
is based on the implementation found in Skiena's Algorithm Design Manual, 2ed. pg. 234.
*/

#include<vector>
#include<iostream>
#include<list>
using namespace std;

bool is_solution(vector<int> v, int count) {
	return v.size() - 1 == count;
}

void process_solution(vector<int> v, int input = 0) {//default arg. when not needed
	cout << '{';
	for (int i = 1; i < v.size(); ++i) cout << v[i];
	cout << "}\n";
}

vector<int> construct_candidates(vector<int> curr, int count, const vector<bool>& is_in) {
	vector<int> candidates;
	for (int i = 1; i < curr.size(); ++i)
		if (!is_in[i]) candidates.push_back(i);
	return candidates;
}

void backtrack(vector<int> curr, int count, vector<bool>& is_in) {
	if (is_solution(curr, count)) process_solution(curr);
	else {
		++count;
		vector<int> candidates = construct_candidates(curr, count, is_in);
		//cout << k << "\n";
		for (int i = 0; i < candidates.size(); ++i) {
			//make move here
			curr[count] = candidates[i];
			is_in[candidates[i]] = true;
			backtrack(curr, count, is_in);
			//unmake move here
			is_in[candidates[i]] = false;
		}
	}
}

void generate_subsets(int n) {
	vector<int> soln(n + 1);
	vector<bool> is_in(n + 1, false);
	backtrack(soln, 0, is_in);
}

int main() {
	while (true) {
		cout << "Enter size of subset." << endl;
		int n; cin >> n;
		generate_subsets(n);
		cout << endl;
	}

}