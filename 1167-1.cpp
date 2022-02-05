//#include <bits/stdc++.h>
//using namespace std;
//
//class Solution
//{
//	int v;
//	vector<pair<int, int>> adjList[100001];
//	int distance[100001];
//	pair<int, int> longest = { 0, 0 }; //{length, vertex}
//	int startPoint;
//private:
//	void InitDistance()
//	{
//		for (size_t i = 0; i < v; i++)
//			distance[i] = 0;
//	}
//
//	void GetInput()
//	{
//		cin >> v;
//		for (size_t i = 0; i < v; i++)
//		{
//			int s;
//			cin >> s;
//			int d;
//			int w;
//			s--;
//			while (true)
//			{
//				cin >> d;
//				if (d == -1)
//					break;
//				cin >> w;
//				d--;
//
//				adjList[s].push_back({ d,w });
//			}
//		}
//	}
//	void DFS(int s, int e, int w)
//	{
//		distance[s] = distance[e] + w;
//		pair<int, int> current{ distance[s], s };
//
//		if (longest < current)
//			longest = current;
//		for (auto u : adjList[s])
//		{
//			int _w = u.second;
//			if (u.first != e) //Because our graph is Tree, we don't need to check is queued or visited.
//				DFS(u.first, s, _w);
//		}
//	}
//
//	void Diameter()
//	{
//		InitDistance();
//		DFS(0, 0, 0);
//		InitDistance();
//		DFS(longest.second, longest.second, 0);
//		cout << longest.first << endl;
//	}
//
//public:
//	void Invoke()
//	{
//		GetInput();
//		Diameter();
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
//};