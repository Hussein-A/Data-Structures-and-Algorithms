4-17. The median of a set of n values is the (ceil)n/2th smallest value.  
(a)  Suppose quicksort always pivoted on the median of the current sub-array. How many comparisons would Quicksort make then in the 
worst case?  
(b)  Suppose quicksort were always to pivot on the (ceil)n/3th smallest value of the current sub-array. 
How many comparisons would be made then in the worstcase?  
.  
***Solution***  
(a) In this case we would be ending up with an even split partitions in terms of size, ie. halving the array in two. Now assuming we
only take *n* comparisons in total at every level of quicksort the question now becomes how deep is the recursion tree. Since we are
halving the array each time this amounts to how many times can the number *n* be halved, ie. *logn* yields a total runtime of *O(nlogn)*.  

(b) A similar analysis as above yields that the depth of the tree will be *log_(3/2)n* (after applying log and change of base rules) yielding
a total runtime of *O(nlog_(3/2)n)*.
