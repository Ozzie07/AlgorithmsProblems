#include <bits/stdc++.h>
using namespace std;

vector<int> fail(string pattern)
{
	int length = pattern.size();
	vector<int> failTable(length, 0);

	int j = 0;
	for (size_t i = 1; i < length; i++)
	{
		while (j > 0 && pattern[i] != pattern[j])
		{
			j = failTable[j - 1];
		}

		if (pattern[i] == pattern[j])
		{
			failTable[i] = ++j;
		}
	}
	return failTable;
}

class Solution
{
	string s;

public:
	void Invoke()
	{
		while (cin >> s)
		{
			if (s == ".")
				break;
			vector<int> table = fail(s);

			int unitlength = s.length() - table[table.size() - 1];
			if (s.length() % unitlength == 0)
			{
				cout << s.length() / unitlength << '\n';
			}
			else
			{
				cout << 1 << '\n';
			}
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