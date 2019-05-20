6-19. Let G be a weighted directed graph with n vertices and m edges, where all edges have positive weight. A directed cycle is a directed 
path that starts and ends at the same vertex and contains at least one edge. Give an O(n3) algorithm to find a directed cycle in G of 
minimum total weight.   
.   
***Solution***   
The O(n^3) cost should tell us we will be using one of Floyd's or Dijkstra's algorithms. Both may work in this situation. The specific
reason for their use is in this sentence "A directed cycle is a directed 
path that starts and ends at the same vertex and contains at least one edge." That is we will be finding the shortest path from a vertex
to itself. We have n vertices and so will need to do n calls of either algo above. Finally outputting which of the n vertices has the
smallest cycle path. The only point we need to worry about is in our implementation
of both algos. For example in Dijkstra's algo. we intialized the shortest distance from a vertex to itself to be 0 (review the algo. in
the repo to see why). This can be fixed by first initializing the distance from the start vertex to its neighbours, setting distance of the start
vertex to be INT_MAX (not 0) and then proceeding as usual.
