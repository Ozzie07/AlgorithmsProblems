//#include <bits/stdc++.h>
//using namespace std;
//
//class Solution
//{
//	string b;
//	string a;
//	short lcs[17001][17001];
//	bool record[17001] = { false, };
//	int firstidx;
//	queue<int> lcsQueue; // b의 a에 대한 lcs에 해당하는 idx를 저장함.
//public:
//	void Add(char c)
//	{
//		printf("%c\n", c);
//		//cout << "a " + c << '\n';
//	}
//	void Delete(char c)
//	{
//		cout << "d " + c << '\n';
//	}
//	void Modify(char c)
//	{
//		cout << "m " + c << '\n';
//	}
//	void Copy(char c)
//	{
//		cout << "c " + c << '\n';
//	}
//
//	void GetInput()
//	{
//		cin >> a >> b;
//	}
//
//	void ShowLCS()
//	{
//		for (size_t i = 0; i < b.size(); i++)
//		{
//			for (size_t j = 0; j < a.size(); j++)
//			{
//				cout << lcs[i][j] << ' ';
//			}
//			cout << '\n';
//		}
//	}
//
//	void Record()
//	{
//		cout << "-------------------------Record--------------------------" << endl;
//		for (size_t i = 0; i < b.size(); i++)
//		{
//			cout << record[i] << ' ';
//		}
//		cout << endl;
//		cout << "-----------------------------------------------------------" << endl;
//		cout << endl;
//	}
//	
//	void LCS()
//	{
//		int flag = 0;
//		for (size_t i = 0; i < b.size(); i++)
//		{
//			if (b[i] == a[0])
//			{
//				firstidx = i;
//				flag = 1;
//			}
//			lcs[i][0] = flag;
//		}
//		flag = 0;
//		for (size_t j = 0; j < a.size(); j++)
//		{
//			if (b[0] == a[j])
//				flag = 1;
//			lcs[0][j] = flag;
//		}
//
//		for (size_t i = 1; i < b.size(); i++)
//		{
//			for (size_t j = 1; j < a.size(); j++)
//			{
//				if (b[i] == a[j])
//				{
//					lcs[i][j] = lcs[i - 1][j - 1] + 1;
//				}
//				else
//				{
//					lcs[i][j] = max(lcs[i][j - 1], lcs[i - 1][j]);
//				}
//			}
//		}
//		ShowLCS();
//		Record();
//		cout << lcs[b.size() - 1][a.size() - 1] << endl;
//	}
//
//	void MakeQueue()
//	{
//		int lastValue = 0;
//		
//		for (size_t i = 0; i < b.size(); i++)
//		{
//			if(lcs[i][a.size() - 1] != lastValue)
//			{
//				lastValue = lcs[i][a.size() - 1];
//				lcsQueue.push(i);
//			}
//		}
//	}
//
//	//void MakeRes()
//	//{
//	//	int cursorToA = 0; //Delete, Modify, Add가 일어날때 불러와야함.
//	//	int cursorToOutput = 0;
//	//	//Start
//	//	for (size_t i = 0; i < b.size(); i++)
//	//	{
//	//		if (lcs[i][a.size() - 1] == 0)
//	//		{
//	//			Add(b[cursorToOutput++]);
//	//		}
//	//	}
//
//	//	if (lcsQueue.front() > firstidx)
//	//	{
//	//		Copy(firstidx);
//	//		cursorToA++;
//	//		cursorToOutput++;
//	//	}
//	//	//
//
//
//
//	//	if (b[lcsQueue.front()] == a[cursorToA])
//	//	{
//	//		for (cursorToOutput; cursorToOutput < b[lcsQueue.front()]; cursorToOutput++)
//	//		{
//	//			Add(b[cursorToOutput]);
//	//		}
//	//		Copy(b[lcsQueue.front()]); cursorToOutput++; lcsQueue.pop(); cursorToA++;
//	//	}
//
//	//	if (b[lcsQueue.front()] != a[cursorToA])
//	//	{
//	//		Delete(a[cursorToA++]);
//	//	}
//
//	//	for (size_t i = cursorToOutput; i < b.size(); i++)
//	//	{
//	//		if (b[lcsQueue.front()] == a[cursorToA])
//	//		{
//
//	//		}
//	//		if (lcsQueue.front() == cursorToOutput)
//	//		{
//	//			Copy(b[cursorToOutput]);
//	//		}
//	//		else
//	//		{
//	//			lcsQueue
//	//		}
//	//		if (lcsQueue.empty())
//	//		{
//	//			Add(b[cursorToOutput]);
//	//		}
//	//	}
//
//	//}
//};
//
//int main() {
//	//	freopen("input.txt", "r", stdin);
//	//	freopen("output.txt", "w", stdout);
//
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	//\n faster than endl. endl makes buffer flush explicitly.
//	while(true)
//	{
//		Solution solution;
//		solution.GetInput();
//		solution.LCS();
//		//solution.MakeRes();
//	}
//	return 0;
//};