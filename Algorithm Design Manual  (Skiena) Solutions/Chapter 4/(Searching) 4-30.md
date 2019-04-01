4-30. A company database consists of 10,000 sorted names, 40% of whom are known asgood customers and who together account for 
60% of the accesses to the database. There are two data structure options to consider for representing the database:  
* Put all the names in a single array and use binary search.  
* Put the good customers in one array and the rest of them in a second array. Only if we do not find the query name on a binary search of 
the first array do we do a binary search of the second array.  
Demonstrate which option gives better expected performance. Does this change if linear search on an unsorted array is used instead 
of binary search for both options?  

***Solution***
Consider that in the second case we have a (worst case) cost of log10000 in the second we have a cost of log4000 plus a 0.4 chance to incur a cost of
log6000 this yields a total (worst case) cost of log4000 + 0.4log6000 (=5.11). On the other hand, as simple as the first case seems to be, it only
gives a cost of log10000(=4) which is smaller than the former hence the first option is the better choice.  
.  
For event where we have only unsorted arrays then we have a cost of 10000 in the first case but only a cost of 4000 +0.4*6000 in the second case
yielding that the second case is far superior to the first.
