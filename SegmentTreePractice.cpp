#include <bits/stdc++.h>
using namespace std;

typedef int LL;

class Solution
{
	int n, m;
	LL arr[100001];
	LL Tree[400004];
	LL PROBLEM_MAX = 1'000'000'010;
	pair<int, int> pairs[100001];
	int TreeHeight;
	int TreeSize; //Num of nodes in tree.

private:
	int RChildIdx(int k)
	{
		return (k << 1) + 1;
	}

	int LChildIdx(int k)
	{
		return (k << 1);
	}

	int ParentIdx(int k)
	{
		return k >> 1;
	}

	void GetInput()
	{
		cin >> n >> m;

		for (size_t i = 0; i < n; i++)
		{
			cin >> arr[i];
		}

		TreeHeight = (int)log2(n) + 2;

		for (size_t i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b;
			a--; b--;
			pairs[i] = { a,b };
		}
	}

	void TreeInit()
	{
		TreeSize = 1 << TreeHeight;

		int arrayOffset = TreeSize >> 1;
		int arrIdx = 0;

		for (size_t i = arrayOffset; i < arrayOffset + n; i++)
		{
			Tree[i] = arr[arrIdx++];
		}

		for (size_t i = arrayOffset + n; i < TreeSize; i++)
		{
			Tree[i] = PROBLEM_MAX;
		}

		for (int i = arrayOffset - 1; i > 0; i--)
		{
			Tree[i] = min(Tree[RChildIdx(i)], Tree[LChildIdx(i)]);
		}
	}

	LL RMQ(int a, int b)
	{
		a += (TreeSize >> 1);
		b += (TreeSize >> 1);

		LL res = PROBLEM_MAX;
		while (b >= a)
		{
			if (a % 2 == 1)
			{
				cout << "a++ occured" << endl;
				res = min(Tree[a++], res);
			}
			if (b % 2 == 0)
			{
				cout << "b-- occured" << endl;
				res = min(Tree[b--], res);
			}
			a = ParentIdx(a);
			b = ParentIdx(b);
			cout << "NEXT...." << endl;
			cout << "a : " << a << "   b : " << b << endl;
		}
		cout << "Finished";
		return res;
	}

	int RMQ(int a, int b)
	{
		a += TreeSize >> 1;
		b += TreeSize >> 1;

		LL res = PROBLEM_MAX;
		while (a <= b)
		{
			if (a % 2 == 1) min(Tree[a++], res);
			if (b % 2 == 0) min(Tree[b--], res);
			a = ParentIdx(a);
			b = ParentIdx(b);
		}
		return res;
	}

	int RAQ(int a, int b)
	{
		a += TreeSize >> 1;
		b += TreeSize >> 1;

		LL res = PROBLEM_MAX;
		while (a <= b)
		{
			if (a % 2 == 1) min(Tree[a++], res);
			if (b % 2 == 0) min(Tree[b--], res);
			a = ParentIdx(a);
			b = ParentIdx(b);
		}
		return res;
	}

public:

	void Invoke()
	{
		GetInput();
		TreeInit();

		for (size_t i = 0; i < m; i++)
		{
			cout << RMQ(pairs[i].first, pairs[i].second) << '\n';
		}
	}

};

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	Solution solution;
	solution.Invoke();
	return 0;
}