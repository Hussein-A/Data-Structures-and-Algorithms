6-7. Let T be a minimum spanning tree of a weighted graph G. Construct a new graph G′ by adding a weight of k to every edge of G.    
(a) Do the edges of T form a minimum spanning tree of G′? Prove the statement or give a counter example.   
(b) Let P={s,...,t} describe a shortest weighted path between vertices s and t of a weighted graph G. Construct a new graph G′ by 
adding a weight of k to every edge of G. Does P describe a shortest path from s to t in G′? Prove the statement or give a counterexample.   
.   
***Solution***   
* a) Yes it does. To see this let's see how Prim's algorithm would proceed at one stage before the addition and after. Suppose at stage t
Prim's added edge e_i from among the entire list of edges it could've added {e_1,...,e_i,...,e_m}, ie. w(e_i) <= w(e_j) for all j by the greedy
nature of Prim's algo where w() returns weight. But then since we are adding k to each we get w(e_i)+k <= w(e_j)+k for all j and so that same edge
e_i will be chosen again. Since the iteration was arbitrary it follows that there no change in the choice of edge for Prim's algo and since
Prim's algo produces a MST it follows that T is still a MST. (Note this assumes that Prim's could've produced T in the first place,
this is true if the edge weights of G are distinct since there is the unique MST, otherwise simply randomizing which edge gets picked
when there is a tie yields that at some run of Prim's we will build the original T).
* b) No (if k is positive). Recall one of our earlier graphs 1-2 (1), 2-3 (1), 3-4 (1), 4-1 (3). The MST formed is 1-2-3-4 with total sum 3. After adding
1 to each edge then that path of 1-2-3-4 is no longer the shortest path from 1 to 4 (a cost of 6) instead the direct edge 4-1 at a cost of
4 is.
