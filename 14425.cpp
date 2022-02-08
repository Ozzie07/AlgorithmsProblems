//#include <bits/stdc++.h>
//
//using namespace std;
//
//
//
//class Trie {
//#define ALPHABET 26
//	Trie* ch[ALPHABET];
//	bool end;
//
//public:
//	Trie()
//	{
//		end = false;
//		for (int i = 0; i < ALPHABET; i++)
//		{
//			ch[i] = NULL;
//		}
//	}
//
//	//~Trie()
//	//{
//	//	for (int i = 0; i < ALPHABET; i++)
//	//	{
//	//		if (ch[i]) delete ch[i];
//	//	}
//	//}
//
//	void insert(const char* s);
//
//	bool find(const char* s)
//	{
//		if (!*s)
//		{
//			if (end) return  true;
//			return false;
//		}
//		int now = *s - 'a';
//		if (!ch[now]) return false;
//		return ch[now]->find(s + 1);
//	}
//};
//
//class TriePool
//{
//	Trie triePool[5'000'010];
//	int stkPtr = 0;
//
//public:
//	Trie* Get()
//	{
//		return &triePool[stkPtr++];
//	}
//};
//
//TriePool triePool;
//
//void Trie::insert(const char* s)
//{
//	//场何盒 贸府.
//	if (!*s)
//	{
//		this->end = true;
//		return;
//	}
//
//	int now = *s - 'a';
//	if (!ch[now]) ch[now] = triePool.Get();
//	ch[now]->insert(s + 1);
//}
//
//
//
//class Solution
//{
//	Trie trie;
//	//Trie* trie = new Trie();
//	int n, m;
//	int res = 0;
//public:
//	void Invoke()
//	{
//		cin >> n >> m;
//		for (size_t i = 0; i < n; i++)
//		{
//			string input;
//			cin >> input;
//			trie.insert(input.c_str());
//		}
//
//		for (size_t i = 0; i < m; i++)
//		{
//			string input;
//			cin >> input;
//			if (trie.find(input.c_str()))
//			{
//				res++;
//			}
//		}
//
//		cout << res << endl;
//	}
//};
//
//int main() {
//	//	freopen("input.txt", "r", stdin);
//	//	freopen("output.txt", "w", stdout);
//
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	Solution solution;
//	solution.Invoke();
//	//\n faster than endl. endl makes buffer flush explicitly.
//
//
//	return 0;
//}