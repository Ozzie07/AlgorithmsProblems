#include <bits/stdc++.h>
using namespace std;

class Solution
{
#define MAX 1003002
	int n;
	int lastChecked = 1;
	short Seive[MAX];
	bool Test[MAX];


	void GetInput()
	{
		cin >> n;
	}

	void Init()
	{
		for (size_t i = 0; i < MAX; i++)
		{
			Seive[i] = -1;
		}
	}

	bool IsPrime(int a)
	{
		if (a == 2)
			return true;

		bool res = true;
		int n = sqrt(a);
		for (size_t i = 2; i <= n; i++)
		{
			if (a % i == 0)
			{
				res = false;
				break;
			}
		}
		return res;
	}

	void Eratostenes() //�ϳ� ã���� lastChecked�� ������ ã�� �Ҽ� �����Ŵ.
	{
		while (true)
		{
			lastChecked++;
			if (Seive[lastChecked] == -1) //���� �湮 ����.
			{
				if (IsPrime(lastChecked))
				{
					Seive[lastChecked] = 1; //�Ҽ���.
					int i = 2;
					while (lastChecked * i < MAX)
					{
						Seive[lastChecked * i] = 0; //�Ҽ��� �ƴ�.
						i++;
					}
					//�ϳ� �߰� ������ ����..
					break;
				}
			}
		}
	}

	bool IsPalindrome(int a)
	{
		string str = to_string(a);
		bool res = true;
		int length = str.length() >> 1;

		for (size_t i = 0; i < length; i++)
		{
			if (str[i] != str[str.length() - 1 - i])
			{
				res = false;
				break;
			}
		}
		return res;
	}


public:
	void Invoke()
	{
		GetInput();
		Init();
		while (true)
		{
			Eratostenes();
			if (lastChecked >= n)
			{
				if (IsPalindrome(lastChecked))
				{
					cout << lastChecked << '\n';
					break;
				}
			}
		}
	}
};


int main() {
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	//\n faster than endl. endl makes buffer flush explicitly.
	Solution sol;
	sol.Invoke();
	return 0;
}