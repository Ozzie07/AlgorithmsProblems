//#include <iostream>
//#include <queue>
//#include <stack>
//#define MAX 10001
//using namespace std;
//
//class Solution
//{
//	int n; //수행해야할 작업의 수.
//	int delay[MAX]; //각 작업마다 걸리는 시간을 저장하는 배열
//	int numOfWorks[MAX]; // 선행해야할 작업의 수를 저장하는 배열
//	int cache[MAX]; // 해당 작업이 완료되는데 걸린 최소 시간을 저장하는 배열
//	stack<int> stk[MAX]; //종속성을 가지는 워크들이 여기에 들어가 있음.
//	//adjList의 inversedDirectedEdges가 들어있다.
//	//해당 작업을 수행하고, 다음에 수행해야 하는 녀석들이 들어있음.
//
//	void GetInput()
//	{
//		cin >> n;
//		//getInput
//		for (int i = 1; i <= n; i++)
//		{
//			int time;
//			cin >> time >> numOfWorks[i];
//			delay[i] = time;
//
//			for (int j = 0; j < numOfWorks[i]; j++)
//			{
//				int prerequisite;
//				cin >> prerequisite;
//
//				stk[prerequisite].push(i);
//			}
//		}
//		//
//	}
//
//	void MakeSol(void)
//	{
//		int result = 0;
//		
//		queue<int> q; //1->2->3->4->5 순으로 진행함.
//		//우리는 input을 받을 때, 5->4->3->2->1의 형태로, 5를 수행하려면 4를 수행해야하고...
//		//였다.
//		//앞서 input을 받는 방법을 보면 조금 다르게 받는다는 것을 알 수 있음.
//		//선행 되어야할 작업을 해당 index로 받고 다음에 작업할 녀석을 stk에 넣어둔다.
//		//q를 선택한 이유가 있는데, 먼저 들어온 녀석들을 전부 처리하고 다음 녀석을 순서대로 처리를 해주어야,
//		//값들의 업데이트가 정상적으로 가능하다.
//			
//
//		//선행작업이 없는 작업들 업데이트.
//		for (int i = 1; i <= n; i++)
//		{
//			if (numOfWorks[i])
//			{
//				continue;
//			}
//
//			q.push(i); //선행해야하는 작업이 없다면, Q에 저장이 된다.
//			cache[i] = delay[i]; //선행해야하는 작업이 없다면 그 자체가 delay가 되므로...
//			// 선행해야하는 작업이 있다면, 이 녀석을 다른 선행해야하는 녀석을 업데이트하는 과정에서
//			// 이 값을 얻을 수 있다. 이는 이하의 while
//		}
//
//		//선행작업이 있는 작업들 업데이트.
//		while (!q.empty())
//		{
//			int job = q.front(); //
//			q.pop();
//
//			while (!stk[job].empty())
//			{
//				int next = stk[job].top();
//				stk[job].pop();
//				if (--numOfWorks[next] == 0)
//				{
//					q.push(next);
//				}
//
//				cache[next] = max(cache[next], cache[job] + delay[next]);
//			}
//		}
//
//		//Find Max.
//		for (int i = 1; i <= n; i++)
//		{
//			result = max(result, cache[i]);
//		}
//
//		cout << result;
//	}
//
//public:
//	void Invoke()
//	{
//		GetInput();
//		MakeSol();
//	}
//};
//
//
//
//int main(void)
//{
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//
//	Solution solution;
//	solution.Invoke();
//	return 0;
//}