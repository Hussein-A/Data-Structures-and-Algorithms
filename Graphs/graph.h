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
	void insert_edge(int x, int y, bool directed, int weight = 1);
	void print_graph();
};