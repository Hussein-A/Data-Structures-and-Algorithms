/*
This algorithm is based upon the Floyd-Warshall algorithm for finding all-pairs shortest paths.
Ie. the shortest path between any two vertices. Please note the implementation below is almost exactly as found
in Skiena's Algorithm Design Manual pg. 211. It was reproduced here with slight changes (ex data structures used) for learning purposes.

Note that the sum of any two edges cannot be greater than or equal to INT_MAX. (ie the diameter of your graph < INT_MAXwww) This is due to how a nonexistent edge
is represented as INT_MAX (not 0 as usual to allow for free rides)

Further note that although it has the same time complexity as an n-times call to Dijkstra's algorithm
(ie. O(n^3)) due to the simplicity of the loops below this algorithm runs faster in practice.
*/

#include"graph.h"
#include<vector>
#include<iostream>

using namespace std;

void floydWarsh(adjmatrix& g) {
	int through_k; //distance when passing through vertex k
	//Notice that shortest path using only first k vertices is:
	//min()

	for (int k = 0; k < g.nvertices; ++k) {
		for (int i = 0; i < g.nvertices; ++i) {
			for (int j = 0; j < g.nvertices; ++j) {
				if (g.edges[i][k] == INT_MAX || g.edges[k][j] == INT_MAX) continue;//prevent overflow
				through_k = g.edges[i][k] + g.edges[k][j];
				g.edges[i][j] = g.edges[i][j] > through_k ? through_k : g.edges[i][j];
			}
		}
	}
}


int main() {
	graph g;
	g.read_file("graphs.txt");
	adjmatrix gmatrix = list_to_matrix(g);

	//before
	gmatrix.print_matrix(); cout << "\n";

	floydWarsh(gmatrix);

	//after, edge weights now represent length of shortest path to given vertex.
	gmatrix.print_matrix();

}
