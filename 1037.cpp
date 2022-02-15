#include <bits/stdc++.h>

using namespace std;

class Solution
{
	int n;
	int arr[51];
	const int problem_Max = 1000001;
	const int problem_Min = 0;
public:
	void Invoke()
	{
		cin >> n;
		int min = problem_Max;
		int max = problem_Min;
		for (size_t i = 0; i < n; i++)
			cin >> arr[i];
		if (n == 1)
			cout << arr[0] * arr[0] << endl;
		else
		{
			//최소와 최대를 찾고 두 수를 곱한다.
			for (size_t i = 0; i < n; i++)
			{
				if (arr[i] > max)
					max = arr[i];
				if (arr[i] < min)
					min = arr[i];
			}
			cout << min * max << endl;
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