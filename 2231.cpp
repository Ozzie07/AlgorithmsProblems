#include <bits/stdc++.h>
using namespace std;

class Solution
{
#define MAX_VALUE 1'000'000
	int n;

	void GetInput()
	{
		cin >> n;
	}

	int FindAddFactor(int input, int cut)
	{
		if (cut == 0)
			return 0;
		int res = 0;
		int digit = 0;
		if (input >= cut)
		{
			digit = input / cut;
		}
		res += digit;
		input -= digit * cut;
		return res + FindAddFactor(input, cut / 10);
	}

	int MakeSepSum(int input)
	{
		return input + FindAddFactor(input, MAX_VALUE);
	}

	int FindMinConstructor()
	{
		for (size_t i = 1; i <= n; i++)
		{
			if (MakeSepSum(i) == n)
			{
				return i;
			}
		}
		return 0;
	}
	

public:
	void Invoke()
	{
		//TEST
		GetInput();
		cout << FindMinConstructor() << endl;
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