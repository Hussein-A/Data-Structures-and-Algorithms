4-36. Consider an n×n array A containing integer elements (positive, negative, and zero). Assume that the elements in each row of A are 
in strictly increasing order, and the elements of each column of A are in strictly decreasing order. (Hence there cannot be two 
zeroes in the same row or the same column.) Describe an efficient algorithm that counts the number of occurrences of the element 0 in A.
Analyze its running time.  
.  
***Solution***  
We take a somewhat similar approach as to the previous matrix question (4-35). Implement a global or local counter zeroes. We first start at the top left corner of the matrix and first check
if that element is greater than 0; if so we move on to the row below and ask again. If not then there is a chance that a 0 lies in this row
(since rows are in increasing sorted order), conduct a Binary Search on this row. We now have two possibilities:  
1. We do not find a 0. If so then a 0 cannot exist in the current column either, move 1 row down and 1 column right and and do the same as above.
2. We find a 0; ++zeroes. Now as the question states no 0 can exist in the current row and column but what about previous (left) columns?
Note that there cannot be a 0 in any of the previous (left) columns due to the nature of the matrix. To see this let M[i][j] == 0 and let
there be a 0 in M[x][y] in some previous column, ie. y < j. (Note moreover we are going top to down so we assume we have dealt with any
zeroes in rows above us, ie. i < x). Consider that M[i][y] < M[i][j] (as y < j) and moreover M[x][y] < M[i][y] (as i < x) 
(both of which are due to properties of the matrix) hence M[x][y] < M[i][j], that is: 0 < 0, a contradiction. This realization allows us
to discard all the columns previous to and including the one the 0 was found in. Now we recurse on our shortened matrix and search again
 (alternatively just ++column and ++row).  
.  
A quick and dirty analysis yields O(nlogm) run time. A more detailed look yields, in the worst case, log(m) + log(m-1)+...+log(m-n)
which by log rules is log(m * (m -1) * (m-2) *...*(m-n) ) = O(log(m^n))=O(nlogm) as before.
