//#include <bits/stdc++.h>
//using namespace std;
//vector<int> MakeTable(string pattern);
//bool KMP(string pattern, string parent);
//
//class Solution
//{
//	int N;
//	string S[1001]; //pattern
//	int Q;
//	string Qs[1001]; //parent
//
//	void GetInput()
//	{
//		cin >> N;
//		for (size_t i = 0; i < N; i++)
//		{
//			cin >> S[i];
//		}
//
//		cin >> Q;
//		for (size_t i = 0; i < Q; i++)
//		{
//			cin >> Qs[i];
//		}
//	}
//
//public:
//	void Invoke()
//	{
//		GetInput();
//
//		for (size_t i = 0; i < Q; i++)
//		{
//			bool isThere = false;
//			for (size_t j = 0; j < N; j++)
//			{
//				if (KMP(S[j], Qs[i]))
//				{
//					isThere = true;
//					break;
//				}
//			}
//			if (isThere)
//			{
//				cout << "YES" << '\n';
//			}
//			else
//			{
//				cout << "NO" << '\n';
//			}
//		}
//	}
//};
//
//vector<int> MakeTable(string pattern)
//{
//	int patternSize = pattern.size();
//	vector<int> table(patternSize, 0);
//	int j = 0;
//
//	for (size_t i = 1; i < patternSize; i++)
//	{
//		while (pattern[i] != pattern[j] && j > 0)
//		{
//			j = table[j - 1];
//		}
//
//		if (pattern[i] == pattern[j])
//		{
//			table[i] = ++j;
//		}
//
//	}
//
//	return table;
//}
//
//bool KMP(string pattern, string parent)
//{
//	int patternSize = pattern.size();
//	int parentSize = parent.size();
//	vector<int> table = MakeTable(pattern);
//
//	int j = 0;
//	for (size_t i = 0; i < parentSize; i++)
//	{
//		while (j > 0 && parent[i] != pattern[j])
//		{
//			j = table[j - 1];
//		}
//
//		if (parent[i] == pattern[j])
//		{
//			if (j == patternSize - 1)
//			{
//				return true;
//			}
//			j++;
//		}
//	}
//
//	return false;
//}
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