//#include <bits/stdc++.h>
//using namespace std;
//
//#define MAX_N 1001
//
//double cache[MAX_N][2 * MAX_N + 1];
//class Solution
//{
//	int n;
//	int m;
//
//	void GetInput()
//	{
//		cin >> n >> m;
//	}
//
//	void CacheInit()
//	{
//		for (size_t i = 0; i < MAX_N; i++)
//		{
//			for (size_t j = 0; j < 2 * MAX_N + 1; j++)
//			{
//				cache[i][j] = -1;
//			}
//		}
//	}
//
//	double climb(int days, int climbed)
//	{
//		if (days >= MAX_N || climbed >= 2 * MAX_N + 1)
//		{
//			cout << days << ' ' << climbed << endl;
//			exit(-1);
//		}
//		if (days == m) return climbed >= n ? 1 : 0;
//
//		double& ret = cache[days][climbed];
//		if (ret != -1) return ret;
//		//if (isMemoed[days][climbed]) return ret;
//		//isMemoed[days][climbed] = true;
//		return ret = 0.25 * climb(days + 1, climbed + 1) + 0.75 * climb(days + 1, climbed + 2);
//	}
//
//public :
//	void Invoke()
//	{
//		GetInput();
//		CacheInit();
//		cout << fixed << climb(0, 0) << endl;
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
//	//cout.precision(11);
//	cout.precision(10);
//	for (size_t i = 0; i < tc; i++)
//	{
//		Solution sol;
//		sol.Invoke();
//	}
//	return 0;
//}