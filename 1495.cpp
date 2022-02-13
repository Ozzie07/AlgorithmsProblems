#include <bits/stdc++.h>
using namespace std;

class Solution
{
	int n, s, m;
	int volume[51];
	bool possibleVolume[51][1002] = { false, };
	void GetInput()
	{
		cin >> n >> s >> m;
		for (size_t i = 1; i <= n; i++)
		{
			cin >> volume[i];
		}
	}

	void MakeTree()
	{
		possibleVolume[0][s] = true;
		for (size_t i = 1; i <= n; i++)
		{
			for (size_t j = 0; j <= m; j++)
			{
				//find true
				if (possibleVolume[i - 1][j])
				{
					//for + volume[i];
					int R = j + volume[i];
					if (R <= m)
					{
						possibleVolume[i][R] = true;
					}

					int L = j - volume[i];
					if (L >= 0)
					{
						possibleVolume[i][L] = true;
					}
				}
			}
		}
	}

	void ShowTree()
	{
		for (size_t i = 0; i <= n; i++)
		{
			for (size_t j = 0; j <= m; j++)
			{
				cout << possibleVolume[i][j];
			}
			cout << endl;
		}
	}

	void ShowRes()
	{
		for (int i = m; i >= 0; i--)
		{
			if(possibleVolume[n][i])
			{
				cout << i;
				return;
			}
		}

		cout << -1;
	}

public:
	void Invoke()
	{
		GetInput();
		MakeTree();
		//ShowTree();
		ShowRes();
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