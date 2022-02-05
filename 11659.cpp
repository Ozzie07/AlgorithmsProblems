//#include <bits/stdc++.h>
//
//using namespace std;
//
//class Solution
//{
//	int n;
//	int m;
//	int arr[100001] = { 0, };
//
//
//public:
//
//	void Invoke()
//	{
//		cin >> n >> m;
//		cin >> arr[0];
//
//		for (size_t i = 1; i < n; i++)
//		{
//			int x;
//			cin >> x;
//			arr[i] = arr[i - 1] + x;
//		}
//		for (size_t i = 0; i < m; i++)
//		{
//			int a, b;
//			cin >> a >> b;
//			a--;
//			b--;
//
//			if (a)
//				cout << arr[b] - arr[a - 1] << '\n';
//			else
//				cout << arr[b] << '\n';
//		}
//	}
//	
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
//	solution.Invoke();
//
//	return 0;
//}