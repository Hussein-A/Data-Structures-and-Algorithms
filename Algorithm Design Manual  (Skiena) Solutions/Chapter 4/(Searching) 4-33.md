4-34. Suppose that you are given a sorted sequence of *distinct* integers {a1,a2,...,an}. 
Give an O(lgn) algorithm to determine whether there exists an index, i, such as a_i=i. 
For example, in{−10,−3,3,5,7},a3=3. In{2,3,4,5,6,7}, there is no such i.  
.  
***Solution***  
The O(lgn) and the sorted nature of the array in the question ought to give us a pretty big hint as to how to approach this problem; 
we ought to consider Binary Search. Our only consideration, as usual, is to provide conditions for when to stop (ie. when we've found
what we're looking for) and how to decide which half to recur on.  
.  
The former question is simple as we need only check that A[i] == i (with the added
usual of the left side of the range < right side). For
the latter question I claim that if (A[mid]>mid) then we must recur on the bottom half (left) and if (A[mid] < mid) then we recur
on the top half (right). To see why this logic holds consider the former case since we have A[mid]>mid and we are increasing with *distinct*
elements in our array it is impossible that at somepoint after mid we have A[i]== i. This is since A[mid+1] > A[mid+1] then this implies that A[mid+2]>mid+2 and hence the element, if it exists at all, cannot be in the right side.  
Simply note that we are increasing by at least 1 each time to the right due to the sorted and *distinct* elements of the array, but the array indexing
only increases by 1 each time you move to the right hence they will never meet. This however does not mean that in the lower half the index
and the element did not meet hence recurring on the bottom half. Similar reasoning also applies when considering the other case of
A[mid]<mid and why it must, if it exists, rest in the top half (right).
