//#include <bits/stdc++.h>
//using namespace std;
//
//class Solution
//{
//	string input;
//	int Dynamic[10010][10010];
//
//	void GetInput()
//	{
//		cin >> input;
//	}
//
//	void InitDynamic()
//	{
//		for (size_t i = 0; i < 10010; i++)
//		{
//			for (size_t j = 0; j < 10010; j++)
//			{
//				Dynamic[i][j] = -1;
//			}
//		}
//	}
//
//	void UpdateDynamic()
//	{
//		InitDynamic();
//		for (size_t i = 0; i < input.size(); i++)
//		{
//			for (size_t j = i + 2; j < i + 5; j++)
//			{
//				if (input.size() <= j)
//					continue;
//				vector<int> subSequence;
//				Dynamic[i][j] = CheckHard(MakeVector(subSequence, i, j));
//			}
//		}
//
//	}
//
//	int Min = INT_MAX;
//	int result = 0;
//	//void Partitioning(vector<int>& partition, int n, int start, int end)
//	//{
//	//	if (n == 0)
//	//	{
//	//		//DOSOMETING
//	//		int localRes = result;
//	//		if (Min > localRes)
//	//		{
//	//			Min = localRes;
//	//		}
//	//		ShowVector(partition);
//	//		return;
//	//	}
//
//	//	if (n < 0)
//	//		return;
//	//	for (size_t i = 3; i <= 5; i++)
//	//	{
//	//		partition.push_back(i);
//	//		//여기서 답을 반영하고.
//	//		int local_end = end + i - 1;
//	//		if (local_end < input.size())
//	//		{
//	//			result += Dynamic[start][local_end];
//	//			cout << "Dynamic[" << start << ']' << '[' << local_end << ']' << Dynamic[start][local_end] << endl;
//	//			cout << "Result : " << result << endl;
//	//			Partitioning(partition, n - i, local_end + 1, local_end + 1);
//	//			//여기서 반영했던 답을 원래대로 복구하고.
//
//	//			result -= Dynamic[start][local_end];
//	//			partition.pop_back();
//	//		}
//	//		
//	//	}
//	//}
//
//	int memo[10010];
//
//	void InitMemo()
//	{
//		for (size_t i = 0; i <= input.size(); i++)
//		{
//			memo[i] = -1;
//		}
//		memo[3] = Dynamic[0][2];
//		memo[4] = Dynamic[0][3];
//		memo[5] = Dynamic[0][4];
//
//	}
//
//	//길이 n 까지 진행했을 때의 최솟값을 항상 저장해놓고 쓴다면
//	int F(int n) // 길이 n인 녀석 중 최소값 반환.
//	{
//		//cout << "n : " << n << ' ';
//		//초기값 생각해야됨.
//		if (n == 0)
//			return 0;
//		if (n < 3) //불가능한 케이스임.
//			return INT_MAX >> 1;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
//		if (memo[n] != -1)
//		{
//			return memo[n];
//		}
//
//		int Min = INT_MAX;
//		int &res = memo[n];
//
//		for (int i = 3; i <= 5; i++)
//		{
//			int local_n = n - i;
//			if (local_n < 0)
//				continue;
//			int local_res = F(local_n) + Dynamic[local_n][n - 1];
//			//cout << "Dynamic[" << local_n - 1 << "][" << n - 1 << "] : " << Dynamic[local_n - 1][n - 1] << endl;
//			//cout <<"local_n : " << local_n << " local_res : " << local_res << endl;;
//			Min = min(Min, local_res);
//		}
//		return res = Min;
//	}
//
//
//	//int Partitioning(int n, int start, int end)
//	//{
//	//	if (memo[n] != -1)
//	//	{
//
//	//	}
//	//	int& res = memo[n];
//
//	//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000007777777777777777777777777777777777777777777777777	if (n == 0)
//	//	{
//	//		//DOSOMETING
//	//		int res = result;
//
//	//		return res;
//	//	}
//
//	//	if (n < 0)
//	//		return;
//	//	for (size_t i = 3; i <= 5; i++)
//	//	{
//	//		//여기서 답을 반영하고.
//	//		int local_end = end + i - 1;
//	//		if (local_end < input.size())
//	//		{
//	//			result += Dynamic[start][local_end];
//	//			//cout << "Dynamic[" << start << ']' << '[' << local_end << ']' << Dynamic[start][local_end] << endl;
//	//			//cout << "Result : " << result << endl;
//	//			Partitioning(n - i, local_end + 1, local_end + 1);
//	//			//여기서 반영했던 답을 원래대로 복구하고.
//
//	//			result -= Dynamic[start][local_end];
//	//		}
//	//	}
//
//	//}
//	//이전에 더했던 정보를 가지고 있을 수 있도록 설계하기.
//	int MakeSolution(vector<int>& partition)
//	{
//		int result = 0;
//		int start = 0;
//		int end = 0;
//		//cout << "-------------------Start--------------------" << endl;
//		for (int e : partition)
//		{
//			end = end + e - 1;
//			result += Dynamic[start][end];
//			//cout << "e : " << e << " start, end : " << start << ", " << end << " Dynamic : " << Dynamic[start][end] << "Result : " << result << endl;
//			start = end + 1;
//			end = end + 1;
//		}
//
//		return result;
//	}
//
//	//void ShowDynamic()
//	//{
//	//	for (size_t i = 0; i < input.size(); i++)
//	//	{
//	//		for (size_t j = 0; j < input.size(); j++)
//	//		{
//	//			cout << Dynamic[i][j] << ' ';
//	//		}
//	//		cout << endl;
//	//	}
//	//}
//
//	vector<int>& MakeVector(vector<int>& subSequence, int start, int end)
//	{
//		for (size_t i = start; i <= end; i++)
//		{
//			subSequence.push_back(input[i] - 48);
//		}
//		return subSequence;
//	}
//
//	void ShowVector(vector<int>& vector)
//	{
//		cout << "------------------------SHOWVECTOR--------------------------" << endl;
//		for (int e : vector)
//		{
//			cout << e << ' ';
//		}
//		cout << endl;
//		cout << "------------------------SHOWVECTOR--------------------------" << endl;
//	}
//
//	bool isAllSame(vector<int>& input)
//	{
//		int firstValue = input[0];
//		for (int e : input)
//		{
//			if (e != firstValue)
//				return false;
//		}
//		return true;
//	}
//
//	bool isIncORDec(vector<int>& input)
//	{
//		int firstValue = input[0];
//		int difference = input[1] - firstValue;
//		if (difference != 1 && difference != -1)
//			return false;
//		for (size_t i = 1; i < input.size(); i++)
//		{
//			if (input[i] - input[i - 1] != difference)
//				return false;
//		}
//		return true;
//
//		//int lastValue = input[0];
//		//for (size_t i = 1; i < input.size(); i++)
//		//{
//		//	if ((lastValue - 1) != input[i] && (lastValue + 1) != input[i])
//		//	{
//		//		return false;
//		//	}
//		//	lastValue = input[i];
//		//}
//		//return true;
//	}
//
//	bool isTwoNumberRepeated(vector<int>& input)
//	{
//
//		if (input.size() == 2)
//			return true;
//		bool converter = true;
//		pair<int, int> firstTwoValue{ input[0], input[1] };
//
//		for (size_t i = 2; i < input.size(); i++)
//		{
//			if (converter)
//			{
//				if (input[i] != firstTwoValue.first)
//					return false;
//			}
//			else
//			{
//				if (input[i] != firstTwoValue.second)
//					return false;
//			}
//			converter = !converter;
//		}
//		return true;
//	}
//
//	bool isArthmeticSequence(vector<int>& input)
//	{
//		int firstValue = input[0];
//		int difference = input[1] - firstValue;
//		for (size_t i = 1; i < input.size(); i++)
//		{
//			if (input[i] - input[i - 1] != difference)
//				return false;
//		}
//		return true;
//	}
//
//	int CheckHard(vector<int>& input)
//	{
//		if (isAllSame(input))
//			return 1;
//
//		if (isIncORDec(input))
//			return 2;
//
//		if (isTwoNumberRepeated(input))
//			return 4;
//
//		if (isArthmeticSequence(input))
//			return 5;
//
//		return 10;
//	}
//
//public:
//	void Invoke()
//	{
//		GetInput();
//		UpdateDynamic();
//		//Partitioning(input.size(), 0, 0);
//		InitMemo();
//		cout << F(input.size()) << endl;
//	}
//
//};
//
//int main()
//{
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
//		Solution solution;
//		solution.Invoke();
//	}
//
//	return 0;
//}
// 