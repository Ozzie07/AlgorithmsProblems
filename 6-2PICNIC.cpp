//#include <bits/stdc++.h>
//using namespace std;
//
//class Solution
//{
//	int n;
//	int m;
//	vector<tuple<int, int, int>> domodachi;
//	vector<tuple<int, int, int>> pairs;
//	int numOfCases = 0;
//
//	bool isPaired[10] = { false, };
//
//	void SetPair(const int &a, const int &b)
//	{
//		isPaired[a] = true;
//		isPaired[b] = true;
//	}
//
//	void UnSetPair(const int &a, const int &b)
//	{
//		isPaired[a] = false;
//		isPaired[b] = false;
//	}
//
//	bool IsCanBePair(const int& a, const int& b)
//	{
//		if (!isPaired[a] && !isPaired[b])
//		{
//			return true;
//		}
//		return false;
//	}
//
//	void GetInput()
//	{
//		cin >> n >> m;
//		for (size_t i = 0; i < m; i++)
//		{
//			int a, b;
//			cin >> a >> b;
//			tuple<int, int, int> local;
//			local = tie(i, a, b);
//			domodachi.push_back(local);
//		}
//	}
//
//	void MakePair()
//	{
//		int numYouSelect = n >> 1;
//		pick(pairs, numYouSelect);
//		cout << numOfCases << '\n';
//	}
//
//	void pick(vector<tuple<int, int ,int>> &picked, int toPick)
//	{
//		if (toPick == 0) { numOfCases++; return; }
//		int smallest = picked.empty() ? 0 : get<0>(picked.back()) + 1;
//
//		for (int next = smallest; next < m; ++next)
//		{
//			if (IsCanBePair(get<1>(domodachi[next]), get<2>(domodachi[next])))
//			{
//				SetPair(get<1>(domodachi[next]), get<2>(domodachi[next]));
//				picked.push_back(domodachi[next]);
//				pick(picked, toPick - 1);
//				picked.pop_back();
//				UnSetPair(get<1>(domodachi[next]), get<2>(domodachi[next]));
//			}
//		}
//	}
//
//public:
//	void Invoke()
//	{
//		GetInput();
//		MakePair();
//	}
//};
//
//int main() {
//	//	freopen("input.txt", "r", stdin);
//	//	freopen("output.txt", "w", stdout);
//
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	int tc;
//	cin >> tc;
//	for (size_t i = 0; i < tc; i++)
//	{
//		Solution solution;
//		solution.Invoke();
//	}
//
//	return 0;
//}