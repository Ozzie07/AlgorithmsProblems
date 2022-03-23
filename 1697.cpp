//#include <bits/stdc++.h>
//using namespace std;
//
////작을 때를 풀 수가 없음.
//
//
//class Solution
//{
//	int subin, brother;
//	int numbers[100001];
//	void GetInput()
//	{
//		cin >> subin >> brother;
//	}
//
//	void InitNumbers()
//	{
//		for (size_t i = 0; i < 100001; i++)
//		{
//			numbers[i] = -1;
//		}
//	}
//
//	int function(int n, int number)
//	{
//		if (numbers[number] != -1)
//			return numbers[number];
//		int ret = INT_MAX;
//		if (n == brother)
//			return number;
//		if (n >= brother + 2)
//			return INT_MAX;
//
//		if (n > brother / 2 + 1)
//			ret = min(ret, function(n - 1, number + 1));
//
//		ret = min(ret, function(n * 2, number + 1));
//		ret = min(ret, function(n + 1, number + 1));
//
//		return numbers[number] = ret;
//	}
//
//public:
//	void Invoke()
//	{
//		GetInput();
//		InitNumbers();
//		cout << function(subin, 0) << endl;;
//	}
//};
//
//int main() {
//	//	freopen("input.txt", "r", stdin);
//	//	freopen("output.txt", "w", stdout);
//
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	Solution sol;
//	sol.Invoke();
//	//\n faster than endl. endl makes buffer flush explicitly.
//	return 0;
//}