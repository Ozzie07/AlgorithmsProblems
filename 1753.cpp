#include <bits/stdc++.h>

using namespace std;

class Solution
{
	vector<pair<int, int>> adjList[20001];
	long long distance[20001];
	bool processed[20001] = { false, };
	int v, e;
	int s;
	void GetInput()
	{
		cin >> v >> e;
		cin >> s;
		s--;
		for (size_t i = 0; i < e; i++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			a--; b--;
			adjList[a].push_back({ b,c });
			//adjList[b].push_back({ a,c });
		}
	}

	void Dijkstra(int startPoint)
	{
		for (size_t i = 0; i < v; i++)
			distance[i] = LLONG_MAX >> 1;
		distance[startPoint] = 0;

		priority_queue<pair<int, int>> pq;
		pq.push({ 0, startPoint });

		while (!pq.empty())
		{
			int currentPosition = pq.top().second;
			pq.pop();
			if (processed[currentPosition])
				continue;
			processed[currentPosition] = true;

			for (auto e : adjList[currentPosition])
			{
				int d, w;
				d = e.first;  //stands for destination.
				w = e.second; //weight.
				if (distance[d] > distance[currentPosition] + w)
				{
					distance[d] = distance[currentPosition] + w;
					pq.push({ -distance[d], d });
				}
			}
		}
	}

public:
	void Invoke()
	{
		GetInput();
		Dijkstra(s);
		for (size_t i = 0; i < v; i++)
		{
			if (distance[i] == (LLONG_MAX >> 1))
				cout << "INF" << '\n';
			else
				cout << distance[i] << endl;
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