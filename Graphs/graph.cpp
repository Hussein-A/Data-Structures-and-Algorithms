#include<vector>
#include<iostream>
#include<fstream>
#include<sstream>
#include<algorithm>
#include<time.h>
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
		this->insert_edge(--a, --b, weight); //convert vertices a,b to (0,n-1) range
		cout << "Edges left: " << this->nedges - i - 1 << "\n";
	}
	
}



void graph::insert_edge(int x, int y, int weight) {
	if (x >= this->nvertices || y >= this->nvertices) error("Error! One of the vertices entered is out of bounds!\n");
	
	++this->nedges;
	this->edges[x].push_back(edgenode{ y, weight }); ++this->degree[x];
	if (!this->directed) {this->edges[y].push_back(edgenode{ x, weight }); ++this->degree[y];}
}

void graph::print_graph() {
	if (this->edges.empty()) {cout << "No edges to print!\n"; return;}
	for (int i = 0; i < this->edges.size(); ++i) {
		for (edgenode edge : this->edges[i]) {
			cout << i << " -> " << edge.neighbor << " weight: " << edge.weight << "\n";
		}
	}
}

//Care when using function below and/or writing own functions to text file
//incomplete
void graph::read_file(const string& name) {
	//file is structered as ADJ MATRIX: 
	//# of vertices
	//directed: true/false
	//weight of neighbor of ith line (ith vertex) 
	ifstream ist{ name };
	if (!ist) error("Cannot open file for reading!");

	string temp;
	ist >> this->nvertices;
	ist >> temp; this->directed = temp == "true" ? true : false;
	this->edges.resize(this->nvertices);
	this->degree.resize(this->nvertices, 0);
	getline(ist, temp); //remove newline


	int i = 0, j = 0, weight = 0;
	string row;
	while (i < this->nvertices && getline(ist, row)) {
		cout << "ROW: " << row << "\n";
		istringstream is{ row };
		j = 0;
		while (is>>weight) {
			if (weight == INT_MAX) { ++j; continue; }//ignore max int weights as they represent non edge
			this->insert_edge(i, j, weight);
			++j;
		}
		++i;
	}


}

void graph::save_graph(const std::string& name) {
	ofstream ost{ name };
	if (!ost) error("ERROR! Cannot open file for writing!\n");
	ost << this->nvertices << "\n";
	if (this->directed) ost << "true\n";
	else ost << "false\n";

	//convert to adjacency matrix and output line
	adjmatrix gmatrix = list_to_matrix(*this);
	for (int i = 0; i < gmatrix.nvertices; ++i) {
		for (int j = 0; j < gmatrix.nvertices; ++j) {
			ost << gmatrix.edges[i][j] << " ";
		}
		if (i != gmatrix.nvertices - 1) ost << "\n"; //dont add new line below last row
	}

}


void graph::rand_graph(int nvertices, int nedges, int max_weight, bool directed) {
	//constructs a random graph with the adj list representation
	int max_nedges = nvertices * (nvertices - 1) / 2;
	if (nedges > max_nedges) error("ERROR! More edges given than possible!\n");

	//init graph
	this->nvertices = nvertices;
	this->nedges = nedges;
	this->directed = directed;
	this->edges.resize(nvertices);
	this->degree.resize(nvertices);

	srand(time(NULL));
	while (nedges > 0) {
		int vertex = rand() % nvertices;
		int neighbor = rand() % nvertices;
		//Don't pick a full vertex ie. one that already has an edge with every other vertex
		while (this->edges[vertex].size() == nvertices - 1) vertex = rand() % nvertices;
		vector<edgenode> vedges = this->edges[vertex];
		
		auto it = std::find_if(vedges.begin(), vedges.end(), [&](edgenode& edge) {return edge.neighbor == neighbor; });
		while (neighbor == vertex || it != vedges.end()) {
			neighbor = rand() % nvertices; //prevent self edges or overwriting existing edges
			it = std::find_if(vedges.begin(), vedges.end(), [&](edgenode& edge) {return edge.neighbor == neighbor; });
		}

		int weight = rand() % max_weight +1;//do not allow 0 weighted edges except for self.
		this->insert_edge(vertex, neighbor, weight);
		--nedges;
	}
}


//adjacency matrix functions
adjmatrix::adjmatrix(int n) {//constructor
	edges = vector<vector<int>>(n, vector<int>(n, INT_MAX)); //n rows, n columns
	nvertices = n;
	//note INT_MAX at i,j represents NO edge. Ie nonexistence of edge since edge weight
	//may be 0 or neg

	//set edge to self to be weight 0
	for (int i = 0; i < nvertices; ++i) { edges[i][i] = 0; }
}

adjmatrix list_to_matrix(graph& g) {
	//convert  a graph as found in graph.h into adj matrix
	adjmatrix gmatrix(g.nvertices);
	for (int i = 0; i < g.nvertices; ++i) {
		for (edgenode edge : g.edges[i]) {
			gmatrix.edges[i][edge.neighbor] = edge.weight;
		}
	}
	for (int i = 0; i < g.nvertices; ++i) {
		gmatrix.edges[i][i] = 0; 
	}
	return gmatrix;
}

void adjmatrix::print_matrix() {
	for (int i = 0; i < this->nvertices; ++i) {
		cout << i << ": ";
		for (int j = 0; j < this->nvertices; ++j) {
			if (this->edges[i][j] == INT_MAX) cout << " NULL ";
			else { cout << this->edges[i][j] << " "; }
		}
		cout << "\n";
	}
}


