#include <bits/stdc++.h>

using namespace std;


int main() {
		//freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	//\n faster than endl. endl makes buffer flush explicitly.

	auto cmp = [](int a, int b) { return a > b; };

	priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
	int n,k;
	cin >> n >> k;

	int input;
	for (size_t i = 0; i < n; i++)
	{
		cin >> input;
		pq.push(input);
	}

	for (size_t i = 0; i < k - 1; i++)
	{
		pq.pop();
	}

	cout << pq.top();

	return 0;
}