6-6. Suppose we are given the minimum spanning tree T of a given graph G (with n vertices and m edges) and a new edge e=(u, v) of weight w 
that we will add to G. Give an efficient algorithm to find the minimum spanning tree of the graph G+e. Your algorithm should run in O(n) 
time to receive full credit.   
.   
***Solution***
Take the edge e and add it to T. Since T was a tree we now have a cycle C in T. In order to return T to a tree we must delete one edge
from this cycle, the question is which edge? Our best bet for returning towards an MST is to delete the most expensive edge in the cycle (
with new graph labeled T_2).   
.   
For this it is clear we must go through each edge in this cycle. How many edges is that? Well
how many edges did T possess in the first place? Since T is a tree it is a fact that it must have had n-1 edges (see pg. 62 of Intro. to graph theory
, 5ed., Robin J. Wilson for a proof) and since we added an edge it now has n edges. In the worst case the cycle traverses over all of the 
n edges and hence we must check each one (this is where the O(n) cost comes from). Now our last task is to show that after deletion of the 
most expensive edge in the cycle we get an MST of G. A full proof is rather laborious so we provide here a sketch.   
.   
In the case that we deleted e then we simply return to T and no cheaper spanning tree could exist otherwise T would not have been an 
MST in the first place. Now suppose we deleted another edge that isn't e in our algo above and that there is a cheaper spanning tree S.
Either S contains the newly added edge e or it doesnt. If it doesn't then it follows that T could not have been a MST originally for in the end
we have a new tree S that is an MST of G (not G+e since it doesn't use that edge) and is cheaper than T. So S must contain the edge e as does
T_2. Note that in an MST the deletion of any edge results in two new MSTs (on n_1, n_2 vertices respectively) of the induced subgraphs on n_1 and n_2
vertices of G respectively. A simple argument by contradiction showing that the original MST couldn't have been an MST otherwise. Armed with
this fact deleting the edge e in both T_2 and S and comparing the sum weight from their respective components yields that if S now contains
a component cheaper than its respective component in T_2 then T could not have been an MST in the first place since all the edges in the
connected component in question in T_2 are the exact same as in T. Hence the resultant tree is an MST.
