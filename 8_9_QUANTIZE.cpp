//#include <bits/stdc++.h>
//using namespace std;
//
//class Solution
//{
//	int n; //������ ����.
//	int m; //����� ������ ��.
//	int arr[101];
//	int Quantized[101];
//	vector<int> quantizingNumber;
//
//	void GetInput()	
//	{
//		cin >> n >> m;
//		for (size_t i = 0; i < n; i++)  
//		{ 
//			cin >> arr[i];
//		}
//
//		sort(arr[0], arr[n - 1]);
//	}
//
//	void TempTEST()
//	{
//		//Q. quantizing number�� ��� ������ ���ΰ�?
//
//	}
//
//	int ErrorSquareSum()
//	{
//		int errorSum = 0;
//		for (size_t i = 0; i < n; i++)
//		{
//			int local = arr[i] - Quantized[i];
//			errorSum += local * local;
//		}
//		return errorSum;
//	}
//
//	void Quantize()
//	{
//		for (size_t i = 0; i < n; i++)
//		{
//			int local_min = INT_MAX;
//			int quantizeValue = 0;
//			for (int e : quantizingNumber)
//			{
//				int local = abs(arr[i] - e);
//				if (local_min > local)
//				{
//					local_min = local;
//					quantizeValue = e;
//				}
//				local_min = min(local_min, local);
//			}
//			Quantized[i] = quantizeValue;
//		}
//	}
//
//	void ShowQuantized()
//	{
//		for (size_t i = 0; i < n; i++) 
//		{ 
//			cout << Quantized[i] << endl; 
//		}
//	}
//
//public:
//	void Invoke()
//	{
//		GetInput();
//		//0. input ����
//		//1. vector�� �� �� ����. HOW? // where vector means Quantizing number.
//		//2. QUANTIZE
//		//3. ERROR�� ����.
//		//4. �ּҰ� �ƴϸ� Q. �ּ������� ��� �� ���ΰ�? ���� ���� 
//		//5. �ּҶ�� ���� ��ȯ
//		TempTEST();
//		Quantize();
//		ShowQuantized();
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
//	int tc;
//	cin >> tc;
//	for (size_t i = 0; i < tc; i++)
//	{
//		Solution sol;
//		sol.Invoke();
//	}
//	return 0;
//}