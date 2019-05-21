/*
This program's goal is to generate all possible paths on a graph on n vertices. Based upon previous
implementations of find all subsets/permutations. Uses custom graph data data structure, see graph.cpp,
graph.h in Graphs subfolder of DSA repo.
*/

#include<vector>
#include<iostream>
#include"graph.h"
using namespace std;

bool is_solution(vector<int> path, int count, int end) {
	return path[count] == end;
}

void process_solution(vector<int> path, int count) {
	cout << '{';
	for (int i = 1; i <= count; ++i) cout << path[i];
	cout << "}\n";
}

vector<int> construct_candidates(const vector<int>& path, int count, const vector<bool>& is_in,const graph& g, int start) {
	vector<int> candidates;
	if (count == 1) candidates.push_back(start); //path can only ever start from start
	else {
		int last = path[count - 1];//path can only continue from neighbours of last added vertex
		for (auto edge : g.edges[last]) {
			if (!is_in[edge.neighbor]) candidates.push_back(edge.neighbor);
		}
	}
	return candidates;
}

void backtrack(vector<int>& path, int count, vector<bool>& is_in, const graph& g, int start, int end) {
	if (is_solution(path, count, end)) process_solution(path, count);
	else {
		++count;
		vector<int> candidates = construct_candidates(path, count, is_in, g, start);
		for (int i = 0; i < candidates.size(); ++i) {
			//make move here
			path[count] = candidates[i];
			is_in[candidates[i]] = true;
			backtrack(path, count, is_in, g, start, end);
			//unmake move here
			is_in[candidates[i]] = false;
		}
	}
}

void generate_paths(const graph& g, int start, int end) {
	vector<int> soln(g.nvertices+1);
	vector<bool> is_in(g.nvertices+1, false);
	backtrack(soln, 0, is_in, g, start, end);
}

int main() {
	graph g; 
	//g.rand_graph(6, 11, 3, false); //nvertices, ned ges, max_edge_weight, bool directed
	g.read_file("graphs.txt");
	while (true) {
		cout << "num of vertices is: " << g.nvertices << "\nVertex to start from?\n";
		int start; cin >> start;
		cout << "\nEnd vertex?\n";
		int end; cin >> end;
		generate_paths(g, start, end);
		cout << "\n";
	}
}