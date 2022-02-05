//#include <bits/stdc++.h>
//
//using namespace std;
////6
////7 1 1 1 5 0 
//
////3
////2 0 0
//
////3
////1 0 0
//
////10
////0 0 0 0 0 0 0 0 2 0
//
////1
////0
//
//class Solution //점화식을 철저하게 생각하지 못했음.
//{
//	int n;
//	int arr[1001];
//	int memo[1001];
//
//	void GetInput()
//	{
//		cin >> n;
//		for (size_t i = 0; i < n; i++)
//		{
//			cin >> arr[i];
//			//if (arr[i] == 0)
//			//	arr[i] = -20000; //적당히 작은 수.
//		}
//	}
//
//	void Show(int* arr)
//	{
//		for (size_t i = 0; i < n; i++)
//			cout << arr[i] << ' ';
//		cout << endl;
//	}
//
//	int num = 0;
//	bool LETSGO()
//	{
//		
//		memo[0] = arr[0];
//		for (size_t i = 1; i < n; i++)
//		{
//			memo[i] = 0;
//		}
//		int largest = memo[0];
//		num++;
//
//		if (n == 1)
//			return true;
//
//		for (size_t i = 1; i < n; i++)
//		{
//
//			largest--;
//			if (largest < 0) // 더 이상 앞으로 갈 수 없음.
//				break;
//
//			if (largest + i >= n - 1) // 끝에 도달할 수 있음.
//			{
//				return true;
//			}
//
//			if (largest < arr[i]) // 다음 점프 대상을 찾음.
//			{
//				largest = arr[i];
//				memo[i] = arr[i];
//				num++;
//			}
//			else
//			{
//				memo[i] = 0;
//			}
//		}
//
//		return false;
//	}
//
//public:
//	void Invoke()
//	{
//		GetInput();
//		Show(arr);
//		if (LETSGO())
//		{
//			cout << num << endl;
//		}
//		else
//		{
//			cout << -1 << endl;
//		}
//		Show(memo);
//
//	}
//
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
//	Solution solution;
//	solution.Invoke();
//	return 0;
//}