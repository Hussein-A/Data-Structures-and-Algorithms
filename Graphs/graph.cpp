#include<vector>
#include<iostream>
#include<sstream>
#include"graph.h"

using namespace std;

//Error handling
struct Exit : runtime_error {
	Exit() : runtime_error("Exit") {}
};

// error() simply disguises throws:
inline void error(const string& s)
{
	throw runtime_error(s);
}

inline void error(const string& s, const string& s2)
{
	error(s + s2);
}

inline void error(const string& s, int i)
{
	ostringstream os;
	os << s << ": " << i;
	error(os.str());
}
//End of Error Handling

void graph::read_graph() {
	cout << "Please enter the number of vertices for this graph.\n";
	cin >> this->nvertices; this->degree.resize(this->nvertices);

	cout << "Please enter the number of edges for this graph.\n";
	cin >> this->nedges; this->edges.resize(this->nvertices);

	cout << "Is the graph directed?(y for yes, n for no.\n";
	char ans; cin >> ans;
	if (ans == 'y') this->directed = true;
	else this->directed = false;

	cout << "which two vertices would you like to connect?\nEnter the number representing the first vertex,"
		<< " followed by the second.\n";
	//Please note the numbering for vertices starts at 0 to " << this->nvertices-1<<"\n"
	int a, b;
	for (int i = 0; i < this->nedges; ++i) {
		cin >> a >> b;
		cout << "weight? (1 for default).\n"; int weight;
		cin >> weight;
		this->insert_edge(--a, --b, directed, weight); //convert vertices a,b to (0,n-1) range
		cout << "Edges left: " << this->nedges - i - 1 << "\n";
	}
	
}

void graph::insert_edge(int x, int y, bool directed, int weight) {
	if (x >= this->nvertices || y >= this->nvertices) error("Error! One of the vertices entered is out of bounds!\n");
	this->edges[x].push_back(edgenode{ y, weight }); ++degree[x];
	if (!directed) {this->edges[y].push_back(edgenode{ x, weight }); ++degree[y];}
}

void graph::print_graph() {
	if (this->edges.empty()) {cout << "No edges to print!\n"; return;}
	for (int i = 0; i < this->edges.size(); ++i) {
		for (edgenode edge : this->edges[i]) {
			cout << i+1 << " -> " << edge.neighbor+1 << " weight: " << edge.weight << "\n";
		}
	}
}



