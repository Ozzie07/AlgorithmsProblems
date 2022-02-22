#include <bits/stdc++.h>
using namespace std;

class Solution
{
	int h, w;
	bool board[21][21];
	int numOfWhite = 0;
	int numOfCases = 0;
	void Initboard()
	{
		for (size_t i = 0; i < 21; i++)
		{
			for (size_t j = 0; j < 21; j++)
			{
				board[i][j] = false;
			}
		}
	}

	//false : 채워져 있거나, Out of Index. true : 채울 수 있음.
	bool isEmpty(int _i, int _j)
	{
		if ((_i >= 0 && _i < h) && (_j >= 0 && _j < w))
		{
			if (!board[_i][_j])
				return true;
		}

		return false;
	}

	void GetInput()
	{
		cin >> h >> w;
		Initboard();
		char a;
		for (size_t i = 0; i < h; i++)
		{
			for (size_t j = 0; j < w; j++)
			{
				a = getchar();
				if (a == '.')
				{
					numOfWhite++;
				}
				else if (a == '#')
				{
					board[i][j] = true;
				}
				else
				{
					j--;
				}
			}
		}
		ShowBoard();
	}

	void ShowBoard()
	{
		cout << "----------------------------------------------------" << endl;
		for (size_t i = 0; i < h; i++)
		{
			for (size_t j = 0; j < w; j++)
			{
				if (board[i][j])
				{
					cout << '#';
				}
				else
				{
					cout << '.';
				}
				//cout << board[i][j] << ' ';
			}
			cout << endl;
		}
	}

	void SetTrue(int i_1, int j_1, int i_2, int j_2, int i_3, int j_3)
	{
		board[i_1][j_1] = true;
		board[i_2][j_2] = true;
		board[i_3][j_3] = true;
		numOfWhite -= 3;
	}
	void SetFalse(int i_1, int j_1, int i_2, int j_2, int i_3, int j_3)
	{
		board[i_1][j_1] = false;
		board[i_2][j_2] = false;
		board[i_3][j_3] = false;
		numOfWhite += 3;
	}

	void Solve(int _i, int _j)
	{
		if (numOfWhite % 3 != 0)
		{
			return;
		}
		//baseCase
		if (numOfWhite == 0)
		{
			numOfCases++;
		}
		//ShowBoard();
		for (size_t i = 0; i < h; i++)
		{
			for (size_t j = 0; j < w; j++)
			{
				if (isEmpty(i, j))
				{
					if (isEmpty(i - 1, j))
					{
						if (isEmpty(i - 1, j - 1))
						{
							SetTrue(i, j, i - 1, j, i - 1, j - 1);
							Solve(i, j);
							SetFalse(i, j, i - 1, j, i - 1, j - 1);
						}
						if (isEmpty(i - 1, j + 1))
						{
							SetTrue(i, j, i - 1, j, i - 1, j + 1);
							Solve(i, j);
							SetFalse(i, j, i - 1, j, i - 1, j + 1);
						}
					}
					if (isEmpty(i + 1, j))
					{
						if (isEmpty(i + 1, j + 1))
						{
							SetTrue(i + 1, j, i + 1, j + 1, i, j);
							Solve(i, j);
							SetFalse(i + 1, j, i + 1, j + 1, i, j);
						}
						if (isEmpty(i + 1, j - 1))
						{
							SetTrue(i + 1, j, i + 1, j - 1, i, j);
							Solve(i, j);
							SetFalse(i + 1, j, i + 1, j - 1, i, j);
						}
					}
					if (isEmpty(i, j - 1))
					{
						if (isEmpty(i + 1, j - 1))
						{
							SetTrue(i, j, i, j - 1, i + 1, j - 1);
							Solve(i, j);
							SetFalse(i, j, i, j - 1, i + 1, j - 1);
						}
						if (isEmpty(i - 1, j - 1))
						{
							SetTrue(i, j, i, j - 1, i - 1, j - 1);
							Solve(i, j);
							SetFalse(i, j, i, j - 1, i - 1, j - 1);
						}
					}
					if (isEmpty(i, j + 1))
					{
						if (isEmpty(i + 1, j + 1))
						{
							SetTrue(i, j, i, j + 1, i + 1, j + 1);
							Solve(i, j);
							SetFalse(i, j, i, j + 1, i + 1, j + 1);
						}
						if (isEmpty(i - 1, j + 1))
						{
							SetTrue(i, j, i, j + 1, i + 1, j + 1);
							Solve(i, j);
							SetFalse(i, j, i, j + 1, i + 1, j + 1);
						}
					}
				}
			}
		}
	}
public:
	void Invoke()
	{
		GetInput();
		Solve(0, 0);
		cout << numOfCases << endl;
	}
};

int main() {
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	//\n faster than endl. endl makes buffer flush explicitly.

	Solution sol;
	sol.Invoke();
	return 0;
}