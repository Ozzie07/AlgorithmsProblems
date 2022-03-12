//#include <bits/stdc++.h>
//using namespace std;
//
//class Solution
//{
//	int n;
//	int arr[501];
//	int LIS[501];
//	void GetInput()
//	{
//		cin >> n;
//		arr[0] = 0;
//		for (size_t i = 1; i <= n; i++)
//		{
//			cin >> arr[i];
//		}
//	}
//
//	int MakeLISArray()
//	{
//		int res = 1;
//		LIS[0] = 0;
//		LIS[1] = 1;
//		for (size_t i = 2; i <= n; i++)
//		{
//			int maxIdx = 0; //indicates largest LIS[idx] while arr[idx] < arr[i]
//			int maxLIS = 0;
//			for (size_t j = 1; j < i; j++)
//			{
//				if (arr[i] > arr[j])
//				{
//					if (maxLIS < LIS[j])
//					{
//						maxIdx = j;
//						maxLIS = LIS[j];
//					}
//				}
//			}
//			LIS[i] = LIS[maxIdx] + 1;
//			res = max(res, LIS[i]);
//		}
//		return res;
//	}
//
//	void FINDLIS()
//	{
//		vector<int> vt;
//		vt.push_back(-INT_MAX);
//
//		for (size_t i = 1; i <= n; i++)
//		{
//			if (arr[i] <= vt.back())
//			{
//				*lower_bound(vt.begin(), vt.end(), arr[i]) = arr[i];
//			}
//			else if (arr[i] > vt.back())
//			{
//				vt.push_back(arr[i]);
//			}
//
//		}
//
//		cout << vt.size() - 1 << endl;
//	}
//
//	void ShowLIS()
//	{
//		cout << '\n';
//		for (size_t i = 0; i < n + 1; i++)
//		{
//			cout << LIS[i] << ' ';
//		}
//		cout << '\n';
//	}
//
//public:
//	void Invoke()
//	{
//		GetInput();
//		//cout << MakeLISArray() << '\n';
//		FINDLIS();
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
//
//	
//	return 0;
//}