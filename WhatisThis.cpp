//#include <bits/stdc++.h>
//
//using namespace std;
//
//class Solution
//{
//	int n;
//	int arr[1000001];
//	int length[1000001];
//	void GetInput()
//	{
//		cin >> n;
//		for (size_t i = 0; i < n; i++)
//		{
//			cin >> arr[i];
//		}
//
//		for (size_t i = 0; i < n; i++)
//		{
//			length[i] = 0;
//		}
//	}
//
//	void ShowLength()
//	{
//		cout << "----------------------------" << endl;
//		for (size_t i = 0; i < n; i++)
//		{
//			cout << length[i] << " ";
//		}
//		cout << "----------------------------" << endl;
//		
//	}
//
//	void UpdateLength()
//	{
//		length[0] = 1;
//		for (int i = 1; i < n; i++)
//		{
//			length[i] = 1;
//			for (int j = i - 1; j >= 0; j--)
//			{
//				cout << "arr[" << i << "] : " << arr[i];
//				cout << "  arr[" << j << "] : " << arr[j];
//				cout << endl;
//				if (arr[i] > arr[j])
//				{
//					length[i] = max(length[i], length[j] + 1);
//				}
//			}
//		}
//	}
//
//	int FindMax()
//	{
//		int localMax = 0;
//		for (size_t i = 0; i < n; i++)
//		{
//			localMax = max(length[i], localMax);
//		}
//
//		return localMax;
//	}
//
//public:
//	void Invoke()
//	{
//		GetInput();
//		UpdateLength();
//		cout << FindMax() << endl;
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
//	Solution solution;
//	solution.Invoke();
//
//	return 0;
//}