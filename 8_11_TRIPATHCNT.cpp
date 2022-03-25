//#include <bits/stdc++.h>
//using namespace std;
//
//class Solution
//{
//	int n;
//	int triangle[101][101];
//	int memo[101][101];
//	int numOfPath[101][101];
//
//	void GetInput()
//	{
//		cin >> n;
//		for (size_t i = 0; i < n; i++)
//		{
//			for (size_t j = 0; j <= i; j++)
//			{
//				cin >> triangle[i][j];
//			}
//		}
//	}
//
//	void InitMemo()
//	{
//		for (size_t i = 0; i < 101; i++)
//		{
//			for (size_t j = 0; j < 101; j++)
//			{
//				memo[i][j] = -1;
//			}
//		}
//	}
//
//	void InitnumOfPath()
//	{
//		for (size_t i = 0; i < 101; i++)
//		{
//			for (size_t j = 0; j < 101; j++)
//			{
//				numOfPath[i][j] = -1;
//			}
//		}
//	}
//
//	int MemoLargest(int i, int j)
//	{
//
//		if (i == n)
//			return 0;
//		int& ret = memo[i][j];
//		if (ret != -1)
//			return ret;
//
//		ret = INT_MAX;
//		ret = max(MemoLargest(i + 1, j + 1) + triangle[i][j], MemoLargest(i + 1, j) + triangle[i][j]);
//
//		return ret;
//	}
//
//	int FindPath(int i, int j)
//	{
//		int& ret = numOfPath[i][j];
//
//		if (i == n - 1) //basecase.
//			return ret = 1;
//
//		if (ret != -1)
//			return ret;
//
//		ret = 0;
//		if (memo[i + 1][j] + triangle[i][j] == memo[i][j])
//			ret += FindPath(i + 1, j);
//		//if (j == i)
//		//	return ret;
//
//		if (memo[i + 1][j + 1] + triangle[i][j] == memo[i][j])
//			ret += FindPath(i + 1, j + 1);
//
//		return ret;
//	}
//
//	void ShowTriangle()
//	{
//		cout << endl;
//		for (size_t i = 0; i < n; i++)
//		{
//			for (size_t j = 0; j <= i; j++)
//			{
//				cout << memo[i][j] << ' ';
//			}
//			cout << endl;
//		}
//		cout << endl;
//	}
//
//	void ShowPath()
//	{
//		cout << endl;
//		for (size_t i = 0; i < n; i++)
//		{
//			for (size_t j = 0; j <= i; j++)
//			{
//				cout << numOfPath[i][j] << ' ';
//			}
//			cout << endl;
//		}
//		cout << endl;
//	}
//
//
//public:
//	void Invoke()
//	{
//		GetInput();
//		InitMemo();
//		InitnumOfPath();
//		MemoLargest(0, 0);
//		//ShowTriangle();
//		int res = FindPath(0, 0);
//		//ShowPath();
//		cout << res << endl;
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
//
//	int tc;
//	cin >> tc;
//	for (size_t i = 0; i < tc; i++)
//	{
//		Solution sol;
//		sol.Invoke();
//	}
//
//	return 0;
//}