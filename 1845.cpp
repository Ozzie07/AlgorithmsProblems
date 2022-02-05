//#include <bits/stdc++.h>
//
//using namespace std;
//
//class Solution
//{
//	int arr[251];
//	int res[251];
//	int temp[251];
//	int n;
//	void GetInput()
//	{
//		cin >> n;
//
//		for (size_t i = 1; i <= n; i++)
//		{
//			arr[i] = i;
//		}
//		//for (size_t i = 1; i <= n; i++)
//		//{
//		//	int a;
//		//	cin >> a;
//		//	res[i] = a;
//		//}
//	}
//
//	void ShowArray()
//	{
//		for (size_t i = 1; i <= n; i++)
//		{
//			cout << "arr[" << i << "] : " << arr[i] << endl;
//		}
//	}
//
//
//	void rot(int a, int b)
//	{
//		int size = b - a + 1;
//
//		int j = 0;
//		for (int i = a; i < a + size; i++)
//			temp[j++] = arr[i];
//
//		j = a;
//		for (int i = size - 1; i >= 0; i--)
//			arr[j++] = -temp[i];
//	}
//
//public:
//	void Invoke()
//	{
//		GetInput();
//		while (true)
//		{
//			int a, b;
//			cin >> a >> b;
//			rot(a, b);
//			ShowArray();
//		}
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
//
//	Solution solution;
//	solution.Invoke();
//	return 0;
//}