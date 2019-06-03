8-10. The integer partition takes a set of positive integers S = s1,...,sn and asks if there is a subset I∈S such that    
∑_(i∈I) si = ∑_(i!∈I) si. Let ∑_(i∈S) si = M. 
Give an O(nM) dynamic programming algorithm to solve the integer partition problem.   
.   
***Solution***
I have to admit I'm not sure I fully understand the problem, specifically "...a subset I∈S". I believe it is meant that I is a subset of
N = {1,2,3,4...,n} where n is the size of the subset. I will assume this is the case. That is, our task is to partition the set into two parts
such that the sum of the elements in each partition is equal to the other. But spoken like this the problem is a simple application of the work
we did in the previous problem (target sum (knapsack) 8-8). Indeed we seek a subset whose sum of its elements is exactly M/2. When we find this
subset the sum of all the elements of S not included in this subset must also equal M/2 since ∑_(i∈N) si = M as given in the problem. We will
return the indices of the elements of one of the subsets then the indices of the other. If I am
mistaken, either about the solution and/or the problem please do let me know.
