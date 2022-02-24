//#include <bits/stdc++.h>
//using namespace std;
//
//class Solution
//{
//#define MAX 10
//#define INF 0x0fffffff
//
//	int n;
//	double dist[MAX][MAX];
//
//	double ShortestPath(vector<int>& path, vector<bool>& visited, double currentLength)
//	{
//		if (path.size() == n)
//		{
//			return currentLength + dist[path[0]][path.back()];
//		}
//		double ret = INF;
//
//		for (int next = 0; next < n; next++)
//		{
//			if (visited[next]) continue;
//			int here = path.back();
//			path.push_back(next);
//			visited[next] = true;
//			double cand = ShortestPath(path, visited, currentLength + dist[here][next]);
//
//			ret = min(ret, cand);
//			visited[next] = false;
//			path.pop_back();
//		}
//
//		return ret;
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
//
//}