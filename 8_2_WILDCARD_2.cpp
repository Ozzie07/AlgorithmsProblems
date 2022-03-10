//#include <bits/stdc++.h>
//using namespace std;
//
//class Solution
//{
//	int n;
//	string pattern;
//	bool isFirstStar = false;
//	bool isLastStar = false;
//	vector<string> subPatterns;
//	string words[50];
//
//	void GetInput()
//	{
//		cin >> pattern;
//		cin >> n;
//		for (size_t i = 0; i < n; i++)
//		{
//			cin >> words[i];
//		}
//	}
//
//	void Devide()
//	{
//		if (pattern[0] == '*')
//			isFirstStar = true;
//		if (pattern[pattern.size() - 1] == '*')
//			isLastStar = true;
//
//		for (size_t i = 0; i < pattern.size(); i++)
//		{
//			string subPattern;
//			if (pattern[i] != '*')
//			{
//				int j = i;
//				while (!(pattern[j] == '*' || j == pattern.size()))
//				{
//					subPattern.push_back(pattern[j]);
//					j++;
//				}
//				i = j - 1;
//				subPatterns.push_back(subPattern);
//				
//			}
//		}
//	}
//	
//	bool isMatched(string &_word, string &_subPattern, int &_cursor)
//	{
//
//		if (_word.size() - _cursor < _subPattern.size())
//		{
//			_cursor = _word.size();
//			return false;
//		}
//
//		for (size_t i = 0; i < _subPattern.size(); i++)
//		{
//			if (_subPattern[i] == '?')
//			{
//				_cursor++;
//				continue;
//			}
//			else
//			{
//				if (_subPattern[i] != _word[_cursor])
//				{
//					return false;
//				}
//				_cursor++;
//			}
//		}
//
//		return true;
//	}
//
//	bool Find(string word)
//	{
//		//�� word�� ���ؼ� �������� �ƴ��� Ȯ���ϱ�.
//		//ó��
//		int cursor = 0; //word�� ����Ű�� �ִ� cursor.
//		int subPatternCursor = 0;
//		if (!isFirstStar)
//		{
//			if (!isMatched(word, subPatterns[subPatternCursor++], cursor))
//				return false;
//		}
//		
//		//�߰�
//
//		// 1. ù ���ڰ� �´� �κб��� cursor �̵�.
//		// 2. �ش� ��ġ���� ��Ī Ȯ��.
//		// 3. ������ ���� �༮. �ƴϸ� false return �� ����.
//		
//		while (subPatternCursor != subPatterns.size())
//		{
//			if(cursor == word.size())
//				break;
//
//			if (subPatterns[subPatternCursor][0] == word[cursor])
//			{
//				if (isMatched(word, subPatterns[subPatternCursor], cursor))
//				{
//					subPatternCursor++;
//				}
//			}
//			else
//			{
//				cursor++;
//			}
//		}
//
//		//��
//		if (subPatternCursor != subPatterns.size())
//			return false;
//
//		if (cursor == word.size())
//			return true;
//
//		if (isFinalCheck(word, subPatterns[subPatternCursor - 1]))
//		{
//			return true;
//		}
//
//		if (isLastStar)
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	}
//
//	bool isFinalCheck(string& word, string& subPattern)
//	{
//		int subPatternSize = subPattern.size();
//		for (size_t i = 0; i < subPatternSize; i++)
//		{
//			if (word[word.size() - subPatternSize + i] != subPattern[i])
//				return false;
//		}
//		return true;
//	}
//public:
//	void Invoke()
//	{
//		GetInput();
//		Devide();
//		vector<string> Answer;
//		for (size_t i = 0; i < n; i++)
//		{
//			if (Find(words[i]))
//				Answer.push_back(words[i]);
//		}
//
//		sort(Answer.begin(), Answer.end());
//		for (string i : Answer)
//		{
//			cout << i << '\n';
//		}
//	}
//};
//
//int main() {
//	//	freopen("input.txt", "r", stdin);
//	//	freopen("output.txt", "w", stdout);
//
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	//\n faster than endl. endl makes buffer flush explicitly.
//
//	bool DEBUG = false;
//	if (DEBUG)
//	{
//
//		Solution solution;
//		solution.Invoke();
//	}
//	else
//	{
//		int tc;
//		cin >> tc;
//		for (size_t i = 0; i < tc; i++)
//		{
//			Solution solution;
//			solution.Invoke();
//		}
//	}
//
//	return 0;
//}
//