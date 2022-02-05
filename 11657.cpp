#include <bits/stdc++.h>

using namespace std;

class Solution
{
	int n, m;
	vector<tuple<int, int, int>> edges;
	long long distance[501];
	bool isTimeCanBack = false;
	vector<int> adjList[501];
	bool visitable[501] = { false, };

	/*int lastVisited[501];
	void InitLastVisited()
	{
		for (size_t i = 0; i < n; i++)
		{
			lastVisited[i] = -1;
		}
	}*/

	void checkIsChanged(vector<int> &a, vector<int> &b)
	{
		int length = a.size();
		for (size_t i = 0; i < length; i++)
			if (a[i] != b[i])
				isTimeCanBack = true;
	}

	void InitVisitable()
	{
		for (size_t i = 0; i < n; i++)
			visitable[i] = false;
	}

	void DFS(int _startPoint, vector<int> &container)
	{
		if (visitable[_startPoint])
			return;
		visitable[_startPoint] = true;
		container.push_back(distance[_startPoint]);
		for (int e : adjList[_startPoint])
		{
			DFS(e, container);
		}
	}

	void GetInput()
	{
		cin >> n >> m;

		for (size_t i = 0; i < m; i++)
		{
			long long a, b, c;
			cin >> a >> b >> c;
			a--; b--;
			tuple<int, int, int> edge = tie(a, b, c);
			adjList[a].push_back(b);
			edges.push_back(edge);
		}
	}

	void BellmanFord(int _startPoint)
	{
		//DistanceInit
		long long magicNum = LLONG_MAX >> 1;
		for (size_t i = 0; i < n; i++)
			distance[i] = magicNum;
		distance[_startPoint] = 0;
		for (size_t i = 0; i < n-1; i++)
		{
			for (auto e : edges)
			{
//				bool isRelaxed = false;
				long long s, d, w;
				tie(s, d, w) = e;
				if (distance[d] > distance[s] + w)
				{
//					isRelaxed = true;
					distance[d] = distance[s] + w;
				}
			}
		}

		//Check for a Negative Cycle.
		vector<int> prev;
		vector<int> current;

		InitVisitable();
		DFS(0, prev);
		for (auto e : edges)
		{
			long long s, d, w;
			tie(s, d, w) = e;
			if (distance[d] > distance[s] + w)
			{
				distance[d] = distance[s] + w;
			}
		}
		InitVisitable();
		DFS(0, current);
		checkIsChanged(prev, current);
	}

	//void History(int _start, int _destination)
	//{
	//	int i = _destination;
	//	stack<int> history;

	//	do
	//	{
	//		if (lastVisited[i] == -1)
	//		{
	//			cout << -1 << '\n';
	//			return;
	//		}
	//		history.push(i);
	//		i = lastVisited[i];
	//	} while (_start = i);


	//	while (!history.empty())
	//	{
	//		cout << history.top() + 1 << ' '; history.pop();
	//	}
	//	cout << '\n';
	//}
public:
	void Invoke()
	{

		GetInput();
		BellmanFord(0);

		if (isTimeCanBack)
		{
			cout << -1;
		}
		else
		{
			for (size_t i = 1; i < n; i++)
			{
				if (visitable[i])
					cout << distance[i] << '\n';
				else
					cout << -1 << '\n';
			}
		}
	}
};


int main() {
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	//\n faster than endl. endl makes buffer flush explicitly.
	Solution solution;
	solution.Invoke();
	return 0;
}