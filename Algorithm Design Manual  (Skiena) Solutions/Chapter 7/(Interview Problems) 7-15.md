7-15. Implement an efficient algorithm for listing all k-element subsets of n items.   
.   
***Solution***   
Given our previous solutions one might think we need only modify our previous all_subsets solution that found all subsets of a given set,
found [here](https://github.com/Hussein-A/Data-Structures-and-Algorithms/blob/master/Combinatorial%20Search%20and%20Heuristic%20Search%20Methods/Backtracking/All%20Subsets.cpp).
Unfortunately due to the way candidates were constructed (using bool to check if the count_th element of the set is included or not) made the modification
too costly in terms of extra work. Instead what we will do is consider how to generate all subsets of size k given our find_all_permutations solution found
[here](https://github.com/Hussein-A/Data-Structures-and-Algorithms/blob/master/Combinatorial%20Search%20and%20Heuristic%20Search%20Methods/Backtracking/All%20Permutations.cpp).   
.   
Our primary difficulty now is that we cannot allow duplicate subsets to be included, ie. {1,2} and {2,1} are to be viewed as 1 subset
and must not both be given, only one. Notice however that for every such permutation of a subset there is a unique representation given
by its sorted subset. This is how we will avoid making duplicates. all of our representations of subsets will be the sorted subset with those
elements. Specifically we will start with the smallest element of our set and every element thereafter when being considered as a candidate
must be larger than the one that comes before it (or equal if you want to consider multisets, the program written below works for that as well).
Although this is the main idea, certain other changes were made to allow for dealing with multisets as well as to deal with sets whose elements
are objects of user defined types.   
.   
Do note that with this particular implementation there is the specific draw back that we need the elements of the set to be comparable. Ie. we can check
that set[i] < set [j]. This is contrasted with all of our previous solutions of find_all_permutations and find_all_subsets. 
```c++
#include<vector>
#include<iostream>
#include<unordered_map>
#include<algorithm>


bool is_solution(int count, const int size) {
	return count == size;
}

template <typename T>
void process_solution(std::vector<T>& solution) {
	//note assumes object of type T is printable
	std::cout << "{ ";
	for (int i = 1; i < solution.size(); ++i) std::cout << solution[i] << " ";
	std::cout << "}\n";
}

template <typename T>
std::vector<T> construct_candidates(std::vector<T>& solution, int count, std::unordered_map<T, int> elem_count) {
	//requires Less_comparable<T>()
	std::vector<T> candidates;
	for (auto it : elem_count) { if (it.first >= solution[count-1] && it.second > 0) candidates.push_back(it.first); }
	return candidates;
}

template <typename T>
void backtrack(std::vector<T>& solution, int count, const int size, std::unordered_map<T, int> elem_count) {
	if (is_solution(count, size)) { process_solution(solution); return; }

	++count;
	std::vector<T> candidates = construct_candidates(solution, count, elem_count);
	for (int i = 0; i < candidates.size(); ++i) {
		solution[count] = candidates[i];
		--elem_count[candidates[i]];
		backtrack(solution, count, size, elem_count);
		++elem_count[candidates[i]];
	}

}

template <typename T>
void size_k_subsets(std::vector<T> set, int k) {
	//requires Less_comparable<T>()
	if (k > set.size()) { std::cout << "subset size greater than set size!\n"; return; }
	std::sort(set.begin(), set.end());
	std::vector<T> solution(k + 1);
	std::unordered_map<T, int> elem_count;
	for (T t : set) ++elem_count[t];

	backtrack(solution, 0, k, elem_count);
}

int main() {
	std::ios_base::sync_with_stdio(false);
	size_k_subsets(std::vector<int> {1, 2, 3, 4}, 2);
	std::cout << "\n\n";
	size_k_subsets(std::vector<char> {'h', 'e', 'l', 'l', 'o'}, 2);
}
```

prints:   
```
{ 1 2 }
{ 1 3 }
{ 1 4 }
{ 2 3 }
{ 2 4 }
{ 3 4 }


{ e h }
{ e l }
{ e o }
{ h l }
{ h o }
{ l l }
{ l o }
```
