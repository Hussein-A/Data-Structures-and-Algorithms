6-2. Is the path between two vertices in a minimum spanning tree necessarily the shortest path between the two vertices in the full graph? 
Give a proof or a counter-example.   
.   
***Solution***   
No consider the graph on 4 vertices: 1-2 (1), 2-3 (1), 3-4 (1), 4-1 (2) where the number in brackets is the weight of the edge. (This
is a cycle graph). Then a MST is one that is simply a long chain starting from 1: 1-2-3-4 whose cost of the path from 1->4 is 3 and yet
the shortest path would've taken 1-4 at a cost of 2. This shows that at least in the case of shortest paths the 
greedy algorithm is not the best choice.
