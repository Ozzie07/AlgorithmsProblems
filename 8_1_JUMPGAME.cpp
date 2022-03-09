//#include <bits/stdc++.h>
//using namespace std;
//
//class Solution
//{
//	int n;
//#define MAX_SIZE 200
//	int arr[MAX_SIZE][MAX_SIZE];
//	bool isPossible[MAX_SIZE][MAX_SIZE];
//
//	void GetInput()
//	{
//		cin >> n;
//
//		for (size_t i = 0; i < n; i++)
//			for (size_t j = 0; j < n; j++)
//				cin >> arr[i][j];
//		//ShowArray();
//	}
//
//	void Init()
//	{
//		for (size_t i = 0; i < n; i++)
//			for (size_t j = 0; j < n; j++)
//				isPossible[i][j] = false;
//	}
//
//	void JUMP(int a, int b)
//	{
//		if (!arr[a][b]) //마지막에 도달함.
//		{
//			isPossible[a][b] = true;
//			return;
//		}
//
//		if (a < n && b < n) //index 범위를 벗어나지 않았다면
//		{
//			isPossible[a][b] = true;
//			if(!isPossible[a + arr[a][b]][b]) // 반복해서 풀이를 스킵하지 않는 것을 놓쳤음.
//				JUMP(a + arr[a][b], b);
//			if(!isPossible[a][b + arr[a][b]]) // 반복해서 풀지 않도록 해주는 부분을 넣지 않았었음. DP의 핵심!
//				JUMP(a, b + arr[a][b]);
//		}
//	}
//
//public:
//	void Invoke()
//	{
//		GetInput();
//		Init();
//		JUMP(0, 0);
//		if (isPossible[n - 1][n - 1])
//			cout << "YES" << '\n';
//		else
//			cout << "NO" << '\n';
//	}
//
//};
//
//int main() {
//	//	freopen("input.txt", "r", stdin);
//	//	freopen("output.txt", "w", stdout);
//
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	//\n faster than endl. endl makes buffer flush explicitly.
//
//	int tc;
//	cin >> tc;
//
//	for (size_t i = 0; i < tc; i++)
//	{
//		Solution solution;
//		solution.Invoke();
//	}
//
//	return 0;
//}