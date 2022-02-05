//#include <bits/stdc++.h>
//#include "RandomNumberGenerator.h"
//using namespace std;
//
//class Solution
//{
//	int n;
//	long long arr[1000001];
//
//	bool check(long long* point, long long target)
//	{
//		if (*(point-1) < target && point[0] >= target)
//			return true;
//		return false;
//	}
//
//	int BinarySearch(long long* arr, int length, long long target)
//	{
//		int start = 0;
//		int end = length - 1;
//		int mid;
//		while (end >= start)
//		{
//			mid = (start + end) >> 1;
//			if (target == arr[mid] || check(&arr[mid], target))
//			{
//				return mid;
//			}
//			else
//			{
//				if (arr[mid] < target)
//				{
//					start = mid + 1;
//				}
//				else
//				{
//					end = mid - 1;
//				}
//			}
//		}
//		return -1;
//	}
//
//
//	int size = 0;
//	void MakeAns()
//	{
//		cin >> n;
//		cin >> arr[0];
//		size = 1;
//		for (size_t i = 1; i < n; i++)
//		{
//			int x;
//			cin >> x;
//			if (arr[size - 1] < x)
//			{
//				arr[size] = x;
//				size++;
//			}
//			else
//			{
//				int a = BinarySearch(arr, size, x);
//				if(arr[a] != -1)
//					arr[a] = x;
//			}
//			ShowArray();
//
//		}
//	}
//
//	void ShowArray()
//	{
//		for (size_t i = 0; i < size; i++)
//		{
//			cout << arr[i] << " ";
//		}
//		cout << endl;
//	}
//
//public:
//	int Invoke()
//	{
//		MakeAns();
//		return size;
//	}
//
//};
//
//class Solution2
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
//	int Invoke()
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
//		return cnt;
//	}
//};
//
//int main() {
//
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	//\n faster than endl. endl makes buffer flush explicitly.
//
//	bool isTest = true;
//	if (isTest)
//	{
//		while (true)
//		{
//			RandomNumberGenerator rnd;
//			freopen("input.txt", "w", stdout);
//			rnd.Init(10, 1, 100);
//			rnd.Generate();
//
//			//Generate Random input
//
//			fclose(stdout);
//			Solution sol1;
//			Solution2 sol2;
//
//			freopen("input.txt", "r", stdin);
//			int a = sol1.Invoke();
//			fclose(stdin);
//
//			freopen("input.txt", "r", stdin);
//			int b = sol2.Invoke();
//			fclose(stdin);
//
//			if (a != b)
//			{
//				freopen("result.txt", "w", stdout);
//				cout << a << " " << b << endl;
//				//save last input,
//				//print out
//				return 0;
//			}
//		}
//	}
//	else
//	{
//		Solution solution;
//		//Solution2 solution;
//
//		cout << solution.Invoke() << endl;
//
//	}
//
//	return 0;
//}
