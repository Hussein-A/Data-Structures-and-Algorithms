#include<vector>
#include<random>
#include<iostream>
#include<algorithm>
#include<utility>





std::vector<int> test{ 7,5,1111,4,12, 45,63,11, 88 ,454, 66, 44, 5555, 12345, 77, -44, 5454, -787, 1122 };


//generates random pivot
template <typename Ran>
int rand_pivot(Ran first, Ran second) {
	//requires Random_access_iterator<Ran>()
	int max = second - first;
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist6(0, max); // distribution in range [1, 6]
	return dist6(rng);
}

template<typename Ran>
Ran partition(const Ran first, const Ran last) {
	int rand = rand_pivot(first, last);
	Ran pivot = first + rand;

	Ran first_high = first; //will mark the pos of the first element higher than pivot

	for (Ran iter = first; iter <= last; ++iter) {
		if (*iter < *pivot) {
			if (first_high == pivot) { std::swap(*iter, *first_high); pivot = iter; }
			else std::swap(*iter, *first_high);
			++first_high;
		}
	}
	std::swap(*pivot, *first_high);

	return first_high;
}

template <typename Ran>
void quick_sort(const Ran first, const Ran last) {
	//requires Random_access_iterator<Ran>()
	if (0 < last - first) {
		Ran pivot = partition(first, last); 	//randomized pivot, see partition

		if (first != pivot) {
			quick_sort(first, pivot - 1);
		}
		quick_sort(pivot + 1, last);
	}
}


int main() {
	quick_sort(test.begin(), test.end() - 1);
	for (int x : test) std::cout << x << " ";
}