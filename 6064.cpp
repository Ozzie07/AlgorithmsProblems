//#include <bits/stdc++.h>
//using namespace std;
//
//
//class Solution
//{
//	int M, N, x, y;
//	void GetInput()
//	{
//		cin >> M >> N >> x >> y;
//	}
//
//	void Find()
//	{
//		int year = 1;
//		int l_x = 1, l_y = 1;
//		bool isFound = false;
//		while (!(l_x == M && l_y == N))
//		{
//			if (l_x == x && l_y == y)
//			{
//				isFound = true;
//				break;
//			}
//
//			l_x++;
//			if (l_x > M)
//			{
//				l_x = 1;
//			}
//			l_y++;
//			if (l_y > N)
//			{
//				l_y = 1;
//			}
//			year++;
//		}
//
//		if (isFound)
//			cout << year << '\n';
//		else
//			cout << -1 << '\n';
//	}
//public:
//	void Invoke()
//	{
//		GetInput();
//		Find();
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
//	int  t;
//	cin >> t;
//	for (size_t i = 0; i < t; i++)
//	{
//		Solution solution;
//		solution.Invoke();
//	}
//
//	return 0;
//}