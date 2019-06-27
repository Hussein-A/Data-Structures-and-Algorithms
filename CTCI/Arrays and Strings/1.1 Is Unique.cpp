/*
Solution to 1.1 of CTCI (Cracking the Coding Interview). 
Task:  Determine if a string has all unique characters, then try again without
using additional data structures.
*/


#include<vector>
#include<iostream>

inline int lchpos(int pos, int max_pos) {
	return 2 * pos + 1 > max_pos ? -1 : 2 * pos + 1;
}

inline int rchpos(int pos, int max_pos) {
	return 2 * pos + 2 > max_pos ? -1 : 2 * pos + 2;
}

void bubble_down(std::vector<int>& pq, int pos, int max_pos) {
	int max_index = pos;
	int lpos = lchpos(pos, max_pos);
	int rpos = rchpos(pos, max_pos);

	//find which of my children, if they exist, are not satisfied with the ordering
	if (lpos != -1 && pq[lpos] > pq[pos]) max_index = lpos;
	if (rpos != -1 && pq[rpos] > pq[pos] && pq[rpos] > pq[max_index]) max_index = rpos;

	if (max_index != pos) {
		std::swap(pq[pos], pq[max_index]);
		bubble_down(pq, max_index, max_pos);
	}

}

void heapsort(std::vector<int>& v) {
	int last_pos = v.size() - 1;
	//construct max heap
	for (int i = last_pos; i >= 0; --i)
		bubble_down(v, i, last_pos);



	//sort in place using heap
	for (last_pos; last_pos >= 0; --last_pos) {
		std::swap(v[last_pos], v[0]);
		bubble_down(v, 0, last_pos - 1);
	}
}


/*//VER 1 (HASHMAP)
#include<unordered_map>
bool is_unique(std::string& s) {
	std::unordered_map<char, int> char_count;
	for (const char& ch : s) {
		++char_count[ch];
		if (char_count[ch] > 1) return false;
	}
	return true;
}
*/

//VER@ (HEAPSORT NO ADDITIONAL DATA)
bool is_unique(std::string& s) {

}

int main() {
	std::string test = "abcde1233";
	if (is_unique(test)) std::cout << "TRUE, UNIQUE.\n";
	else std::cout << "FALSE, NOT UNIQUE.\n";
}