//#include <bits/stdc++.h>
//using namespace std;
//vector<int> Button[10];
//
//void SetButton()
//{
//	Button[0].push_back(0);
//	Button[0].push_back(1);
//	Button[0].push_back(2);
//
//	Button[1].push_back(3);
//	Button[1].push_back(7);
//	Button[1].push_back(9);
//	Button[1].push_back(11);
//
//	Button[2].push_back(4);
//	Button[2].push_back(10);
//	Button[2].push_back(14);
//	Button[2].push_back(15);
//
//	Button[3].push_back(0);
//	Button[3].push_back(4);
//	Button[3].push_back(5);
//	Button[3].push_back(6);
//	Button[3].push_back(7);
//
//	Button[4].push_back(6);
//	Button[4].push_back(7);
//	Button[4].push_back(8);
//	Button[4].push_back(10);
//	Button[4].push_back(12);
//
//	Button[5].push_back(0);
//	Button[5].push_back(2);
//	Button[5].push_back(14);
//	Button[5].push_back(15);
//
//	Button[6].push_back(3);
//	Button[6].push_back(14);
//	Button[6].push_back(15);
//
//	Button[7].push_back(4);
//	Button[7].push_back(5);
//	Button[7].push_back(7);
//	Button[7].push_back(14);
//	Button[7].push_back(15);
//
//	Button[8].push_back(1);
//	Button[8].push_back(2);
//	Button[8].push_back(3);
//	Button[8].push_back(4);
//	Button[8].push_back(5);
//
//	Button[9].push_back(3);
//	Button[9].push_back(4);
//	Button[9].push_back(5);
//	Button[9].push_back(9);
//	Button[9].push_back(13);
//}
//
//class Solution
//{
//	int clock[16];
//	int numOfButtonPush;
//	int minimum = INT_MAX;
//	int DEBUG = 0;
//private:
//	//void ShowCurrentState()
//	//{
//	//	for (size_t i = 0; i < 16; i++)
//	//	{
//	//		cout << clock[i] << ' ';
//	//	}
//	//	cout << endl;
//	//	system("pause");
//	//}
//
//	void GetInput()
//	{
//		numOfButtonPush = 0;
//		for (size_t i = 0; i < 16; i++)
//		{
//			int input;
//			cin >> input;
//			if (input == 12)
//				input = 0;
//			clock[i] = input / 3;
//		}
//	}
//
//	bool IsAllTwelve()
//	{
//		bool res = true;
//		for (size_t i = 0; i < 16; i++)
//		{
//			if (clock[i])
//				res = false;
//		}
//		return res;
//	}
//
//	void Tick(int& input, int numOfClick)
//	{
//		input += numOfClick;
//		if (input > 3)
//			input -= 4;
//	}
//
//	void UnTick(int& input, int numOfClick)
//	{
//		input -= numOfClick;
//		if (input < 0)
//			input += 4;
//	}
//
//	void PushButton(vector<int>& button, int numOfClick)
//	{
//		for (int e : button)
//			Tick(clock[e], numOfClick);
//		numOfButtonPush += numOfClick;
//	}
//
//	void UnPushButton(vector<int>& button, int numOfClick)
//	{
//		for (int e : button)
//			UnTick(clock[e], numOfClick);
//		numOfButtonPush -= numOfClick;
//	}
//
//	int buttonCall[10] = { 0, };
//
//	void FindMinimum(int buttonNum)
//	{
//		
//		/*if(buttonNum == 9)
//			DEBUG++;*/
//		if (IsAllTwelve())
//		{
//			minimum = min(minimum, numOfButtonPush);
//			return;
//		}
//
//		if (buttonNum == 10)
//			return;
//
//		for (int i = 0; i <= 3; i++)
//		{
//			PushButton(Button[buttonNum], i);
//			FindMinimum(buttonNum + 1);
//			UnPushButton(Button[buttonNum], i);
//		}
//	}
//
//	void ShowNumOfButtonCall()
//	{
//		for (size_t i = 0; i < 10; i++)
//		{
//			cout << buttonCall[i] << ' ';
//		}
//		cout << endl;
//	}
//
//public:
//	void Invoke()
//	{
//		GetInput();
//		FindMinimum(0);
//		if (minimum == INT_MAX)
//		{
//			cout << -1 << '\n';
//		}
//		else
//		{
//			cout << minimum << '\n';
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
//	SetButton();
//
//	int tc;
//	cin >> tc;
//	for (size_t i = 0; i < tc; i++)
//	{
//		Solution solution;
//		solution.Invoke();
//	}
//	return 0;
//}