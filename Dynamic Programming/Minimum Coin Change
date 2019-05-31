/*
Program to compute the minimum number of coins needed to produce change of n units using denominations from {d_1,...,d_k}.
This is a variant of the knapsack problem in that we have a bag with max weight capacity n and we have infinitely many objects of weight d_1,...,d_k
and each object has value 1. Our task is to fill this bag to its max weight while minimize the value in the bag.

We apply a DP approach to solve this. Based on the recursive formula:
C[i] = min {C[i-d_j*S_j]+S_j} where d_j is s.t. d_l <= i and 1 <=  S <= max{S*d_j | S*d_j <= i}.
The case where we cannot give change for n given the denom (such as change for 1 dollar given only {3,5,10} denominations) we put int_max as the cost.
*/

#include<iostream>
#include<vector>
#include<algorithm> //std::max and min

int min_cost(int target, const std::vector<int>& denom, const std::vector<int>& cost) {
	int multiple = target / denom[0];
	if (multiple == 0) return INT_MAX; //all denoms are bigger than the target, no way to get change for 0.0001 cents if you're smallest is 1 cent
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
