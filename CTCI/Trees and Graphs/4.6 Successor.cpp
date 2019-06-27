/*
Problem to return the next node (in order successor) of a binary tree.
Problem 4.6 in CTCI
*/

#include<iostream>

struct TreeNode {
	int val;
	TreeNode* left{ nullptr };
	TreeNode* right{ nullptr };
	TreeNode* parent{ nullptr };

	TreeNode(int x) : val{ x } {};
};

TreeNode* next(TreeNode* root) {
	//case 1: no right child
	if (root->right == nullptr) return root->parent;
	else {
		TreeNode* temp = root->right;
		while (temp->left != nullptr)
			temp = temp->left;

		return temp;
	}
}

int main() {
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(0);
	root->left->parent = root;

	root->left->left = new TreeNode(-1);
	root->left->left->parent = root->left;
	
	root->right = new TreeNode(2);
	root->right->parent = root;

	std::cout << next(root->left->left)->val << "\n";
}