#include <bits/stdc++.h>
using namespace std;

class Solution
{
	int n;
	int m;
	vector<int> adjList[50001];
	vector<pair<int, int>> input;
	int history[50001];
	int distance[50001] = { 0, };
	int height = 0;
	int parent[50001][17]; //parent[n][i] = The 2^i th parent node of n.
	void GetInput()
	{
		cin >> n;
		for (size_t i = 0; i < n-1; i++)
		{
			int s, d;
			cin >> s >> d;
			s--;
			d--;
			adjList[s].push_back(d);
			adjList[d].push_back(s);
		}

		cin >> m;
		for (size_t i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b;
			a--; b--;
			input.push_back(make_pair(a, b));
		}
	}

	void DFS(int startPoint, int prev)
	{
		if (height < distance[startPoint])
			height = distance[startPoint];

		for (int e : adjList[startPoint])
		{
			if (prev == e)
				continue;
			parent[e][0] = startPoint;
			distance[e] = distance[startPoint] + 1;
			DFS(e, startPoint);
		}
	}

	//for DFS.
	//void ShowDistance()
	//{
	//	for (size_t i = 0; i < n; i++)
	//	{
	//		cout << "distance[" << i + 1 << "] : " << distance[i] << endl;
	//	}
	//}

	int log2_h;
	void setParent() {
		DFS(0, 0);
		log2_h = (int)log2(height);

//		ShowDistance();
		for (int i = 1; i <= log2_h + 1; i++)
		{
			for (int j = 0; j < n; j++)
			{
				parent[j][i] = parent[(parent[j][i - 1])][i - 1];
			}
		}
	}

	int LCA(int x, int y)
	{
		//�Ʒ��� �ڵ尡 Ŀ���� �ʵ���, �ڵ忡 �ϰ����� �������� y�� ũ�ٰ� �����Ѵ�.
		if (distance[x] > distance[y])
		{
			swap(x, y);
		}

		//�� ��带 ���� ���̷�
		for (int i = log2_h +1 ; i >= 0; i--)
		{
			if (distance[y] - distance[x] >= (1 << i))
			{
				y = parent[y][i];
			}
		}
		//cout << "----------------------" << endl;
		//cout << "distance[y] : " << distance[y] << "   distance[x] : " << distance[x] << endl;
		//cout << "----------------------" << endl;

		if (x == y) return x;

		//���� ���̱��� ������, ���� ���� ����(i)�� �ö󰡸鼭 ���� ������ ã��.
		for (int i = log2_h + 1; i >= 0; i--)
		{
			//cout << "parent[" << x + 1 << ']' << '[' << i + 1 << ']' << " :   " << parent[x][i] << endl; 
			//cout << "parent[" << y + 1 << ']' << '[' << i + 1 << ']' << " :   " << parent[y][i] << endl;
			if (parent[x][i] != parent[y][i]) //���ʿ��� ���� ���ٴ� ���� �̹� ���� ������ �����ٴ� �ǹ�, �� �Ʒ����� ���� Ʋ���ٴ� ���� �� �ö󰡾� �Ѵٴ� �ǹ�.
			{

				x = parent[x][i];
				y = parent[y][i];
			}
		}

		return parent[x][0];
	}


public:
	void Invoke()
	{
		GetInput();
		setParent();
		//ShowParent();
		for (size_t i = 0; i < m; i++)
		{
			int x, y;
			tie(x, y) = input[i];
			cout << LCA(x, y) + 1 << '\n';
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