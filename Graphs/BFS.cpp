#include<vector>
#include<queue>
#include<iostream>
#include<algorithm>
#include<list>
/*
BFS simplified with areas to process verticies and edges placed as comments.
Uses graph representation as adjacency list (vector<vector<int>>) rather than more complex graph data structures.
*/


enum class state {
	undiscovered, discovered, processed
};


void bfs(std::vector<std::vector<int>>& graph, std::vector<state> &states,  int start) {
	std::queue<int> to_do; to_do.push(start);
	std::vector<int> parent(graph.size()); parent[start] = -1; //root, no parent
	states[start] = state::discovered;

	while (!to_do.empty()) {
		int curr = to_do.front();
		//process vertex early here if needed
		for (int& neighbor : graph[curr]) {
			if (states[neighbor] == state::undiscovered) {
				to_do.push(neighbor);
				parent[neighbor] = curr;
				states[neighbor] = state::discovered;
				//process this edge here if needed
			}
		}

		//process vertex late here if needed
		states[curr] == state::processed;
		to_do.pop();
	}

	for (int i = 0; i < parent.size(); ++i) { std::cout << parent[i] << " is the parent of: " << i << "\n"; }

}





int main() {
	std::vector<std::vector<int>> graph{ {1,2,3}, {0}, {0,3}, {0, 2} };//undirected graph

	std::vector<state> states(graph.size(), state::undiscovered);
	auto it = find(states.begin(), states.end(), state::undiscovered);

	//find all connected components
	while (it != states.end()) {
		bfs(graph, states, std::distance(states.begin(), it));
		it = find(states.begin(), states.end(), state::undiscovered);
	}
}
