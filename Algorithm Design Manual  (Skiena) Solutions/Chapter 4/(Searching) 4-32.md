4-32. Consider the numerical 20 Questions game. In this game, Player 1 thinks of a number in the range 1 to n. 
Player 2 has to figure out this number by asking the fewest number of true/false questions. Assume that nobody cheats.  
1.  What is an optimal strategy if n in known?  
2.  What is a good strategy is n is not known?  
.  

***Solution***  
1. If n is known then this problem can be reworded into the following: Suppose you have a sorted array of size n whose elements are the 
first n consecutive integers (ie. A = {1,2,3,4,...,n}) and one number, X, in this array is picked by someone and you are meant to find this
number. What is a good algorithm that finds this number? We should immediately think of Binary Search. What would be the questions that BS
asks? Is X larger than the middle element? If true then X lies in the right half of our current range, find the mid of that range and
ask the same question. If false then X lies in the left half, again repeat the same steps as above. Just as in BS we ask at most logn questions
to find X.  
2. If we can find a suitable range for X to be in then we can just go back to the above and implement the translated Binary Search algorithm.
How can we effectively find such a range? We may ask is X larger than 10? If true we have found our range, implement above. If false
ask is X larger than 100? If true see above, if false ask is X larger than 1000? etc... Note this finds X based on the number of digits it has.
We could have also alternatively kept incrementing 2^i (ie. doubling our range) and asking the same questions. In a big O sense they are of
the same complexity due to log rules change of base.
