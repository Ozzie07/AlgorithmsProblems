//#include <bits/stdc++.h>
//using namespace std;
//
//vector<vector<int>> Board;
//int h, w;
//
//void ShowBoard()
//{
//	for (auto e : Board)
//	{
//		for (auto i : e)
//		{
//			cout << i;
//		}
//		cout << endl;
//	}
//}
//
//void GetInput()
//{
//	scanf("%d %d", &h, &w);
//	Board.resize(h);
//	for (size_t i = 0; i < h; i++)
//	{
//		Board[i].resize(w);
//	}
//	char a;
//	for (size_t i = 0; i < h; i++)
//	{
//		for (size_t j = 0; j < w; j++)
//		{
//			a = getchar();
//			if (a == '.')
//			{
//				Board[i][j] = 0;
//			}
//			else if (a == '#')
//			{
//				Board[i][j] = 1;
//			}
//			else
//			{
//				j--;
//			}
//		}
//	}
//}
//
//
//const int coverType[4][3][2]
//{
//	{{0,0}, {1,0} ,{0,1} },
//	{{0,0}, {0,1} ,{1,1} },
//	{{0,0}, {1,0} ,{1,1} },
//	{{0,0}, {1,0} ,{1,-1} }
//};
//
//bool Set(vector<vector<int>>& board, int y, int x, int type, int delta)
//{
//	bool ok = true;
//	for (int i = 0; i < 3; ++i)
//	{
//		const int ny = y + coverType[type][i][0];
//		const int nx = x + coverType[type][i][1];
//		if (ny < 0 || ny >= board.size() || nx < 0 || nx >= board[0].size())
//		{
//			ok = false;
//		}
//		else if ((board[ny][nx] += delta) > 1)
//			ok = false;
//	}
//	return ok;
//}
//
//int cover(vector<vector<int>>& board)
//{
//	int _i = -1, _j = -1;
//	for (int i = 0; i < board.size(); ++i)
//	{
//		for (int j = 0; j < board[i].size(); ++j)
//		{
//			if (board[i][j] == 0)
//			{
//				_i = i;
//				_j = j;
//				break;
//			}
//		}
//
//		if (_i != -1) break;
//	}
//
//	if (_i == -1) return 1;
//	int ret = 0;
//	for (int type = 0; type < 4; ++type)
//	{
//		if (Set(board, _i, _j, type, 1))
//		{
//			ret += cover(board);
//		}
//		Set(board, _i, _j, type, -1);
//	}
//
//	return ret;
//}
//
//int main() {
//	//	freopen("input.txt", "r", stdin);
//	//	freopen("output.txt", "w", stdout);
//	int tc;
//	scanf("%d", &tc);
//	for (size_t i = 0; i < tc; i++)
//	{
//		GetInput();
//		//Timer timer;
//		int res = cover(Board);
//		//timer.elapsed();
//		printf("%d\n", res);
//	}
//	//\n faster than endl. endl makes buffer flush explicitly.
//	return 0;
//}