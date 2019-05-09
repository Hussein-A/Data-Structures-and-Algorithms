/*
The following is an implementation of Dijkstra's Algorithm for finding shortests paths from 
a starting vertex (root) on weighted graphs. This is based upon the algorithm as outlined in Skiena's Algorithm Design
Manual pg. 206 with O(n^2) time complexity.
*/

#include"graph.h"
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>

using namespace std;

void print_path(vector<int>& parent, int target) {
	string path; path += to_string(target) + " >- ";
	while (target != 0) {
		if (parent[target] == 0) path += to_string(0);
		else { path += to_string(parent[target]) + " >- "; }
		target = parent[target];
	}
	reverse(path.begin(), path.end());
	cout << path << "\n";
}

void dijkstra(graph& g, int start) {
	//initialize
	vector<int> distance(g.nvertices, INT_MAX); //holds distance to start
	vector<bool> intree(g.nvertices, false); //is in tree or not
	vector<int> parent(g.nvertices, -1); //parent of node in tree, no parent is -1

	distance[start] = 0; //distance from vertex to itself is 0
	int vertex = start;
	while (intree[vertex] == false) {
		intree[vertex] = true;
		//update distances to tree given added vertex
		for (edgenode edge : g.edges[vertex]) {
			if (distance[edge.neighbor] > distance[vertex] + edge.weight) {
				distance[edge.neighbor] = distance[vertex] + edge.weight;
				parent[edge.neighbor] = vertex;
			}
		}

		//choose next vertex based on shortest distance to start
		int dist = INT_MAX;
		for (int i = 0; i < g.nvertices; ++i) {
			if (!intree[i] && dist > distance[i]) {
				dist = distance[i];
				vertex = i;
			}
		}
	}
	print_path(parent, g.nvertices-1);
}

int main() {
	graph g;
	g.read_file("graphs.txt");
	//std::cout << "\n"; Remove comment delimiter if you want to see the graph description
	//g.print_graph();
	//std::cout << "\n";
	dijkstra(g, 0);
}