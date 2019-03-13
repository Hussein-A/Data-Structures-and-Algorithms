#include<vector>
#include<algorithm>
#include<iostream>


std::vector<int> test{ 7,5,1111,4,12, 45,63, 11, 88 ,454, 66, 44, 5555, 12345, 77, -44, 5454, -787, 1122,11,11,11,11,11, 11 };

template <typename T>
void print_range(std::vector<T>& v, const int& first, const int& last) {
	for (int i = first; i <= last; ++i) std::cout << v.at(i) << " ";
}

template<typename T>
// requires Equal_comparable<T>()
bool BS(std::vector<T>& v, int low, int high, T target) {
	int mid;
	if (low > high) return false;
	else {
		mid = low + (high - low) / 2;
		if (v[mid] == target) {return true;}
		else if (v[mid] < target) {return BS(v, mid + 1, high, target);}
		else {return BS(v, low, mid - 1, target);}
	}
}

template <typename T>
// requires Equal_comparable<T>()
int BScount_left(std::vector<T>& v, int low, int high, T target) {
	int mid;
	if (low > high) return low;
	else {
		mid = low + (high - low) / 2;
		if (v[mid] < target) { return BScount_left(v, mid+1, high, target); }
		else { return BScount_left(v, low, mid-1, target); }
	}
}

template <typename T>
// requires Equal_comparable<T>()
int BScount_right(std::vector<T>& v, int low, int high, T target) {
	int mid;
	if (low > high) return low;
	else {
		mid = low + (high - low) / 2;
		if (v[mid] > target) { return BScount_right(v, low, mid-1, target); }
		else { return BScount_right(v, mid+1, high, target); }
	}
}

template <typename T>
	//requires Random_access_iterator<Ran>()
	// requires Equal_comparable<T>()
	// requires Less_comparable<T>():
int BScount(std::vector<T>& v, int low, int high, T target) {
	if (!BS(v, low, high, target)) return 0;//double check to ensure target is even there

	int lower = BScount_left(v, low, high, target);
	int upper = BScount_right(v, low, high, target);
	return upper - lower;

}

int main() {
	std::sort(test.begin(), test.end());
	for (int elem : test) {
		std::cout << "The count of element: " << elem << " = " << BScount(test, 0, (int)test.size() - 1, elem) << "\n";
	}
}