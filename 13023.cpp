#include <bits/stdc++.h>

using namespace std;

bool Visit[2001] = { false, };
vector<int> adjList[2001];
int indicator = 0;

priority_queue<int> pq;

void DFS(int start)
{
	if (Visit[start])
		return;
	Visit[start] = true;
	//Do
	if (indicator == 4)
	{
		cout << 1;
		exit(0);
	}
	//Something which you want to do.
	for (int e : adjList[start])
	{
		indicator++;
		DFS(e);
		indicator--;

	}
	Visit[start] = false;
}

int main() {
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	//\n faster than endl. endl makes buffer flush explicitly.


	int n;
	int m;
	cin >> n >> m;

	int s, d;
	for (size_t i = 0; i < m; i++)
	{
		cin >> s >> d;
		adjList[s].push_back(d);
		adjList[d].push_back(s);
	}

	for (size_t i = 0; i < n; i++)
	{
		DFS(i);
	}

	cout << 0;
	return 0;
}