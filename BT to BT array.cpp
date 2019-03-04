/*
Converts a binary tree with the given structure into a binary tree array representation.

 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<vector>
#include<algorithm>
#include<string>
#include<queue>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

using namespace std;

void clean_vector(vector<string>& v) {
	int end = v.size() - 1;
	int i = end;
	for (i; i > 0; --i) {
		if (v.at(i - 1) != "NULL") break;
	}

	v.erase(v.begin() + i, v.end());
}

vector<string> tree_array(TreeNode* root) {
	//returns the array representation of a tree given the root node
	queue<TreeNode*> nodes;
	vector<string> tree_vals; tree_vals.push_back(to_string(root->val));

	if (root->left != NULL) { nodes.push(root->left); tree_vals.push_back(to_string(root->left->val)); }
	if (root->right != NULL) { nodes.push(root->right); tree_vals.push_back(to_string(root->right->val)); }
	if (!root->right && !root->left) { return tree_vals; }

	while (!nodes.empty()) {


		//move from left to right in a single level
		auto it = find(tree_vals.begin(), tree_vals.end(), to_string(nodes.front()->val));
		int index = distance(tree_vals.begin(), it);
		if (2 * index + 4 > tree_vals.size()) tree_vals.resize(2 * index + 4, "NULL");


		if (nodes.front()->left != NULL) {
			nodes.push(nodes.front()->left);
			tree_vals[2 * (index)+1] = to_string(nodes.front()->left->val);
		}
		else { tree_vals.at(2 * (index)+1) = "NULL"; }

		if (nodes.front()->right != NULL) {
			nodes.push(nodes.front()->right);
			tree_vals.at(2 * (index)+2) = to_string(nodes.front()->right->val);
		}
		else { tree_vals.at(2 * (index)+2) = "NULL"; }

		nodes.pop();

	}
	clean_vector(tree_vals);
	return tree_vals;
}

int main() {

}