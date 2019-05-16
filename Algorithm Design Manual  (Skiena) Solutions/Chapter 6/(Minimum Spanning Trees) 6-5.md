6-5. Does either Prim’s and Kruskal’s algorithm work if there are negative edge weights? Explain why or why not.   
.   
***Solution***   
Yes, indeed careful reflection over the description of each algo will yield that in each case when we consider which edge to add next
to the tree (in Kruskal's case which edge to connect two components) we only care that the edge that we choose is the *least* edge that
satisfies our conditions. Not that it is non-negative. The code for both algos is provided in the DSA repo under the graphs subfolder to verify
for yourself (or see Skiena Algorithm Design Manual, 2ed. pg 195, pg 198 for implementations of Prim and Kruskal respectively).
