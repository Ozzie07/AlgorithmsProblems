#include <bits/stdc++.h>
using namespace std;

class Solution
{
	string a;
	string b;
	int lcs[1001][1001];
	bool record[17001] = { false, };

public:
	void GetInput()
	{
		cin >> a >> b;
	}

	void ShowLCS()
	{
		for (size_t i = 0; i < a.size(); i++)
		{
			for (size_t j = 0; j < b.size(); j++)
			{
				cout << lcs[i][j] << ' ';
			}
			cout << '\n';
		}

	}

	void LCS()
	{
		int flag = 0;
		for (size_t i = 0; i < a.size(); i++)
		{
			if (a[i] == b[0])
				flag = 1;
			lcs[i][0] = flag;
		}
		flag = 0;
		for (size_t j = 0; j < b.size(); j++)
		{
			if (a[0] == b[j])
				flag = 1;
			lcs[0][j] = flag;
		}

		for (size_t i = 1; i < a.size(); i++)
		{
			for (size_t j = 1; j < b.size(); j++)
			{
				if (a[i] == b[j])
				{
					lcs[i][j] = lcs[i - 1][j - 1] + 1;
				}
				else
				{
					lcs[i][j] = max(lcs[i][j - 1], lcs[i - 1][j]);
				}
			}
		}
		//ShowLCS();
		cout << lcs[a.size() - 1][b.size() - 1] << endl;
	}
};

int main() {
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	//\n faster than endl. endl makes buffer flush explicitly.
	{
		Solution solution;
		solution.GetInput();
		solution.LCS();
	}
	return 0;
};