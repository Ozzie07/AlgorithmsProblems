//#include <bits/stdc++.h>
//using namespace std;
//
//class Solution
//{
//	const int INF = 987654321;
//	//A[] : ����ȭ�ؾ� �� ����, ������ ����
//	//pSum[] : A[]�� �κ����� �����Ѵ�. pSum[i]�� A[0].. A[i]�� ��
//	//pSqSum[] : A[] ������ �κ����� �����Ѵ�. pSqSum[i]�� A[0]^2 .. A[i]^2�� ��.
//	int n; int m;
//	int A[101], pSum[101], pSqSum[101];
//
//	void GetInput()
//	{
//		cin >> n;
//		cin >> m;
//		for (size_t i = 0; i < n; i++)
//		{
//			cin >> A[i];
//		}
//
//	}
//
//	void ShowArr(int* A)
//	{
//		cout << "------------------SHOWARRAY-------------------" << endl;
//		for (size_t i = 0; i < n; i++)
//		{
//			cout << A[i] << ' ';
//		}
//		cout << endl;
//		cout << "------------------SHOWARRAY-------------------" << endl;
//	}
//
//	void precalc()
//	{
//		sort(A, A + n);
//		pSum[0] = A[0];
//		pSqSum[0] = A[0] * A[0];
//		for (int i = 1; i < n; ++i)
//		{
//			pSum[i] = pSum[i - 1] + A[i];
//			pSqSum[i] = pSqSum[i - 1] + A[i] * A[i];
//		}
//	}
//
//	//Eq => ans = sqSum(a to b) - 2 * m * Sum(a to b) + m ^ 2 * (b - a + 1);
//
//	int minError(int lo, int hi)
//	{
//		//�κ� ���� �̿��ؼ� Sum, Sqsum�� ����.
//		int sum = pSum[hi] - (lo == 0 ? 0 : pSum[lo - 1]);
//		int sqSum = pSqSum[hi] - (lo == 0 ? 0 : pSqSum[lo - 1]);
//		// [lo, hi] ������ m �̶�� ���� ����ȭ�� ����. m�� ���. ������� ����ȭ ���� �� minError�� ���� �ּҰ� �� �� �ִ�.
//		int m = int(0.5 + ((double)sum / (hi - lo + 1)));
//
//		// sum(A[i] - m) ^ 2 �� ������ ����� �κ� ������ ǥ���ϱ�.
//		int ret = sqSum - 2 * m * sum + m * m * (hi - lo + 1);
//		return ret;
//	}
//
//	int cache[101][11];
//	
//	void CacheInit()
//	{
//		for (size_t i = 0; i <= n; i++)
//		{
//			for (size_t j = 0; j <= m; j++)
//			{
//				cache[i][j] = -1;
//			}
//		}
//	}
//
//	int quantize(int from, int parts)
//	{
//		//base case :  ��� ���ڸ� �� ����ȭ ���� ��,
//		if (from == n) return 0;
//		//base case :  ���ڴ� ���� ���Ҵµ�, �� ���� �� ���� �� ���� ū ���� ��ȯ�Ѵ�.
//		if (parts == 0)return INF;
//		int& ret = cache[from][parts];
//
//		if (ret != -1) return ret;
//		ret = INF;
//
//		for (int partSize = 1; from + partSize <= n; ++partSize)
//		{
//			ret = min(ret, minError(from, from + partSize - 1) + quantize(from + partSize, parts - 1));
//		}
//
//		return ret;
//	}
//public:
//	void Invoke()
//	{
//		GetInput();
//		CacheInit();
//		precalc();
//		cout << quantize(0, m) << endl;
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
//	int tc;
//	cin >> tc;
//	for (size_t i = 0; i < tc; i++)
//	{
//		Solution sol;
//		sol.Invoke();
//	}
//	return 0;
//}