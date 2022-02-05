//#include <bits/stdc++.h>
//
//using namespace std;
//
//class Solution
//{
//	int numOfVertex, m;
//	int link[1001];
//	int size[1001];
//	vector<tuple<int, int, int>> edges;
//
//	bool (*cmp)(tuple<int, int, int> a, tuple<int, int, int> b) =
//		[](tuple<int, int, int> a, tuple<int, int, int> b) { return get<2>(a) < get<2>(b); };
//
//	/*struct cmp
//	{
//		bool operator(tuple<int, int, int> a, tuple<int, int, int> b)
//		{
//			return get<2>(a) < get<2>(b);
//		}
//	};*/
//	void GetInputs()
//	{
//		cin >> numOfVertex >> m;
//		for (size_t i = 0; i < m; i++)
//		{
//			int a, b, c;
//			cin >> a >> b >> c;
//			a--; b--;
//			tuple<int, int, int> edge = tie(a, b, c);
//			edges.push_back(edge);
//			tuple<int, int, int> edgeUndi = tie(b, a, c);
//			edges.push_back(edgeUndi);
//		}
//		
//
//		//UnionFind Init.
//		for (size_t i = 0; i < numOfVertex; i++)
//		{
//			link[i] = i;
//			size[i] = 1;
//		}
//	}
//
//	int Find(int _x)
//	{
//		//while (link[_x] != _x)
//		//{
//		//	_x = link[_x];
//		//}
//		//return _x;
//		if (_x == link[_x])  return _x;
//		return link[_x] = Find(link[_x]);
//	}
//
//	bool Same(int _a, int _b)
//	{
//		return Find(_a) == Find(_b);
//	}
//
//	void Unite(int _a, int _b)
//	{
//		_a = Find(_a);
//		_b = Find(_b);
//		if (size[_a] < size[_b]) swap(_a, _b);
//		size[_a] += size[_b];
//		link[_b] = _a;
//	}
//
//	/*void PrintEdge(vector<tuple<int, int, int>>& edges) {
//		for (auto edge : edges)
//		{
//			cout << get<0>(edge) + 1 << ' ' << get<1>(edge) + 1 << ' ' << get<2>(edge) << endl;
//		}
//	}*/
//
//	int KruskalAlgorithm()
//	{
//		sort(edges.begin(), edges.end(), cmp);
//		
//		int numOfEdge = 0;
//		int sum = 0;
//
//		for (auto edge : edges)
//		{
//			int a, b, c;
//			tie(a, b, c) = edge;
//			if (!Same(a, b))
//			{
//				Unite(a, b);
//				numOfEdge++;
//				sum += c;
//			}
//			if (numOfEdge - 1 == numOfVertex)
//				break;
//		}
//
//		return sum;
//	}
//
//public:
//	void Invoke()
//	{
//		GetInputs();
//		cout << KruskalAlgorithm();
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
//
//	Solution solution;
//	solution.Invoke();
//	return 0;
//}