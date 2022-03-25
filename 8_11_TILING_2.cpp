//#include <bits/stdc++.h>
//using namespace std;
//int memo[101];
//int divider = 1000000007;
//class Solution
//{
//	int n;
//
//	void GetInput()
//	{
//		cin >> n;
//	}
//
//
//	int Tiling(int n)
//	{
//		int& ret = memo[n];
//		if (ret != -1)
//			return ret;
//
//		return ret = (Tiling(n - 1) + Tiling(n - 2)) % divider;
//	}
//
//public:
//	void Invoke()
//	{
//		GetInput();
//		cout << Tiling(n) << endl;;
//	}
//};
//void InitMemo()
//{
//	for (size_t i = 0; i <= 100; i++)
//	{
//		memo[i] = -1;
//	}
//	memo[0] = 0;
//	memo[1] = 1;
//	memo[2] = 2;
//}
//
//int main() {
//	//	freopen("input.txt", "r", stdin);
//	//	freopen("output.txt", "w", stdout);
//	InitMemo();
//
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	//\n faster than endl. endl makes buffer flush explicitly.
//	int tc;
//	cin >> tc;
//
//	for (size_t i = 0; i < tc; i++)
//	{
//		Solution solution;
//		solution.Invoke();
//	}
//	return 0;
//}