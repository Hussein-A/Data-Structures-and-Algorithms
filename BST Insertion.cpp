#include<algorithm>
#include<vector>
#include<string>


using namespace std;

template <typename T> 
struct TreeNode {
	T val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(T x) : value{ x }, left{ NULL }, right{ NULL }{};
};



template <typename T>
//requires Less_comparable<L, T>()
void BT_insertion(TreeNode<T>* root, T x) {
	//requires comparisons between item type T
	//value must be unique
	if (root == NULL) return;

	if (x < root->val){
		if (root->left == NULL) { root->left = new TreeNode{ val }; return; }
		BT_insertion(root->left);
	}
	else {
		if (root->right == NULL) { root->right = new TreeNode{ val }; return; }
		BT_insertion(root->right);
	}
	return;
}

int main() {
	
}