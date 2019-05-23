/*
The purpose of this program is to implement a random sampling heuristic on the specific 
domain of the Travelling Salesman Problem (TSP). Note this assumes the graph given is a complete 
graph on n vertices. We rely on a custom graph data structure as found in graph.cpp and graph.h in the graphs folder of the DSA repo.
*/

#include"graph.h"
#include<iostream>
#include<list>
#include<random>
#include<vector>

using namespace std;
random_device r;
mt19937 rng(r());


int path_cost(const vector<int>& path, const adjmatrix& g) {
	//this function is the main reason for using an adj matrix representation of the graph.
	//With this we can have constant time edge weight access for a pair of vertices.
	int cost{ 0 };

	for (int i = 1; i < g.nvertices; ++i) {
		int parent = path[i-1];
		int vertex = path[i];
		cost += g.edges[parent][vertex];
	}
	//must add edge connecting end to start again
	cost += g.edges[path[g.nvertices - 1]][0];

	return cost;
}

void rand_path(vector<int>& path, const graph& g) {
	uniform_int_distribution<int> dist(0, g.nvertices - 2);
	list<int> candidates(g.nvertices-1);
	int j = 1;
	for (auto it = candidates.begin(); it != candidates.end(); ++it) *it = j++;

	//generate path from unchosen candidates
	j = 1; 
	for (auto it = path.begin()+1; it != path.end(); ++it) {
		int adv = dist(rng);
		auto iter = candidates.begin(); advance(iter, adv);
		int next = *iter;
		*it = next;
		if (j == g.nvertices - 1) continue; //to prevent a>b in line below for uniform dist
		dist.param(uniform_int_distribution<int>::param_type(0, g.nvertices - 2 - j)); ++j;
		candidates.erase(iter);
	}
}

vector<int> random_sampling_TSP(graph& g, int iterations) {
	//sort_graph_edges(g);
	vector<int> solution(g.nvertices, 0); //note we always start the path with the first vertex, 0 (since the path is a cycle and goes through all vertices anyway)
	vector<int> candidate = solution;
	adjmatrix gmat = list_to_matrix(g); //for quick path cost computation
	int min_cost{ INT_MAX };
	int cost{ 0 };

	while (iterations > 0) {
		rand_path(candidate, g);
		cost = path_cost(candidate, gmat);
		if (cost < min_cost) {
			solution = candidate;
			min_cost = cost;
		}
		--iterations;
	}
	cout << "Most optimal path found so far is: \n";
	for (int i = 0; i < solution.size(); ++i) cout << solution[i] << " ";
	cout << "\nCost is: " << path_cost(solution, gmat) << "\n";
	return solution;
}

int main() {
	ios_base::sync_with_stdio(false);
	graph g;
	g.read_file("graphs.txt"); //complete undirected graph on 40 vertices with max edge weight 10 (strictly positive edge weights

	random_sampling_TSP(g, 100000);
	

	/*
	//Use this to generate your own random complete graph.
	//Do remember that in order for the graph to be complete the number of edges should be nvertices*(nvertices-1)/2
	
	//int nvertices, int nedges, int max_weight, bool directed
	g.rand_graph(40, 780, 500, false);
	g.save_graph("graphs.txt");
	*/
}