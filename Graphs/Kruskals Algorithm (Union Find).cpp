/*
The following is a modified version of Kruskal's algorithm as outlined in Skienna's Algorithm Design Manual, 2 ed. pg. 196.
This algorithm finds the minimum spanning tree of a given graph (of course assuming the graph is connected).
Version 2 with complexity O(mlogm), n vertices, m edges.
This version is using Union-Find Data structure. There is a second version that is NOT using that data structure.
*/


#include"Union-Find.h"
#include"graph.h"
#include<vector>
#include<iostream>
#include<algorithm>

bool same_component(set_union& s, int i, int j) {
	return s.find(i) == s.find(j);
}

bool comp(std::vector<int> x, std::vector<int> y) {
	return  x[0] < y[0];
}

void kruskalsAlgo_UnionFind(graph& g) {
	//initialize
	set_union components = set_union(g.nvertices);
	std::vector<std::vector<int>> weights;
	for (int i = 0; i < g.nvertices; ++i) {
		for (edgenode edge : g.edges[i]) {
			weights.push_back({ edge.weight, i, edge.neighbor });
		}
	}
	std::sort(weights.begin(), weights.end(), comp);

	for (auto edge : weights) {
		if (same_component(components, edge[1], edge[2])) continue;
		std::cout << "Connecting: " << edge[1] << " to " << edge[2] << "\n";
		components.union_merge(edge[1], edge[2]);
	}
}

int main() {
	graph g;
	g.read_file("graphs.txt");
	std::cout << "\n"; 
	g.print_graph(); 
	std::cout << "\n";
	kruskalsAlgo_UnionFind(g);
	/*
	//If you would like to use your own graph please remove the comment blocks, delete the above and use:
	graph g;
	g.read_graph();
	std::cout << "\n";
	g.print_graph();
	std::cout << "\n";
	kruskalsAlgo_UnionFind(g);
	*/
}