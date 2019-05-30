8-3. The longest common substring (not subsequence) of two strings X and Y is the longest string that appears as a run of consecutive letters
in both strings. For example, the longest common substring of photograph and tomography is ograph.   
(a)  Let n = |X| and m = |Y|. Give a O(nm) dynamic programming algorithm for longest common substring based on the longest common 
subsequence/editdistance algorithm.   
(b)  Give a simpler O(nm) algorithm that does not rely on dynamic programming.   
.   
***Solution***   
a) We will modify the edit distance algorithm. Consider a specific such substring. It must have ended at some point, say position i and j in 
X and Y respectively.  It must be the case that X[i] == Y[j] as that is the end of the sequence. Moreover the length of that substring ending
there is 1 + the length of the longest substring that ended at X[i-1] and Y[j-1]. This is the basis for our recursion from which we will apply
dynamic programming. The full code is given below and it is a modification of the edit distance algorithm. Specifically we ignore all mention
of substition, insertion or deletion. Indeed, modifying either string could derail our substring calculation completely. We will keep the match
function and have it return a bool if there is a match or not. If there isn't then len[i][j] = 0 (the longest common substring cannot
end at the position where there is no common character). This is O(nm) as we go through every position of the matrix.   
```c++
#include<string>
#include<vector>
#include<iostream>
#include<algorithm> //std::reverse

bool match(char x, char y) {
	if (x == y) return true;
	else return false;
}

void print_substring(const std::string& x, std::pair<int,int> max_pos, std::vector<std::vector<int>>& matrix) {
	//follow along the diagonal of the max len position until you reach 0
	int row = max_pos.first;
	int clmn = max_pos.second;
	int curr = matrix[row][clmn];

	std::string substring;
	while (curr > 0 && row > 0 && clmn > 0) {
		substring += x[row-1];
		clmn--; row--;
		curr = matrix[row][clmn];
	}
	std::reverse(substring.begin(), substring.end());
	std::cout << substring << "\n";
}

int LCS(const std::string& x, const std::string& y) {
	std::vector<std::vector<int>> len(x.size()+1, std::vector<int>(y.size()+1, 0)); //|x|+1 by |y|+1 matrix, +1 to better represent positions (not 0 index)

	int max = 0;
	std::pair<int, int> max_pos;
	for (int i = 1; i < len.size(); ++i) {
		for (int j = 1; j < len[0].size(); ++j) {
			//what is the length of the longest common subtring that ends at X[i] and Y[j]? 
			if (match(x[i - 1], y[j - 1])) {// 1 + the longest that ended at the letter just before if X[i] == Y[j]
				len[i][j] = len[i - 1][j - 1] + 1;
			}
			else len[i][j] = 0; //otherwise it cannot end at X[i], Y[j] since they don't match

			if (len[i][j] > max) {
				max = len[i][j]; max_pos.first = i; max_pos.second = j;
			}
		}
	}
	/* //This is the matrix generated (ignoring first 0 row and clmn), remove comment delimiters to print
	std::cout << "   ";
	for (int i = 0; i < y.size(); ++i) std::cout << y[i] << " "; std::cout << "\n";
	for (int i = 1; i < len.size(); ++i) {
		if (i > 0) std::cout << x[i - 1] << ": ";
		for (int j = 1; j < len[0].size(); ++j) {
			std::cout << len[i][j] << " ";
		}
		std::cout << "\n";
	}
	*/
	print_substring(x, max_pos, len);
	return max;
}

int main() {
	std::cout << "Length: " << LCS("photograph", "tomography");
}
```
b) A simple approach is for each letter in X, say, we will iterate through the letters of Y. If there is a match we continue on in
each string until they no longer match. Reset to that first position where we initiated the match but continue on from that position in Y (the last place they matched) in the iteration above and search for further matches. The implementation
below perhaps makes this clearer (also O(nm)):   
```c++
#include<vector>
#include<string>
#include<iostream>

std::pair<int,int> run_len(const std::string& x, const std::string& y, int i, int j, std::string& temp) {
	//find len of substring that starts with i in x and j in y and where it ended in y
	int count = 0;
	while (i < x.size() && j < y.size()) {
		if (x[i] == y[j]) {++count; temp += x[i];}
		else {--j; break; } //return to last good position
		++i; ++j;
	}
	return std::make_pair(count, j);
}

int LCS(const std::string& x, const std::string& y) {
	std::string longest_string;

	std::string copy; //hold current common substring
	int max = 0;
	for (int i = 0; i < x.size(); ++i) {
		copy = "";
		for (int j = 0; j < y.size(); ++j) {
    
			if (x[i] == y[j]) {
				std::pair<int, int> len_pos = run_len(x, y, i, j, copy); //find how long the common substring runs
				j = len_pos.second; //where did the substring end in Y, continue from there

				if (len_pos.first > max) {
					max = len_pos.first;
					longest_string = copy;
				}
				copy = "";
			}
		}
	}
	std::cout << longest_string << "\n";
	return max;
}

int main() {
	std::cout << LCS("graph", "topograph");
}
```

