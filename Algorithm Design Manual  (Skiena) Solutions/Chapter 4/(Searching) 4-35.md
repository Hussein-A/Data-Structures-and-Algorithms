4-35. Let M be an n×m integer matrix in which the entries of each row are sorted in increasing order (from left to right) 
and the entries in each column are in increasing order (from top to bottom). Give an efficient algorithm to find the position of 
an integer x in M, or to determine that x is not there. How many comparisons of x with matrix entries does your algorithm use in 
worst case?  
.  
***Solution***  
A quick and intuitive solution is to, since the rows are sorted, apply Binary Search n times yielding an O(nlogm) algorithm. However this
approach behaves as though we were simply given n sorted arrays of size m that have no relation with each other, which is not the case here.
Exploiting this relationship will yield a more efficient* algorithm as follows: Begin at the bottom left corner of the matrix and check
if we are larger than this element or not. If so we shift to the right one place (ie. moving to the right column) otherwise we must be smaller
(obviously checking for equality when we compare) and so we must move up 1 position (ie. moving up one row). This algorithm yields an 
O(n+m) cost. We output not found if we increment past the row or column bound.  Below is the code used to solve this problem on LeetCode.  
.  
*Notice if the number of rows (alternatively columns) is small, ex. n ==1, then this yields O(logm) which is certainly better than the 
latter solution.  
.  
*Code (C++ LeetCode Submission)*
```
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int& row_size = matrix.size();
        if (row_size == 0) return false;
        const int& col_size = matrix[0].size();
        if (col_size == 0) return false;
        
        
        int row = row_size-1;
        int col = 0;
        int* curr_val= &matrix[row][col];
        while (row >=0 && col < col_size){
            curr_val = &matrix[row][col];
            if (*curr_val == target) return true;
            else if (target > *curr_val) ++col;
            else --row;
        }
        return false;
        
    }
};

```
