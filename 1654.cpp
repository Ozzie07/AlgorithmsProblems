//#include <bits/stdc++.h>
//
//using namespace std;
//class Solution
//{
//	int k, n;
//	priority_queue<int> origin_Values;
//	priority_queue<int> pq;
//
//	bool Try(int _length)
//	{
//		pq = origin_Values;
//
//		int _n = 0;
//		for (size_t i = 0; i < k; i++)
//		{
//			if (pq.top() < _length)
//				break;
//			_n += (pq.top() / _length); pq.pop();
//		}
//		if (_n >= n)
//			return true;
//		return false;
//	}
//
//	void GetInput()
//	{
//		cin >> k >> n;
//		for (size_t i = 0; i < k; i++)
//		{
//			int input;
//			cin >> input;
//			pq.push(input);
//		}
//		origin_Values = pq;
//	}
//
//	void BinarySearch()
//	{
//		int last = origin_Values.top();
//		int first = 0;
//		int mid;
//
//		while (last >= first)
//		{
//			mid = ((long long)last + (long long)first) >> 1;
//			if (mid == 0)
//				mid = 1;
//			if (Try(mid))
//			{
//				first = mid + 1;
//				if (!Try(mid + 1))
//					break;
//			}
//			else
//			{
//				last = mid - 1;
//			}
//		}
//
//		cout << mid;
//	}
//
//public:
//	Solution()
//	{
//		this->GetInput();
//		this->BinarySearch();
//	}
//
//
//};
//
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
//
//	return 0;
//}