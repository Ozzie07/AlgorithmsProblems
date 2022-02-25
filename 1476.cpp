#include <bits/stdc++.h>
using namespace std;

class Solution
{
	int E = 15, S = 28, M = 19;

	int e, s, m; //target

	int e_i = 1, s_i = 1, m_i = 1; //current

	int year = 1;

	void ShowCurrent()
	{
		cout << "E : " << e_i << "  S : " << s_i << "  M: " << m_i << endl;
		system("pause");
	}

	void GetInput()
	{
		cin >> e >> s >> m;
	}

	void OneYear()
	{
		e_i++;
		if (e_i > E)
		{
			e_i = 1;
		}
		s_i++;
		if (s_i > S)
		{
			s_i = 1;
		}
		m_i++;
		if (m_i > M)
		{
			m_i = 1;
		}
		year++;
	}

	bool Compare()
	{
		if (e == e_i && m == m_i && s == s_i)
		{
			return true;
		}
		return false;
	}

	void Find()
	{
		while (!Compare())
		{
			OneYear();
			//ShowCurrent();
		}
	}

public:
	void Invoke()
	{
		GetInput();
		Find();
		cout << year << '\n';
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