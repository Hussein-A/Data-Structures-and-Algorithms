4.24 Let A[1..n] be an array such that the first n−√n elements are already sorted (though we know nothing about the remaining elements). 
Give an algorithm that sort sA in substantially better than O(*nlogn*) steps.  
.  
***Solution***  
One naive idea might be to simply implement selection sort with a starting sorted array of size (n-√n). This yields a total cost of
O(√n*n-n). However we can do better than this by following the idea of mergesort. We will sort the remaining √n elements in O(√nlog√n) time
and then merge them with the remaining n-√n elements. We recall that mergesort will take, in this case, O(n). Basic analysis shows that
O(√nlog√n) cost is less than the O(n) cost of merging yielding a total cost of O(n).
