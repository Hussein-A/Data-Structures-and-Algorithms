4-16. Use the partitioning idea of quicksort to give an algorithm that finds the median element of an array of n integers 
in expected O(n) time. (Hint: must you look at both sides of the partition?)  
.  
***Solution***  
We will use the partitioning idea of quicksort and as the hint suggests we will only consider one part of the partition each iteration.
Pick a random pivot index and sorting according to those larger than and those less than as usual in a normal quicksort run. Now we recall
that in quicksort the pivot index always ends up in its correct position in total sorted order after a partition sort is done. We will use 
this information to determine which of the two partitions we will recurse on as follows:  

If the index of the pivot after the partitioning is done
is n/2 than we have found our median as the median must occupy that position (some modifications will be needed in the case of even *n* or odd *n*).
Else if the pivot index is larger than *n/2* we choose the lower partition instead and repeat. Otherwise we choose the upper or rightmost
partition. This eventually ends with an element that is the median. An analysis yields *O(n)* as for each iteration the size of the partition
we are partitioning and (pivot-)sorting is halved (average) each time yielding a total AVERAGE cost of *O(n)+O(n/2)+*O(n/4)*+...=*O(n)*. A code fragment is provided
below.   
.  
*Code Fragment (C++)*  
```
int median(std::vector<int>& nums, std::vector<int>::iterator left, std::vector<int>::iterator right) {
	if (left == right) return *left;

	auto it = partition(left, right); //just as in quicksort, returns iterator pointing to pivot element
	int index = distance(nums.begin(), it);
	int target_index = nums.size() / 2;

	if (index ==  target_index) {
		return *it;
	}

	if (index > target_index) return median(nums, left, it);
	else return median(nums, it, right);
}
```  
.  
**NOTE** This algorithm can be easily extended to one that finds the *kth* smallest element in expected *O(n)* time by simply adding
an argument for target_index above (since the kth smallest element must be in the kth position in the totally sorted array).
