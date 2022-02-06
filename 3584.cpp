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
		//���̸� �����ϰ� ����.
		
			//���� �ϰ����� ���� y�� �� ���� �ִٰ� �����Ѵ�.
		if (depth[x] > depth[y])
		{
			swap(x, y);
		}
			//����� ���̸� �����ϰ� ����.

		for (int i = h; i >= 0; i--)
		{
			if (depth[y] - depth[x] >= (1 << i))
			{
				y = precomputed[y][i];
			}
		}
		//���̸� �����ϰ� ������� ��������? �ٷ� re-turn.
		if (x == y) return x;

		//������ ũ�⸸ŭ �Ž��� �ö󰡸�, �ּ��� ��츦 ã�´�.

		for (int i = h; i >= 0; i--)
		{
			if (precomputed[x][i] != precomputed[y][i])
			{
				x = precomputed[x][i];
				y = precomputed[y][i];
			}
		}

		//���� �����ϸ� ������ ���� �������� Ȯ��, �׸��� �� ��带 ��ȯ.
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