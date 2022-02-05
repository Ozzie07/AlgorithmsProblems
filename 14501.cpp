#include <bits/stdc++.h>
#define ARR_MAX 1500010
using namespace std;

class Solution
{
	int n;
	int T[ARR_MAX];
	int P[ARR_MAX];
	int F[ARR_MAX]; //F? �ڿ��� ���� ������. i ��°���� pay �ִ밪�̶� ����.
public:

	void GetInput()
	{
		cin >> n;
		for (size_t i = 0; i < n; i++)
		{
			cin >> T[i];
			cin >> P[i];
		}
		for (size_t i = 0; i <= n; i++)
		{
			F[i] = 0;
		}
	}

	void Calculate()
	{
		F[n - 1] = T[n - 1];
		for (int i = n - 1; i >= 0; i--)
		{
			if (T[i] + i <= n) //�ش� Job�� ���� ���� ���� ó�� �����ϴٸ�
			{
				if (T[i] == 1)
				{
					F[i] = F[i + 1] + P[i];
 				}
				else
				{
					int temp = F[i + T[i]] + P[i]; // �ش� ���� ������ ����� pay
					if (temp > F[i + 1])
					{
						F[i] = temp; //�ش� job ����.
					}
					else
					{
						F[i] = F[i + 1]; //job ���� ����.
					}

				}
			}
			else
			{
				F[i] = F[i + 1];
			}
		//	cout << "----------------------" << endl;
		//	cout << "i : " << i  << " : " << F[i] << endl;
		//	cout << "----------------------" << endl;
		}
	}

	void Invoke()
	{
		GetInput();
		Calculate();
		cout << F[0];
	}
};

int main() {
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	//\n faster than endl. endl makes buffer flush explicitly.
	Solution solution;
	solution.Invoke();
	return 0;
}