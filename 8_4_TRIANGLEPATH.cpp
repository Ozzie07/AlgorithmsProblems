//#include <bits/stdc++.h>
//using namespace std;
//
//class Solution
//{
//	int n;
//	int Triangle[100][100];
//	int MEMO[100][100];
//	void GetInput()
//	{
//		cin >> n;
//		for (size_t i = 0; i < n; i++)
//		{
//			for (size_t j = 0; j <= i; j++)
//			{
//				cin >> Triangle[i][j];
//			}
//		}
//	}
//
//	void Memoization()
//	{
//		MEMO[0][0] = Triangle[0][0];
//		for (size_t i = 1; i < n; i++)
//		{
//			for (size_t j = 0; j <= i; j++)
//			{
//				if (j == 0)
//					MEMO[i][j] = Triangle[i][j] + MEMO[i - 1][0];
//				else
//				{
//					MEMO[i][j] = Triangle[i][j] + max(MEMO[i - 1][j], MEMO[i - 1][j - 1]);
//				}
//			}
//		}
//	}
//
//	int FindMax()
//	{
//		int result = 0;
//		for (size_t i = 0; i < n; i++)
//		{
//			result = max(MEMO[n - 1][i], result);
//		}
//		return result;
//	}
//
//public:
//	void Invoke()
//	{
//		GetInput();
//		Memoization();
//		cout << FindMax() << '\n';
//	}
//};
//
//int main() {
//	//	freopen("input.txt", "r", stdin);
//	//	freopen("output.txt", "w", stdout);
//
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	//\n faster than endl. endl makes buffer flush explicitly.
//	int tc;
//	cin >> tc;
//	for (size_t i = 0; i < tc; i++)
//	{
//		Solution sol;
//		sol.Invoke();
//	}
//	return 0;
//}