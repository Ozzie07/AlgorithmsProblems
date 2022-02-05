#include <bits/stdc++.h>

using namespace std;

bool visit1[1001] = { false, };
bool visit2[1001] = { false, };
vector<int> adj[1001];

void BFS(int startPoint)
{
	if (visit1[startPoint])
		return;
	visit1[startPoint] = true;
	//
	cout << startPoint << ' ';
	//
	for (int u : adj[startPoint])
		BFS(u);
}
int main() {
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	//\n faster than endl. endl makes buffer flush explicitly.

	int n, m, s;
	cin >> n >> m >> s;

	int source, destination;
	for (size_t i = 0; i < m; i++)
	{
		cin >> source >> destination;
		adj[source].push_back(destination);
		adj[destination].push_back(source);
	}

	for (size_t i = 1; i <= n; i++)
		sort(adj[i].begin(), adj[i].end());

	//BFS
	BFS(s);

	cout << '\n';
	//DFS
	{
		queue<int> q;
		
		visit2[s] = true;
		q.push(s);

		while (!q.empty())
		{
			int c = q.front();
			q.pop();
			//
			cout << c << ' ';
			//
			for (int u : adj[c])
			{
				if (visit2[u])
					continue;
				q.push(u);
				visit2[u] = true;
			}
		}
	}
	return 0;
}