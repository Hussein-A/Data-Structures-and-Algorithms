/*
The purpose of this program is to implement a local search heuristic on the specific
domain of the Travelling Salesman Problem (TSP). Specifically this is implementing
a hillclimbing algorithm as described in Skiena Algorithm Design Manual, 2ed. pg 252. 
Note this assumes the graph given is a complete graph on n vertices. 
We rely on a custom graph data structure as found in graph.cpp and graph.h in the graphs folder of the DSA repo.
The ability to generate your own random graph is given in main() in a comment.

Aside: If you would like to compare this algorithm to random sampling, it is included for you at the very end after main(){}. Follow the instructions contained there (simply removing comment delims)
to add it and compare results.
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
		int parent = path[i - 1];
		int vertex = path[i];
		cost += g.edges[parent][vertex];
	}
	//must add edge connecting end to start again
	cost += g.edges[path[g.nvertices - 1]][0];

	return cost;
}

int path_cost(const vector<int>& path, const vector<int>& new_path, const adjmatrix& g, int s_index, int j_index, int old_cost) {
	//this path_cost is optimized for finding the cost of a new path that differs in only two swapped vertices in the tour
	//leading to constant time computation for a transition cost to a new path rather than O(n) time above.
	if (j_index < s_index) swap(s_index, j_index);

	//note will never swap the first vertex with anything else as that is the start point for all tours
	int new_cost{ old_cost };
	int parent_s = path[s_index-1]; int child_s = s_index == path.size() - 1 ? 0 : path[s_index + 1];//return edge to 0 is not included in path/ avoid
	int parent_j = path[j_index-1]; int child_j = j_index == path.size() - 1 ? 0 : path[j_index + 1];
	const int& s = path[s_index]; const int& j = path[j_index];

	//compute switching in j
	new_cost += g.edges[parent_s][j] - g.edges[parent_s][s];
	if (s_index + 1 != j_index) new_cost += g.edges[j][child_s] - g.edges[s][child_s]; //care when swapping neighbours
	

	//compute switching in s
	if (s_index + 1 != j_index) new_cost += g.edges[parent_j][s] - g.edges[parent_j][j];
	new_cost += g.edges[s][child_j] - g.edges[j][child_j];

	return new_cost - old_cost;

}

void rand_path(vector<int>& path, const graph& g) {
	uniform_int_distribution<int> dist(0, g.nvertices - 2);
	list<int> candidates(g.nvertices - 1);
	int j = 1;
	for (auto it = candidates.begin(); it != candidates.end(); ++it) *it = j++;

	//generate path from unchosen candidates
	j = 1;
	for (auto it = path.begin() + 1; it != path.end(); ++it) {
		int adv = dist(rng);
		auto iter = candidates.begin(); advance(iter, adv);
		int next = *iter;
		*it = next;
		if (j == g.nvertices - 1) continue; //to prevent a>b in line below for uniform dist
		dist.param(uniform_int_distribution<int>::param_type(0, g.nvertices - 2 - j)); ++j;
		candidates.erase(iter);
	}
}

vector<int> hillclimb_TSP(graph& g) {
	//note we always start the path with the first vertex, 0 (since the path is a cycle and goes through all vertices anyway)
	vector<int> tour(g.nvertices, 0); 	
	rand_path(tour, g); //pick random path to start local search
	adjmatrix gmat = list_to_matrix(g); //convert for quick path cost computation
	cout << "Original seed path cost: " << path_cost(tour, gmat) << "\n";

	vector<int> new_tour(g.nvertices, 0);
	int cost = path_cost(tour, gmat);

	bool stuck = true;
	START:do {
		stuck = true;
		for (int s_index = 1; s_index < g.nvertices-1; ++s_index) {
			for (int j_index = s_index + 1; j_index < g.nvertices; ++j_index) {
				new_tour = tour; swap(new_tour[s_index], new_tour[j_index]);
				int delta = path_cost(tour, new_tour, gmat, s_index, j_index, cost);
				if (delta < 0) {
					stuck = false;
					tour = new_tour;
					cost += delta;
					goto START;
				}
			}
		}

	} while (!stuck);

	cout << "Most optimal path found for HILLCLIMB so far is: \n";
	for (int i = 0; i < tour.size(); ++i) cout << tour[i] << " ";
	cout << "\nCost is: " <<  cost << "\n\n";
	return tour;
}



int main() {
	ios_base::sync_with_stdio(false);
	graph g;
	g.read_file("graphs.txt"); //see graph contained in graphs.txt for structure of graph


	hillclimb_TSP(g);
	//random_sampling_TSP(g, 100000); remove comment // if you want to compare this algo with random_sampling_TSP


	/*
	//Use this to generate your own random complete graph.
	//Do remember that in order for the graph to be complete the number of edges should be nvertices*(nvertices-1)/2

	//int nvertices, int nedges, int max_weight, bool directed
	g.rand_graph(40, 780, 500, false);
	g.save_graph("graphs.txt");
	*/
}

/*
Random sampling is left here for the convenience of the user if they wish to compare this algo (HILLCLIMB) with random sampling.
Simply place this function back without the comment delimiters and remove the comment // in the main() above as described.

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
	cout << "Most optimal path found for RS_TSP so far is: \n";
	for (int i = 0; i < solution.size(); ++i) cout << solution[i] << " ";
	cout << "\nCost is: " << path_cost(solution, gmat) << "\n\n";
	return solution;
}
*/
