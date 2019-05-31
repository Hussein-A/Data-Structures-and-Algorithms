8-5. Let P1, P2,..., Pn be n programs to be stored on a disk with capacity D megabytes. Program Pi requires si megabytes of storage. 
We cannot store them all because D<sum^n_i=1 = si   
(a)  Does a greedy algorithm that selects programs in order of nondecreasing si maximize the number of programs held on the disk? 
Prove or give a counter-example.   
(b)  Does a greedy algorithm that selects programs in order of nonincreasing order si use as much of the capacity of the disk as possible? 
Prove or give a counter-example.   
.   
***Solution***   
* a) Yes. If not it must be the case that we are replacing at least one of the programs with weight s_i with a program of weight s_j where
s_i <= s_j. But this clearly will require removing at least one (including P_i) program negating any gain we could get by swapping Pi for Pj.   
* b) No. Consider the case of programs with weight {5,4,2} and a disk with capacity 6. The optimal choice is programs 2 and 3 to fully
use the disk's capacity yet the greedy algorithm can only put program 1 in with a space of 1 left over.
