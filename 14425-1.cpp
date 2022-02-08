//#include <bits/stdc++.h>
//#include <unordered_set>
//
//using namespace std;
//unordered_set<string> s;
////s.find return iterator of set. if no such element is found. it returns s.end().
//string input;
//int n, m, res;
//
//int main() {
//	//	freopen("input.txt", "r", stdin);
//	//	freopen("output.txt", "w", stdout);
//
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cin >> n >> m;
//	for (size_t i = 0; i < n; i++)
//	{
//		cin >> input;
//		s.insert(input);
//	}
//
//	for (size_t i = 0; i < m; i++)
//	{
//		cin >> input;
//		
//		if (s.count(input))
//			res++;
//	}
//
//	cout << res << '\n';
//	//\n faster than endl. endl makes buffer flush explicitly.
//	return 0;
//}