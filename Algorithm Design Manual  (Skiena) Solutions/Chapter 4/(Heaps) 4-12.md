4-12. Devise an algorithm for finding the k smallest elements of an unsorted set of n integers in *O(n+klogn)*.  
.  
***Solution***
Construct a heap in *O(n)* time then repeatedly query and pop the min element *k* times which costs *O(klogn)* hence a total cost of
*O(n + klogn)*.
