#include <bits/stdc++.h>
#define LENGTH 1000001
using namespace std;
int main() {
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	//\n faster than endl. endl makes buffer flush explicitly.

	int que[LENGTH];
	int* front = que;
	int* back = que;
	int size = 0;
	int n;
	cin >> n;
	string operation;



	for (size_t i = 0; i < n; i++)
	{
		cin >> operation;

		switch (operation[0])
		{
		case'p':
			if (operation[1] == 'u')
			{
				//push
				cin >> *back;
				size++;
				back++;
				break;
			}
			//pop
			if (!size) //ifsize 0??
			{
				cout << -1 << '\n';
				break;
			}
			cout << *front << '\n';
			front++;
			size--;
			break;
		case's':
			cout << size << '\n';
			//size
			break;
		case'e':
			//empty
			if (size)
				cout << 0 << '\n';
			else //ifsize 0??
				cout << 1 << '\n';
			break;
		case'f':
			if (!size)
			{
				cout << -1 << '\n';
				break;
			}
			cout << *front << '\n';
			//front
			break;
		case'b':
			if (!size)
			{
				cout << -1 << '\n';
				break;
			}
			cout << *(back - 1) << '\n';
			//back;
			break;
		}
	}

	return 0;
}