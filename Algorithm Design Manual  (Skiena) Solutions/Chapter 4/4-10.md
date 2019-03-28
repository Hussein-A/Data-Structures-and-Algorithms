4-10. Given a set S of n integers and an integer T, give an *O(n^(k-1)logn)* algorithm to test whether k of the integers in S add up to T.  
.  
***Solution***  
We will use the same idea as in 4-8 mainly we will first sort the array and note that if there exists k such elements of S labeled x_1,...,x_k such that x_1+...+x_k= T
then we also have x_1+...x_(k-1) = T-x_k and so on until x_1 = T-x_k-...-x_2. This gives an idea for a recursive, backtracking algorithm.
Our new target each call will be starting with T-x_k (where we will iterate over x_k) then calling our new target to be T-x_k with --k.
Finally when we reach the final target at k = 0 we will call a binary search on x_1. This yields the required *O(n^(k-1)logn)* algorithm.  
.  
*Code (C++)*  
```
#include<vector>
#include<algorithm>
#include<utility>
#include<iostream>

int k = 4;//change as desired
std::vector<int> k_sum(k, -1);

bool findksum(std::vector<int>& arr, int target, int k) {
	if (k > arr.size() || arr.size() == 0 || k<0) return false;
	--k;
	if (k == 0) {
		bool it = std::binary_search(arr.begin(), arr.end(), target);
		if (it) k_sum.at(k) = *find(arr.begin(), arr.end(), target);
		return it;
	}
	
	for (int i = 0; i < arr.size(); ++i) {
		k_sum.at(k) = arr[i];
		int new_target = target - arr[i];
		if (findksum(arr, new_target, k)) return true;
	}
	return false;
}

int main() {
	std::vector<int> test{ 2,3,4,5,6,7,8,9,10 };
	int target = 16;//change as desired
	sort(test.begin(), test.end());
	if (findksum(test, target, k)) {
		std::cout << "FOUND\n" << "The " << k << " integers that sum to " << target << " are: \n";
		for (int x : k_sum) { std::cout << x << "\n"; }
	}
	else std::cout << "Not Found!\n";

}
```
