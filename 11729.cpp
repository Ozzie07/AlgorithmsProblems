#include <bits/stdc++.h>

using namespace std;


bool isEven;

int F(int level)
{
	if (level == 1)
		return 1;
	return 1 + 2 * F(level - 1);
}

void Move(int level, int from, int to, int sub)
{
	if (level == 1)
		cout << from << ' ' << to << '\n';
	else
	{
		Move(level - 1, from, sub, to);
		cout << from << ' ' << to << '\n';
		Move(level - 1, sub, to, from);
	}
}
class Solution
{
	int n;

public:
	void GetInput()
	{
		cin >> n;
		cout << F(n) << '\n';
		Move(n, 1, 3, 2);
	}
};

int main() {
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	//\n faster than endl. endl makes buffer flush explicitly.
	Solution sol;
	sol.GetInput();
	return 0;
}