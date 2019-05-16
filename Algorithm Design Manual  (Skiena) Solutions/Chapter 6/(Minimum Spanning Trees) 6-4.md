6-4. Can Prim’s and Kruskal’s algorithm yield different minimum spanning trees? Explain why or why not.   
.   
***Solution***   
Depending on the graph. If the graph has distinct edge weights then no, both will produce the same graph, otherwise yes. Towards the latter
it is clear, in fact even the same algorithm applied twice may yield different MSTs depending on how it deals with tie breakers in edge weights.
To see why the former is true we need only reflect on the fact that both are inherently greedy algorithms. Further one can see Prim's algo
as Kruskal's in that each vertex is its own component initially and we are connecting components to a specific tree component at each turn.
If the above is confusing a proof is provided below:   
*Proof*   
Rather than showing directly that both Prim and Kruskal must converge towards the same MST in distinct edge weighted graph G we show
instead that G as described above must have only one distinct MST from which it follows that both algos converge to the same MST.
Suppose that we have a graph G with distinct edge weights with two distinct MST A and B. It must be the case then that there is an edge that 
is in one MST but not the other. Pick the cheapest amongst them and wlog suppose it is in A and label it a. 
Consider what would occur if we added a to B. By definition of a tree a cycle would be formed in B. 
Note that this cycle does not exist in A (as it is a tree) and hence there is an edge c in B that does not exist in A. Notice by the way
we picked a above that a < c so delete c and put a in B. The result is still a tree but whose sum of edge weights is less than the original
of B, a contradiction as we supposed that B was an MST.
