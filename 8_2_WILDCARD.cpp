#include <bits/stdc++.h>
using namespace std;

class Solution
{
	string wildCardPattern;
	int n;
	string fileNames[50];

	void GetInput()
	{
		cin >> wildCardPattern;
		cin >> n;
		for (size_t i = 0; i < n; i++)
		{
			cin >> fileNames[i];
		}
	}

	int cursor = 0;
	int Case = 2;

	string FindLocalPattern()
	{
		//case 0 , p
		//case 1 , *p
		//case 2 , p*
		//case 3 , *p*
		//specify pattern

		string temp;
		int lastCursorPosition = cursor;
		for (cursor; cursor < wildCardPattern.size(); cursor++)
		{
			temp.push_back(wildCardPattern[cursor]);

			if (wildCardPattern[cursor] == '*')
			{
				temp.pop_back();
				if (cursor == lastCursorPosition) //*p인 케이스.
				{
					cursor++;
 					for (cursor; cursor < wildCardPattern.size(); cursor++)
					{
						temp.push_back(wildCardPattern[cursor]);
						if (wildCardPattern[cursor] == '*') //*p*인 케이스.
						{
							temp.pop_back();
							cursor++;
							Case = 3;
							return temp;
						}
					}
					Case = 1;
					return temp;
					break;
				}
				else //p* 인 케이스.
				{
					cursor++;
					Case = 2;
					return temp;
				}
			}
		}

		if (lastCursorPosition == 0)
		{
			Case = 0;
		}
		else
		{
			Case = 1;
		}
		return temp;
	}

	bool isMatched(int& localCursor, string fileName, string pattern)
	{
		for (size_t i = 0; i < pattern.size(); i++)
		{
			if (pattern[i] == '?')
			{
				localCursor++;
				continue;
			}
			else
			{
				if (pattern[i] != fileName[localCursor])
					return false;
				localCursor++;
			}
		}
		return true;
	}

	bool firstStarredMatching(int& localCursor, string& fileName, string& pattern)
	{
		//find pattern's first character
		int pattern_idx = 0;
		if (pattern.size() == 0)
			return true;
		for (localCursor; localCursor < fileName.size(); localCursor++)
		{
			if (fileName[localCursor] == pattern[pattern_idx])
			{
				if (isMatched(localCursor, fileName, pattern))
					return true;
			}
		}
		return false;
	}

	bool PatternMatching(string &fileName)
	{
		//case 0 , p
		//case 1 , *p
		//case 2 , p*
		//case 3 , *p*

		string localPattern;
		int localCursor = 0;
		while (!(Case == 0 || Case == 1))
		{
			localPattern = FindLocalPattern();
			cout << "localPattern : " << localPattern << endl;
			switch (Case)
			{
			case 0:
			{
				//둘이 서로 완전히 일치하는지. 를 확인하기.
				if (localPattern.size() != fileName.size())
					return false;
				return isMatched(localCursor, fileName, localPattern);
				break;
			}
			case 1:
			{
				//localCursor를 따라서 맞는지 확인.
				return firstStarredMatching(localCursor, fileName, localPattern);
				//return isMatched(localCursor, fileName, localPattern);
				break;
			}
			case 2:
			{
				//주어진 p의 길이만큼 맞는지 확인.
				if (!isMatched(localCursor, fileName, localPattern))
					return false;
				if (wildCardPattern[cursor - 1] == '*') //last.
					return true;
				break;
			}
			case 3:
			{
				//p의 길이만큼 맞는지 확인.
				if (!firstStarredMatching(localCursor, fileName, localPattern))
					return false;
				/*if (!isMatched(localCursor, fileName, localPattern))
					return false;*/
				if (wildCardPattern[cursor - 1] == '*' && cursor > wildCardPattern.size()) //last.
					return true;
				break;
			}
			default:
				break;
			}
		}
	}

public:
	void Invoke()
	{
		GetInput();
		vector<string> answer;
		for (size_t i = 0; i < n; i++)
		{
			cursor = 0;
			Case = 2;
			if (PatternMatching(fileNames[i]))
				answer.push_back(fileNames[i]);
		}

		cout << "------------------------------------RES-------------------------------------" << endl;
		for (auto i : answer)
		{
			cout << i << '\n';
		}
		cout << "------------------------------------RES-------------------------------------" << endl;

	}


};

int main() {
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);  

	ios::sync_with_stdio(0);
 	cin.tie(0);
	//\n faster than endl. endl makes buffer flush explicitly.

	int tc;
	cin >> tc;
	for (size_t i = 0; i < tc; i++)
	{
		Solution solution;
		solution.Invoke();
	}
	return 0;
}