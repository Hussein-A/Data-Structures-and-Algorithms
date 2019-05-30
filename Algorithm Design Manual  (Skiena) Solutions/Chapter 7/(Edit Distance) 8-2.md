8-2. Suppose you are given three strings of characters: X,Y,and Z, where |X|=n, |Y|=m, and |Z|=n+m. Z is said to be a shuffle of X and Y 
iff Z can be performed by interleaving the characters from X and Y in a way that maintains the left-to-right ordering of the characters 
from each string.   
(a)  Show that cchocohilaptes is a shuffle of chocolate and chips, but chocochilatspe is not.   
(b)  Give an efficient dynamic-programming algorithm that determines whether Z is a shuffle of X and Y. 
Hint: the values of the dynamic programming matrix you construct should be Boolean, not numeric.   
.   
***Solution***   
a) Notice that s comes before p in chocochilatspe when it must be the other way around as given in chips.    
.   
b) Consider the last element of Z, where Z is say "cchocohilaptes" in the above. It must be the case that this letter comes either from the last letter
of X or the last letter of Y IF Z is a shuffle of X,Y. In our case it comes from chips as chocolate does not have an S at the end. Remove
this last letter from both Z and Y to get two new shortened strings. Now apply the same logic again with the last letter of Z (using the above
would now be: cchocohilapte, Y = chip). This approach works fine until we are unable to tell whether the last letter of Z came from X or Y 
(ex if chocolote was chocolates instead). Arbitrarily choosing which string it came from will not work (CAR, RAT, CARATR, always choose X in a tie).
But neither do we know which string the last letter came from so we will have to try both possibilities. This suggests a backtracking approach.
Where DP comes in is in the recursive formula that will allow us to cache computations. We have   
S[i][j] = (S[i-1][j] & X[i] == Z[i+j]) OR (S[i][j-1] & Y[j-1] == Z[i+j]) which evaluates to a bool. This is to be read as the first i letters
of X and the first j letters of Y form a shuffle in the first i+j of Z iff (the first i-1 of X and j of Y are a shuffle in Z AND the ith letter
of X is the i+jth letter of Z) OR (the first i of X and j-1 of Y are a shuffle in Z AND the j-1 letter of Y matches the i+jth letter of Z).   
.   
Code for this problem is given below.
```c++
#include<vector>
#include<iostream>



bool is_shuffle(std::string x, std::string y, std::string z){
	//use DP
	std::vector<std::vector<bool>> S(x.size() + 1, std::vector<bool>(y.size() + 1));
	for (int row = 0; row < S.size(); ++row) S[row][0] = true;
	for (int clmn = 0; clmn < S[0].size(); ++clmn) S[0][clmn] = true;

	for (int row = 1; row < S.size(); ++row) {
		for (int clmn = 1; clmn < S[0].size(); ++clmn) {
			S[row][clmn] = (S[row - 1][clmn] && x[row - 1] == z[row + clmn - 1]) || (S[row][clmn - 1] && y[clmn - 1] == z[row + clmn - 1]);
		}
	}
	return S[x.size()][y.size()];
}

int main() {
	if (is_shuffle("car", "rat", "cartar")) {
		std::cout << "TRUE\n";
	}
	else std::cout << "FALSE\n";
}
```
