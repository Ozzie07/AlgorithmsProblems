#include <bits/stdc++.h>
using namespace std;

class Solution
{
	int n;
public:
	void Invoke()
	{
		while (cin >> n)
		{
			int i = 0;
			int sum = 0;
			int res = 1;
			while (true)
			{
				sum = (res + sum) % n;
				if (sum == 0)
					break;
				i++;
				res = (res * 10) % n;
			}
			cout << i + 1 << endl;
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