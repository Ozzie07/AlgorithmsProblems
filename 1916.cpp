#include <bits/stdc++.h>
using namespace std;

class Graph
{
	int magicNumber = INT_MAX >> 1;
	int n, m;
	int distance[1001] = {};
	bool visited[1001] = {false,};
	int lastVisited[1001] = { 0, };
	vector<pair<int, int>> adjList[100001]; //adjList[_SOURCE] = {_DESTINATION, _WEIGHT}
	int start, destination;

public:
	void getInput()
	{
		cin >> n >> m;
		for (size_t i = 0; i < m; i++)
		{
			int s, d, w;
			cin >> s >> d >> w;
			adjList[s - 1].push_back({ d - 1, w }); //problem start idx from 1. you should notice that when make soltuion.

		}
		cin >> start >> destination;
		start--;
		destination--;
	}

	void Dijkstra(int startPoint)
	{
		Init();
		priority_queue<pair<int, int>> pq; //-distance, vertexIdx
		distance[startPoint] = 0;
		pq.push({0, startPoint});
		while (!pq.empty())
		{
			int current = pq.top().second;  pq.pop();
			if (visited[current])
				continue;
			visited[current] = true;

			for (pair<int, int> i : adjList[current])
			{
				if (distance[i.first] > distance[current] + i.second)
				{
					distance[i.first] = distance[current] + i.second; //값이 바뀌었다? Update가 필요한 시점이다~
					//lastVisited[i.first] = current;
					pq.push({ -distance[i.first], i.first });
				}
			}
		}
	}

	void Find()
	{
		Dijkstra(start);
		cout << distance[destination] << endl;
	}

	void Init()
	{
		for (size_t i = 0; i < n; i++)
		{
			distance[i] = magicNumber;
		}
	}

	void History()
	{
		int i = destination;
		stack<int> history;

		history.push(destination);
		while (lastVisited[i] != start)
		{
			i = lastVisited[i];
			history.push(i);
		}
		history.push(start);

		cout << history.size() << '\n';
		while (!history.empty())
		{
			cout << history.top() + 1 << ' ';
			history.pop();
		}
	}


	void Invoke()
	{
		getInput();
		Find();
		//History();
	}
};

int main() {
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	//\n faster than endl. endl makes buffer flush explicitly.
	Graph graph;
	graph.Invoke();

	return 0;
}