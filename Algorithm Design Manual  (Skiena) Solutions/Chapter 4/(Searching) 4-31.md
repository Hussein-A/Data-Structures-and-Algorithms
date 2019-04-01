4-31. Suppose you are given an array A of n sorted numbers that has been circularly shifted k positions to the right. 
For example, {35,42,5,15,27,29} is a sorted array that has been circularly shifted k= 2 positions, while{27,29,35,42,5,15} 
has been shifted k= 4 positions.  
1. Suppose you know what k is. Give an O(1) algorithm to find the largest number in A.  
2. Suppose you do not know what k is. Give an O(lgn) algorithm to find the largest number in A. 
For partial credit, you may give an O(n) algorithm.  
. 

***Solution***  
1. For the first part we first take k mod n, where n is the size of the array (for example a shift of 6 in an array of size 6 returns everything
to the original position). After this we need only go to the (k mod n) position in the array (ie. the (k mod n) -1 position when are
talking about the index of the array since they start at 0).  
2. An immediate O(n) algorithm is to simply iterate through the array each time checking if the element infront of me is less than me.
If it is I know immediately that the position I am in must be the largest. For a more optimal solution we notice that the presence of O(logn)
bound should tell us that we will need to be "halving" our array for search each iteration. This should remind us of binary search. 
Now we need only figure out which half to throw away and which half to recurse on.  This can be done as follows:  
Find A[mid] and A[0] if (A[mid]>A[0]) then largest must be in the right half, we will recurse on that. Else it will be in the bottom half.
As to how we will know when we are done we will use the same idea as in the O(n) case. If we are in the right
half then check if A[mid]>A[mid+1] then A[mid] = largest. Else we must be going to the left half and so we check if A[mid-1] > A[mid] if so
we have found the largest as required.
