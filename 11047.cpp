//#include <bits/stdc++.h>
//
//using namespace std;
//class Solution
//{
//	int n, k;
//	int arr[11];
//	void GetInput()
//	{
//		int res = 0;
//		cin >> n >> k;
//		for (size_t i = 0; i < n; i++)
//		{
//			cin >> arr[i];
//		}
//		for (int i = n - 1; i >= 0; i--)
//		{
//			if (k >= arr[i])
//			{
//				res += k / arr[i];
//				k = k % arr[i];
//			}
//		}
//		
//		cout << res;
//	}
//
//public:
//	void Invoke()
//	{
//		GetInput();
//	}
//
//};
//
//int main() 
//{
//	//	freopen("input.txt", "r", stdin);
//	//	freopen("output.txt", "w", stdout);
//
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	//\n faster than endl. endl makes buffer flush explicitly.
//	Solution solution;
//	solution.Invoke();
//
//	return 0;
//}