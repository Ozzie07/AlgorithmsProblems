//#include <bits/stdc++.h>
//#define MAX_EA 10001
//using namespace std;
//
//class BinaryIndexedTree //FanwickTree
//{
//
//	int tree[MAX_EA] = { 0, };
//	int arr[MAX_EA] = { 0, };
//	int n; //n == MAX_EA
//	int p(int k)
//	{
//		return k & -k;
//	}
//
//	int sum(int a, int b)
//	{
//		int s = 0;
//		while (a <= b)
//		{
//			s += arr[a];
//			a++;
//		}
//
//		return s;
//	}
//
//	void treeInit()
//	{
//		for (size_t i = 0; i < n; i++)
//		{
//			tree[i] = sum(i - p(i) + 1, i);
//		}
//	}
//
//
//	//preprocessing 과정이다.
//	int sum(int k) //구간합을 구하는 문제였다면... Sum을 통해서 했어야겠지?
//	{
//		int res = 0;
//		while (k >= 1)
//		{
//			res += tree[k]; //update한 tree를 가지고 있지 않네?
//			k -= k & -k;
//		}
//		return res;
//	}
//
//	void add(int k, int x) {
//		while (k <= n)
//		{
//			tree[k] += x;
//			k += k & -k;
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