8-4. The longest common subsequence (LCS) of two sequences T and P is the longest sequence L such that L is a subsequence of both T and P. 
The shortest common super sequence (SCS) of T and P is the smallest sequence L such that both T and P are a subsequence of L.   
(a)  Give efficient algorithms to find the LCS and SCS of two given sequences.   
(b)  Let d(T,P) be the minimum edit distance between T and P when no sub-stitutions are allowed 
(i.e., the only changes are character insertion and deletion). Prove that d(T,P) = |SCS(T,P)| − |LCS(T,P)|
where |SCS(T,P)| (|LCS(T,P)|) is the size of the shortest SCS (longest LCS) of T and P.   
.   
***Solution***   
a) For LCS: This will be a modification of our find the longest common substring of two strings (we may think of any sequence as a string).
The restriction before was that our subsequence must be consecutive however in this situation they need not be. The first code fragment below
shows how we only needed 4 lines of change with only 1 having any real change to the algorithm.   
.   
For SCS:  Certainly we could concatenate the letters of T and P to get a supersequence
at a length of |T| + |P| however this may not be the most optimal (consider CAR, CAT into CARCAT vs. CART). 
Consider how we may use the LCS to construct the SCS. Start with S (the SCS)
= LCS. It is clear that we could not have overpaid here since certainly S must contain letters common to both, moreover this is ordering obeys
the left-right of both by definition of LCS. Now to attain the SCS simply add the letters of each string to S obeying their relative order to
the LCS already within S (ex. with CAR, CAT S= CA ->CAR->CART, R and T must go after A in the LCS to respect their original ordering). Can we go wrong
with this? Certainly we must have a common supersequence since we are adding the remaining letters of each string, moreover it is in the proper order
by construction. So the only way to go wrong is if we inserted a letter more than we needed to (as for C in CARCAT above). But this is impossible
since we first let S = LCS and if we added two letters in proper ordering when only one sufficed then that letter must've been included in the LCS
in the first place, a contradiction.   
.   
b) It is not too difficult to see this. We will show that the optimal edit distance algorithm (modified as given) will first delete all nonLCS 
characters from P (we mean that the ordering of the LCS remains in P after deletion) then add the remaining characters from the target as needed (in proper order of course). To see this suppose not, where could we have 
gone wrong? It could not be when we first deleted all non LCS elements. For if that was the case then we must have had to reinsert later on in the same order
relative to the LCS because it was in T, but if so then it was a letter common to both T and P and in the same relative order as T, P and the LCS but then it must've been
part of the LCS all along, a contradiction. Insertion after this step cannot cause any headaches because they must be included to get the target string
T (we only add letters still missing in T in correct order). But this is precisely |SCP|-|LCS| as required.


```c++
//LCS

int match(char x, char y) {
	if (x == y) return 1; //CHANGED
	else return 0; //CHANGED
}

void print_substring(const std::string& x, std::pair<int, int> max_pos, std::vector<std::vector<int>>& matrix) {
	//follow along the diagonal of the max len position until you reach 0
	int row = max_pos.first;
	int clmn = max_pos.second;
	int curr = matrix[row][clmn];

	std::string substring;
	while (curr > 0 && row > 0 && clmn > 0) {
		if (curr > matrix[row-1][clmn-1]) substring += x[row - 1]; //CHANGED
		clmn--; row--;
		curr = matrix[row][clmn];
	}
	std::reverse(substring.begin(), substring.end());
	std::cout << substring << "\n";
}

int LCS(const std::string& x, const std::string& y) {
	std::vector<std::vector<int>> len(x.size() + 1, std::vector<int>(y.size() + 1, 0)); //|x|+1 by |y|+1 matrix, +1 to better represent positions (not 0 index)

	int max = 0;
	std::pair<int, int> max_pos;
	for (int i = 1; i < len.size(); ++i) {
		for (int j = 1; j < len[0].size(); ++j) {
			len[i][j] = len[i - 1][j - 1] + match(x[i-1], y[j-1]); //CHANGED
			if (len[i][j] > max) {
				max = len[i][j]; max_pos.first = i; max_pos.second = j;
			}
		}
	}
	//REMOVED LONG COMMENT
	print_substring(x, max_pos, len);
	return max;
}

int main() {
	std::cout << "Length: " << LCS("94", "342395");
}
```
