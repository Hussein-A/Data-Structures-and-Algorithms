4-28 In one of my research papers [Ski88], I discovered a comparison-based sorting algorithm that runs in O(nlog(√n)).
Given the existence of an Ω(nlogn) lowerbound for sorting, how can this be possible?  
.  
***Solution***  
Note that by log rules we have log√n = (logn)/2. Hence O(nlog√n) = O((n/2)logn)= O(nlogn). So there is no violation of the lowerbound.
