4-23. We seek to sort a sequence S of n integers with many duplications, such that the number of distinct integers in S is O(*logn*).
Give an O(*nlog logn*) worst-case time algorithm to sort such sequences.  
.  
***Solution***  
Our idea is going to be exactly the same as in 4-22. Namely we will construct a binary search tree with the keys being the elements of S
however without repetition (ie. if we were to remove all copies of elements from S construct your tree from the remaining unique elements).
The value represented by the key will be the number of copies we have come across thus far of that particular element. Again, similar reasoning
as in 4-22 yields that we will need O(*nlogk*) time where k is the number of distinct elements of S. In this case since |k| is O(*logn*) we
arrive at the required result which is O(*nloglogn*) as required.
