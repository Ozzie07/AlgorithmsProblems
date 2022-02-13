#include <bits/stdc++.h>
using namespace std;


int ABS(int a)
{
	if (a < 0)
		return -a;
	return a;
}

int main() {
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	int x, l, r;
	cin >> x >> l >> r;
	if ((l <= x) && (x <= r))
	{
		cout << x;
	}
	else
	{
		if (ABS(x - l) > ABS(x - r))
		{
			cout << r;
		}
		else
		{
			cout << l;
		}
	}
	
	//\n faster than endl. endl makes buffer flush explicitly.
	return 0;
}