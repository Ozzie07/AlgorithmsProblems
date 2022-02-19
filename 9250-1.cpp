#include <bits/stdc++.h>
#include "timer.h"
using namespace std;



class Trie
{
public:
	Trie* go[26];
	Trie* fail;
	bool output;

	Trie()
	{
		;
	}

	void TrieInit()
	{
		fill(go, go + 26, nullptr);
		output = false;
	}

	void Insert(const char* key);

};

//for ObjectPooling;
Trie trie[105001];
int numOfElem = 1;

void Trie::Insert(const char* key)
{
	{
		if (*key == '\0')
		{
			output = true;
			return;
		}
		int next = *key - 'a';
		if (!go[next])
		{
			go[next] = &trie[numOfElem++];
			go[next]->TrieInit();
		}
		go[next]->Insert(key + 1);
	}
}


class Solution
{
	int N, M;
	char str[10001];
	Trie* root = &trie[0];

public:
	void Invoke()
	{
		{
			Timer timer;
			root->TrieInit();
			scanf("%d", &N);
			for (int i = 0; i < N; i++)
			{
				scanf("%s", str);
				root->Insert(str);
			}
			timer.elapsed();
		}
		{
			Timer timer;
			BFS();
			timer.elapsed();
		}
		{
			Timer timer;
			Solve();
			timer.elapsed();
		}
	}

	void BFS()
	{
		queue<Trie*> Q;
		root->fail = root;
		Q.push(root);
		while (!Q.empty())
		{
			Trie* current = Q.front();
			Q.pop();
			for (int i = 0; i < 26; i++)
			{
				Trie* next = current->go[i];
				if (!next) continue;

				if (current == root) next->fail = root;
				else
				{
					Trie* dest = current->fail;

					while (dest != root && !dest->go[i])
						dest = dest->fail;

					if (dest->go[i]) dest = dest->go[i];
					next->fail = dest;
				}

				if (next->fail->output) next->output = true;

				Q.push(next);
			}
		}
	}

	void Solve()
	{
		scanf("%d", &M);
		for (size_t i = 0; i < M; i++)
		{
			scanf("%s", str);
			Trie* current = root;

			bool result = false;

			for (size_t j = 0; str[j]; j++)
			{
				int next = str[j] - 'a';

				while (current != root && !current->go[next])
					current = current->fail;

				if (current->go[next])
					current = current->go[next];

				if (current->output)
				{
					result = true;
					break;
				}
			}
			printf("%s\n", result ? "YES" : "NO");
		}
	}

};

int main() {
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	//\n faster than endl. endl makes buffer flush explicitly.

	Solution solution;
	solution.Invoke();
	return 0;
}