#include <bits/stdc++.h>

using namespace std;

class Solution
{
	int a, b, c;

public:
	void Invoke()
	{
		cin >> a >> b >> c;

		cout << (a + b) % c << '\n';
		cout << ((a % c) + (b % c)) % c << '\n';
		cout << (a * b) % c << '\n';
		cout << ((a % c) * (b % c)) % c << '\n';

	}
};

int main() {
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	Solution solution;
	solution.Invoke();
	//\n faster than endl. endl makes buffer flush explicitly.
	return 0;
}