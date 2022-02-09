//#include <bits/stdc++.h>
//#define INF 1000
//using namespace std;
//short dp[1001][1001][2]; 
//short min(short a, short b) { return a < b ? a : b; }
//
//class Solution
//{
//	string a;
//	string b;
//	int lcs[1001][1001];
//	int res = 0;
//public:
//	void GetInput()
//	{
//		getline(cin, a);
//		getline(cin, b);
//		cout << "----------a.size()--------------" << endl;
//		cout << a.size() << endl;
//		cout << "----------b.size()--------------" << endl;
//		cout << b.size() << endl;
//	}
//
//	void ShowLCS()
//	{
//		for (size_t i = 0; i < a.size(); i++)
//		{
//			for (size_t j = 0; j < b.size(); j++)
//			{
//				cout << lcs[i][j] << ' ';
//			}
//			cout << '\n';
//		}
//
//	}
//
//	void LCS()
//	{
//		int flag = 0;
//		for (size_t i = 0; i < a.size(); i++)
//		{
//			if (a[i] == b[0])
//				flag = 1;
//			lcs[i][0] = flag;
//		}
//		flag = 0;
//		for (size_t j = 0; j < b.size(); j++)
//		{
//			if (a[0] == b[j])
//				flag = 1;
//			lcs[0][j] = flag;
//		}
//
//		for (size_t i = 1; i < a.size(); i++)
//		{
//			for (size_t j = 1; j < b.size(); j++)
//			{
//				if (a[i] == b[j])
//				{
//					lcs[i][j] = lcs[i - 1][j - 1] + 1;
//				}
//				else
//				{
//					lcs[i][j] = max(lcs[i][j - 1], lcs[i - 1][j]);
//				}
//			}
//		}
//		ShowLCS();
//	}
//
//	int numOfPartition = 0;
//	int GetRes()
//	{
//		return numOfPartition;
//	}
//	bool IsPossible()
//	{
//		int LAST_i_POSITION;
//		int jInit = 0;
//		int LengthOfSequence = 0;
//		if (a[0] == b[0])
//			LAST_i_POSITION = -1;
//		else
//			LAST_i_POSITION = -2;
//		for (size_t i = 0; i < a.size(); i++)
//		{
//			for (size_t j = jInit; j < b.size(); j++)
//			{
//
//				if (a[i] == b[j])
//				{
//					if (LAST_i_POSITION + 1 != j) //바로 다음이 아님.
//						numOfPartition++;
//					jInit = j + 1;
//					LengthOfSequence++;
//					LAST_i_POSITION = j;
//					break;
//				}
//			}
//		}
//		cout << "-----------Length of Sequence------------" << endl;
//		cout << LengthOfSequence << endl;
//		if (LengthOfSequence == a.size())
//			return true;
//		return false;
//	}
//};
//
//int main()
//{
//
//	{
//		int i, j, r, na, nb;
//		char a[1004], b[1004];
//		cin >> (a);
//		cin >> (b);
//		na = strlen(a); nb = strlen(b);
//		if (na > nb) { puts("-1"); return 0; }
//		for (i = 1, dp[0][0][0] = 0, dp[0][0][1] = INF; i <= nb; i++) dp[0][i][0] = INF, dp[0][i][1] = 1;
//		for (i = 0; i < na; i++)
//		{
//			for (j = 0; j <= i; j++) dp[i + 1][j][0] = dp[i + 1][j][1] = INF;
//			for (j = i; j < nb; j++)
//			{
//				if (a[i] == b[j]) dp[i + 1][j + 1][0] = min(dp[i][j][0], dp[i][j][1]);
//				else dp[i + 1][j + 1][0] = INF;
//				dp[i + 1][j + 1][1] = min(dp[i + 1][j][0] + 1, dp[i + 1][j][1]);
//			}
//		}
//		r = min(dp[na][nb][0], dp[na][nb][1]);
//		printf("%d\n", (r >= INF) ? -1 : r);
//	}
//
//	Solution solution;
//	solution.GetInput();
//	if (solution.IsPossible())
//	{
//		cout << "-----------RES-----------" << endl;
//		cout << solution.GetRes() << endl;
//		cout << "------------------------" << endl;
//	}
//	else
//	{
//		cout << "-----------RES-----------" << endl;
//		cout << -1 << endl;
//		cout << "------------------------" << endl;
//	}
//
//}
