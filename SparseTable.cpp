////aurz.tistory.com/8
//#define MAX_LENGTH 1025
//#include <bits/stdc++.h>
//
//
//class ParseTable
//{
//	int n;
//	int sp[MAX_LENGTH][11]; // where 10 = K, MAX_LENGTH = 1025 이므로, 2^10 까지 구해야함.
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
//				//여기에 구하고자 하는 것을 넣음. 이 경우에는 구간 합이다.
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
//	//희소 테이블을 사용하면, 구간 최소 값을 O(1) 시간에 가능.
//	//... 이전에는 2의 거듭으로 log n 개의 구간들을 고려해야했찌만, RMQ에서는 그럴 필요가 없음.
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