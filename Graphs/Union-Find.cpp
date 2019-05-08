#include"Union-Find.h"

using namespace std;

set_union::set_union(int n) {
	parent.resize(n); for (int i = 0; i < n; ++i) parent[i] = i;
	tree_size.resize(n,1);
	size = n;
}

int set_union::find(int i) {
	if (this->parent[i] == i) return i;
	else return set_union::find(this->parent[i]);
}

void set_union::union_merge(int i, int j) {
	int left_tree = set_union::find(i);
	int right_tree = set_union::find(j);

	if (left_tree == right_tree) return; //already in same tree

	if (this->tree_size[left_tree] >= this->tree_size[right_tree]) {
		//merge smaller tree into bigger tree.
		this->parent[right_tree] = left_tree; //Root of smaller tree is now a child root of bigger tree
		this->tree_size[left_tree] += tree_size[right_tree]; //update new size
	}
	else {
		//same as above but reverse left and right tree
		this->parent[left_tree] = right_tree;
		this->tree_size[right_tree] += tree_size[left_tree];
	}
}