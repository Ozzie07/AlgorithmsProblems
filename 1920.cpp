#include <bits/stdc++.h>
using namespace std;

class Solution
{
	int n, m;
	int arr[100001];
	int targets[100001];

	void GetInput()
	{
		cin >> n;
		for (size_t i = 0; i < n; i++)
		{
			cin >> arr[i];
		}

		cin >> m;
		for (size_t i = 0; i < m; i++)
		{
			cin >> targets[i];
		}
	}

	int BSearch(int arr[], int length, int target)
	{
		int first = 0;
		int last = length - 1;
		int mid;
		while (first <= last)
		{
			mid = (first + last) / 2;
			if (target == arr[mid])
			{
				return 1;
			}
			else
			{
				if (target < arr[mid])
					last = mid - 1;
				else
					first = mid + 1;
			}
		}

		return 0;
	}

public:
	void Invoke()
	{
		GetInput();
		sort(arr, arr + n);
		for (size_t i = 0; i < m; i++)
		{
			cout << BSearch(arr, n, targets[i]) << '\n';
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