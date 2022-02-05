//#include <bits/stdc++.h>
//
//using namespace std;
//
//class Solution
//{
//
//	int N;
//	int Dp[1001] = { 0, };
//
//public:
//	void Sol()
//	{
//		Dp[1] = 1;
//
//		cin >> N;
//
//		for (int i = 1; i <= N; i++) 
//		{
//			int num;
//			cin >> num;
//
//			if (Dp[i] == 0) //i 까지 도달할 수 없음.
//				continue;
//			for (int j = 1; (j <= num) && (i + j <= 1000); j++) 
//			{
//				if (Dp[i + j] > Dp[i] + 1 || Dp[i + j] == 0)
//					Dp[i + j] = Dp[i] + 1;
//			}
//		}
//
//
//		if (Dp[N] == 0)
//			cout << -1 << endl;
//		else
//			cout << Dp[N] - 1 << endl;
//	}
//
//	void Show(int* arr)
//	{
//		for (size_t i = 0; i < N; i++)
//			cout << arr[i] << ' ';
//		cout << endl;
//	}
//
//	void invoke()
//	{
//		Sol();
//		//Show(Dp);
//	}
//};
//
//int main() {
//
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	Solution solution;
//	solution.invoke();
//	return 0;
//}