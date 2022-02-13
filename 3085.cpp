//#include <bits/stdc++.h>
//
//using namespace std;
//
//class Solution
//{
//	int N;
//	char** candy;
//	char** MakeArray(int N)
//	{
//		char **res = new char* [N];
//		for (size_t i = 0; i < N; i++)
//		{
//			res[i] = new char[N];
//		}
//		return res;
//	}
//	void Array()
//	{
//		for (size_t i = 0; i < N; i++)
//		{
//			for (size_t j = 0; j < N; j++)
//			{
//				cout << candy[i][j] << ' ';
//			}
//			cout << endl;
//		}
//		cout << endl;
//	}
//
//	void GetInput()
//	{
//		scanf("%d", &N);
//		candy = MakeArray(N);
//		for (size_t i = 0; i < N; i++)
//		{
//			for (size_t j = 0; j < N; j++)
//			{
//				char a = (char)getchar();
//				if (a == '\n' || a == ' ' || a == '\t')
//				{
//					j--;
//					continue;
//				}
//				else
//				{
//					candy[i][j] = a;
//				}
//			}
//		}
//	}
//
//	int SearchForRow(int target)
//	{
//		int max = 1;
//		int count = 1;
//		for (size_t i = 1; i < N; i++)
//		{
//			if (candy[target][i] == candy[target][i - 1])
//			{
//				count++;
//				if (count > max)
//					max = count;
//			}
//			else
//			{
//				count = 1;
//			}
//		}
//		return max;
//	}
//
//	int SearchForColumn(int target)
//	{
//		int max = 0;
//		int count = 1;
//		for (size_t i = 1; i < N; i++)
//		{
//			if (candy[i][target] == candy[i - 1][target])
//			{
//				count++;
//				if (count > max)
//					max = count;
//			}
//			else
//			{
//				count = 1;
//			}
//		}
//
//		return max;
//	}
//
//	int SwapColumnSearchRow(int target)
//	{
//		int max = 0;
//		int loop_res = 0;
//		for (size_t i = 1; i < N; i++)
//		{
//			swap(candy[i][target], candy[i - 1][target]);
//			loop_res = SearchForRow(i);
//			if (loop_res > max)
//				max = loop_res;
//			loop_res = SearchForRow(i - 1);
//			if (loop_res > max)
//				max = loop_res;
//			swap(candy[i][target], candy[i - 1][target]);
//		}
//		return max;
//	}
//
//	int SwapRowSearchColumn(int target)
//	{
//		int max = 0;
//		int loop_res = 0;
//		for (size_t i = 1; i < N; i++)
//		{
//			swap(candy[target][i], candy[target][i - 1]);
//			loop_res = SearchForColumn(i);
//			if (loop_res > max)
//				max = loop_res;
//			loop_res = SearchForColumn(i-1);
//			if (loop_res > max)
//				max = loop_res;
//			swap(candy[target][i], candy[target][i - 1]);
//		}
//		return max;
//	}
//
//	int SearchForRowAndSwap(int target)
//	{
//		int max = 0;
//		max = SearchForRow(target);
//		for (size_t i = 1; i < N; i++)
//		{
//			if (candy[i][target] == candy[i - 1][target])
//				continue;
//			swap(candy[target][i], candy[target][i - 1]);
//			int loop_res = SearchForRow(target);
//			if (loop_res > max)
//				max = loop_res;
//			swap(candy[target][i], candy[target][i - 1]);
//		}
//		return max;
//	}
//
//	int SearchForColumnAndSwap(int target)
//	{
//		int max = 0;
//		//For No Swaped.
//		max = SearchForColumn(target);
//		//For Swapped.
//		for (size_t i = 1; i < N; i++)
//		{
//			if (candy[i][target] == candy[i - 1][target])
//				continue;
//			swap(candy[i][target], candy[i - 1][target]);
//			int loop_res = SearchForColumn(target);
//			if (loop_res > max)
//				max = loop_res;
//			swap(candy[i][target], candy[i - 1][target]);
//		}
//		return max;
//	}
//
//	int FindMax()
//	{
//		int max = 0;
//
//		//바꾸어서 다른 녀석들이 영향을 받지 않을 때 넣어줘야함.
//		for (size_t i = 0; i < N; i++)
//		{
//			int a = SearchForColumn(i);
//			int b = SearchForRow(i);
//			if (a > max)
//				max = a;
//			if (b > max)
//				max = b;
//		}
//
//		for (size_t i = 0; i < N; i++)
//		{
//			int a = SwapRowSearchColumn(i);
//			int b = SwapColumnSearchRow(i);
//			if (a > max)
//				max = a;
//			if (b > max)
//				max = b;
//		}
//		return max;
//	}
//
//public:
//	void Invoke()
//	{
//		GetInput();
//		cout << FindMax() << '\n';
//	}
//
//};
//
//int main() {
//	//	freopen("input.txt", "r", stdin);
//	//	freopen("output.txt", "w", stdout);
//
//	//\n faster than endl. endl makes buffer flush explicitly.
//	while (true)
//	{
//		Solution solution;
//		solution.Invoke();
//	}
//
//	return 0;
//}
//
