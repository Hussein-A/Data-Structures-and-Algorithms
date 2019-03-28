4-14. Give an *O(nlogk)*-time algorithm that merges k sorted lists with a total of n elements into one sorted list. (Hint: use a heap to speed up the elementary *O(kn)*-time algorithm).  
.  
***Solution***
As the hint suggests we will apply a heap based algorithm as follows. Take the minimum (ie. first) element from each list and construct a heap (of height *logk*) from those
k elements (*O(k)*) but be sure to keep track of which element came from which list. Next repeatedly extract the minimum element from the heap
and place it in the next position in the sorted list. Now that the heap is missing its min element replace it with the next element
after it in the list that the minimum element came from and bubble down if necessary. We will query the min element *n* times each time 
bubbling down with the next element which costs *O(logk)* hence yielding a total time cost of *O(nlogk)*.  
