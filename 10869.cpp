#include <bits/stdc++.h>

using namespace std;

int main() {
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	//\n faster than endl. endl makes buffer flush explicitly.
	int a, b;
	cin >> a >> b;
	cout << a + b << '\n';
	cout << a - b << '\n';
	cout << a * b << '\n';
	cout << a / b << '\n';
	cout << a % b << '\n';
	return 0;
}