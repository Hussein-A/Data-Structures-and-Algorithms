/*
Program to solve 4.1 of CTCI. 
Given a directed graph, design an algorithm to find out whether there is a
route between two nodes.
*/

#include<vector>
#include<list>
#include<queue>


struct treeNode {
	int val;
	treeNode* left{ nullptr };
	treeNode* right{ nullptr };
};


bool is_path(const std::vector<std::list<int>>& graph, int start, int target) {
	if (graph.empty()) return true;
	else if (start >= graph.size() || start < 0 || target >= graph.size() || target < 0)
		return false;

	std::vector<bool> found(graph.size(), false);
	found[start] = true;
	std::queue<int> to_search;
	to_search.push(start);	

	while (!to_search.empty()) {
		int node = to_search.front();
		to_search.pop();

		if (node == target) return true;

		for (int neighbor : graph[node]) {
			if (!found[neighbor]) {
				to_search.push(neighbor);
				found[neighbor] = true;
			}
		}
	}

	return false;
}


int main() {
	std::vector<std::list<int>> graph(5);
	graph[0] = { 1,2 };
	graph[1] = { 2,4 };
	graph[2] = { 4,3 };

	return is_path(graph, 4, 3);

}
