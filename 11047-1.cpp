//#include <bits/stdc++.h>
//
//using namespace std;
//
//
//class Solution
//{
//	int n;
//	int k;
//	int inf = INT_MAX >> 1;
//	vector<int> coins;
//
//	int RecursiveSolution(int x)
//	{
//		if (x < 0)
//		{
//			return inf;
//		}
//		if (x == 0) return 0;
//		int localMin = inf;
//
//		for (auto c : coins)
//		{
//			localMin = min(localMin, RecursiveSolution(x - c) + 1);
//		}
//
//		return localMin;
//	}
//
//public:
//
//	void sol()
//	{
//		cin >> n >> k;
//		for (size_t i = 0; i < n; i++)
//		{
//			int a;
//			cin >> a;
//			coins.push_back(a);
//		}
//		cout << RecursiveSolution(k) << endl;
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
//	Solution solution;
//	solution.sol();
//
//	return 0;
//};