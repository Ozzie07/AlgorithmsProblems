//#include <bits/stdc++.h>
//
//using namespace std;
//
//class Solution
//{
//	//Inputs
//	int n, k;
//	int coins[101];
//
//	//DP
//	int count[10001] = { 0, };
//
//	void GetInput()
//	{
//		cin >> n >> k;
//		for (size_t i = 0; i < n; i++)
//			cin >> coins[i];
//	}
//
//	void Show()
//	{
//		for (size_t i = 0; i <= k; i++)
//		{
//			cout << count[i] << " ";
//		}
//		cout << endl;
//	}
//
//	void Update()
//	{
//		count[0] = 1;
//		for (int i = 0; i < n; i++)
//		{
//			for (int j = coins[i]; j <= k; j++)//새로운 coins[i]를 추가했을 때의 경우의 수를 업데이트 한다.
//			{
//				count[j] = count[j] + count[j - coins[i]];
//			}
//		}
//	}
//
//public:
//	void Invoke()
//	{
//		GetInput();
//		Update();
//		cout << count[k];
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
//	Solution solution;
//	solution.Invoke();
//	return 0;
//}