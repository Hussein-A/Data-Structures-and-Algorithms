8-6. Coins in the United States are minted with denominations of 1, 5, 10, 25, and 50 cents. Now consider a country whose coins are 
minted with denominations of {d1,...,dk} units. We seek an algorithm to make change of n units using the minimum number of coins for 
this country.   
(a) The greedy algorithm repeatedly selects the biggest coin no bigger than the amount to be changed and repeats until it is zero. S
how that the greedy algorithm does not always use the minimum number of coins in a country whose denominations are {1,6,10}.   
(b) Give an efficient algorithm that correctly determines the minimum number of coins needed to make change of n units using denominations 
{d1,...,dk}. Analyze its running time.   
.   
***Solution***   
* a) Consider the case of 18 units. The greedy algo will give change {10, 6, 1 ,1} for a total of 4 coins. Yet we could have given that 
amount with just 3 coins {6,6,6}.   
* b) We will go through all possibilities while keeping track of the cheapest way to make change for i (units) 0 <= i <= n (represented
as C[i]). We note that:   
C[i] = min {C[i-d_j*S_j]+S_j} where d_j is s.t. d_j <= i and 1 <=  S_j <= max{S | S(d_j) <= i}. This costs O(nDm) where D is the size of the
denomination list, and m is max over all S_j. A full implementation makes this clear and is given below.   
```c++
#include<iostream>
#include<vector>
#include<algorithm> //std::max and min

int min_cost(int target, const std::vector<int>& denom, const std::vector<int>& cost) {
    //assumes denom is sorted (done by function caller, min_coins)
	int multiple = target / denom[0];
	if (multiple == 0) return INT_MAX; //all denoms are bigger than the target, no way to get change for 1 cents if you're smallest is 5 cent
	std::vector<int> candidate_costs;

	for (int i = 0; i < denom.size() && denom[i] <= target; ++i) {
		multiple = target / denom[i];
		for (multiple; multiple > 0; --multiple) {
			int remainder = cost[target - denom[i] * multiple];			
			if (remainder == INT_MAX) candidate_costs.push_back(INT_MAX); //prevent int overflow but still represent it as impossible
			else candidate_costs.push_back(remainder + multiple);

		}
	}
	return *std::min_element(candidate_costs.begin(), candidate_costs.end());
}

int min_coins(std::vector<int> denom, int n) {
	if (n <= 0) return 0;
	std::vector<int> cost(n + 1);

	//sort the denom's to ensure ordering (O(nlogn))
	std::sort(denom.begin(), denom.end());

	for (int i = 1; i < cost.size(); ++i) {
		cost[i] = min_cost(i, denom, cost); //O(nDm) where D is the size of denom, m is the max of {m | d_j*m <= n, 0 <= j <= denom.size()}
	}
	return cost[n];
}


int main() {
	std::cout << "min. number of coins needed: " << min_coins(std::vector<int> {1, 6, 10}, 6) << "\n";
}
```
