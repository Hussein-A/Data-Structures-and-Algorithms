6-3. Assume that all edges in the graph have distinct edge weights (i.e. , no pair of edges have the same weight). 
Is the path between a pair of vertices in a minimumspanning tree necessarily a shortest path between the two vertices in the full graph?
Give a proof or a counterexample.   
.   
***Solution***   
Pick a graph as before but now with increasing edges.
Ie. 1-2 (1), 2-3 (2), 3-4 (3), 4-1 (4). Prim's algo. gives us the same spanning tree: 1-2-3-4 with a cost from 1-4 being 5 yet that is not
the shortest path in the graph. For the curious the question can be formalized as follows:
To provide a counter example we seek a sequence of numbers a_1,...,a_k, b with the following properties:
1. For each i, a_i >=1 and b>=1.   
2. For each i and j such that i < j: a_i < b. (This is necessary due to the MST algorithms, ex. Prim, and how they choose which edge to add 
next to the tree, ie. always add the cheapest one).
3. For any i != j then a_i != a_j.
4. a_1+a_2+...+a_k > b.

