#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:

	int L;
	int N;
	//매 초 1회, 문자열 회전을 한다.
	string pattern;

public:

	void GetInput()
	{
		cin >> L >> pattern;
	}

	//Q. How to get N?

	void MakeTable()
	{
		int patternSize = pattern.size();
		vector<int> table(patternSize, 0);
		int j = 0;
		for (size_t i = 1; i < patternSize; i++)
		{
			while (j > 0 && pattern[i] != pattern[j])
			{
				j = table[j - 1];
			}

			if (pattern[i] == pattern[j])
			{
				table[i] = ++j;
			}
		}
		cout << L - table[L - 1];
	}
};



int main() {
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	Solution solution;
	solution.GetInput();
	solution.MakeTable();
	//\n faster than endl. endl makes buffer flush explicitly.


	return 0;
}