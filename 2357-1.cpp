#include <bits/stdc++.h>


//segment tree
using namespace std;

int Min(int a, int b)
{
	if (a > b)
		return b;
	return a;
}

int Max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}

vector<pair<int, int>> pairs;

class Solution
{
	int tree[300001];
	int n, m;
	int k; // k > n 을 만족하는 가장 작은 (2의 x승으로 나타낼 수 있는 수).
	int (*WhatYouWantTodo)(int a, int b);
	int initValue;
private:

public:
	void GetInput()
	{
		cin >> n >> m;
		int x = (int)log2(n);
		k = 1 << (x + 1); // k is the smallest value. when x is 2^x > n, k = 2^(x+1).

		for (size_t i = k; i < k + n; i++)
			cin >> tree[i];
		
		for (size_t i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b;
			a--;
			b--;
			pairs.push_back({ a, b });
		}
	}

	//with k notion, you should follow it. 
	//you should think dummy value that will no affect result.
	//ex) min(dummy, a) == a
	//ex2) max(dummy, a) == a
	void FillDummy(int InitValue) 
	{
		initValue = InitValue;
		for (size_t i = k + n; i < (2 * k); i++)
			tree[i] = InitValue;
	}

	int& prarentElem(int i)
	{
		return tree[i >> 1];
	}

	int& LchildElem(int i)
	{
		return tree[i << 1];
	}

	int& RchildElem(int i)
	{
		return tree[(i << 1) + 1];
	}

	void SetFunction(int(*func)(int, int))
	{
		WhatYouWantTodo = func;
	}

	void MakeTree() // O(n)
	{
		for (size_t i = k - 1; i > 0; i--)
		{
			tree[i] = WhatYouWantTodo(LchildElem(i), RchildElem(i));
		}
	}

	int SegmentQuery(int a, int b)
	{
		a += k; b += k;
		int res = initValue;
		while (a <= b) {
			if (a % 2 == 1) res = WhatYouWantTodo(res, tree[a++]);
			if (b % 2 == 0) res = WhatYouWantTodo(res, tree[b--]);
			a = a >> 1;  b = b >> 1;
		}

		return res;
	}
};

void MakeSol(Solution& solutionMin, Solution& solutionMax, pair<int, int>& pair)
{
	cout << solutionMin.SegmentQuery(pair.first, pair.second);
	cout << ' ';
	cout << solutionMax.SegmentQuery(pair.first, pair.second);
	cout << '\n';
}

int main() {
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	//\n faster than endl. endl makes buffer flush explicitly.
	{
		Solution solutionMin;
		Solution solutionMax;
		solutionMin.GetInput();
		solutionMax = solutionMin;

		//InitMinTree
		solutionMin.SetFunction(Min);
		solutionMin.FillDummy(INT_MAX >> 1);
		solutionMin.MakeTree();
		//InitMaxTree
		solutionMax.SetFunction(Max);
		solutionMax.FillDummy(0);
		solutionMax.MakeTree();

		for (auto p : pairs)
			MakeSol(solutionMin, solutionMax, p);
	}

	return 0;
}