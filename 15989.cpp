#include <bits/stdc++.h>
using namespace std;

class Solution
{
	int numOfTestCase;
	void Show(int* arr, int size)
	{
		cout << "----------------------------------------" << endl;
		for (size_t i = 0; i <= size; i++)
		{
			cout << arr[i] << ' ';
		}
		cout << endl;
		cout << "----------------------------------------" << endl;
	}

public:
	void Sol()
	{
		cin >> numOfTestCase;

		for (size_t i = 0; i < numOfTestCase; i++)
		{
			int target;
			cin >> target;
			int Possibles[10001] = { 0, };

			Possibles[0] = 1;
			for (size_t i = 1; i <= 3; i++) // 1 => 1만 있다고 가정, 2 => 1 과 2가 있다고 가정, 3 => 1, 2, 3 이 있다고 가정. 3 자리에 n을 넣으면 n 까지 있다고 가정. 행렬에도 응용 가능함.
			{
				for (size_t j = i; j <= target; j++)
				{
					Possibles[j] = Possibles[j] + Possibles[j - i];
				}
				//cout << i << endl;
				//Show(numbers, num);
			}
			cout << Possibles[target] << '\n';
		}
	}
};

int main() {
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	//\n faster than endl. endl makes buffer flush explicitly.
	Solution solution;
	solution.Sol();
	return 0;
}