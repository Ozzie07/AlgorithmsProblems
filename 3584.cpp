#include <bits/stdc++.h>

using namespace std;

class Solution
{
	vector<int> adjList[10001];
	int rootNode = 0;
	int depth[10001] = { 0, };
	int precomputed[10001][14] = { rootNode, };
	int x, y;
	int n;
	int h;
private:

public:
	void GetInput()
	{
		cin >> n;

		int a, b;
		cin >> a >> b;
		a--; b--;
		rootNode = a;
		adjList[a].push_back(b);
		adjList[b].push_back(a);

		for (size_t i = 0; i < n - 2; i++)
		{
			//Make Edges
			int a, b; //edges;
			cin >> a >> b;
			a--; b--;
			adjList[a].push_back(b);
			adjList[b].push_back(a);
		}
		//Ancestors
		cin >> x >> y;
		x--; y--;
		h = log2(n);
	}

	void DFS(int _rootNode, int previous)
	{
		for (int e : adjList[_rootNode])
		{
			if (e == previous)
				continue;
			depth[e] = depth[_rootNode] + 1;
			DFS(e, _rootNode);
			precomputed[e][0] = _rootNode;
		}
	}

	void SetParent()
	{
		for (size_t j = 1; j < h; j++)
		{
			for (size_t i = 0; i < n; i++)
			{
				precomputed[i][j] = precomputed[precomputed[i][j - 1]][j - 1];
			}
		}
	}

	int LCA(int x, int y)
	{
		//높이를 동일하게 맞춤.
		
			//논리의 일관성을 위해 y가 더 깊이 있다고 가정한다.
		if (depth[x] > depth[y])
		{
			swap(x, y);
		}
			//노드의 깊이를 동일하게 맞춤.

		for (int i = h; i >= 0; i--)
		{
			if (depth[y] - depth[x] >= (1 << i))
			{
				y = precomputed[y][i];
			}
		}
		//깊이를 동일하게 맞췄더니 같아졌다? 바로 re-turn.
		if (x == y) return x;

		//동일한 크기만큼 거슬러 올라가며, 최소인 경우를 찾는다.

		for (int i = h; i >= 0; i--)
		{
			if (precomputed[x][i] != precomputed[y][i])
			{
				x = precomputed[x][i];
				y = precomputed[y][i];
			}
		}

		//값이 동일하면 어디까지 값이 동일한지 확인, 그리고 그 노드를 반환.
		return precomputed[x][0];
	}

	void Invoke()
	{
		GetInput();
		DFS(rootNode, rootNode);
		SetParent();
		cout << LCA(x, y) + 1 << '\n';
	}
};

int main() {
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	//\n faster than endl. endl makes buffer flush explicitly.
	int t;
	cin >> t;
	for (size_t i = 0; i < t; i++)
	{
		Solution solution;
		solution.Invoke();
	}
	return 0;
}