//#include <bits/stdc++.h>
//
//using namespace std;
//typedef long long Data;
//class ParseTableSolution
//{
//	int n, m;
//	Data arr[100001];
//	Data processed[100001][19];
//	int LOG[100002];
//
//	pair<Data, Data> pairs[100001];
//	void GetInput()
//	{
//		cin >> n >> m;
//		for (size_t i = 0; i < n; i++)
//		{
//			cin >> arr[i];
//		}
//		for (size_t i = 0; i < m; i++)
//		{
//			int a, b;
//			cin >> a >> b;
//			a--; b--;
//			pairs[i] = { a,b };
//		}
//
//	}
//
//	void Preprocess()
//	{
//		LOG[1] = 0;
//		for (size_t i = 2; i <= n; i++)
//		{
//			LOG[i] = LOG[i >> 1] + 1;
//		}
//
//		for (size_t i = 0; i < n; i++)
//		{
//			processed[i][0] = arr[i];
//		}
//		
//
//		for (int j = 1; j <= LOG[n]; j++)
//		{
//			for (int i = 0; i + (1<<j) <= n; i++)
//			{
//				//processed에서 i와 j의 역할이 무엇인지 생각해보면 알 수 있음. 다음 번에는 이걸 생각하자.
//				processed[i][j] = min(processed[i][j - 1],
//									  processed[i + (1 << (j - 1))][j - 1]);
//				//cout << "i : " << i << " j: " << j << " is " << processed[i][j] << '\n';
//			}
//		}
//	}
//
//	void LOGValueCheck()
//	{
//		for (size_t i = 0; i < n; i++)
//		{
//			cout << LOG[i] << endl;
//		}
//	}
//
//	int RangeMinQeury(int a, int b)
//	{
//		int j = LOG[b - a + 1];
//		return min(processed[a][j], 
//				   processed[b - (1 << j) + 1][j]);
//	}
//
//	void OutputMaker()
//	{
//		for (size_t i = 0; i < m; i++)
//		{
//			int a, b;
//			tie(a, b) = pairs[i];
//			cout << RangeMinQeury(a, b) << endl;
//		}
//	}
//
//public:
//	void Invoke()
//	{
//		GetInput();
//		Preprocess();
//		//LOGValueCheck();
//		OutputMaker();
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
//	ParseTableSolution solution;
//	solution.Invoke();
//
//	return 0;
//}