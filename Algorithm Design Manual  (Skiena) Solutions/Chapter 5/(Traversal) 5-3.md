4-3. Prove by induction that there is a unique path between any pair of vertices in a tree.  
.  
***Solution***  
1. We first prove the uniqueness. Suppose instead that two such paths existed P1 and P2 that connected x to y. It is not
hard to see that a cycle now exists, simply use P1 to go from x to y and P2 to go back (of course assuming our tree
is undirected).  
2. Next we proceed by induction on the depth of the tree. The case that we are depth 0 (1 vertex) and 1 (at most 3 vertices) is clear by definition
of a tree (or simply go through the possibilities). So suppose the statement holds for depths up to and including *n* we show it holds for
depth *n+1*. Consider arbitrary vertices x,y. If both x and y lay within the tree of depth *n*  then we apply our induction
hypothesis to achieve the result. Now suppose that at least one of the two vertices, say x, are of depth n+1 (ie. leaves) note that since we are
in a tree x can only have 1 edge connecting it to the rest of the tree, moreover this edge connects it to its parent which is of depth *n*.
Hence any such path must go through its parent so we may, without loss of generality, simply consider a path from its parent to the target
vertex y. Again if y is of depth at most *n* then we are done by the IH else apply the same argument as above to consider only the parent of
y which allows us to apply the IH.
