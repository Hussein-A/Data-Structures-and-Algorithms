Your job is to arrange n ill-behaved children in a straight line, facing front. You are given a list of m statements of the form “i hates j”. If i hates j, 
then you do not want to put i somewhere behind j, because then i is capable of throwing something at j.
(a)  Give an algorithm that orders the line, (or says that it is not possible) in O(m+n) time.
(b)  Suppose instead you want to arrange the children in rows such that if i hates j, then i must be in a lower numbered row than j. Give an efficient algorithm to find 
the minimum number of rows needed, if it is possible.   
.   
***Solution***   
* a) Construct a directed graph on n vertices where each vertex represents a child. If i hates j construct a directed edge from i to j (i -> j ).
This forms a directed graph. Now conduct a depth first search of the graph as usual in search of a topological sort. If we ever come across a backedge
(ie. we come across an edge that goes to an already discovered ancestor) then exit and return false since the graph contains a cycle and a directed
graph contains a topological sort IFF it is acyclic. This runs in O(n+m) time as per DFS.   
* b) This one is a little bit trickier. One idea might be that we need as many rows as the largest number of kids that any one kid will hate. But 
we may consider the case that there is only one kid that hates everyone else and yet all the other children do not hate anyone at all. Simply place the
angry child at the very front and all the other kids in a single row behind him giving us two rows instead of degree(angry child vertex).
Instead note that since we are in a DAG (conduct a DFS to verify this before hand) we must have vertices of degree 0 else this graph is not acyclic.
(prove so by induction and note that if there existed a deadend vertex it could not be of degree >= 1). Places all vertices of degree 0 in the furthest
row in the rear now delete these vertices. Since we are removing edges for the other vertices not of degree 0 we have now generated a new set
of degree 0 vertices, do the same and place these new ones infront of the previous row, etc. The time cost of this algorithm will depend strongly 
on whether or not we have set aside space to keep track of vertex degrees, how much time it takes to update vertex degrees after a round of
deleting 0 degree vertices, finding the 0 degree vertices, etc.
