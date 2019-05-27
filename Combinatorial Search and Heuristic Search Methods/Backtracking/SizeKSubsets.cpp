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
