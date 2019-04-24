/*
Iterative version of DFS using an explicit stack rather than the call stack.
Do note that this does not necessarily traverse the graph the same way the recursive DFS does since it jumps to the last
added child of a parent node. A simple way to fix this is to reverse the stack.
*/

#include<vector>
#include<stack>
#include<iostream>

using namespace std;

enum class state {
	undiscovered = 0, discovered, processed
};

void Iter_DFS(const vector<vector<int>>& graph, int start) {
	if (graph.size() == 0) return;
	
	//initialize
	vector<state> states(graph.size());
	stack<int> to_visit{};
	to_visit.push(start);

	while (!to_visit.empty()) {
		int node = to_visit.top(); to_visit.pop();
		if (states[node] != state::undiscovered) continue;
		states[node] = state::discovered;

		for (int neighbor : graph[node]) {
			if (states[neighbor] == state::undiscovered) {
				to_visit.push(neighbor);
			}
		}
		cout << " " << node << " ";
	}
}

int main() {
	vector<vector<int>> graph = 
	{ {1,3,2}, {0,2,3}, {1,0,2}, {0,1,3} };
	//{ {1,2}, {0, 3, 4}, {0,4,5}, {1}, {1,2,5}, {4,2} };
	Iter_DFS(graph, 0);
}