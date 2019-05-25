/*
This program's goal is to generate all possible permutations of an n (not necessarily unique) element set of integers. This code
is based on the implementation found in Skiena's Algorithm Design Manual, 2ed. pg. 234.
*/

#include<vector>
#include<iostream>
#include<unordered_map>

void process_solution(const std::vector<int>& solution) {
	for (int i = 1; i < solution.size(); ++i) std::cout << solution[i] << " ";
	std::cout << "\n";
}

bool is_solution(std::vector<int>& solution, int count) {
	if (count != solution.size()-1) return false;
	else return true;
}

std::vector<int> construct_candidates(std::vector<int>& solution, int count, std::unordered_map<int,int>& num_counts) {
	std::vector<int> candidates;

	for (auto it : num_counts) {if (it.second > 0) candidates.push_back(it.first);}
	return candidates;
}

void backtrack(std::vector<int>& solution, int count, std::unordered_map<int, int>& num_counts) {
	if (is_solution(solution, count)) process_solution(solution);
	++count;

	std::vector<int> candidates = construct_candidates(solution, count, num_counts);
	for (int i = 0; i < candidates.size(); ++i) {
		solution[count] = candidates[i]; //make choice
		--num_counts[candidates[i]]; 

		backtrack(solution, count, num_counts);
		++num_counts[candidates[i]]; //unmake choice and try next candidate
	}

}

void multiset_perm(std::vector<int> set) {
	std::vector<int> solution(set.size()+1);

	//keep track of how many copies of particular num we have
	std::unordered_map<int, int> num_counts;
	for (int x : set) ++num_counts[x];

	backtrack(solution, 0, num_counts);
}

int main() {

	multiset_perm(std::vector<int>{ 1,1,2,2 });

}
