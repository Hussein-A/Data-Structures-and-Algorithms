/*
This is a program to, given 2 lists/arrays to generate every possible merging of the two arrays that
respects the relative order of the elements within each array.

A backtracking approach is taken.
*/

#include<vector>
#include<iostream>
#include<list>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left{ nullptr };
	TreeNode* right{ nullptr };

	TreeNode(int x) : val{ x } {};
};

bool is_solution(const vector<int>& vec1, const vector<int>& vec2, int start1, int start2) {
	return (vec1.size() == start1 && vec2.size() == start2);
}

void process_solution(list<int>& prefix, vector<list<int>>& solution) {
	solution.push_back(prefix);
}

vector<bool> construct_candidates(const vector<int>& vec1, const vector<int>& vec2, int start1, int start2) {
	vector<bool> candidates(2, false);
	if (start1 != vec1.size()) candidates[0] = true;
	if (start2 != vec2.size()) candidates[1] = true;

	return candidates;
}


void weave(const vector<int>& vec1, const vector<int>& vec2, int start1, int start2, list<int>& prefix, vector<list<int>>& solution){
	if (is_solution(vec1, vec2, start1, start2)) process_solution(prefix, solution);
	else {
		vector<bool> candidates = construct_candidates(vec1, vec2, start1, start2);

		for (int i = 0; i < candidates.size(); ++i) {
			if (i == 0 && candidates[i]) {
				prefix.push_back(vec1[start1++]);
				weave(vec1, vec2, start1--, start2, prefix, solution);
				prefix.erase(--prefix.end());
			}
			else if (i == 1 && candidates[i]) {
				prefix.push_back(vec2[start2++]);
				weave(vec1, vec2, start1, start2--, prefix, solution);
				prefix.erase(--prefix.end());
			}
		}

	}
}

vector<list<int>> BSTsequences(TreeNode* root) {
	vector<list<int>> sequences;
	if (root == nullptr) return sequences;
	else if (root->left == nullptr && root->right == nullptr) { //leaf
		sequences.push_back({ root->val });
		return sequences;
	}


	vector<list<int>> left_sequences = BSTsequences(root->left);
	vector<list<int>> right_sequences = BSTsequences(root->right);

	if (left_sequences.empty())
		left_sequences.swap(right_sequences);

	for (auto& lseq : left_sequences) {
		if (right_sequences.empty()) {

		}
		else {
			for (auto& rseq : right_sequences) {

			}
		}

	}


	
}

int main() {
	vector<int> first = { 1,2,3};
	vector<int> second = { 4,5,6 };
	list<int> prefix;
	vector<list<int>> solution;

	weave(first, second, 0, 0, prefix, solution);
	for (auto List : solution) {
		for (int x : List) {
			cout << x << " ";
		}
		cout << "\n";
	}
}
