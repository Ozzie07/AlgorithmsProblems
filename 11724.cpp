//#include <bits/stdc++.h>
//
//using namespace std;
//int Visit[1001] = {false, };
//vector<int> adj[1001];
//void DFS(int a);
//int res = 0;
//int n;
//int m;
//
//void Ans()
//{
//	for (size_t i = 0; i < n; i++)
//	{
//		if (!Visit[i])
//		{
//			DFS(i);
//			res++;
//		}
//	}
//}
//
//void DFS(int a)
//{
//	if (Visit[a])
//		return;
//	Visit[a] = true;
//	//Do Something
//	//
//	for (int e : adj[a])
//	{
//		DFS(e);
//	}
//}
//
//int main() {
//	//	freopen("input.txt", "r", stdin);
//	//	freopen("output.txt", "w", stdout);
//
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	//\n faster than endl. endl makes buffer flush explicitly.
//
//	
//
//	cin >> n >> m;
//
//	int s, d;
//	for (size_t i = 0; i < m; i++)
//	{
//		cin >> s >> d;
//		s--;
//		d--;
//		adj[s].push_back(d);
//		adj[d].push_back(s);
//	}
//
//	Ans();
//
//	cout << res;
//
//
//	return 0;
//}