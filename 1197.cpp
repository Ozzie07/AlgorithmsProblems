#include <bits/stdc++.h>

using namespace std;

class Solution
{
	int v, e;
	int link[10001];
	int size[10001];
	vector<tuple<int, int, int>> edges;

	void GetInput()
	{
		cin >> v >> e;
		for (size_t i = 0; i < e; i++)
		{
			long long a, b, c;
			cin >> a >> b >> c;
			tuple<int, int, int> edge = tie(a, b, c);
			tuple<int, int, int> edgeR = tie(b, a, c);
			edges.push_back(edge);
			edges.push_back(edgeR);
		}

		for (size_t i = 0; i < v; i++)
			link[i] = i;

		for (size_t i = 0; i < v; i++)
			size[i] = 1;
	}

	int Find(int x)
	{
		//while (link[x] != x)
		//	x = link[x];
		//return x;
		if (link[x] == x)
			return x;
		return link[x] = Find(link[x]);
	}

	bool Same(int a, int b)
	{
		if (Find(a) == Find(b))
			return true;
		return false;
	}

	void Unite(int a, int b) //b를 a로 연결시킴.
	{
		a = Find(a);
		b = Find(b);
		if (size[a] < size[b])
			swap(a, b);
		size[a] += size[b];
		link[b] = a;
	}

	int Kruskal()
	{
		bool (*cmp)(tuple<int, int, int> a, tuple<int, int, int> b) =
			[](tuple<int, int, int> a, tuple<int, int, int> b) {return get<2>(a) < get<2>(b); };

		sort(edges.begin(), edges.end(), cmp);

		int numOfEdge = 0;
		int totalValue = 0;

		for (auto edge : edges)
		{
			int a, b, c;
			tie(a, b, c) = edge;
			if (!Same(a, b))
			{
				Unite(a, b);
				numOfEdge++;
				totalValue += c;
			}
		}

		return totalValue;
	}
public:

	void Invoke()
	{
		GetInput();
		cout << Kruskal() << endl;
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