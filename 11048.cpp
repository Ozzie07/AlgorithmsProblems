#include <bits/stdc++.h>

using namespace std;

class Solution
{
	int n, m;
	int arr[1001][1001];
	int memo[1001][1001];
	void GetInput()
	{
		cin >> n >> m;
		for (size_t i = 0; i < n; i++)
		{
			for (size_t j = 0; j < m; j++)
			{
				cin >> arr[i][j];
			}
		}
	}

	void UpdateMemo()
	{
		memo[0][0] = arr[0][0];
		for (size_t i = 1; i < n; i++)
		{
			memo[i][0] = arr[i][0] + memo[i - 1][0];
		}
		for (size_t i = 1; i < m; i++)
		{
			memo[0][i] = arr[0][i] + memo[0][i - 1];
		}

		for (size_t i = 1; i < n; i++)
		{
			for (size_t j = 1; j < m; j++)
			{
				memo[i][j] = max(memo[i - 1][j], memo[i][j - 1]) + arr[i][j];
			}
		}
	}

public:
	void Invoke()
	{
		GetInput();
		UpdateMemo();
		cout << memo[n - 1][m - 1] << endl;
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