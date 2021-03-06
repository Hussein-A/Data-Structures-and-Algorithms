#include<vector>
#include<cmath>
#include<iostream>
#include<algorithm>


//implementation of (min)heap for integers, using array representation
//position of the children of k are 2*k+1 and 2*k+2

	int parent(std::vector<int>& pq, const int pos) { 
		if (pos == 0) return -1;
		else if (pos == 1) return 0;
		else return ceil(((double)pos-2) / 2); 
	}
	int left_child_pos(std::vector<int>& pq, const int pos) {
		int child_pos = 2 * pos + 1;
		if (child_pos >= (int)pq.size()) return -1;
		else return child_pos;
	}
	int right_child_pos(std::vector<int>& pq, const int pos) {
		int child_pos = 2 * pos + 2;
		if (child_pos >= (int)pq.size()) return -1;
		else return child_pos;
	}



void bubble_up(std::vector<int>& pq, const int pos) {
	int parent_pos = parent(pq, pos);
	if (parent_pos == -1) return;
	if (pq[parent_pos] > pq[pos]) {
		std::swap(pq[parent_pos], pq[pos]);
		bubble_up(pq, parent_pos);
	}
}

void bubble_down(std::vector<int>& pq, const int pos) {
	int left = left_child_pos(pq, pos);
	int right = right_child_pos(pq, pos);

	if (left == -1 && right == -1) return;
	else {
		int min_pos;
		if (left != -1 && right != -1) {
			min_pos = pq.at(left) < pq.at(right) ? left : right;
			if (pq[pos] > pq[min_pos]) {
				std::swap(pq[min_pos], pq[pos]);
				bubble_down(pq, min_pos);
			}
		}
		else min_pos = left != -1 ? left : right;
		if (pq[pos] > pq[min_pos]) {
			std::swap(pq[min_pos], pq[pos]);
			bubble_down(pq, min_pos);
		}
	}
}

void insert(std::vector<int>& pq, int n) {
	pq.push_back(n);
	bubble_up(pq, pq.size()-1);
}

void delete_min(std::vector<int>& pq) {
	int last = pq.size() - 1;
	std::swap(pq[0], pq[last]);
	pq.erase(pq.end() - 1);
	bubble_down(pq, 0);
}

int get_min(std::vector<int>& pq) {
	if (pq.size() <= 0) std::cout << "Warning no elements in queue!";
	else {
		int temp = pq[0];
		delete_min(pq);
		return temp;
	}
}

std::vector<int> make_heap(std::vector<int>& v) {
	//utilize the bubble down procedure of creating a heap by
	//bubble down from the end, rather than insert one by one.
	std::vector<int> priority_queue = v;
	int last = priority_queue.size() - 1;
	for (int i = last; i >= 0; --i) {
		bubble_down(priority_queue, i);
	}
	return priority_queue;
}

void heapsort(std::vector<int>& v) {
	std::vector<int> priority_queue = make_heap(v);
	for (int i = 0; i < v.size(); ++i) {v[i] = get_min(priority_queue);}
}



int main() {
	std::vector<int> test{ 1492,1783,1804,1918,2001,1865,1941,1776,1945,1963, 2111,77, -11 };
	heapsort(test);

	for (int x : test) std::cout << x << "\n";
}
