//#include <bits/stdc++.h>
//
//using namespace std;
//
//class Solution
//{
//	int n;
//	int t[10001];
//	vector<int> adjList[10001];
//	bool isVisited[10001] = { false, };
//	stack<int> SequenceOfWorks;
//	stack<int> stacks[10001];
//	int lastVisitedVertex[10001];
//	int totalTime[10001] = { 0, };
//	void GetInput()
//	{
//		cin >> n;
//		for (size_t i = 0; i < n; i++)
//		{
//			cin >> t[i];
//			int numOfWorks;
//			cin >> numOfWorks;
//			for (size_t j = 0; j < numOfWorks; j++)
//			{
//				int d;
//				cin >> d;
//				d--;
//				adjList[i].push_back(d);
//			}
//		}
//	}
//
//	void VisitInit()
//	{
//		for (size_t i = 0; i < n; i++)
//			isVisited[i] = false;
//	}
//
//	void DFS_logic(int _startPoint, stack<int> &_stk)
//	{
//		if (isVisited[_startPoint])
//			return;
//		isVisited[_startPoint] = true;
//		//dosomething
//		for (int e : adjList[_startPoint])
//			DFS_logic(e, _stk);
//
//		_stk.push(_startPoint);
//	}
//
//	void DFS(int _startPoint, stack<int> &_stk)
//	{
//		VisitInit();
//		DFS_logic(_startPoint, _stk);
//	}
//	
//	void MakeAnswer()
//	{
//		totalTime[0] = t[0];
//		for (size_t i = 1; i < n; i++)
//		{
//			stacks[i].pop();//to remove itself.
//
//			if (stacks[i].empty())
//			{
//				totalTime[i] = max(totalTime[i - 1], t[i]);
//			}
//			else
//			{
//				stack<int> stack_i = stacks[i];
//				int localMax = 0;
//				while (!stack_i.empty())
//				{
//					localMax = max(localMax, totalTime[stack_i.top()]);
//					stack_i.pop();
//				}
//				totalTime[i] = t[i] + localMax;
//			}
//		}
//		cout << totalTime[n - 1] << endl;
//	}
//
//public:
//	void Envoke()
//	{
//		int maxVal = 0;
//		GetInput();
//		for (size_t i = 0; i < n; i++)
//		{
//			DFS(i, stacks[i]); //Get all dependencies.
//		}
//		MakeAnswer();
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
//	Solution solution;
//	solution.Envoke();
//	return 0;
//}