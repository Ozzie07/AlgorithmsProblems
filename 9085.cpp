#include <bits/stdc++.h>

using namespace std;
int main() {
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	//\n faster than endl. endl makes buffer flush explicitly.
	int tc;
	int n;
	cin >> tc;
	for (size_t i = 0; i < tc; i++)
	{
		int sum = 0;
		cin >> n;
		for (size_t j = 0; j < n; j++)
		{
			int a;
			cin >> a;
			sum += a;
		}
		cout << sum << '\n';
	}
	
	return 0;
}