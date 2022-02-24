//#include <bits/stdc++.h>
//using namespace std;
//
//const int dx[8]{ -1, -1, -1, 1, 1, 1, 0, 0 };
//const int dy[8]{ -1, 0 ,1, -1, 0, 1, -1, 1 };
//class Solution
//{
//	//char BOGGLE[5][5];
//	string BOGGLE[5];
//	int n;
//	string str[10];
//	void GetInput()
//	{
//		for (size_t i = 0; i < 5; i++)
//		{
//			cin >> BOGGLE[i];
//			/*for (size_t j = 0; j < 5; j++)
//			{
//				char c;
//				c = getchar();
//				if (c == '\n')
//				{
//					j--;
//					continue;
//				}
//				BOGGLE[i][j] = c;
//			}*/
//		}
//
//		cin >> n;
//		for (size_t i = 0; i < n; i++)
//		{
//			cin >> str[i];
//			//printf("--------------------------------------\n");
//			//printf("What you get %s\n", string[i]);
//			//printf("--------------------------------------\n");
//		}
//	}
//
//	bool hasWord(int y, int x, string word)
//	{
//		if (!isInRange(y, x))
//			return false;
//		if (BOGGLE[y][x] != word[0])
//			return false;
//		if (word.size() == 1) return true;
//
//		for (int direction = 0; direction < 8; direction++)
//		{
//			int nextY = y + dy[direction];
//			int nextX = x + dx[direction];
//			if (hasWord(nextY, nextX, word.substr(1)))
//			{
//				return true;
//			}
//		}
//		return false;
//	}
//
//	bool isInRange(int y, int x)
//	{
//		if ((x >= 0 && x < 5) && (y >= 0 && y < 5))
//		{
//			return true;
//		}
//		return false;
//	}
//	void Show()
//	{
//		for (size_t i = 0; i < 5; i++)
//		{
//			for (size_t j = 0; j < 5; j++)
//			{
//				printf("%c", BOGGLE[i][j]);
//			}
//			printf("\n");
//		}
//	}
//
//	void Solve()
//	{
//		for (size_t k = 0; k < n; k++)
//		{
//			bool ishasword = false;
//			for (size_t i = 0; i < 5; i++)
//			{
//				for (size_t j = 0; j < 5; j++)
//				{
//					if (hasWord(i, j, str[k]))
//					{
//						ishasword = true;
//						break;
//					}
//				}
//				if (ishasword) break;
//			}
//			if(ishasword)
//				cout << str[k] << " YES" << endl;
//			else
//				cout << str[k] << " NO" << endl;
//		}
//	}
//
//public:
//	void Invoke()
//	{
//		GetInput();
//		Solve();
//	}
//};
//
//int main() {
//	//	freopen("input.txt", "r", stdin);
//	//	freopen("output.txt", "w", stdout);
//
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	//\n faster than endl. endl makes buffer flush explicitly.
//	int tc;
//	cin >> tc;
//	for (size_t i = 0; i < tc; i++)
//	{
//		Solution solution;
//		solution.Invoke();
//	}
//	return 0;
//}
//
