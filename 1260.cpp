#include <bits/stdc++.h>

using namespace std;

class node
{
private:
	bool visited = false;
	int distance = 0;
	vector<int> edges;

public:
	node() {  }
	void Visit() { visited = true; }
	void VisitReset() { visited = false; }
	bool IsVisit() { return visited; }
	int GetDistance() { return distance; }
	int& SetDistance() { return distance; }
	void AddEdge(int destination) { edges.push_back(destination); sort(edges.begin(), edges.end()); }
	vector<int>& GetEdges() { return edges; }
};

class edge
{
public:
	int source;
	int destination;
	
	edge(int _source, int _destination) { source = _source; destination = _destination; }
};

class Graph
{
private:
	int numofvertex;
	node* graph;
	queue<int> q; // for bfs

private:

	void visitInit()
	{
		for (size_t i = 1; i <= numofvertex; i++)
			graph[i].VisitReset();
	}

	void DFS_logic(int startpoint)
	{
		if (graph[startpoint].IsVisit())
			return;

		graph[startpoint].Visit();

		//dosomething
		cout << startpoint << ' ';
		//

		for (int e : graph[startpoint].GetEdges())
			DFS_logic(e);
	}

	void BFS_logic(int startpoint)
	{
		graph[startpoint].Visit();
		graph[startpoint].SetDistance() = 0;
		q.push(startpoint);

		while (!q.empty())
		{
			int s = q.front(); q.pop();

			//dosomething
			cout << s << ' ';
			//

			for (int u : graph[s].GetEdges())
			{
				if (graph[u].IsVisit())
					continue;
				graph[u].Visit();
				graph[u].SetDistance() = graph[s].GetDistance() + 1;
				q.push(u);
			}
		}
	}

public:
	Graph(int _numofvertex) { graph = new node [_numofvertex + 1];  numofvertex = _numofvertex; }
	void AddEdge(edge edge)
	{
		graph[edge.source].AddEdge(edge.destination);
		graph[edge.destination].AddEdge(edge.source);
		//edges.push_back(edge);
	}
	
	void BFS(int startPoint)
	{
		visitInit();
		BFS_logic(startPoint);
	}

	void DFS(int startPoint)
	{
		visitInit();
		DFS_logic(startPoint);
	}
};

int main() {
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	//\n faster than endl. endl makes buffer flush explicitly.
	int v, e;
	int startpoint;
	cin >> v >> e >> startpoint;
	Graph graph(v);

	int s, d;
	for (size_t i = 0; i < e; i++)
	{
		cin >> s >> d;
		graph.AddEdge(edge(s, d));
	}

	graph.DFS(startpoint);
	cout << '\n';
	graph.BFS(startpoint);
	cout << endl;

	return 0;
}