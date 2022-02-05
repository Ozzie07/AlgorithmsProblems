//#include <bits/stdc++.h>
//using namespace std;
//
//class Solution
//{
//	int v;
//	vector<pair<int, int>> adjList[100001];
//	int numofEdge[100001];
//	int toLeaf[100001];
//	bool visited[100001] = { false, };
//	int findStartPoint = 3;
//private:
//	void GetInput()
//	{
//		cin >> v;
//		InitnumOfEdge();
//
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
//				//OUT
//				numofEdge[s]++;
//			}
//		}
//		InittoLeaf();
//		InitVisited();
//	}
//
//	void InitVisited()
//	{
//		for (size_t i = 0; i < v; i++)
//			visited[i] = false;
//	}
//
//	void InittoLeaf()
//	{
//		for (size_t i = 0; i < v; i++)
//		{
//			if (numofEdge[i] == 1)
//				toLeaf[i] = 0;
//			else
//				toLeaf[i] = -1;
//		}
//	}
//
//	void InitnumOfEdge() //Leaf 인가? 를 알기 위해서.
//	{
//		for (size_t i = 0; i < v; i++)
//		{
//			numofEdge[i] = 0;
//		}
//	}
//
//	void DFS_Tree(int s, int e)
//	{
//		cout << "current node : " << s << endl;
//		for (auto u : adjList[s])
//		{
//			if (u.first != e) DFS_Tree(u.first, s);
//		}
//	}
//
//	int ToLeaf(int x)
//	{
//		int max_local = 0;
//		if (visited[x])
//			return toLeaf[x];
//
//		visited[x] = true;
//		for (auto e : adjList[x])
//		{
//			if (toLeaf[e.first] != -1)
//			{
//				max_local = max((e.second + toLeaf[e.first]), max_local);
//			}
//			else
//			{
//				max_local = max((e.second + ToLeaf(e.first)), max_local);
//			}
//		}
//		//OUT
//		//cout << x << " : " << max_local << endl;
//		toLeaf[x] = max_local;
//		return max_local;
//	}
//
//	//void ShowtoLeaf()
//	//{
//	//	for (size_t i = 0; i < v; i++)
//	//	{
//	//		cout << "i : " << toLeaf[i] << endl;
//	//	}
//	//}
//
//	//0을 시작으로 하는 leaf까지의 거리 중에서 가장 긴 녀석 두 개를 선택하여 더함
//	//그 때의 destination도 저장해서 해당 edge의 weight도 더해야 함.
//	int pairSum(pair<int, int> &_a)
//	{
//		return _a.first + _a.second;
//	}
//
//	int maxLength()
//	{
//		vector<int> letsFindMax; //{weight, idx}
//
//		for (auto e : adjList[findStartPoint])
//		{
//			letsFindMax.push_back((toLeaf[e.first] + e.second));
//		}
//
//		if (letsFindMax.size() == 1)
//			return toLeaf[findStartPoint];
//
//		bool (*cmp)(int a, int b) = [](int a, int b) {return a > b; };
//		sort(letsFindMax.begin(), letsFindMax.end(), cmp);
//
//		return letsFindMax[0] + letsFindMax[1];
//	}
//
//public:
//	void Invoke()
//	{
//		cin >> findStartPoint;
//		GetInput();
//		ToLeaf(findStartPoint);
//		cout << maxLength() << endl;
//	}
//
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
//	while (true)
//	{
//		Solution solution;
//
//		solution.Invoke();
//	}
//	return 0;
//};