//#include <bits/stdc++.h>
//using namespace std;
//
//typedef long long Data;
//
//class Solution
//{
//	Data a, b, c;
//
//public:
//
//	void Solve()
//	{
//		cin >> a >> b >> c;
//
//		cout << Power(a, b) << endl;
//	}
//	
//	Data multi(Data start, Data end)
//	{
//		Data mid = (end + start) >> 1;
//		Data res;
//		if (end == start)
//		{
//			res = a % c;
//			return res;
//		}
//		else
//		{
//			res = (multi(start, mid) * multi(mid + 1, end)) % c;
//			return res;
//		}
//	}
//
//	Data Power(Data x, Data m)
//	{
//		if (m == 0)
//			return 1;
//		else if (m == 1)
//			return x % c;
//		else if (m % 2 > 0)
//			return (Power(x, m - 1) * x) % c;
//
//		//Note.
//		//(Power(x, m>>1)%c) * (Power(x, m>>1)%c) 보다 빠름.
//		Data local = Power(x, m >> 1) % c;
//		return (local * local) % c;
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
//	Solution solution;
//	solution.Solve();
//
//	return 0;
//}
