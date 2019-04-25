Consider a set of movies M1,M2,...,Mk. There is a set of customers, each one of which indicates the two movies they would like to see this 
weekend. Movies are shown on Saturday evening and Sunday evening. Multiple movies may be screened at the same time. You must decide which 
movies should be televised on Saturday and which on Sun-day, so that every customer gets to see the two movies they desire.    
Is there a schedule where each movie is shown at most once? Design an efficient algorithm to find such a schedule if one exists.   
.   
***Solution***
Consider constructing a graph on k vertices each labeled M_k respectively representing the movies. We will attach an edge between
M_i and M_j iff there exists a customer C such that C wants to view M_i and M_j. Our task is to split the vertex set into two groups
Saturday and Sunday. Immediately we should be asking if this graph is bipartite. That is can we color one set of the vertices red (Saturday),
and the other blue (Sunday) such that no two vertices of the same color have an edge between them? To solve this we use BFS just as we did
for our earlier problems. Whereby we pick a random vertex to be our root, color that 'red' and all of its children 'blue' and begin again
like BFS with its first child coloring all its children the opposite color of its parent. Below is code that solves the Is Graph Bipartite?
question from LeetCode.        
We output false if the graph is not bipartite (ie. no valid schedule exists) and true otherwise. Where for the latter case we simply place
those vertices colored red on Saturday and those vertices colored blue on Sunday.   
.   
```c++
class Solution {
public:

	bool flag = true;
	void bfs(vector<vector<int>>& graph, vector<int>& colors, vector<int>& state, const int start) {
		//do bfs
		//initialize
		queue<int> myqueue; myqueue.push(start);
		colors[start] = 1;
		state[start] = 1;

		int curr = start;
		while (!myqueue.empty()) {
			curr = myqueue.front();

			for (const int& neighbor : graph[curr]) {
				if (state[neighbor] == 0) {
					state[neighbor] = 1;
					//set color
					if (colors[curr] == 1) colors[neighbor] = 2;
					else colors[neighbor] = 1;
					myqueue.push(neighbor);
				}

				else {//already seen or processed, check color
					if (colors[curr] == colors[neighbor]) flag = false;
				}
			}
			state[curr] = 2;
			myqueue.pop();
		}
	}

	bool isBipartite(vector<vector<int>>& graph) {
		if (graph.size() == 0) return true;
		vector<int> colors(graph.size(), 0);//0 for uncolored, 1 for red, 2 for blue
		vector<int> state(graph.size(), 0);//0 for undiscovered, 1 for discovered, 2 for processed
		auto it = find(state.begin(), state.end(), 0);

		while (it != state.end()) {
			bfs(graph, colors, state, distance(state.begin(), it));
			if (flag == false) return false;
			it = find(state.begin(), state.end(), 0);
		}

		//check

		return flag;
	}
};
```
