/*
Program to, given n numbers (possibly negative) numbers on a circle, find the maximum contiguous sum along an arc of the circle.
This also compares the solution time for the O(n) approach with that of the O(n^2)
*/

#include<vector>
#include<iostream>
#include<random>
#include<chrono>


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

int maxSubcircle1(std::vector<int> circle) {
	if (circle.size() == 1) return circle[0];
	//bruteforce every possibility

	//get ith partial sum, 0th element is 0
	std::vector<int> sum(circle.size() + 1);
	for (int i = 1; i < sum.size(); ++i) sum[i] = sum[i - 1] + circle[i - 1];

	int max_sum = INT_MIN;
	//try as if normal line not circle
	for (int i = 0; i < sum.size() - 1; ++i) {
		for (int j = i + 1; j < sum.size(); ++j) {
			int ijsum = sum[j] - sum[i];
			if (max_sum < ijsum) max_sum = ijsum;
		}
	}

	//now account for "looping" subarrays for circle
	int last = sum.size() - 1;
	int rsum;
	int lsum;
	int total;
	for (int i = 1; i < sum.size() - 2; ++i) {
		for (int j = last; j > i; --j) {
			rsum = sum[last] - sum[j];
			lsum = sum[i];
			total = lsum + rsum;
			if (max_sum < total) max_sum = total;
		}
	}

	return max_sum;
}

int main() {
	std::ios_base::sync_with_stdio(false);

	std::random_device r;
	std::mt19937 rng(r());
	std::uniform_int_distribution<int> dist(INT_MIN/10000, INT_MAX/10000);
	std::vector<int> circle(10000);
	for (int& x : circle) x = dist(r);

	std::cout << "The max sum with O(n) is: ";
	auto start = std::chrono::high_resolution_clock::now();
	std::cout << maxSubcircle(circle) << "\n";
	auto stop = std::chrono::high_resolution_clock::now();
	std::cout << "With time: " << std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count() << "\n";


	std::cout << "The max sum with O(n^2) is: ";
	start = std::chrono::high_resolution_clock::now();
	std::cout << maxSubcircle1(circle) << "\n";
	stop = std::chrono::high_resolution_clock::now();
	std::cout << "With time: " << std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count() << "\n";
}


