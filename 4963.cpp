#include <bits/stdc++.h>

using namespace std;

class Solution
{
	int dx_w[8] = { 1,-1,0,1,-1,0,1,-1 };
	int dx_h[8] = { 0,0,1,1,1, -1,-1,-1 };

	int cnt = 0;
	int w, h;
	int isVisited[51][51];

private:
	void VisitInit()
	{
		for (size_t i = 0; i < h; i++)
			for (size_t j = 0; j < w; j++)
				isVisited[i][j] = false;
	}

	bool IsAllowedAccess(int _h, int _w)
	{
		if ((_h < h && _h >= 0) && (_w < w && _w >= 0))
			return true;
		return false;
	}

	void DFS(pair<int, int> start)
	{
		if (isVisited[start.first][start.second])
			return;
		int x_h = start.first;
		int x_w = start.second;
		isVisited[x_h][x_w] = true;

		for (size_t i = 0; i < 8; i++)
		{
			int nx_h = x_h + dx_h[i];
			int nx_w = x_w + dx_w[i];
			if (IsAllowedAccess(nx_h, nx_w))
				DFS({ nx_h, nx_w });
		}
	}
public:
	Solution() { 
		while (true)
		{
			//VisitInit();
			cin >> w >> h;
			if (!w)
				if (!h)
					break;
			for (size_t i = 0; i < h; i++)
				for (size_t j = 0; j < w; j++)
				{
					int input;
					cin >> input;
					isVisited[i][j] = !input;
				}
			MakeSolution();
		}
	}

	void MakeSolution()
	{
		cnt = 0;

		for (size_t i = 0; i < h; i++)
		{
			for (size_t j = 0; j < w; j++)
			{
				if (!isVisited[i][j])
				{
					DFS({ i,j });
					cnt++;
				}
			}
		}
		cout << cnt << endl;
	}
};

int main() {
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	//\n faster than endl. endl makes buffer flush explicitly.
	Solution solution;

	return 0;
}