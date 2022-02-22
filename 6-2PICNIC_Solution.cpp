//#include <bits/stdc++.h>
//using namespace std;
//
//class Solution
//{
//	int n, m;
//	bool areFriends[10][10];
//
//	void FriendsInit()
//	{
//		for (size_t i = 0; i < 10; i++)
//		{
//			for (size_t j = 0; j < 10; j++)
//			{
//				areFriends[i][j] = false;
//			}
//		}
//	}
//
//	void GetInput()
//	{
//		cin >> n >> m;
//		FriendsInit();
//		for (size_t i = 0; i < m; i++)
//		{
//			int a, b;
//			cin >> a >> b;
//			areFriends[a][b] = true;
//			areFriends[b][a] = true;
//		}
//	}
//
//	int countParings(bool taken[10])
//	{
//		int firstFree = -1; //실패 값으로 초기화해줌.
//
//		//가장 처음 짝이 없는 녀석을 선택.
//		for (int i = 0; i < n; i++)
//		{
//			if (!taken[i]) {
//				firstFree = i;
//				break;
//			}
//		}
//
//
//		//짝이 없는 녀석이 없다면... 모두 선택되었다는 이야기이므로... 종료.
//		if (firstFree == -1) return 1;
//
//		int ret = 0;
//		//선택된 학생과 짝지을 학생을 결정
//		for (int pairWith = firstFree + 1; pairWith < n; ++pairWith)
//		{
//			//순회 중 찾았으면?
//			if (!taken[pairWith] && areFriends[firstFree][pairWith])
//			{
//				//그 두 녀석을 pair로 만들고...
//				taken[firstFree] = taken[pairWith] = true;
//				//재귀 함수로 들어가서...  firstFree가 더 이상 없을 때까지... (BaseCase로 수렴(Converge)하도록 Base case를 선택한다.)
//				ret += countParings(taken);
//				//끝나면 돌려놓아야함 왜냐? 다른 조합도 확인해야하기 때문에. 앞서 조합을 선택하는 방법과 동일하다.
//				taken[firstFree] = taken[pairWith] = false;
//			}
//		}
//
//		return ret;
//	}
//
//
//public:
//
//	void Invoke()
//	{
//		GetInput();
//		bool local[10] = { false };
//		cout << countParings(local) << '\n';
//	}
//};
//
//int main() {
//	//	freopen("input.txt", "r", stdin);
//	//	freopen("output.txt", "w", stdout);
//
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	int tc;
//	cin >> tc;
//	for (size_t i = 0; i < tc; i++)
//	{
//		Solution solution;
//		solution.Invoke();
//	}
//
//	return 0;
//}