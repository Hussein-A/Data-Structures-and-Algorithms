#include<algorithm>
#include<vector>
#include<iostream>

using std::cout;

template <typename T>
void isort(std::vector<T>& v) {
	//requires Less_comparable<L,T>()
	
	//find min and set to first position
	auto min = v.begin();
	auto curr = v.begin();
	while (curr != v.end()) {
		if (*curr < *min) { min = curr; }
		++curr;
	}
	std::iter_swap(v.begin(), min);

	//now start insertion sort
	for (int i = 1; i < (int)v.size(); ++i) {
		int j = i;
		while (v[j] < v[j - 1]) {
			int temp = v[j-1]; //swap
			v[j - 1] = v[j];
			v[j] = temp;
			--j;
		}
	}

}

int _isort() {
	std::vector<int> test {9, 8, 7, 6, 5, 4, 3, 2, 1};
	isort(test);
	for (int x : test) cout << x << " ";

	return 0;
}