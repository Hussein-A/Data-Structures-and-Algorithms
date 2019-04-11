5-4. Prove that in a breadth-first search on a undirected graph G,
every edge is either a tree edge or a cross edge, where x is neither an ancestor nor descendant of y, in cross edge (x, y).  
.  
***Solution***  
Note the classification of an edge occurs when we first come across it and cannot be reclassified later on (otherwise every tree edge
is a backedge when viewing it from the point of view of the child, etc.) So suppose that not and that we have come across an undiscovered edge and it is a
backedge, ie. connecting to either an ancestor or to vertex in a level above us. I claim that this is impossible as since this edge
connects to a vertex above us by the nature of BFS we must have processed all the edges of that vertex first before moving on to the 
later levels. This means that the offending vertex must have been immediately labeled as a child of the above vertex. Hence every edge
must be of the types listed above.
