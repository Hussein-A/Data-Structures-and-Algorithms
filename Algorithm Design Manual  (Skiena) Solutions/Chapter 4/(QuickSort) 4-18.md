4-18. Suppose an array A consists of n elements, each of which is red, white, or blue. We seek to sort the elements so that all the 
reds come before all the whites, which come before all the blues. The only operation permitted on the keys are  
* Examine(A,i)– report the color of theith element ofA.  
* Swap(A,i,j)–swaptheith element ofAwith thejth element.  
Find a correct and efficient algorithm for red-white-blue sorting. There is a linear-time solution.  
.  
***Solution***  
**1** We will use the technique of quicksorting whereby we sort an array into elements smaller than the pivot and those elements above it.
First we will choose our pivot element to be 1 without regard for where the copies of 1 go as long as they are all after any 0 ie. 
[2,0,1,2,1,1,0,0,0] -> [0,0,0,0,1,1,2,1,2] is acceptable after partitioning. Next we will go move to the first 1 we see and partition
from that position to the end placing all 1s before 2s. In essence in our first pass we place all 0s before all 1s and 2s then our second pass
places all 1s before 2s yielding a *O(2n)* (linear) algorithm. Code is provided below.  
.  
**2** Have three counters one for each colour. Simply go through the array incrementing the respective colour at each position then 
go back through the array and overwrite the position starting with 0s until you are out of 0s, then 1s then 2s. Again an *O(2n) = O(n)* approach.  
.  
Below is code for the first solution.
*Code (C++)* 
```
void sortColors(vector<int>& nums) {
        if (nums.size() == 0) return;
        //use similiar idea to quicksort pivots
        vector<int>::iterator first1 = nums.begin();
        vector<int>::iterator curr = nums.begin();
        
        while (curr != nums.end()){
            if (*curr == 0){swap(*curr, *first1); ++first1;}
            ++curr;
        }
        //do again but this time imagine you have an array of only 1s and 2s
        curr = nums.begin();
        while (curr != nums.end() &&*curr == 0) ++curr;
        vector<int>::iterator first2 = curr;
        
        while (curr != nums.end()){
            if (*curr == 1){swap(*curr, *first2); ++first2;}
            ++curr;
        }
        
        
    }
 ```
