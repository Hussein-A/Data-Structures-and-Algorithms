Multisets are allowed to have repeated elements. A multiset of n items may thus have fewer than n! distinct permutations. 
For example, {1,1,2,2} has only six different permutations: {1,1,2,2},{1,2,1,2},{1,2,2,1},{2,1,1,2},{2,1,2,1},
and{2,2,1,1}. Design and implement an efficient algorithm for constructing all permutations of a multiset.   
.   
***Solution***   
Our main difficulty from trying to copy the standard find_all_permutations algorithm used before is that we now have possible duplicates.
Our construct_candidates() function checked all elements already in the solution vector and did not allow such elements to be used again.
One way to fix this is by simply keeping a count of how many times we have used a particular element vs. how many of the element there are
in the first place. All that remains is the specifics of the implementation. We will be using hashing to keep track of each element and its 
associated count. A full implementation is provided below.

```c++
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
		solution[count] = candidates[i];
		--num_counts[candidates[i]]; //make choice

		backtrack(solution, count, num_counts);
		++num_counts[candidates[i]]; //unmake choice
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
```
