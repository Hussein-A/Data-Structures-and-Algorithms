4-1: The Grinch is given the job of partitioning 2n players into two teams of n players each. Each player has a numerical rating that measures
how good he/she isat the game. He seeks to divide the players as unfairly as possible, so as to create the biggest possible talent 
imbalance between team A and team B. Show how the Grinch can do the job inO(nlogn)time.  

***Solution:*** Sort the 2n players using your favourite *O(nlogn)* algorithm. Then divide the sorted list in two via the middle element.
