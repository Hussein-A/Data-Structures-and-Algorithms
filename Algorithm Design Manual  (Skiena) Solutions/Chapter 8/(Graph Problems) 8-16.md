 8-16. Consider a city whose streets are defined by an X×Y grid. We are interested in walking from the upper left-hand corner of the grid to 
the lower right-hand corner. Unfortunately, the city has bad neighborhoods, whose intersections we do not want to walk in. 
We are given an X×Y matrix BAD, where BAD[i,j] = “yes” if and only if the intersection between streets i and j is in a neighborhood to avoid.   

* (a) Give an example of the contents of BAD such that there is no path across the grid avoiding bad neighborhoods.   
* (b) Give an O(XY) algorithm to find a path across the grid that avoids bad neighborhoods.   
* (c) Give an O(XY) algorithm to find the shortest path across the grid that avoids bad neighborhoods. 
You may assume that all blocks are of equal length. For partial credit, give an O(X2Y2) algorithm.   
.   
***Solution***
 
a) <pre>no - yes 
      |      |
yes - no
</pre>   
b) Implement a BFS first search on the graph starting from the first vertex (upper left hand corner 0,0) and only add adjacent vertices to
the queue if and only if it is not labeled BAD. This runs in O(V + E) time as it is a BFS. Now we only need to check how many edges there can be
in a XY grid (V == XY here clearly). But this is a simple task as we may count the "horizontal" edges in each row then add to that the "vertical"
edges in each column. Doing this summation yields the total number of edges to be 2XY-X-Y, that is our algorithm runs in O(XY) time as required.   
.   
c) Since our graph is unweighted, BFS finds the shortest such path as described above in O(XY) time.
