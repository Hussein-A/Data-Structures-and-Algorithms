4-29 Mr. B. C. Dull claims to have developed a new data structure for priority queues that supports the operations Insert, Maximum, 
and Extract-Max—all in O(1) worst-case time. Prove that he is mistaken. 
(Hint: the argument does not involve a lot of gory details—just think about what this would imply about the Ω(nlogn) lowerbound for sorting.)  
.  
***Solution***  
As the hint suggests we need only reflect on the lowerbound of nlogn for comparison based sorting. I claim that if such a data structure
exists then it would be a violation of the lower bound. To see this consider the following: insert all n elements of an array in O(n)
then extract max n times in O(n) for a total cost of O(n), violating the lower bound. Hence Dull must be mistaken.
