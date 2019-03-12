#include<vector>
#include<algorithm>
#include<list>
#include<queue>
#include<iostream>




template <typename T>
void merge(std::vector<T>& v, const int lower, const int mid, const int upper) {
	//requires Less_comparable<L,T>()

	std::queue<int> buffer1;
	std::queue<int> buffer2;
	for (int i = lower; i < mid; ++i) { buffer1.push(v[i]); }//initialize the queues
	for (int i = mid; i < upper; ++i) { buffer2.push(v[i]); }

	int i = lower;
	while (!(buffer1.empty() || buffer2.empty())) {
		if (buffer1.front() <= buffer2.front()) {
			v[i++] = buffer1.front(); buffer1.pop();
		}
		else {
			v[i++] = buffer2.front(); buffer2.pop();
		}
	}
	//copy over remaining elements
	while (!buffer1.empty()) { v[i++] = buffer1.front(); buffer1.pop(); }
	while (!buffer2.empty()) { v[i++] = buffer2.front(); buffer2.pop(); }

}


//vector version
template <typename T>
void merge_sort(std::vector<T>& v, const int lower, const int upper) {
	int mid;
	if (lower < upper) {
		mid = (lower + upper) / 2;
		merge_sort(v, lower, mid);
		merge_sort(v, mid + 1, upper);
		merge(v, lower, mid, upper);
	}
}

int main() {
	std::vector<int> test{ 100,5,6,7,8,1,3,55,7,55,10 };
	merge_sort(test, 0, test.size());
	for (int x : test) std::cout << x << " ";
}