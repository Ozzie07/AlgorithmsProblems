#include <bits/stdc++.h>
#define LENGTH 100001
using namespace std;

int main() {
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	//\n faster than endl. endl makes buffer flush explicitly.

	int n;
	cin >> n;

	//you can imagine
	//****Max_Heap****/mid/****Min_heap****//

	priority_queue<int, vector<int>, less<int>> max_heap;
	priority_queue<int, vector<int>, greater<int>> min_heap;

	int input;
	cin >> input;
	max_heap.push(input);
	cout << max_heap.top() << ' ';

	for (size_t i = 1; i < n; i++)
	{
		cin >> input;
		if (max_heap.size() == min_heap.size())
			max_heap.push(input);
		else
			min_heap.push(input);

		if (max_heap.top() > min_heap.top())
		{
			//Swap Top.
			int a = max_heap.top();
			max_heap.pop();
			int b = min_heap.top();
			min_heap.pop();
			max_heap.push(b);
			min_heap.push(a);
		}
		cout << max_heap.top() << ' ';
	}

	return 0;
} ;