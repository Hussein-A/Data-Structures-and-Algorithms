/*the following is based upon the Union-Find data structure as outlined in Skiena's Algorithm
Design Manual, pg 199.

*/

#pragma once
#include<vector>


struct set_union {
	std::vector<int> parent; //parent element
	std::vector<int> tree_size; //size of subtree rooted at position i
	int size; //size of set

	set_union(int n); //constructor
	int find(int i); //find the root (ie representative) of the tree that contains i
	void union_merge(int i, int j); //merge the two components that contain i and j
};

