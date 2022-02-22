#include <bits/stdc++.h>
using namespace std;

class Solution
{
	int x;
	int n = 10;

	void GetInput()
	{
		cin >> x;
	}

	int pow(int mit, int seng)
	{
		int res = 1;
		while (seng > 0)
		{
			res = mit * res;
			seng--;
		}
		return res;
	}

	void Solve()
	{
		int res = 0;
		for (size_t i = 10; i > 0; i--)
		{
			if (x % pow(10, i) >= pow(10, i - 1))
			{
				int local = x - pow(10, i - 1);
				//cout << "i : " << i  << "  local : " << local + 1 << endl;
				res += (local + 1) * i;
				x = pow(10, i - 1) - 1;
			}
		}
		cout << res << endl; 
	}

public:
	void Invoke()
	{
		GetInput();
		Solve();
	}
};

int main() {
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	//\n faster than endl. endl makes buffer flush explicitly.
	Solution sol;
	sol.Invoke();

	return 0;
}