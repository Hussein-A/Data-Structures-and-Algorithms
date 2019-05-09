//the following is a modified version of the prim's algorithm as outlined in Skienna's Algorithm Design Manual, 2 ed. pg. 195.

#include"graph.h"
#include<iostream>
#include<algorithm>

using namespace std;

void primsAlgo(graph& g, int start) {
	//initialize
	int sum = 0;
	vector<bool> intree(g.nvertices, false); 
	vector<int> distance(g.nvertices, INT_MAX);
	vector<int> parent(g.nvertices,-1);
	distance[start] = 0;
	int curr = start;

	while (!intree[curr]) {
		intree[curr] = true;
		if (parent[curr] != -1) {// for user verification, can be removed
			cout << "Connecting " << parent[curr] << " -> " << curr << "\n";
		}
		for (edgenode edge : g.edges[curr]) {
			if (!intree[edge.neighbor] && distance[edge.neighbor] > edge.weight) {
				distance[edge.neighbor] = edge.weight;
				parent[edge.neighbor] = curr;
			}
		}

		int dist = INT_MAX;
		for (int i = 0; i < g.nvertices; ++i) {
			if (!intree[i] && dist > distance[i]) {
				dist = distance[i];
				curr = i;
			}
		}
	}
}

int main() {
	graph g;
	g.read_graph();
	g.print_graph();
	primsAlgo(g, 0);

}