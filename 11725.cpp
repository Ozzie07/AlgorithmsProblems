//#include <bits/stdc++.h>
//
//using namespace std;
//
//class Solution
//{
//	int n;
//	vector<int> adjList[100001];
//	bool visited[100001];
//	bool isMeetRoot;
//
//	void GetInput()
//	{
//		cin >> n;
//		for (size_t i = 0; i < n - 1; i++)
//		{
//			int s, d;
//			cin >> s >> d;
//			s--; d--;
//			adjList[s].push_back(d);
//			adjList[d].push_back(s);
//		}
//	}
//
//	void InitVisit()
//	{
//		for (size_t i = 0; i < n; i++)
//			visited[i] = false;
//	}
//
//	void DFS(int startPoint)
//	{
//		if (visited[startPoint])
//			return;
//
//		visited[startPoint] = true;
//		if (startPoint == 0)
//		{
//			isMeetRoot = true;
//			return;
//		}
//
//		for (int d : adjList[startPoint])
//			DFS(d);
//	}
//
//	bool IsAncestor(int startPoint, int direction)
//	{
//		isMeetRoot = false;
//		InitVisit();
//		visited[startPoint] = true;
//		DFS(direction);
//		return isMeetRoot;
//	}
//
//	void Output()
//	{
//		for (size_t i = 1; i < n; i++)
//			for (int e : adjList[i])
//				if (IsAncestor(i, e))
//				{
//					e++;
//					cout << e << '\n';
//				}
//	}
//
//public:
//	void Invoke()
//	{
//		GetInput();
//		Output();
//	}
//
//};
//
//
//int main() {
//	//	freopen("input.txt", "r", stdin);
//	//	freopen("output.txt", "w", stdout);
//
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	//\n faster than endl. endl makes buffer flush explicitly.
//	Solution solution;
//	solution.Invoke();
//	return 0;
//}