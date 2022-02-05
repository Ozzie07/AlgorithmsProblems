//#include <bits/stdc++.h>
// Fanwick Tree, BinaryIndexedTree
//구간합을 구하는 녀석을 잘못사용했음.
//이 녀석을 사용하려면
// 어떤 넓은 범위에 대해 시행한 구간함수 질의 Q(a,b)에 대해서
// 그것보다 작은 구간에 대한 질의에서 포함된 녀석들을 서로 빼줄 수 있어야함.
// 이 min, max 케이스는 이 경우에 해당하지 않으므로 적용할 수 없다.
//using namespace std;
//
//class Solution
//{
//	int n, m;
//	int arr[100001];
//	int tree[100001];
//
//	pair<int, int> pairs[100001];
//
//	int RangeMin(int a, int b)
//	{
//		int res = INT_MAX >> 1;
//		while (a <= b)
//		{
//			res = RangeMin(arr[a], res);
//			a++;
//		}
//		return res;
//	}
//
//	int p(int k)
//	{
//		return k & -k;
//	}
//
//	void TreeInit()
//	{
//		for (size_t i = 1; i <= n; i++)
//			tree[i] = RangeMin(i - p(i) + 1, i);
//	}
//
//	void GetInput()
//	{
//		cin >> n >> m;
//		for (size_t i = 1; i <= n; i++)
//			cin >> arr[i];
//
//		for (size_t i = 1; i <= m; i++)
//		{
//			int a, b;
//			cin >> a >> b;
//			pairs[i] = { a,b };
//		}
//	}
//
//	int RangeMinfromOneTo(int _k)
//	{
//		int res = INT_MAX >> 1;
//		while (_k >= 1)
//		{
//			min(res, tree[_k]);
//			_k -= _k & -_k;
//		}
//		return res;
//	}
//
//	void PrintRes()
//	{
//		for (auto p : pairs)
//		{
//			min(RangeMinfromOneTo(p.second), RangeMinfromOneTo(p.first));
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
//
//
//	return 0;
//}