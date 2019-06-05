/*
This program finds the optimal solution using DP to the following problem 
(description taken from leetcode formulation, 887. Super Egg Drop):

You are given K eggs, and you have access to a building with N floors from 1 to N.
Each egg is identical in function, and if an egg breaks, you cannot drop it again.
You know that there exists a floor F with 0 <= F <= N such that any egg dropped at a floor higher than F will break, and any egg dropped at or below floor F will not break.
Each move, you may take an egg (if you have an unbroken one) and drop it from any floor X (with 1 <= X <= N).
Your goal is to know with certainty what the value of F is.
What is the minimum number of moves that you need to know with certainty what F is, regardless of the initial value of F?

This is also problem 8-15 in Skiena's Algorithm Design Manual, 2ed.

The idea is to use the recursive equation E[k][n] = min(x)_1^n{ max{ E[k][n-x], E[k-1][x-1] } }
To be read as the min as x goes from 1 to n of the following values: max{E[k][n-x], E[k-1][x]}
ie. if we dropped the egg at the xth floor does it break or not? If it does we have to check the first x floors with only k-1 eggs
if not we still have k eggs but n-x floors to check now.
*/

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