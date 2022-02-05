#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

class Solution
{
	int n, m, k;
	LL arr[1000001];
	LL Tree[5000000];
	int TreeHeight; // 보편적인 트리의 정의 + 1의 값을 담고 있음.
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
			Tree[i] = 0;
		}

		for (int i = arrayOffset - 1; i > 0; i--)
		{
			Tree[i] = (Tree[RChildIdx(i)] + Tree[LChildIdx(i)]);
		}
	}

	LL RangeSumQuery(int a, int b)
	{
		a += (TreeSize >> 1);
		b += (TreeSize >> 1);

		LL sum = 0;
		while (b >= a)
		{
			if (a % 2 == 1) sum += Tree[a++];
			if (b % 2 == 0) sum += Tree[b--];
			a = ParentIdx(a);
			b = ParentIdx(b);
		}
		return sum;
	}

	void Substitude(int k, LL x)
	{
		int arrayOffset = TreeSize >> 1;
		k += arrayOffset;

		x -= Tree[k];

		Tree[k] += x;
		for (k = ParentIdx(k); k >= 1; k = ParentIdx(k))
		{
			Tree[k] = Tree[RChildIdx(k)] + Tree[LChildIdx(k)];
		}
	}

public:
	void Invoke()
	{
		cin >> n >> m >> k;

		for (size_t i = 0; i < n; i++)
		{
			cin >> arr[i];
		}

		TreeHeight = (int)log2(n) + 2;

		TreeInit();

		for (size_t i = 0; i < m + k; i++)
		{
			int checker;
			int a, b;
			LL x;
			cin >> checker;
			if (checker == 1)
			{
				//a번째 수를 b로 바꾼다.
				cin >> a >> x;
				a--;
				Substitude(a, x);
			}
			else
			{
				//sum(a,b)를 구한다.
				cin >> a >> b;
				a--; b--;
				cout << RangeSumQuery(a, b) << '\n';
			}
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
