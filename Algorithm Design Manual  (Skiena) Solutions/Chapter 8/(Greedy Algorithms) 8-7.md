8-7. In the United States, coins are minted with denominations of 1, 5, 10, 25, and 50 cents. Now consider a country whose coins are minted 
with denominations of {d1,...,dk} units. We want to count how many distinct ways C(n) there are to make change of n units. For example, 
in a country whose denominations are {1,6,10}, C(5) = 1, C(6) to C(9) = 2, C(10) = 3, and C(12) = 4.
* (a)  How many ways are there to make change of 20 units from {1,6,10}?   
* (b)  Give  an  efficient  algorithm  to  compute C(n),  and  analyze  its  complexity. 
(Hint: think in terms of computing C(n, d), the number of ways to make change of n units with highest denomination d. 
Be careful to avoid overcounting.)   

***Solution***

* a) 7 {(20,0,0) (14, 1, 0 ) (8, 2, 0) (2, 3, 0) (10, 0, 1) (4, 1, 1) (0,0,2) } where the numbers in () represent the multiples of
1,6, and 10 respectively.   
* b) We proceed as the hint suggests. Name we recognize the following recursive solution:   
C[i][j] = C[i][j-1] + C[i-jx1][j-1]+...+C[i-jxm][j-1] where i represents i units, j represents the jth largest denomination and m is the
largest multiple of j such that jxm <= i. With the following implementation we achieve an O(nkM}) where M is the maximum of multiples
that satisify m as described above (and k = |{d1,...,dk}|}).   
```c++
#include<vector>
#include<iostream>
#include<algorithm>

int find_sum(const std::vector<std::vector<int>>& C, int a, int b, int clmn) {
	//get sum of C[i][d-1] + C[i-d*1][d-1]+ ... + C[i-d*m][d-1] where m is i / d(the highest integer multiple of d s.t.d*m <= i)
	int multiple = a / b;

	int cost = 0;
	for (multiple;  multiple >= 0; --multiple) {
		cost += C[a - b * multiple][clmn - 1];
	}

	return cost;
}

int coin_combinations(std::vector<int> denom, int target) {
	//assume denoms are not sorted
	std::sort(denom.begin(), denom.end());

	std::vector<std::vector<int>> cost(target + 1, std::vector<int>(denom.size()));
	
	//initialize
	for (int i = 0; i < cost[0].size(); ++i) cost[0][i] = 1; //there is always 1 way to make the empty set from any set
	for (int i = 0; i < cost.size(); ++i) {
		if ((i / denom[0])*denom[0] == i) cost[i][0] = 1; //only 1 way to make i with the smallest unit possible only if its fully divisible by smallest
		else cost[i][0] = 0;
	}

	//compute C[i][d]
	for (int i = 1; i < cost.size(); ++i) {
		for (int j = 1; j < cost[0].size(); ++j) {
			cost[i][j] = find_sum(cost, i, denom[j], j);
		}
	}

	//print matrix
	for (int i = 0; i < cost.size(); ++i) {
		for (int j = 0; j < cost[0].size(); ++j) {
			std::cout << cost[i][j] << " ";
		}
		std::cout << "\n";
	}

	return cost[target][denom.size()-1];

}

int main() {
	std::cout << "Number of ways to get change: " << coin_combinations(std::vector<int> {1, 6, 10}, 20);
}
```
