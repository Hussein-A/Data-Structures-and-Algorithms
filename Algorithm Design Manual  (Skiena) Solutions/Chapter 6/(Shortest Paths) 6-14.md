6-14. The single-destination shortest path problem for a directed graph seeks the shortest path from every vertex to a specified vertex v. 
Give an efficient algorithm to solve the single-destination shortest paths problem.   
.   
***Solution***   
Note that were this an undirected graph all we would need to do is call Dijkstra's algorithm with v as the starting vertex.
This is since in an undirected graph the shortest path between u to v is the exact same as the shortest path from v to u. One way might be
to call Dijkstra's algorithm for every other vertex other than v, effectively computing the all-pairs shortest paths in O(n^3) time.
However a quicker way would be to notice that a path from u to v in a directed graph, say u->i_1->...->i_k->v is actually a path (shortest) from v to u
if the edge directions are reversed. Hence simply reverse the direction of all the edges in the graph and apply dijkstra's algorithm
with starting vertex v to attain your required path (be sure to reverse the edges again at the end to undo the initial reversal
and arrive at the correct order of path traversal). This runs in O(n^2) time as it's a single call of Dijkstra. (Note this assumes the edge
weights are positive of course otherwise Dijkstra's algo. would not work here).
