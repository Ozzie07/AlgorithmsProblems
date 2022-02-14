#include <bits/stdc++.h>
using namespace std;

class Solution
{
	int S, E, N;
	int t;
	int numbers[2001];
	bool isPalindrome[2001][2001] = { false, };
	bool processed[2001][2001] = { false, };

public:

	void GetInput()
	{
		cin >> N;
		for (size_t i = 1; i <= N; i++)
			cin >> numbers[i];

		cin >> t;
		for (size_t i = 0; i < t; i++)
		{
			cin >> S >> E;
			if (IsPalindrome(S, E))
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
			//find palindrome.
		}
	}

	bool IsPalindrome(int s, int e)
	{
		if (processed[s][e])
			return isPalindrome[s][e];

		int length = (e - s + 1);

		if (length == 1)
		{
			isPalindrome[s][e] = true;
		}
		else if (length == 2)
		{
			if (numbers[e] == numbers[s])
				isPalindrome[s][e] = true;
		}
		else if (length % 2 == 1)
		{
			if (numbers[e] == numbers[s] && IsPalindrome(s + 1, e - 1))
				isPalindrome[s][e] = true;
		}
		else if (length % 2 == 0)
		{
			if (numbers[s] == numbers[e] && IsPalindrome(s + 1, e - 1))
				isPalindrome[s][e] = true;
		}

		processed[s][e] = true;
		return isPalindrome[s][e];
	}
};

int main() {
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	//\n faster than endl. endl makes buffer flush explicitly.

	Solution solution;
	solution.GetInput();
	return 0;
}