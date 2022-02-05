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

	int lower_binary(int* arr, int length, int target)
	{
		int start = 0;
		int end = length - 1;
		int mid;
		while (end > start)
		{
			mid = (start + end) >> 1;
			if (arr[mid] >= target) //arr[mid]가 한 번 target과 동일한 녀석중 가장 왼쪽에 도달하면 더 이상은 움직이지 않음.
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
			if (arr[mid] > target) //arr[mid]가 target 보다 한 step 큰 지점에 도달하면 더 이상 움직이지 않음.
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
			int ub = upper_binary(cards, n, targets[i]);
			int num = 0;
			if (cards[lb] == targets[i])
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