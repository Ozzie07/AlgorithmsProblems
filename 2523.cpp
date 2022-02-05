#include <bits/stdc++.h>

using namespace std;

int main() {
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	//\n faster than endl. endl makes buffer flush explicitly.
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cout << '*';
		}
		cout << '\n';
	}
	for (int i = n - 1; i > 0; i--)
	{
		for (int j = i; j > 0; j--)
		{
			cout << '*';
		}
		cout << '\n';
	}
	return 0;
}