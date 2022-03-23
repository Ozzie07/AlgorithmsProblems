//#include <bits/stdc++.h>
//using namespace std;
//
//typedef long long Data;
//class Solution
//{
//	int n, m;
//	Data arr_n[100];
//	Data arr_m[100];
//	Data newArr[200];
//	int newArrSize;
//
//	void GetInput() 
//	{ 
//		cin >> n >> m; 
//		for (size_t i = 0; i < n; i++)
//		{
//			cin >> arr_n[i];
//		}
//		for (size_t i = 0; i < m; i++)
//		{
//			cin >> arr_m[i];
//		}
//	}
//	
//	void ResetNewArray()
//	{
//
//	}
//
//	void MakeNewArr(int cursor_n, int cursor_m)
//	{
//		int cursor = 0;
//		while (!(cursor_n == n || cursor_m == m))
//		{
//			if (arr_n[cursor_n] > arr_m[cursor_m])
//			{
//				newArr[cursor++] = arr_m[cursor_m++];
//			}
//			else
//			{
//				newArr[cursor++] = arr_n[cursor_n++];
//			}
//		}
//
//		if (cursor_n == n)
//		{
//			for (cursor_m; cursor_m < m; cursor_m++)
//			{
//				newArr[cursor++] = arr_m[cursor_m];
//			}
//		}
//
//		if (cursor_m == m)
//		{
//			for (cursor_n; cursor_n < n; cursor_n++)
//			{
//				newArr[cursor++] = arr_n[cursor_n];
//			}
//		}
//		newArrSize = cursor;
//
//		//ShowArr();
//	}
//
//	void ShowArr()
//	{
//		cout << "--------------------------SHOWARR---------------------------" << endl;
//		for (size_t i = 0; i < newArrSize; i++)
//		{
//			cout << newArr[i] << ' ';
//		}
//		cout << endl;
//		cout << "--------------------------SHOWARR---------------------------" << endl;
//	}
//
//	int FINDLIS()
//	{
//		vector<Data> vt;
//		vt.push_back(-(LLONG_MAX - 1));
//
//		for (size_t i = 0; i < newArrSize; i++)
//		{
//			if (newArr[i] <= vt.back())
//			{
//				*lower_bound(vt.begin(), vt.end(), newArr[i]) = newArr[i];
//			}
//			else if (newArr[i] > vt.back())
//			{
//				vt.push_back(newArr[i]);
//			}
//		}
//
//		return vt.size() - 1;
//	}
//
//
//public:
//	void Invoke()
//	{
//		GetInput();
//		int res = 0;
//		for (size_t i = 0; i < n; i++)
//		{
//			MakeNewArr(i, 0);
//			res = max(res, FINDLIS());
//			
//		}
//		for (size_t j = 0; j < m; j++)
//		{
//			MakeNewArr(0, j);
//			res = max(res, FINDLIS());
//		}
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
//	int tc;
//	cin >> tc;
//	for (size_t i = 0; i < tc; i++) 
//	{
//		Solution solution;
//		solution.Invoke();
//	}
//	return 0;
//}