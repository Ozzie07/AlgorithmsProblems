#include <bits/stdc++.h>
#define MAX_STUDENT 32001
#define MAX_EDGE 100001
using namespace std;

bool Visit[MAX_STUDENT] = { false, };
vector<int> adjList[MAX_STUDENT];
vector<int> TopologicalSort;

void DFS(int s)
{
	if (Visit[s])
	{
		return;
	}
	Visit[s] = true;
	for (int e : adjList[s])
	{
		DFS(e);
	}
	TopologicalSort.push_back(s);
}

int main() {
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	//\n faster than endl. endl makes buffer flush explicitly.

	
	int n, m;
	cin >> n >> m;
	for (size_t i = 0; i < m; i++)
	{
		int s, d;
		cin >> s >> d;
		adjList[s].push_back(d);
	}

	//sort(adjList->begin(), adjList->end());

	for (size_t i = 1; i <= n; i++)
	{
		DFS(i);
	}

	reverse(TopologicalSort.begin(), TopologicalSort.end());

	for (int i : TopologicalSort)
		cout << i << ' ';

	return 0;
}