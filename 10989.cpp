#include <bits/stdc++.h>
#define LENGTH 10001

using namespace std;

void InitArray(int* arr, int length)
{
	for (size_t i = 0; i < LENGTH; i++)
	{
		arr[i] = 0;
	}
}

int Larger(int a, int b)
{
	if (a > b)
		return a;
	return b;
}



int main() {
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	//\n faster than endl. endl makes buffer flush explicitly.
	int arr[LENGTH];
	InitArray(arr, LENGTH);

	int numOfInput;
	int input;
	int max = 0;
	cin >> numOfInput;
	for (size_t i = 0; i < numOfInput; i++)
	{
		cin >> input;
		max = Larger(max, input);
		arr[input]++;
	}

	for (size_t i = 1; i <= max; i++)
	{
		while (arr[i])
		{
			cout << i << ' ';
			arr[i]--;
		}
	}

	return 0;
}