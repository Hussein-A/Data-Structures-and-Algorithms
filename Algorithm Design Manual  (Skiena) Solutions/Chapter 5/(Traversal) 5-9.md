5-9. Suppose an arithmetic expression is given as a tree. Each leaf is an integer and each internal node is one of the standard arithmetical operations (+,−,∗,/). 
For example, the expression 2 + 3∗4+(3∗4)/5 is represented by the tree in Figure 5.17(a).  
![Alt text](https://github.com/Hussein-A/Data-Structures-and-Algorithms/blob/master/Algorithm%20Design%20Manual%20%20(Skiena)%20Solutions/Chapter%205/Skiena%20Fig.%205.17.png)
Give an O(n) algorithm for evaluating such an expression, where there are n nodes in the tree.
.  
***Solution***  
We follow a recursive approach as follows in the pseudocode below. We assume our TreeNode data structure has two pointers (of type TreeNode) towards its left and right child
(if they exist) as well as one character pointer that contains either an integer or one of the operations (-,+,*, /).
```
int evaluate (TreeNode* root){
  
  if (is_int(root->val)) return root->val;
  else switch(root->val){
  case '-': return evaluate(root->left) * evaluate(root->right); break;
  ...//other operations here
  case '/': return evaluate(root->left) / evaluate(root->right);  break;
  }
  
}
```
