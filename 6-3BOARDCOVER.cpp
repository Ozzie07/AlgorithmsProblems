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
	bool IsEmpty(int _i, int _j)
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
		scanf("%d %d", &h, &w);
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
			cout << '\n';
		}
		system("pause");

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
		if (numOfWhite == 0)
		{
			numOfCases++;
		}
		//findlowestfalse;
		int i = _i;
		int j = _j;
		bool isFirst = true;
		bool Found = false;
		for (size_t idx_i = i; idx_i < h; idx_i++)
		{
			for (size_t idx_j = 0; idx_j < w; idx_j++)
			{
				if (!board[idx_i][idx_j])
				{
					i = idx_i;
					j = idx_j;
					Found = true;
					break;
				}
			}
			if (Found)
			{
				break;
			}
		}
		//cout << "i : " << i << " j : " << j << endl;
		//try 4.

		if (IsEmpty(i + 1, j))
		{
			if (IsEmpty(i + 1, j + 1))
			{
				SetTrue(i + 1, j, i + 1, j + 1, i, j);
				Solve(i, j);
				SetFalse(i + 1, j, i + 1, j + 1, i, j);
			}
			if (IsEmpty(i + 1, j - 1))
			{
				SetTrue(i + 1, j, i + 1, j - 1, i, j);
				Solve(i, j);
				SetFalse(i + 1, j, i + 1, j - 1, i, j);
			}
		}

		if (IsEmpty(i, j + 1))
		{
			if (IsEmpty(i + 1, j + 1))
			{
				SetTrue(i, j, i, j + 1, i + 1, j + 1);
				Solve(i, j);
				SetFalse(i, j, i, j + 1, i + 1, j + 1);
			}
			if (IsEmpty(i + 1, j))
			{
				SetTrue(i, j, i + 1, j, i, j + 1);
				Solve(i, j);
				SetFalse(i, j, i + 1, j, i, j + 1);
			}
		}
	}

	//void Solve(int _i, int _j)
	//{
	//	//ShowBoard();
	//	//system("pause");
	//	//baseCase
	//	//ShowBoard();
	//	if (numOfWhite == 0)
	//	{
	//		numOfCases++;
	//	}
	//	//ShowBoard();
	//	bool isFirst = true;
	//	for (size_t i = _i; i < h; i++)
	//	{
	//		bool isComplete = true;
	//		for (size_t j = 0; j < w; j++)
	//		{
	//			//ShowBoard();
	//			if (isFirst)
	//			{
	//				j = _j;
	//				isFirst = false;
	//			}
	//			if (IsEmpty(i, j))
	//			{
	//				if (IsEmpty(i + 1, j))
	//				{
	//					if (IsEmpty(i + 1, j + 1))
	//					{
	//						SetTrue(i + 1, j, i + 1, j + 1, i, j);
	//						Solve(i, j);
	//						SetFalse(i + 1, j, i + 1, j + 1, i, j);
	//					}
	//					if (IsEmpty(i + 1, j - 1))
	//					{
	//						SetTrue(i + 1, j, i + 1, j - 1, i, j);
	//						Solve(i, j);
	//						SetFalse(i + 1, j, i + 1, j - 1, i, j);
	//					}
	//				}

	//				if (IsEmpty(i, j + 1))
	//				{
	//					if (IsEmpty(i + 1, j + 1))
	//					{
	//						SetTrue(i, j, i, j + 1, i + 1, j + 1);
	//						Solve(i, j);
	//						SetFalse(i, j, i, j + 1, i + 1, j + 1);
	//					}
	//					if (IsEmpty(i + 1, j))
	//					{
	//						SetTrue(i, j, i + 1, j, i, j + 1);
	//						Solve(i, j);
	//						SetFalse(i, j, i + 1, j, i, j + 1);
	//					}
	//				}

	//			}


	//		}
	//		//check all j is true;
	//		for (size_t j = 0; j < w; j++)
	//		{
	//			if (!board[i][j])
	//			{
	//				isComplete = false;
	//				break;
	//			}
	//		}
	//		if (!isComplete)
	//			break;
	//	}
	//}
public:
	void Invoke()
	{
		GetInput();
		//Timer timer;
		if (numOfWhite % 3 != 0)
		{
			;
		}
		else
		{
			Solve(0, 0);
		}
		//timer.elapsed();
		printf("%d\n", numOfCases);
	}
};

int main() {
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);

	//\n faster than endl. endl makes buffer flush explicitly.
	int tc;
	scanf("%d", &tc);
	for (size_t i = 0; i < tc; i++)
	{
		Solution sol;
		sol.Invoke();
	}
	return 0;
}