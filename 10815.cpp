#include <bits/stdc++.h>

using namespace std;
bool BinarySearch(int* arr, int length, int target);

class Solution
{
	int n, m;
	int cards[500001];
	int targets[500001];
	void GetInput()
	{
		cin >> n;
		for (size_t i = 0; i < n; i++)
		{
			cin >> cards[i];
		}

		cin >> m;
		for (size_t i = 0; i < m; i++)
		{
			cin >> targets[i];
		}
	}

	void ShowArray()
	{
		for (size_t i = 0; i < n; i++)
		{
			cout << cards[i] << ' ';
		}
		cout << endl;
	}

public:
	void Solve()
	{
		GetInput();
		sort(cards, (cards + n));

		for (size_t i = 0; i < m; i++)
		{
			if (BinarySearch(cards, n, targets[i]))
				cout << '1' << ' ';
			else
				cout << '0' << ' ';
		}
	}
};

bool BinarySearch(int* arr, int length, int target)
{
	int start = 0;
	int end = length - 1;
	int mid;
	while (end >= start)
	{
		mid = (start + end) >> 1;

		if (arr[mid] == target)
			return true;
		else
		{
			if (arr[mid] < target)
				start = mid + 1;
			else
				end = mid - 1;
		}
	}

	return false; //failed.
}


int main() {
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	//\n faster than endl. endl makes buffer flush explicitly.

	Solution solution;
	solution.Solve();
	return 0;
}