7-1. A derangement is a permutation p of {1,...,n} such that no item is in its properposition, i.e. p_i != i for all 1<=i<=n. 
Write an efficient backtracking program with pruning that constructs all the derangements of n items.   
.   
***Solution***   
We will modify our original find_permutations algorithm found [here](https://github.com/Hussein-A/Data-Structures-and-Algorithms/blob/master/Combinatorial%20Search%20and%20Heuristic%20Search%20Methods/Backtracking/All%20Permutations.cpp).
Specifically what we will need to change is our construct_candidates() function. Now on top of being unable to reuse numbers already chosen
previously as we build up our permutation we cannot choose the ith number for the ith position of our permutation. For the sake
of completion I have provided the full program below which includes some minor changes to the original program above in addition to
construct_candidates().

```c++
#include<vector>
#include<iostream>


void process_solution(const std::vector<int>& solution) {
	for (int i = 1; i < solution.size(); ++i) std::cout << solution[i] << " ";
	std::cout << "\n";
}

bool is_solution(const std::vector<int>& solution, int count) {
  //note no need to check validity of derangement since our backtracking algorithm
  //builds it up correctly by construction. We are NOT building all possible permutations and then removing
  //those that are not derangements.
  if (count != solution.size() - 1) return false;
  else return true;
}


std::vector<int> construct_candidates(std::vector<int> solution, const int count) {
	std::vector<bool> is_in(solution.size(), false); is_in[0] = true;
	std::vector<int> candidates;

	//remove nums already used from consideration
	for (int i = 1; i < count; ++i) {
		int num = solution[i];
		is_in[num] = true;
	}


	//add all remaining as candidates (except the count_th position)
	for (int j = 1; j < is_in.size(); ++j) {
		if (!is_in[j] && j != count) { //The only important change is here
			candidates.push_back(j);
		}
	}
	return candidates;
}

void backtrack(std::vector<int>& solution, int count) {
	if (is_solution(solution, count)) process_solution(solution);
	++count;

	std::vector<int> candidates = construct_candidates(solution, count);
	for (int i = 0; i < candidates.size(); ++i) {
		solution[count] = candidates[i];
		backtrack(solution, count);
	}
}

void derangement(int n) {
	std::vector<int> set(n+1);
	backtrack(set, 0);
}

int main() {
	std::ios_base::sync_with_stdio(false);

	derangement(6);
}

```
