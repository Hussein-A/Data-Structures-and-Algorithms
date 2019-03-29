4-3.Take a sequence of 2nreal numbers as input. Design anO(nlogn) algorithm thatpartitions the numbers intonpairs, with the property that the partition minimizesthe maximum sum of a pair. For example, say we are given the numbers (1,3,5,9).The possible partitions are ((1,3),(5,9)), ((1,5),(3,9)), and ((1,9),(3,5)). The pairsums for these partitions are (4,14), (6,12), and (10,8). Thus the third partition has 10 as its maximum sum, which is the minimum over the three partitions.  
.  
***Solution***
Sort the numbers using your favourite *O(nlogn)* algorithm. Pair the last element with the first, the second last with the second, etc.
