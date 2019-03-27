4-2: For each of the following problems, give an algorithm that finds the desired numbers within the given amount of time. 
To keep your answers brief, feel free to use algorithms from the book as subroutines. 
For the example,S={6,13,19,3,8}, 19−3 maximizes the difference, while 8−6 minimizes the difference.  
.  
(a) Let S be an unsorted array of n integers. Give an algorithm that finds the pair x, y∈S that maximizes |x−y|. 
Your algorithm must run in O(n) worst-case time.  
.  
(b) Let S be asorted array of n integers. Give an algorithm that finds the pair x, y∈S that maximizes |x−y|. 
Your algorithm must run in O(1) worst-case time.  
.  
(c) Let S be an unsorted array of n integers. Give an algorithm that finds the pair x, y∈S that minimizes|x−y|, forx!=y. Your algorithm must run in *O(nlogn)* worst-case time.  
.  
(d) Let S be as orted array of n integers.
Give an algorithm that finds the pair x, y∈S that minimizes|x−y|,for x!=y. Your algorithm must run in *O(n)* worst-case time.  

***Solution***  
(a) Use the same algorithm as finding the max or min in *O(n)* time for an unsorted array but this time keep two values as you go through
the array, int max and int min. Check against each element if greater than max or less than min updating as necessary. These two will maximize your difference.    
.  
(b) Pick the first and last integer.  
.  
(c) Sort the list in *O(nlogn)*. If such a pair exists where can we expect to find them? They must be right beside each other otherwise there is an element inbetween that would
give a smaller minimum distance. Hence go through the sorted list each time checking the distance between the current element and the one infront.
Keep track of this by a min value as well as the x,y value that gave that min. This second step after sorting takes *O(n)*.  
.  
(d) Same as above but without sorting.
