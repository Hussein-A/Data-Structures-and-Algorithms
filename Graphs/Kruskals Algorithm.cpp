/*
The following is a modified version of Kruskal's algorithm as outlined in Skienna's Algorithm Design Manual, 2 ed. pg. 196.
This algorithm finds the minimum spanning tree of a given graph (of course assuming the graph is connected).
Version 1 with complexity O(nm), n vertices, m edges.
This version is NOT using Union-Find Data structure. There is a second version using that data structure.
*/

#include"graph.h"
#include<iostream>
#include<algorithm>

using namespace std;

void mergeComponents(vector<int>& component, int x, int y) {
	int temp = component[y];
	for (int& comp : component) {
		if (comp == temp) comp = component[x];
	}
}

bool inComponent(vector<int>& component, int x, int y) {
	return component[x] == component[y];
}



bool comp(vector<int> x, vector<int> y) {
	return  x[0] < y[0];
}

void kruskalsAlgo(graph& g) {
	//initiailize
	vector<int> component(g.nvertices);
	for (int i = 0; i < g.nvertices; ++i) component[i] = i; //set all to different components.

	vector <vector<int>> weights; //keep track of which vertices it connects through vector of size 3
	for (int vertex = 0; vertex < g.nvertices; ++vertex) {
		for (edgenode edge : g.edges[vertex]) {
			weights.push_back({ edge.weight, vertex, edge.neighbor });
		}
	}
	sort(weights.begin(), weights.end(), comp);

	for (auto edge_pair : weights) {
		if (!inComponent(component, edge_pair[1], edge_pair[2])) {
			mergeComponents(component, edge_pair[1], edge_pair[2]);
			cout << "connecting " << edge_pair[1] << " to " << edge_pair[2] << "\n";
		}
	}

}

int main() {
	graph g;
	g.read_file("graphs.txt");
	std::cout << "\n";
	g.print_graph();
	std::cout << "\n";
	kruskalsAlgo(g);

	/*
	//If you would like to use your own graph please remove the comment blocks and use:
	graph g;
	g.read_graph();
	std::cout << "\n";
	g.print_graph();
	std::cout << "\n";
	kruskalsAlgo(g);
	*/
}