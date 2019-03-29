4-22. Show that  *n* positive integers in the range 1 to k can be sorted in *O(nlogk)* time. The interesting case is when k<<*n*.  
.  
***Solution***  
Consider how you would normally sort such a list. One idea might be to use a binary search tree where our keys will be the elements themselves
ie. ranging from 1 to k and the value that the key represents would be the count of that particular key. This yields a tree with a height of
*logk* and since we are doing *n* insertions we will construct this tree in *O(nlogk)*. Next it becomes a simple matter of querying the min. n times
where we delete that particular node (the current min) only when key->val is 0 (ie the array does not have any more copies of that element/key).
Since deletion, insertion and find_min all take *O(logk)* time it is not hard to see that this yields a *O(nlogk)* algorithm.
