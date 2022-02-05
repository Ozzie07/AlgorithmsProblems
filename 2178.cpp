#include <bits/stdc++.h>

using namespace std;

class Solution
{
	int n, m;
	bool map[101][101] = { false, }; // false is true, ture is false, and also it indicates visited.
	int d_n[4] = { 0,0,1,-1 };
	int d_m[4] = { 1,-1,0,0 };
	int distance[101][101];

	bool isAllowMove(int _n, int _m)
	{
		if (_n >= 0 && _n < n && _m >= 0 && _m < m)
		{
			return true;
		}
		return false;
	}

	void getInput()
	{
		scanf("%d %d", &n, &m);
		for (size_t i = 0; i < n; i++)
			for (size_t j = 0; j < m; j++)
				scanf("%1d", &map[i][j]);
	}

	void BFS(pair<int, int> _startPoint, pair<int, int> _targetPoint)
	{
		if (!map[_startPoint.first][_startPoint.second])
			return;
		queue<pair<int, int>> q;
		q.push(_startPoint);

		map[_startPoint.first][_startPoint.second] = false; //See the description on map.'
		distance[_startPoint.first][_startPoint.second] = 1;

		while (!q.empty())
		{
			pair<int, int> currentPosition = q.front(); q.pop();
			//Dosomething.
			if (currentPosition == _targetPoint)
			{
				printf("%d\n", distance[currentPosition.first][currentPosition.second]);
				//cout << distance[currentPosition.first][currentPosition.second];
			}
			//
			for (size_t i = 0; i < 4; i++)
			{
				int n_n = currentPosition.first + d_n[i]; //where n stand for next.
				int n_m = currentPosition.second + d_m[i]; //where n stand for next.
				if (isAllowMove(n_n, n_m))
				{
					if (map[n_n][n_m])
					{
						map[n_n][n_m] = false;
						distance[n_n][n_m] = distance[currentPosition.first][currentPosition.second] + 1;
						q.push({ n_n,n_m });
					}
				}
			}
		}
	}
public:

	void Invoke()
	{
		getInput();
		BFS({ 0,0 }, { n - 1,m - 1 });
	}
};

int main() {
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);

	//\n faster than endl. endl makes buffer flush explicitly.

	Solution solution;
	solution.Invoke();

	return 0;
}