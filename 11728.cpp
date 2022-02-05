#include <bits/stdc++.h>

using namespace std;

class Solution
{
	int n, m;
	int arr[2000001];
public:
	void GetInput()
	{
		cin >> n >> m;
		for (size_t i = 0; i < n+m; i++)
		{
			cin >> arr[i];
		}
		sort(arr, arr + n + m);
		for (size_t i = 0; i < n+m; i++)
		{
			cout << arr[i] << ' ';
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
	solution.GetInput();                                                
	return 0;
}