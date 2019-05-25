7-14. Write a function to find all permutations of the letters in a particular string.   
.   
***Solution***   
At first blush this problem may seem as though it will require us to redo our backtracking algorithm for sets of integers. But we need only 
realize that chars have unique int representations. Hence all we will need to do to solve this problem is convert our string into a set
of integers each of whom represents a character in the string, apply our backtracking algo for permutations of n integers, then convert
the result back into chars and print. (Assuming of course we have solved the find all permutations of a multiset of n integers, see [here](https://github.com/Hussein-A/Data-Structures-and-Algorithms/blob/master/Combinatorial%20Search%20and%20Heuristic%20Search%20Methods/Backtracking/All%20Permutations.cpp) 
for such a solution). All though only little is changed from the above, the full implementation is provided below if it helps in anyway. It 
includes //CHANGED comment to indicate what part from the above program has been changed.
```c++
//NOTE ' ' will not be ignored and be included in permutations if the string contains it.

#include<vector>
#include<iostream>
#include<unordered_map>
#include<string>


void process_solution(const std::vector<int>& solution) {
	//convert back to chars and print
	for (int i = 1; i < solution.size(); ++i) std::cout << (char)solution[i];   //CHANGED
	std::cout << "\n";
}

bool is_solution(std::vector<int>& solution, int count) {
	if (count != solution.size() - 1) return false;
	else return true;
}

std::vector<int> construct_candidates(std::vector<int>& solution, int count, std::unordered_map<int, int>& num_counts) {
	std::vector<int> candidates;

	for (auto it : num_counts) { if (it.second > 0) candidates.push_back(it.first); }
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

void string_perm(std::string string) {   //CHANGED
	//use exact same procedure as normal multiset permutation of n integers but convert to and back to chars at the end
	//note we view ' ' as a distinct char and will be included in permutations
	std::vector<int> set(string.size());
	for (int i = 0; i < string.size(); ++i) set[i] = (int)string[i];   //CHANGED

	std::vector<int> solution(set.size() + 1);

	//keep track of how many copies of particular num we have
	std::unordered_map<int, int> num_counts;
	for (int x : set) ++num_counts[x];

	backtrack(solution, 0, num_counts);
}

int main() {
	string_perm("hello");
}
```
