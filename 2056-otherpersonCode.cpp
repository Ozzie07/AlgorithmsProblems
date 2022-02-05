//#include <iostream>
//#include <queue>
//#include <stack>
//#define MAX 10001
//using namespace std;
//
//class Solution
//{
//	int n; //�����ؾ��� �۾��� ��.
//	int delay[MAX]; //�� �۾����� �ɸ��� �ð��� �����ϴ� �迭
//	int numOfWorks[MAX]; // �����ؾ��� �۾��� ���� �����ϴ� �迭
//	int cache[MAX]; // �ش� �۾��� �Ϸ�Ǵµ� �ɸ� �ּ� �ð��� �����ϴ� �迭
//	stack<int> stk[MAX]; //���Ӽ��� ������ ��ũ���� ���⿡ �� ����.
//	//adjList�� inversedDirectedEdges�� ����ִ�.
//	//�ش� �۾��� �����ϰ�, ������ �����ؾ� �ϴ� �༮���� �������.
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
//		queue<int> q; //1->2->3->4->5 ������ ������.
//		//�츮�� input�� ���� ��, 5->4->3->2->1�� ���·�, 5�� �����Ϸ��� 4�� �����ؾ��ϰ�...
//		//����.
//		//�ռ� input�� �޴� ����� ���� ���� �ٸ��� �޴´ٴ� ���� �� �� ����.
//		//���� �Ǿ���� �۾��� �ش� index�� �ް� ������ �۾��� �༮�� stk�� �־�д�.
//		//q�� ������ ������ �ִµ�, ���� ���� �༮���� ���� ó���ϰ� ���� �༮�� ������� ó���� ���־��,
//		//������ ������Ʈ�� ���������� �����ϴ�.
//			
//
//		//�����۾��� ���� �۾��� ������Ʈ.
//		for (int i = 1; i <= n; i++)
//		{
//			if (numOfWorks[i])
//			{
//				continue;
//			}
//
//			q.push(i); //�����ؾ��ϴ� �۾��� ���ٸ�, Q�� ������ �ȴ�.
//			cache[i] = delay[i]; //�����ؾ��ϴ� �۾��� ���ٸ� �� ��ü�� delay�� �ǹǷ�...
//			// �����ؾ��ϴ� �۾��� �ִٸ�, �� �༮�� �ٸ� �����ؾ��ϴ� �༮�� ������Ʈ�ϴ� ��������
//			// �� ���� ���� �� �ִ�. �̴� ������ while
//		}
//
//		//�����۾��� �ִ� �۾��� ������Ʈ.
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