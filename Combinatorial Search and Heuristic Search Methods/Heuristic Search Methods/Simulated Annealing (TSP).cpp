/*
The purpose of this program is to implement the simulated annealing algorithm on the domain of the travelling salesman problem (TSP).
This implementation (strictly the simulated_annealing() function) is based strongly upon the partial one found in Skiena, Algorithm Design Manual, 2ed. pg 257
This was done more with the motivation of learning and seeing how the algorithm is implemented in C++ than any original implementation.

Custom graph data structure is used, details of which can be found in "graph.h" and graph.cpp included in the DSA/Graphs repo.

For the users convenience if they wish to measure against the previous algos used for this problem (Random sampling, hillclimb) they have also been included here.
Please feel free to play with the constants used (K, COOLING_FACTOR, etc.). The ones used are just what I found to work best during short tests.

The output path of all 3 is given, the respective cost as well as the time taken for each.
*/

#include<chrono> //to measure fnc time
#include"graph.h"
#include<iostream>
#include<list>
#include<math.h>
#include<random>
#include<vector>

using namespace std;
using namespace chrono;
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
	else if (j_index == s_index) return old_cost;

	//note will never swap the first vertex with anything else as that is the start point for all tours
	int new_cost{ old_cost };
	int parent_s = path[s_index - 1]; int child_s = s_index == path.size() - 1 ? 0 : path[s_index + 1];//return edge to 0 is not included in path/ avoid
	int parent_j = path[j_index - 1]; int child_j = j_index == path.size() - 1 ? 0 : path[j_index + 1];
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

vector<int> simulated_annealing(graph& g) {
	//general inits
	adjmatrix gmat = list_to_matrix(g); //used to quickly compute path cost
	uniform_int_distribution<int> dist(1, g.nvertices - 1); //for which two random vertices to swap (note never swap vertex 0 with anything as it is always the start)
	uniform_real_distribution<double> r(0, 1); //to "flip" coin and see if will accept negative transition (ie. loss)

	vector<int> solution(g.nvertices, 0);
	vector<int> candidate = solution;

	rand_path(solution, g);//initial random solution
	int cost = path_cost(solution, gmat);
	

	//algo specific init
	const int K = pow(10, 1.9); //change this (higher) to make negative transitions more likely to occur at higher temps.
	double temperature = 1;
	const double COOLING_FACTOR = 0.85;
	const int COOLING_STEPS = 15;
	const int STEPS_PER_TEMP = 10000;

	for (int i = 0; i < COOLING_STEPS; ++i) {
		temperature *= COOLING_FACTOR;
		int curr_cost = cost;

		for (int j = 0; j < STEPS_PER_TEMP; ++j) {
			int s_index = dist(rng);
			int j_index = dist(rng);

			candidate = solution;
			swap(candidate[s_index], candidate[j_index]);

			//for probability check
			int delta = path_cost(solution, candidate, gmat, s_index, j_index, cost);
			double exponent = (-delta) / (K*temperature);
			double merit = pow(exp(1), exponent);
			double flip = r(rng);

			if (delta < 0 || merit > flip) {//always accept cheaper solns or if more expensive soln if chance to accept is high enough
				solution = candidate;
				cost += delta;
			}
			else {} //reject
		}
		
		if (curr_cost > cost) {//has progress been made at this temp?
			temperature /= COOLING_FACTOR;
		}
	}
	cout << "Path is: \n"; for (int x : solution) cout << x << " "; cout << "\n";
	cout << "At a cost of: " << path_cost(solution, gmat) << "\n";
	return solution;
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
	cout << "Path is: \n";
	for (int i = 0; i < solution.size(); ++i) cout << solution[i] << " ";
	cout << "\nCost is: " << path_cost(solution, gmat) << "\n";
	return solution;
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
	for (int s_index = 1; s_index < g.nvertices - 1; ++s_index) {
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

cout << "Path is: \n";
for (int i = 0; i < tour.size(); ++i) cout << tour[i] << " ";
cout << "\nCost is: " << cost << "\n";
return tour;
}

int main() {
	ios_base::sync_with_stdio(false);

	graph g;
	g.read_file("graphs.txt");
	adjmatrix gmat = list_to_matrix(g); //for path cost computation below
	
	cout << "Simulated Annealing \n";
	auto start = high_resolution_clock::now();
	simulated_annealing(g);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(stop - start);
	cout << "Time taken: " << duration.count() << " milliseconds\n\n";


	cout << "Random Sampling \n";
	start = high_resolution_clock::now();
	random_sampling_TSP(g, 15000);
	stop = high_resolution_clock::now();
	duration = duration_cast<milliseconds>(stop - start);
	cout << "Time taken: " << duration.count() << " milliseconds\n\n";


	cout << "HillClimb \n";
	start = high_resolution_clock::now();
	hillclimb_TSP(g);
	stop = high_resolution_clock::now();
	duration = duration_cast<milliseconds>(stop - start);
	cout << "Time taken: " << duration.count() << " milliseconds\n\n";
}

/*
//Use this to generate your own random complete graph.
//Do remember that in order for the graph to be complete the number of edges should be nvertices*(nvertices-1)/2
//It is untested what occurs if there are fewer edges than needed.

//int nvertices, int nedges, int max_weight, bool directed
g.rand_graph(40, 780, 500, false);
g.save_graph("graphs.txt");
*/