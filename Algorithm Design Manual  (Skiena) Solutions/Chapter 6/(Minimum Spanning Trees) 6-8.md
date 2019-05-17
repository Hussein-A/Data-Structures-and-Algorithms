6-8. Devise and analyze an algorithm that takes a weighted graph G and finds the smallest change in the cost to a non-MST edge that would cause
a change in the minimum spanning tree of G. Your algorithm must be correct and run in polynomial time.   
.   
***Solution***   
Let T be an instance of the MST in question. Pick a particular tie breaker function that allows Prim's algo to generate T (if the
edges of G are distinct in weight then no such function is needed). Our strategy will be to ride along the running of Prim's algorithm
and conduct our search at each round of Prim's. First we must realize that in order to change the structure of the tree given by Prim's
we must choose an edge not in T, that is to say with respect to Prim, we pick an edge that was not the cheapest edge at the time it was considered
during a round. So proceed as follows:   
1. For an arbitrary stage of Prim's go through all the candidate edges as usual. Find the *second cheapest*
edge after the cheapest edge that was chosen to go into T. Compute the difference between that and the cheapest, call it x. O(m)   
2. Push x into a min-based heap. O(logn)   
3. Pop the smallest element from the heap, say y. The smallest such value will then be >y. That is if you subtracted a value >y from the
particular edge from which this difference was computed then this would result in the change in the structure of T.   

This yields a total cost of O(nm +nlogn).
