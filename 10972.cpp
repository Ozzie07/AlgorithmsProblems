//#include <bits/stdc++.h>
//using namespace std;
//
//class Solution
//{
//	int n;
//	vector<int> picked;
//	
//	void GetInput()
//	{
//		cin >> n;
//		for (size_t i = 0; i < n; i++)
//		{
//			int a;
//			cin >> a;
//			picked.push_back(a);
//		}
//	}
//
//	void pick(int n, vector<int>& picked, int toPick)
//	{
//		if (toPick == 0) {
//			printPicked(picked); return;
//		}
//		int smallest = picked.empty() ? 0 : picked.back() + 1;
//
//		for (int next = smallest; next < n; next++)
//		{
//			picked.push_back(next);
//			pick(n, picked, toPick - 1);
//			picked.pop_back();
//		}
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
//	return 0;
//}