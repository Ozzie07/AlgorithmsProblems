//#include <bits/stdc++.h>
//using namespace std;
//
//typedef long long LL;
//
//class Solution
//{
//	LL n;
//	LL seriesOfOne = 1;
//	int lastAdd = 1; //1, 10, 100, 1000...
//	int res = 1;
//public:
//	void Invoke()
//	{
//		while (cin >> n)
//		{
//			seriesOfOne = 1;
//			lastAdd = 1;
//			res = 1;
//			while (true)
//			{
//				if (n == 0)
//				{
//					cout << res;
//					break;
//				}
//				AddOne(seriesOfOne);
//				n = seriesOfOne;
//			}
//		}
//	}
//
//	void AddOne(LL& _seriesOfOne)
//	{
//		lastAdd = multiply(lastAdd, 10);
//		_seriesOfOne = add(seriesOfOne, lastAdd);
//		res++;
//	}
//
//	LL multiply(LL a, LL b)
//	{
//		return ((a % n) * (b % n)) % n;
//	}
//
//	LL add(LL a, LL b)
//	{
//		return ((a % n) + (b % n)) % n;
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
