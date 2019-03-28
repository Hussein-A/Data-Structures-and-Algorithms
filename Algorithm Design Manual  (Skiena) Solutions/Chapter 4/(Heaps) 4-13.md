You wish to store a set of n numbers in either a max-heap or a sorted array. For each application below, state which data structure is better, or if it does not matter. Explain your answers.  
(a)  Want to find the maximum element quickly.  
(b)  Want to be able to delete an element quickly.  
(c)  Want to be able to form the structure quickly.  
(d)  Want to find the minimum element quickly.  
.  
***Solution***  
(a) Assuming we have a max heap then in either case it takes *O(1)* time.  
.  
(b) If we do not know the index of the element we are deleting and are required to find it first then a sorted array is better as we can 
apply binary search since we cannot search for an element in a heap without visiting every element. That being said if we do know the index
it would be best to use a heap as the bubble down procedure only costs *O(logn)* time (assuming we are not using the array representation
of a heap in which case both are equal.)  
.  
(c) It is better to use a heap as we can construct it in *O(n)* time.  
.  
(d) If we are working with a max heap then we would have to search through every single element to get the min since a heap does not
force a total order on the elements it holds. Alternatively a sorted array can find the minimum element in *O(1)* time by visiting the
first element.
