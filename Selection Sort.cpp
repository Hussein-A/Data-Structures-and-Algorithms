#include<list>
#include<vector>
#include<iostream>

template <typename T>
void ssort(std::list<T>& items) {
	std::list<T> sorted;

	while (!items.empty()) {
		auto min_node = items.begin(); T min = *min_node;
		auto curr = items.begin();
		while (curr!= items.end()) {
			if (*curr < min) {min_node = curr; min = *min_node;}
			++curr;
		}
		//remove the minimum from the list and add it to the sorted list
		sorted.push_back(min);
		std::cout << min << "\n";
		items.erase(min_node);
	}
	items = sorted;
}


int selection_test() {
	std::list<int> test{ 9,8,5,3,2,6,7,11,14 };
	ssort(test);
	for (int x : test) {
		std::cout << x << " ";
	}
	return 0;
}