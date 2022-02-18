//#include <bits/stdc++.h>
//using namespace std;
//void ShowVector(vector<pair<int, int>> vec);
//vector<int> MakeTable(string pattern);
//vector<pair<int, int>> KMP(string pattern, string parent);
//
//class Solution
//{
//	string Long;
//	string shorts[501];
//	vector<pair<int, int>> KMPResult[501];
//	bitset<100001> KMPResBit[501];
//
//	int n;
//
//	void GetInputAndMakeKMPTable()
//	{
//		cin >> Long;
//		cin >> n;
//		for (size_t i = 0; i < n; i++)
//		{
//			cin >> shorts[i];
//			KMPResult[i] = KMP(shorts[i], Long);
//			KMPResBit[i].reset();
//		}
//	}
//
//public:
//	void Solve()
//	{
//		GetInputAndMakeKMPTable();
//
//		////Debug
//		//for (size_t i = 0; i < n; i++)
//		//{
//		//	ShowVector(KMPResult[i]);
//		//}
//
//		MakeBitSet();
//
//		Compare();
//
//	}
//
//	void Comp()
//	{
//		int max = 0;
//		for (size_t i = 0; i < n; i++)
//		{
//			int local = KMPResult[i][0].second - KMPResult[i][0].first + 1;
//		}
//
//		for (size_t i = 0; i < n; i++)
//		{
//			for (size_t j = i + 1; j < n; j++)
//			{
//				int i_pointer = 0;
//				int i_first, i_second;
//
//				int j_pointer = 0;
//				int j_first, j_second;
//
//				i_first = KMPResult[i][i_pointer].first;
//				i_second = KMPResult[i][i_pointer].second;
//				j_first = KMPResult[j][j_pointer].first;
//				j_second = KMPResult[j][j_pointer].second;
//
//				if (i_first < j_first)
//				{
//
//				}
//				else
//				{
//
//				}
//			}
//		}
//	}
//
//	void Compare()
//	{
//		bitset<100001> res;
//		int max = 0;
//
//		for (size_t i = 0; i < n; i++)
//		{
//			int local = FindMostSuccessive(KMPResBit[i]);
//			if (max < local)
//				max = local;
//		}
//
//		for (size_t i = 0; i < n; i++)
//		{
//			for (size_t j = i + 1; j < n; j++)
//			{
//				res = KMPResBit[i] ^ KMPResBit[j];
//				int local = FindMostSuccessive(res);
//				if (max < local)
//					max = local;
//				// 최대로 1이 이어지는 길이를 측정해야함.
//				// max에 그 값을 저장하고,
//
//			}
//		}
//		cout << max;
//		//여기서 출력.
//	}
//
//
//	void MakeBitSet()
//	{
//		for (size_t i = 0; i < n; i++)
//		{
//			for (auto e : KMPResult[i])
//			{
//				for (size_t j = e.first; j <= e.second; j++)
//				{
//					KMPResBit[i].set(j, 1);
//				}
//			}
//		}
//	}
//
//	
//	int FindMostSuccessive(bitset<100001> input)
//	{
//		int max = 0;
//		for (size_t i = 0; i < Long.size(); i++)
//		{
//			if (input[i])
//			{
//				int local = 1;
//				for (size_t j = i + 1; j < Long.size(); j++)
//				{
//					if (input[j])
//					{
//						local++;
//					}
//					else
//					{
//						i = j + 1;
//						break;
//					}
//				}
//				if (max < local)
//					max = local;
//			}
//		}
//		return max;
//	}
//};
//
//void ShowVector(vector<pair<int, int>> vec)
//{
//	for (auto c : vec)
//	{
//		cout << "first : " << c.first << "   second : " << c.second << endl;
//	}
//}
//
//vector<int> MakeTable(string pattern)
//{
//	int size = pattern.size();
//	vector<int> res(size, 0);
//	int j = 0;
//	for (size_t i = 1; i < size; i++)
//	{
//		while (j > 0 && pattern[i] != pattern[j])
//		{
//			j = res[j - 1];
//		}
//
//		if (pattern[i] == pattern[j])
//		{
//			res[i] = ++j;
//		}
//	}
//
//	return res;
//}
//
//vector<pair<int, int>> KMP(string pattern, string parent)
//{
//	int patternSize = pattern.size();
//	int parentSize = parent.size();
//	vector<int> table = MakeTable(pattern);
//	int j = 0;
//	vector<pair<int, int>> res;
//
//	for (size_t i = 0; i < parentSize; i++)
//	{
//		while (j > 0 && parent[i] != pattern[j])
//		{
//			j = table[j - 1];
//		}
//
//		if(parent[i] == pattern[j])
//		{
//			// We did it!
//			if (j == patternSize - 1)
//			{
//				res.push_back({ i - patternSize + 1, i });
//				j = table[j];
//			}
//			++j;
//		}
//	}
//
//	return res;
//}
//
//
//int main() {
//	//	freopen("input.txt", "r", stdin);
//	//	freopen("output.txt", "w", stdout);
//
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	//\n faster than endl. endl makes buffer flush explicitly.
//	Solution solution;
//	solution.Solve();
//
//	return 0;
//}
//
///*for (size_t i = 0; i < n; i++)
//{
//	for (size_t j = i + 1; j < n; j++)
//	{
//		int i_pointer = 0;
//		int i_first, i_second;
//
//		int j_pointer = 0;
//		int j_first, j_second;
//
//		i_first = KMPResult[i][i_pointer].first;
//		i_second = KMPResult[i][i_pointer].second;
//		j_first = KMPResult[j][j_pointer].first;
//		j_second = KMPResult[j][j_pointer].second;
//		if (i_first < j_first)
//		{
//
//		}
//		else
//		{
//
//		}
//	}
//}*/