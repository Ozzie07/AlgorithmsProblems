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
//		int firstFree = -1; //���� ������ �ʱ�ȭ����.
//
//		//���� ó�� ¦�� ���� �༮�� ����.
//		for (int i = 0; i < n; i++)
//		{
//			if (!taken[i]) {
//				firstFree = i;
//				break;
//			}
//		}
//
//
//		//¦�� ���� �༮�� ���ٸ�... ��� ���õǾ��ٴ� �̾߱��̹Ƿ�... ����.
//		if (firstFree == -1) return 1;
//
//		int ret = 0;
//		//���õ� �л��� ¦���� �л��� ����
//		for (int pairWith = firstFree + 1; pairWith < n; ++pairWith)
//		{
//			//��ȸ �� ã������?
//			if (!taken[pairWith] && areFriends[firstFree][pairWith])
//			{
//				//�� �� �༮�� pair�� �����...
//				taken[firstFree] = taken[pairWith] = true;
//				//��� �Լ��� ����...  firstFree�� �� �̻� ���� ������... (BaseCase�� ����(Converge)�ϵ��� Base case�� �����Ѵ�.)
//				ret += countParings(taken);
//				//������ �������ƾ��� �ֳ�? �ٸ� ���յ� Ȯ���ؾ��ϱ� ������. �ռ� ������ �����ϴ� ����� �����ϴ�.
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