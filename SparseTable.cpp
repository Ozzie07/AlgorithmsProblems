////aurz.tistory.com/8
//#define MAX_LENGTH 1025
//#include <bits/stdc++.h>
//
//
//class ParseTable
//{
//	int n;
//	int sp[MAX_LENGTH][11]; // where 10 = K, MAX_LENGTH = 1025 �̹Ƿ�, 2^10 ���� ���ؾ���.
//	int A[MAX_LENGTH];
//	int LOG[MAX_LENGTH];
//
//	void Precomputation()
//	{
//		for (size_t i = 0; i < n; i++)
//		{
//			sp[i][0] = A[i];
//		}
//
//		for (int j = 1; j <= 10; j++)
//		{
//			for (int i = 0; i + (1 << j) <= n; i++)
//			{
//				//���⿡ ���ϰ��� �ϴ� ���� ����. �� ��쿡�� ���� ���̴�.
//				sp[i][j] = sp[i][j - 1] + sp[i + (1 << (j - 1))][j - 1];
//			}
//		}
//	}
//	
//	int RangeSumQuery(int a, int b)
//	{
//		int sum = 0;
//		for (int j = 10; j >= 0; j--)
//		{
//			if ((1 << j) <= b - a + 1)
//			{
//				sum += sp[b][j];
//				b += 1 << j;
//			}
//		}
//		return sum;
//	}
//
//	//Range Mininum Queries (RMQ)
//	//��� ���̺��� ����ϸ�, ���� �ּ� ���� O(1) �ð��� ����.
//	//... �������� 2�� �ŵ����� log n ���� �������� ����ؾ����, RMQ������ �׷� �ʿ䰡 ����.
//	//
//
//};
//int sp[1025][20];
//
//using namespace std;
//
//int main() {
//	//	freopen("input.txt", "r", stdin);
//	//	freopen("output.txt", "w", stdout);
//
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	//\n faster than endl. endl makes buffer flush explicitly.
//
//	return 0;
//}