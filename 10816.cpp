#include <bits/stdc++.h>

using namespace std;
int BinarySearch(int* arr, int length, int target);
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

	int lower_binary(int* arr, int length, int target)
	{
		int start = 0;
		int end = length - 1;
		int mid;
		while (end > start)
		{
			mid = (start + end) >> 1;
			if (arr[mid] >= target)
				end = mid;
			else start = mid + 1;
		}
		return end;
	}

	int upper_binary(int* arr, int length, int target)
	{
		int start = 0;
		int end = length - 1;
		int mid;
		while (end > start)
		{
			mid = (start + end) >> 1;
			if (arr[mid] > target)
				end = mid;
			else start = mid + 1;
		}
		return end;
	}

public:
	void Solve()
	{
		GetInput();
		sort(cards, (cards + n));
		for (size_t i = 0; i < m; i++)
		{
			int lb = lower_binary(cards, n, targets[i]);
			bool isExist = BinarySearch(cards, n, targets[i]);
			int ub = upper_binary(cards, n, targets[i]);
			int num = 0;
			//cout << "target : " << targets[i] << ' ';
			//cout << "isExist : " << isExist << ' ';
			//cout << "lb : " << lb << ' ';
			//cout << "ub : " << ub << '\n';

			if (isExist)
			{
				if (lb == ub)
					num++;
				else
				{
					if (cards[lb] == targets[i])
					{
						num++;
					}
					if (cards[ub] == targets[i])
					{
						num++;
					}
					num += (ub - lb - 1);
				}
				cout << num << ' ';
			}
			else
				cout << 0 << ' ';
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
	solution.Solve();
	return 0;
}