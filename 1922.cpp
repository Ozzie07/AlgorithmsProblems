//#include <bits/stdc++.h>
//
//using namespace std;
//
//class Solution
//{
//	int n; //컴퓨터의 수
//	int m; // 연결할 수 있는 선의 수
//	bool visited[1001] = { false, };
//	vector<int> adjList[1001];
//
//	struct cmp
//	{
//		bool operator()(tuple<int, int, int> a, tuple<int, int, int> b)
//		{
//			return get<2>(a) < get<2>(b);
//		}
//	};
//
//	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, cmp> edges;
//	//TODO:: 처음과 끝. 한 번씩만 정렬하면 됨.
//
//	void ConKruskalMST()
//	{
//		vector<tuple<int, int, int>> recvEdge;
//		tuple<int, int, int> edge;
//		int numofEdges = edges.size();
//
//		while (numofEdges + 1 > n)
//		{
//			int a, b, c;
//			edge = edges.top();
//			edges.pop();
//			numofEdges--;
//
//			RemoveEdge(get<0>(edge), get<1>(edge));
//
//			if (!isConnected(get<0>(edge), get<1>(edge)))
//			{
//				RecoverEdge(get<0>(edge), get<1>(edge));
//				recvEdge.push_back(edge);
//				numofEdges++;
//			}
//		}
//
//		for (auto e : recvEdge)
//		{
//			edges.push(e);
//		}
//	}
//
//	int MSTValue()
//	{
//		int res = 0;
//		while (!edges.empty())
//		{
//			tuple<int, int, int> edge;
//			edge = edges.top();
//			edges.pop();
//			res += get<2>(edge);
//		}
//		return res;
//	}
//
//	void InitVisit()
//	{
//		for (size_t i = 0; i < n; i++)
//		{
//			visited[i] = false;
//		}
//	}
//
//	bool isConnected(int _start, int _destination)
//	{
//		InitVisit();
//		DFS(_start);
//		return visited[_destination];
//	}
//
//	void RemoveEdge(int _s, int _d)
//	{
//		{
//			auto iterator = find(adjList[_s].begin(), adjList[_s].end(), _d);
//			adjList[_s].erase(iterator);
//		}
//		{
//			auto iterator = find(adjList[_d].begin(), adjList[_d].end(), _s);
//			adjList[_d].erase(iterator);
//		}
//	}
//
//	void RecoverEdge(int _s, int _d)
//	{
//		adjList[_s].push_back(_d);
//		adjList[_d].push_back(_s);
//	}
//
//	void DFS(int _startPoint)
//	{
//		if (visited[_startPoint])
//			return;
//		visited[_startPoint] = true;
//		for (int e : adjList[_startPoint])
//			DFS(e);
//	}
//
//	void GetInput()
//	{
//		cin >> n >> m;
//		for (size_t i = 0; i < m; i++)
//		{
//			int a, b, c;
//			cin >> a >> b >> c;
//			a--; b--;
//			adjList[a].push_back(b);
//			adjList[b].push_back(a);
//			tuple<int, int, int> edge = tie(a, b, c);
//			edges.push(edge);
//		}
//	}
//
//	//is Cycle
//	//v=e+1
//	//v-1 = e
//
//	//void Kruskal()
//	//{
//	//	for (auto e : edges)
//	//	{
//	//		if (n = numOfEdges + 1)
//	//			return;
//	//		{
//	//			//add
//	//			//if(cycle)
//	//			// {
//	//			//		//subtract
//	//			//		//continu;
//	//			// }
//	//			//totalCost = e.third;
//	//		}
//	//	}
//	//}
//
//public:
//
//	void Invoke()
//	{
//		GetInput();
//		ConKruskalMST();
//		cout << MSTValue() << endl;
//	}
//
//};
//
//int main() {
//	//	freopen("input.txt", "r", stdin);
//	//	freopen("output.txt", "w", stdout);
//
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	//\n faster than endl. endl makes buffer flush explicitly.
//
//	Solution solution;
//	solution.Invoke();
//	return 0;
//}