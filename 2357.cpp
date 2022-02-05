//#include <bits/stdc++.h>
// Fanwick Tree, BinaryIndexedTree
//�������� ���ϴ� �༮�� �߸��������.
//�� �༮�� ����Ϸ���
// � ���� ������ ���� ������ �����Լ� ���� Q(a,b)�� ���ؼ�
// �װͺ��� ���� ������ ���� ���ǿ��� ���Ե� �༮���� ���� ���� �� �־����.
// �� min, max ���̽��� �� ��쿡 �ش����� �����Ƿ� ������ �� ����.
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