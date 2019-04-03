4-40. If you are given a million integers to sort, what algorithm would you use to sort them? How much time and memory would that consume?  
.  
***Solution***
It may seem as though we need only throw a die and pick our favourite O(nlogn) sorting algorithm however certain assumptions about the integers
we are to sort as well as certain other considerations (such as where the data is stored, if it fits in main memory, do we want
to minimize extra space utilization, etc.) will give us more
insight as to which algorithm to pick. For example:  
1. There are many duplicates in the array such that *k*, the number of distinct elements, is such that k<<n. In such a case we recall
a previous problem we have solved, 4-22, and noted that using heapsort we can actually get an O(nlogk) algorithm (see 4-22 for more details).
Moreover this takes an O(1) space since we can modify the array to make the heap.
2. Most of our data is stored on a disk. In such a case we want to minimize reading/access of the disk hence an inclination towards mergesort.
Space complexity is O(n) as we needed to use deques to merge arrays.
3. The array is almost sorted. In such a case insertion sort might seem to be the better choice among the canditates despite its O(n^2) 
complexity since insertion sort works by comparing A[curr] with A[curr-1]. This takes O(1) space.  

Many considertions such as the above play a role in deciding which algorithm to choose, though given nothing else one might do well to choose
quicksort (worst case space is O(n) with average of O(logn)).
