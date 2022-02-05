//#include <iostream>
//#include <vector>
//#include <tuple>
//#include <queue>
//#include <algorithm>
//#define INT_MAX 0x11111111
//class Node
//{
//	int value;
//	std::vector<std::pair<int, int>> adj; //destination, weight
//	bool visited = false;
//	int distance = 0; //for BFS, Bellman-Ford Algorithm... ShortestPath Prob.
//public:
//	Node() { value = 0; }
//	Node(int _value) { value = _value; }
//
//	void AddEdge(int destination, int weight)
//	{
//		adj.push_back(std::make_pair(destination, weight));
//	}
//
//	bool Isvisited()
//	{
//		return visited;
//	}
//
//	void Visit()
//	{
//		visited = true;
//	}
//
//	void VisitReset()
//	{
//		visited = false;
//	}
//
//	std::vector<std::pair<int, int>>& Adjacent()
//	{
//		return adj;
//	}
//
//	int GetDistance()
//	{
//		return distance;
//	}
//
//	void SetDistance(int x)
//	{
//		distance = x;
//	}
//};
//
//
//class Graph
//{
//private:
//
//	Node* graph;
//	std::vector<std::tuple<int, int, int>> edges; //source, destination, weight
//	int size;
//	std::queue<int> q;
//private:
//	void resetVisited()
//	{
//		for (size_t i = 0; i < size; i++)
//			graph[i].VisitReset();
//	}
//
//	void DFS_logic(int startPoint, void (*ptr)(Node a))
//	{
//		if (graph[startPoint].Isvisited())
//			return;
//
//		graph[startPoint].Visit();
//		//DoSomething in Node.
//		std::cout << "node : " << startPoint << ':';
//		ptr(graph[startPoint]);
//		//
//		for (auto e : graph[startPoint].Adjacent())
//			DFS_logic(e.first, ptr);
//	}
//
//	void BFS_logic(int startPoint, void (*ptr)(Node a))
//	{
//		graph[startPoint].Visit();
//		graph[startPoint].SetDistance(0);
//		q.push(startPoint);
//		while (!q.empty()) {
//			int s = q.front(); q.pop();
//			//DoSomething in Node.
//			ptr(graph[s]);
//			//
//			for (auto u : graph[s].Adjacent())
//			{
//				if (graph[u.first].Isvisited())
//					continue;
//				graph[u.first].Visit();
//				graph[u.first].SetDistance(graph[s].GetDistance());
//				q.push(u.first);
//			}
//		}
//	}
//
//	void EdgeSort()
//	{
//		std::sort(edges.begin(), edges.end(), [](std::tuple<int, int, int> a, std::tuple<int, int, int> b) {return std::get<0>(a) > std::get<0>(b); });
//	}
//
//
//public:
//	Graph(int _size) { graph = new Node[_size]; size = _size; }
//
//	void AddEdge(int source, int destination, int weight)
//	{
//		graph[source].AddEdge(destination, weight);
//		edges.push_back(std::make_tuple(source, destination, weight));
//	}
//
//	void AddEdgeUndirect(int source, int destination, int weight)
//	{
//		AddEdge(source, destination, weight);
//		AddEdge(destination, destination, weight);
//	}
//
//	void DFS(int startPoint, void (*ptr)(Node a))
//	{
//		DFS_logic(startPoint, ptr);
//		resetVisited();
//	}
//
//	void BFS(int startPoint, void(*ptr)(Node a))
//	{
//		BFS_logic(startPoint, ptr);
//	}
//
//	void ShortestPath(int startPoint)
//	{
//		EdgeSort();
//		for (size_t i = 0; i < size; i++)
//			graph[i].SetDistance(INT_MAX);
//
//		graph[startPoint].SetDistance(0);
//		for (size_t i = 0; i < size - 1; i++)
//		{
//			for (auto e : edges) {
//				int a, b, w;
//				std::tie(a, b, w) = e;
//				graph[b].SetDistance(std::min(graph[b].GetDistance(), graph[a].GetDistance() + w));
//			}
//		}
//
//		resetVisited();
//	}
//
//	void Dijkstra(int startPoint)
//	{
//		std::priority_queue<std::pair<int, int>> pq; //-distance, node
//
//		for (size_t i = 0; i < size; i++)
//			graph[i].SetDistance(INT_MAX);
//		graph[startPoint].SetDistance(0);
//		pq.push({ 0, startPoint });
//
//		while (!pq.empty())
//		{
//			int a = pq.top().second; pq.pop();
//			if (graph[a].Isvisited()) 
//				continue;
//			graph[a].Visit();
//			for (auto u : graph[a].Adjacent())
//			{
//				int b = u.first;
//				int w = u.second;
//				if (graph[a].GetDistance() + w < graph[b].GetDistance())
//				{
//					graph[b].SetDistance(graph[a].GetDistance() + w);
//					pq.push({ -graph[b].GetDistance(),b });
//				}
//			}
//		}
//
//		resetVisited();
//	}
//};
//
//void funcptr (Node a)
//{
//	std::cout << a.GetDistance() << '\n';
//}
//
//
//int main()
//{
//	Graph gh(5);
//	gh.AddEdgeUndirect(0, 1, 2);
//	gh.AddEdgeUndirect(0, 2, 3);
//	gh.AddEdgeUndirect(0, 3, 7);
//	gh.AddEdgeUndirect(1, 3, 3);
//	gh.AddEdgeUndirect(2, 3, 1);
//	gh.AddEdgeUndirect(1, 4, 5);
//	gh.AddEdgeUndirect(3, 4, 2);
//
////	gh.ShortestPath(0);
//	gh.Dijkstra(0);
//	gh.DFS(0, funcptr);
//
//
//	Graph graph2(6);
//	graph2.AddEdgeUndirect(0,1,1);
//	graph2.AddEdgeUndirect(0,3,2);
//	graph2.AddEdgeUndirect(0,2,3);
//	graph2.AddEdgeUndirect(2,3,4);
//	graph2.AddEdgeUndirect(1,3,5);
//	graph2.AddEdgeUndirect(2,4,2);
//	graph2.AddEdgeUndirect(3,4,3);
//	graph2.AddEdgeUndirect(1,5,1);
//	graph2.AddEdgeUndirect(3,5,2);
//
//	//graph2.AddEdgeUndirect(0, 1, 2);
//	//graph2.AddEdgeUndirect(0, 2, 3);
//	//graph2.AddEdgeUndirect(0, 3, 7);
//	//graph2.AddEdgeUndirect(1, 3, 3);
//	//graph2.AddEdgeUndirect(2, 3, 1);
//	//graph2.AddEdgeUndirect(1, 4, 5);
//	//graph2.AddEdgeUndirect(3, 4, 2);
//
//	graph2.ShortestPath(0);
//	//graph2.Dijkstra(0);
//	graph2.DFS(0, funcptr);
//
//	return 0;
//};