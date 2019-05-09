#include<vector>
#include<iostream>

using namespace std;

enum class state {
	undiscovered = 0, discovered, processed
};

void DFS(const vector<vector<int>>& graph, int start, vector<state>& states) {
	states[start] = state::discovered;
	//process vertex if required

	for (int neighbor : graph[start]) {
		if (states[neighbor] == state::undiscovered) {
			DFS(graph, neighbor, states);
		}
	}

	states[start] = state::processed;
	cout << " " << start << " ";
}

int main() {
	vector<vector<int>> graph = { {1,2}, {0, 3, 4}, {0,4,5}, {1}, {1,2,5}, {4,2} };
	vector<state> states(graph.size());
	DFS(graph, 0, states);
}