#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<set>
#include<tuple>
#include<queue>
using namespace std;
struct Trie
{
	struct node
	{
		int children[26];
		bool valid;
		node() {
			for (int i = 0; i < 26; i++) {
				children[i] = -1;
			}
			valid = false;
		}
	};
	vector<node> trie;
	int root;
	int init() {
		node x;
		trie.push_back(x);
		return (int)trie.size() - 1;
	}
	Trie() {
		root = init();
	}
	void add(int node, string& s, int idx) {
		if (idx == s.size()) {
			trie[node].valid = true;
			return;
		}
		int c = s[idx] - 'a';
		if (trie[node].children[c] == -1) {
			int next = init();
			trie[node].children[c] = next;
		}
		int child = trie[node].children[c];
		add(child, s, idx + 1);
	}
	void add(string& s) {
		add(root, s, 0);
	}
	bool search(int node, string& s, int idx) {
		if (node == -1) return false;
		if (idx == s.length()) return true;
		int c = s[idx] - 'a';
		int child = trie[node].children[c];
		return search(child, s, idx + 1);
	}
	bool search(string& s) {
		return search(root, s, 0);
	}
};
int main() {
	int n, m;
	cin >> n >> m;
	Trie trie;
	int ans = 0;
	while (n--) {
		string str;
		cin >> str;
		trie.add(str);
	}
	while (m--)
	{
		string str;
		cin >> str;
		if (trie.search(str)) {
			ans++;
		}
	}
	cout << ans;
	return 0;
}
