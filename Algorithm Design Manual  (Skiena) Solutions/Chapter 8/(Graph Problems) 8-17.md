8-17. Consider the same situation as the previous problem. We have a city whose streets are defined by an X×Y grid. We are interested in 
walking from the upper left-hand corner of the grid to the lower right-hand corner. We are given an X×Y matrix BAD, 
where BAD[i,j] = “yes” if and only if the intersection between streets i and j is somewhere we want to avoid. 
If there were no bad neighborhoods to contend with, the shortest path across the grid would have length (X−1) + (Y−1) blocks, 
and indeed there would be many such paths across the grid. 
Each path would consist of only rightward and downward moves. Give an algorithm that 
takes the array BAD and returns the number of safe paths of length X+Y−2. For full credit, your algorithm must run in O(XY).   
.   
***Solution***   
As the problem states any such path to the lower right must be of length (X+Y-2) and hence we are only allowed rightward or downward moves.
Suppose there were no bad neighbourhoods, how many paths would there be? Well at each step we must decide where to go right or down and we
have X+Y-2 steps in total. We ask where can I place my right steps (total of Y-1) on this array of length X+Y-2? That is simply 
X+Y-2 choose Y-1. How did we solve this problem of finding the number of combinations? By using DP. Indeed, now we create an XY matrix 
in each of whose box we will ask: how many ways are there to get to me (assuming only right and down moves) from the upper left corner?
It's the number of ways to get to the box on top of me (if it exists) + the number of ways to get to the box to the left of me.   
Ie. C[i][j] = C[i][j-1] + C[i-1][j]. This is a similar recursion to the one we used for the binomial coefficients calculator [here](https://github.com/Hussein-A/Data-Structures-and-Algorithms/blob/master/Dynamic%20Programming/Binomial%20Coefficients%20Calculator.cpp)
From which we can see that it takes O(XY) time as required.
