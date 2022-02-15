#include <bits/stdc++.h>
using namespace std;

class Solution
{
	string parent;
private:

	void GetInput()
	{
		cin >> parent;
	}

	int MakeTable(string pattern)
	{
		int patternSize = pattern.size();
		vector<int> table(patternSize, 0);
		int max = 0;

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
				if (j > max)
					max = j;
			}
		}

		return max;
	}

	int FindMax()
	{
		int parentSize = parent.size();
		int max = 0;
		for (size_t i = 0; i < parentSize - 1; i++)
		{
			int localRes = MakeTable(parent);
			if (localRes > max)
				max = localRes;
			parent.erase(0, 1);
			//cout << parent << endl;
		}

		return max;
	}
public:
	void Invoke()
	{
		GetInput();
		cout << FindMax() << endl;;
	}

	void Test()
	{

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