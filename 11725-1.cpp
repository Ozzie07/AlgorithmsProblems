#include <bits/stdc++.h>

using namespace std;

class Solution
{
	int n;
	vector<int> adjList[100001];
	bool visited[100001];
	int distance[100001];
	int history[100001];
	void GetInput()
	{
		cin >> n;
		for (size_t i = 0; i < n - 1; i++)
		{
			int s, d;
			cin >> s >> d;
			//s--; d--;
			adjList[s].push_back(d);
			adjList[d].push_back(s);
		}
	}

	void InitVisit()
	{
		for (size_t i = 0; i <= n; i++)
		{
			visited[i] = false;
		}
	}

	/*void DFS(int startPoint) //DFS는 왜 안되는가.
	{
		if (visited[startPoint])
			return;
		visited[startPoint] = true;
		cout << "current Node : " << startPoint << '\n';
		for (int e : adjList[startPoint])
		{
			if (!visited[e])
				history[startPoint] = e;
			DFS(e);
		}
	}*/

	void BFS(int startPoint)
	{
		queue<int> q;
		q.push(startPoint);
		visited[startPoint] = true;

		while (!q.empty())
		{
			//doSomething
			int current = q.front();
			q.pop();
			//
			for (int d : adjList[current])
			{
				if (visited[d])
					continue;
				q.push(d);
				history[d] = current;
				visited[d] = true;
			}
		}
	}

	void Print()
	{
		for (size_t i = 2; i <= n; i++)
			cout << history[i] << '\n';
	}

public:
	void Invoke()
	{
		GetInput();
		InitVisit();
		BFS(1);
		Print();
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