//this is a modified version of Skiena's graph data structure as found in Skienna Algorithm Design Manual, 2 ed. chapter 5 and chapter 6.
//It supports directed, weighted graphs.

#pragma once
#include<vector>

struct edgenode {
	int neighbor;
	int weight{ 1 };
};

struct graph {
	std::vector<std::vector<edgenode>> edges;
	std::vector<int> degree;
	int nvertices{ 0 };
	int nedges{ 0 };
	bool directed{ false };

	void read_graph();
	void read_file(const std::string& name);
	void insert_edge(int x, int y, int weight = 1);
	void print_graph();
	void rand_graph(int nvertices, int nedges, int max_weight, bool directed);
	void save_graph(const std::string& name);
};

// Adjacency matrix representation of graphs
struct adjmatrix {
	std::vector<std::vector<int>> edges;
	int nvertices;

	adjmatrix(int n);
	void print_matrix();
};

//helper function
adjmatrix list_to_matrix(graph& g);