8-15. Eggs break when dropped from great enough height. Specifically, there must be a floor f in any sufficiently tall building such 
that an egg dropped from the fth floor breaks, but one dropped from the (f−1)st floor will not. 
If the egg always breaks, then f= 1. If the egg never breaks, then f = n+1. You seek to find the critical floor f using an n-story building.
The only operation you can perform is to drop an egg off some floor and see what happens. You start out with k eggs, and seek to drop eggs 
as few times as possible. Broken eggs cannot be reused. Let E(k, n) be the minimum number of egg droppings that will always suffice.   
* (a)  Show that E(1,n)=n.   
* (b)  Show that E(k, n) = Θ(n^(1/k)).   
* (c)  Find a recurrence for E(k, n). What is the running time of the dynamic program to find E(k, n)?   
.   
***Solution***   
* (a) Given a single egg it is clear that we must visit every floor starting from the very first. Indeed if we were to skip any floor with a
single egg and the egg breaks afterward we would be unable to tell if the floor is the floor we skipped or the one that the egg broke from.
(This is in the case we skip a floor and the egg breaks in the floor right after). Hence E(1,n)=n.
* (b) Unsure, if the reader is aware of the solution I would very much like to know.   
* (c) Suppose we pick a random floor, x, and drop an egg from that floor, consider the two possibilites. If it breaks then we have 1 less egg
but we only need to consider the first x-1 floors. If it doesnt then we still have k eggs and only need to consider the rest of the floors, n-x.
Our remaining question is which floor, x, should we pick? For this we must go through all possibilities and find the floor which minimizes the maximum
of the two possibilities above. In symbols this is:   
E[k][n] = 1 + min (for(x = 1; x <=n; ++x) max{E[k-1][x-1], E[k][n-x]}; The implementation in code is given below from which we find our
running time of O(kn^2).
```c++
#include<vector>
#include<iostream>
#include<algorithm>

int min_floor(const int height, const int neggs) {
	std::vector<std::vector<int>> E(neggs+1, std::vector<int>(height + 1)); //use 1 - n numbering rather than 0 - n-1

	//init E[1][n] == n (go through every floor starting from the first given 1 egg)
	for (int floor = 1; floor <= height; ++floor) E[1][floor] = floor;
	for (int eggs = 1; eggs <= neggs; ++eggs) E[eggs][1] = 1; //given only 1 floor, just drop once

	for (int eggs = 2; eggs <= neggs; ++eggs) {
		for (int floor = 2; floor <= height; ++floor) {

			int min = INT_MAX;
			for (int x = 1; x <= floor; ++x) {
				//find the floor, x, that minimizes the below
				int max = std::max(E[eggs][floor - x], E[eggs - 1][x-1]);
				if (max < min) min = max;
			}
			E[eggs][floor] = 1 + min;
		}
	}

	return E[neggs][height];
}

int main() {
	int height = 100;
	int neggs = 2;
	std::cout << "min number of droppings: " << min_floor(height, neggs) << "\n";
}
```
