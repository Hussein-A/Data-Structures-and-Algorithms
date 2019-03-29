4-20. Give an efficient algorithm to rearrange an array of n keys so that all the negative keys precede all the nonnegative keys.   
.  
***Solution***
This can be solved exactly as we would a normal round of quicksort partitioning/sorting in that the only difference this time is that
our pivot element may not be an element of the array rather we will fix it to be 0 and sort all those positive go above and negative
go below. This, as before, is one-pass *O(n)* algorithm. Code demonstrates this below.  
.  
*Code (C++)*  
```
        if (nums.size() == 0) return;
        //use similiar idea to quicksort pivots
        vector<int>::iterator first_plus = nums.begin();
        vector<int>::iterator curr = nums.begin();
        
        while (curr != nums.end()){
            if (*curr <0){swap(*curr, *first_plus); ++first_plus;}
            ++curr;
        }
```
