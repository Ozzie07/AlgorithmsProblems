//#include <bits/stdc++.h>
//using namespace std;
//
//struct Trie {
//#define ALPHABET 26
//	Trie* ch[ALPHABET];
//	bool end;
//
//	Trie()
//	{
//		end = false;
//		for (int i = 0; i < ALPHABET; i++) ch[i] == NULL;
//	}
//
//	~Trie()
//	{
//		for (int i = 0; i < ALPHABET; i++)
//		{
//			if (ch[i]) delete ch[i];
//		}
//	}
//
//	void insert(const char* s)
//	{
//		//场何盒 贸府.
//		if (!*s)
//		{
//			this->end = true;
//			return;
//		}
//
//		int now = *s - 'A';
//		if (!ch[now]) ch[now] = new Trie;
//		ch[now]->insert(s + 1);
//	}
//
//	bool find(const char* s)
//	{
//		if (!*s)
//		{
//			if (end) return  true;
//			return false;
//		}
//		int now = *s - 'A';
//		if (!ch[now]) return false;
//		return ch[now]->find(s + 1);
//	}
//};
//
//int main() {
//	Trie* root = new Trie;
//	string s;
//	root->insert(s.c_str());
//	string tmp = "AAA";
//	if (root->find(tmp.c_str())) cout << "Find!";
//	else cout << "No";
//	delete root;
//
//}