//#include <bits/stdc++.h>
//
//using namespace std;
//
//class Solution
//{
//	int n;
//	int cnt = 0;
//	vector<int> LIS;
//
//
//public:
//	void ShowVector(vector<int> a)
//	{
//		for (int i : a)
//		{
//			cout << i << " ";
//		}
//		cout << endl;
//	}
//
//	void Invoke()
//	{
//		cin >> n;
//		LIS.push_back(0);
//		for (size_t i = 0; i < n; i++)
//		{
//			int a;
//			cin >> a;
//			if (LIS.back() < a)
//			{
//				LIS.push_back(a);
//				cnt++;
//			}
//			else
//			{
//				vector<int>::iterator low = lower_bound(LIS.begin(), LIS.end(), a);
//				*low = a;
//			}
//		}
//
//		cout << cnt;
//	}
//};
//int main() {
//	//	freopen("input.txt", "r", stdin);
//	//	freopen("output.txt", "w", stdout);
//
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	//\n faster than endl. endl makes buffer flush explicitly.
//	Solution solution;
//	solution.Invoke();
//	return 0;
//}