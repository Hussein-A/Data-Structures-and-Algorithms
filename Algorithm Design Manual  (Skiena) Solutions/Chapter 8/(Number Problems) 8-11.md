8-11. Assume that there are n numbers (some possibly negative) on a circle, and we wish to find the maximum contiguous sum along an arc of 
the circle. Give an efficient algorithm for solving this problem.   
.   
***Solution***   
The main difficulty in this problem is that the elements are not strictly ordered and given to us, as they lie on a circle. This makes 
the regular DP approach difficult. However we may still use the previous ideas of finding the max contigous subarray sum when we notice the following.
When we snip the circle's arc at a single point and form a line we get, to us, a regular array. Now the arc when projected onto this "line" can have two
of forms: either it is a regular interval of the array, in which case we apply our regular O(n) DP algo to tackle it, or the arc "wraps" 
around the aray. That is, for example:     
1,2,3], -10, -10, [4,5,6  If we were to "wrap" around
we must avoid the worst cont subarray. In essence we are slicing out this bad cont subarray. How can we identify this?
Notice that this is actually the reverse problem of finding the max cont subarray in that now we are finding the min cont subarray.
All we need to do is multiply the values of the array (or "line") by -1 and reapply our standard O(n) algo for finding the max cont subarray.
Then we subtract this value from the total sum of the entire array (ie. "slicing" out the bad subarray) then we compare this value
to the one we got when we assumed there was no wrapping around of the original "line" subarray. We return whichever is larger. This is O(n)
time as we are only applying the regular O(n) algo twice.   
If you are curious how this compares to the bruteforce O(n^2) implementation a comparison can be found [here](https://github.com/Hussein-A/Data-Structures-and-Algorithms/blob/master/Dynamic%20Programming/Max%20Circular%20Subarray%20Sum.cpp)
```c++
#include<vector>
#include<iostream>


int max_interval_val(std::vector<int>& line){
	//regular O(n) algo to find max contiguous subarray
	std::vector<int> max_int(line.size(), line[0]);

	for (int i = 1; i < line.size(); ++i) {
		max_int[i] = max_int[i - 1] < 0 ? line[i] : max_int[i - 1] + line[i];
	}

	int max = INT_MIN;
	for (int x : max_int) {
		if (max < x) max = x;
	}
	return max;
}

int maxSubcircle(std::vector<int> circle) {
	int total = 0;
	int max_int = max_interval_val(circle);
	for (int& val : circle) {
		total += val; 
		val *= -1;
	}

	//find the worst contigous sum (which is the best if the circle vals were negative)
	int worst_interval_val = max_interval_val(circle);
	int max_loop = total - (-worst_interval_val);

	if (max_loop > max_int) return max_loop;
	else return max_int;
}
```
