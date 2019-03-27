4-4. Assume that we are given n pairs of items as input, where the first item is a number and the second item is one of three colors (red, blue, or yellow). Furtherassume that the items are sorted by number. Give anO(n) algorithm to sort the items by color (all reds before all blues before all yellows) such that the numbers for identical colors stay sorted.  
.  
***Solution***  
Construct three "buckets" (ie. lists) representing each colour in the specified order, red, blue, yellow. As you go through the n pairs
in numerical order add the pair (push_back) to the correct coloured "bucket" according to their colour. Once finished connect the tail of the
red bucket to the head of the blue bucket, the tail of the new, latter list to the head of the yellow list to get a new list that is sorted by
colour and where within the colour subsets they are sorted numerically. Where the latter is due to the fact that the n pairs of items as input
were already numerically sorted for us and we are traversing and adding according to that order.

*Code*  
```
list<pair> red;
list<pair> blue;
list<pair> yellow;
for (pair : input){
    if (pair.colour == red) red.push_back(pair);
    else if (pair.colour == blue) blue.push_back(pair);
    else yellow.push_back(pair);
}
//concatenate  
for (pair : blue) red.push_back(pair);
for (pair: yellow) red.push_back(pair);

return red;
```
