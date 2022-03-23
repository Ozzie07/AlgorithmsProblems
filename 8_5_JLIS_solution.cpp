//#include <bits/stdc++.h>
//using namespace std;
//
//typedef long long DATA;
//
//class Solution
//{
//	const DATA NEGINF = LLONG_MIN;
//	int n, m, A[100], B[100];
//	int cache[101][101];
//	// min(A[indexA], B[indexB], max(A[indexA], B[indexB])) 로 시작하는
//	// 합친 증가 부분 수열의 최대 길이를 반환한다.
//	// 단 indexA == indexB == -1 혹은 A[indexA] != B[indexB] 라고 가정한다.
//	
//	void CacheInit()
//	{
//		for (size_t i = 0; i < 101; i++)
//		{
//			for (size_t j = 0; j < 101; j++)
//			{
//				cache[i][j] = -1;
//			}
//		}
//	}
//
//	void GetInput()
//	{
//		cin >> n >> m;
//		for (size_t i = 0; i < n; i++)
//		{
//			cin >> A[i];
//		}
//
//		for (size_t j = 0; j < m; j++)
//		{
//			cin >> B[j];
//		}
//		CacheInit();
//
//	}
//
//	vector<DATA> vt;
//
//	int jlis(int indexA, int indexB) //jlis의 정의. indexA와 indexB에서 시작하는 jlis의 최대 길이를 반환.
//	{
//		//memoization
//		int& ret = cache[indexA + 1][indexB + 1];
//		if (ret != -1) return ret;
//
//		//A[indexA], B[indexB] 가 이미 존재.. 2개는 항상 있다.
//		if (A[indexA] == B[indexB])
//			ret = 1;
//		else
//			ret = 2;
//
//		DATA a = (indexA == -1 ? NEGINF : A[indexA]);
//		DATA b = (indexB == -1 ? NEGINF : B[indexB]);
//		DATA maxElement = max(a, b);
//
//		//다음 원소를 찾는다.
//		for (int nextA = indexA + 1; nextA < n; ++nextA)
//		{
//			if (maxElement < A[nextA])
//				ret = max(ret, jlis(nextA, indexB) + 1);
//		}
//		for (int nextB = indexB + 1; nextB < m; ++nextB)
//		{
//			if (maxElement < B[nextB])
//				ret = max(ret, jlis(indexA, nextB) + 1);
//		}
//		cout << "index A : " << indexA << " index B : " << indexB << " ret : " << ret << endl; 
//		return ret;
//	}
//
//	void JLIS(int indexA, int indexB)
//	{
//		int result;
//		if (A[n - 1] == B[n - 1])
//			result = 1;
//		else
//			result = 2;
//
//		int i = n - 2;
//		int j = m - 2;
//		while (true)
//		{
//
//		}
//
//		for (indexB = m; indexB >= 0; indexB--)
//		{
//
//		}
//	}
//
//public:
//	void Invoke()
//	{
//		GetInput();
//		int res = jlis(-1, -1) - 2;
//		if (res == 0)
//			cout << 1 << endl;
//		else
//			cout << res << endl;
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
//	int tc;
//	cin >> tc;
//	for (size_t i = 0; i < tc; i++)
//	{
//		Solution solution;
//		solution.Invoke();
//	}
//	return 0;
//}