#include <bits/stdc++.h>
using namespace std;
int memo[101];
int divider = 1000000007;

void InitMemo()
{
	for (size_t i = 0; i <= 100; i++)
	{
		memo[i] = -1;
	}
	memo[0] = 1;
	memo[1] = 1;
	memo[2] = 2;
}

class Solution
{
	int n;

	void GetInput()
	{
		cin >> n;
	}


	int Tiling(int n)
	{
		int& ret = memo[n];
		if (ret != -1)
			return ret;

		return ret = (Tiling(n - 1) + Tiling(n - 2)) % divider;
	}

	int AsymTiling(int n)
	{
		if (n % 2 == 1)
			return (Tiling(n) - Tiling(n / 2) + divider) % divider;
		int ret = Tiling(n);

		//MOD를 구할 때, Subtraction에서는 주의를 해주어야 한다.
		ret = (ret - Tiling(n / 2) + divider) % divider;
		ret = (ret - Tiling(n / 2 - 1) + divider) % divider;
		return ret;
	}
public:
	void Invoke()
	{
		GetInput();
		cout << AsymTiling(n) << endl;
	}
};


int main() {
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	InitMemo();

	ios::sync_with_stdio(0);
	cin.tie(0);
	//\n faster than endl. endl makes buffer flush explicitly.
	int tc;
	cin >> tc;

	for (size_t i = 0; i < tc; i++)
	{
		Solution solution;
		solution.Invoke();
	}
	return 0;
}