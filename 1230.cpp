#include <bits/stdc++.h>

using namespace std;
//hello fine
//hello, how are you ? i'm fi thank you fine and you? 이 경우, 해결을 못하고 있음.
class Solution
{
	string a;
	string b;
	int lcs[1001][1001];
	int res = 0;
public:
	void GetInput()
	{
		getline(cin ,a);
		getline(cin ,b);
	}

	void ShowLCS()
	{
		for (size_t i = 0; i < a.size(); i++)
		{
			for (size_t j = 0; j < b.size(); j++)
			{
				cout << lcs[i][j] << ' ';
			}
			cout << '\n';
		}
	}

	void LCS()
	{
		int flag = 0;
		for (size_t i = 0; i < a.size(); i++)
		{
			if (a[i] == b[0])
				flag = 1;
			lcs[i][0] = flag;
		}
		flag = 0;
		for (size_t j = 0; j < b.size(); j++)
		{
			if (a[0] == b[j])
				flag = 1;
			lcs[0][j] = flag;
		}

		for (size_t i = 1; i < a.size(); i++)
		{
			for (size_t j = 1; j < b.size(); j++)
			{
				if (a[i] == b[j])
				{
					lcs[i][j] = lcs[i - 1][j - 1] + 1;
				}
				else
				{
					lcs[i][j] = max(lcs[i][j - 1], lcs[i - 1][j]);
				}
			}
		}
		ShowLCS();
	}

	int numOfPartition = 0;
	int GetRes()
	{
		return numOfPartition;
	}
	bool IsPossible()
	{
		int LAST_i_POSITION;
		int jInit = 0;
		int LengthOfSequence = 0;
		if (a[0] == b[0])
			LAST_i_POSITION = -1;
		else
			LAST_i_POSITION = -2;
		for (size_t i = 0; i < a.size(); i++)
		{
			for (size_t j = jInit; j < b.size(); j++)
			{

				if (a[i] == b[j])
				{
					if (LAST_i_POSITION + 1 != j) //바로 다음이 아님.
						numOfPartition++;
					jInit = j + 1;
					LengthOfSequence++;
					LAST_i_POSITION = j;
					break;
				}
			}
		}
		//cout << "-----------Length of Sequence------------" << endl;
		//cout << LengthOfSequence << endl;
		if (LengthOfSequence == a.size())
			return true;
		return false;
	}
};

int main() {
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	//\n faster than endl. endl makes buffer flush explicitly.
	Solution solution;
	solution.GetInput();
	solution.LCS();
	//if (solution.IsPossible())
	//{
	//	cout << "-----------RES-----------" << endl;
	//	cout << solution.GetRes() << endl;
	//	cout << "------------------------" << endl;
	//}
	//else
	//{
	//	cout << "-----------RES-----------" << endl;
	//	cout << -1 << endl;
	//	cout << "------------------------" << endl;
	//}
	//solution.LCS();
	return 0;
}