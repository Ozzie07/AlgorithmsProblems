#include <bits/stdc++.h>

using namespace std;



enum class Color {
	RED,
	GREEN,
};

int numOfComponents = 0;
bool colorRed = true;

void ColoringVertex_logic(int numOfVertex, int start, vector<int>* adjList, bool* visit, Color *color)
{
	if (visit[start])
	{
		return;
	}
	visit[start] = true;
	//doSomething
	if (colorRed)
		color[start] = Color::RED;
	else
		color[start] = Color::GREEN;
	colorRed = !colorRed;
	//
	for (int e : adjList[start])
	{
		ColoringVertex_logic(numOfVertex, e, adjList, visit, color);
	}
	colorRed = !colorRed;

}

void ColoringVertex(int numOfVertex, int start, vector<int>* adjList, bool* visit, Color* color)
{
	if (visit[start])
		return;
	ColoringVertex_logic(numOfVertex, start, adjList, visit, color);
}


void visitInit(bool* visit, int numOfVertex)
{
	for (size_t i = 0; i < numOfVertex; i++)
	{
		visit[i] = false;
	}
}

void StringColor(Color color)
{
	switch (color)
	{
	case Color::RED:
		cout << "RED" << endl;
		break;
	case Color::GREEN:
		cout << "GREEN" << endl;
	}
}

bool IsBipartite(int numOfVertex, vector<int>* adjList, bool* visit, Color* color)
{
	for (size_t i = 0; i < numOfVertex; i++)
	{
		for (int e : adjList[i])
		{
			//cout << i+1 << ": ";
			//StringColor(color[i]);
			//cout << e+1 << ": ";
			//StringColor(color[e]);
			//cout << endl;
			if (color[i] == color[e])
				return false;

		}
	}

	return true;
}



int main() {
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	//\n faster than endl. endl makes buffer flush explicitly.
	int n;
	cin >> n;

	for (size_t i = 0; i < n; i++)
	{
		vector<int> adjList[20001];
		bool visit[20001];
		Color color[20001];
		int v, e;
		cin >> v >> e;
		int s, d;
		for (size_t i = 0; i < e; i++)
		{
			cin >> s >> d;
			s--;
			d--;
			adjList[s].push_back(d);
			adjList[d].push_back(s);
		}
		visitInit(visit, v);
		for (size_t i = 0; i < v; i++)
		{
			ColoringVertex(v, i, adjList, visit, color);
		}
		visitInit(visit, v);

		if (IsBipartite(v, adjList, visit, color))
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}


	return 0;
}