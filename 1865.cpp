//#include <bits/stdc++.h>
//
//using namespace std;
//
//class Solution
//{
//	int n, m, w;
//	int distanceToDestination[501];
//	vector<tuple<int, int, int>> edges;
//	bool isVisited[501] = { false, };
//	bool isTimeCanBack = false;
//	queue<int> minusDestination;
//	int distanceToSource[501];
//
//	void GetInputs()
//	{
//		cin >> n >>  m >> w;
//
//		for (size_t i = 0; i < m; i++)
//		{
//			int s, e, t;
//			cin >> s >> e >> t;
//			s--; e--;
//			tuple<int, int, int> edge = tie(s, e, t);
//			edges.push_back(edge);
//			edge = tie(e, s, t);
//			edges.push_back(edge);
//		}
//
//		for (size_t i = 0; i < w; i++)
//		{
//			int s, e, t;
//			cin >> s >> e >> t;
//			s--; e--;
//			t = -t;
//			tuple<int, int, int> edge = tie(s, e, t);
//			edges.push_back(edge);
//		}
//		
//	}
//
//	void Bellman_Ford_StoD(int _startPoint)
//	{
//		//distanceInit
//		int magicNum = INT_MAX >> 1; //JUST Something large num.
//		for (size_t i = 0; i < n; i++)
//			distanceToDestination[i] = magicNum;
//
//		distanceToDestination[_startPoint] = 0;
//		for (size_t i = 0; i < n; i++)
//		{
//			bool isRelaxed = false;
//			if (isRelaxed)
//				return;
//			for (auto e : edges)
//			{
//				int s, d, w;
//				tie(s, d, w) = e;
//				if (distanceToDestination[d] > distanceToDestination[s] + w)
//				{
//					isRelaxed = true;
//					distanceToDestination[d] = distanceToDestination[s] + w;
//				}
//			}
//		}
//	}
//
//	void Bellman_Ford_DtoS(int _startPoint)
//	{
//		//distanceInit
//		int magicNum = INT_MAX >> 1; //JUST Something large num.
//		for (size_t i = 0; i < n; i++)
//			distanceToSource[i] = magicNum;
//
//		distanceToSource[_startPoint] = 0;
//		for (size_t i = 0; i < n; i++)
//		{
//			bool isRelaxed = false;
//			for (auto e : edges)
//			{
//				int s, d, w;
//				tie(s, d, w) = e;
//				if (distanceToSource[d] > distanceToSource[s] + w)
//				{
//					isRelaxed = true;
//					distanceToSource[d] = distanceToSource[s] + w;
//				}
//			}
//		}
//	}
//
//	//void SPFA(int _startPoint)
//	//{
//	//	int magicNum = INT_MAX >> 1;
//	//	for (size_t i = 0; i < n; i++)
//	//		distanceToSource[i] = magicNum;
//	//	queue<int> q;
//	//	distanceToSource[_startPoint] = 0;
//	//	q.push(_startPoint);
//
//	//	while (!q.empty())
//	//	{
//	//		int u = q.front(); q.pop();
//	//		for (auto e : ).......
//	//		{
//	//			int s, d, w;
//	//			tie(s, d, w) = e;
//	//			if (distanceToSource[d] > distanceToSource[s] + w)
//	//			{
//	//				distanceToSource[d] = distanceToSource[s] + w;
//	//				q.push(d);
//	//			}
//	//		}
//	//	}
//	//}
//
//
//	void Sol()
//	{
//		for (size_t fromS = 0; fromS < n; fromS++)
//		{
//			Bellman_Ford_StoD(fromS);
//
//			for (size_t fromD = 0; fromD < n; fromD++)
//			{
//				if (distanceToDestination[fromD] < 0) // s to d is minus
//				{
//					//find d to s.
//					Bellman_Ford_DtoS(fromD);
//					if (distanceToDestination[fromS] + distanceToSource[fromD] < 0)
//					{
//						isTimeCanBack = true;
//						return;
//					}
//				}
//			}
//		}
//	}
//public:
//
//	void Invoke()
//	{
//		GetInputs();
//		Sol();
//		if (isTimeCanBack)
//			cout << "YES" << endl;
//		else
//			cout << "NO" << endl;
//	}
//};
//
//int main() {
//	//	freopen("input.txt", "r", stdin);
//	//	freopen("output.txt", "w", stdout);
//
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	//\n faster than endl. endl makes buffer flush explicitly.
//	int tc;
//	cin >> tc;
//
//	for (size_t i = 0; i < tc; i++)
//	{
//		Solution solution;
//		solution.Invoke();
//	}
//
//	return 0;
//}