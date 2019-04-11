5-5. Give a linear algorithm to compute the chromatic number of graphs where each vertex has degree at most 2. 
Must such graphs be bipartite?  
.  
***Solution***  
To the latter question the answer is no, the counter example is the a simple cycle on three vertices (ie. a triangle).  
For the linear algorithm we recall a graph theorem that states if G is a simple grapth with largest vertex-degree k then G is k+1 colourable.
For a proof please see page 102 of Introduction to Graph Theory by Robin J. Wilson (Thm 5.1). A hint of the above is to proceed by induction.
Now armed with this hint we recall one of the uses of BFS was to test whether a graph G is 2-colourable. If not then the graph must be 3-colourable by the 
above (of course the case that G is only 1 vertex is trivially 1 colour).  Since BFS is linear time then so is this algorithm.  
.  
An alternate method (without proof) would be to again use BFS but this time modify its two-colouring implementation as follows: if you come across a cross
edge pick a colour that isn't of your parent and different from your neighbour. This is linear time.
