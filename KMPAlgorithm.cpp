//#include <bits/stdc++.h>
//using namespace std;
//
//vector<int> makeTable(string pattern)
//{
//	int patternSize = pattern.size();
//	vector<int> table(patternSize, 0);
//	int j = 0;
//
//	for (size_t i = 1; i < patternSize; i++)
//	{
//		while (j > 0 && pattern[i] != pattern[j])
//		{
//			cout << "j -1 : " << j - 1 << endl;
//			j = 0;
//		}
//		
//		if (pattern[i] == pattern[j]) //���λ�� ���̻縦 �÷����� ��..
//		{
//			table[i] = ++j;
//		}
//		cout << "pattern[" << i << "] : " << pattern[i] << "  pattern[" << j << "] : " << pattern[j] << "  table[" << i << "] : " << table[i] << endl;
//
//	}
//	//cout << "pattern : " << table[patternSize - 1] << endl;
//	return table;
//}
//
//void KMP(string parent, string pattern)
//{
//	vector<int> table = makeTable(pattern);
//	int parentSize = parent.size();
//	int patternSize = pattern.size();
//	int j = 0;
//	for (int i = 0; i < parentSize; i++)
//	{
//		while (j > 0 && parent[i] != pattern[j])
//		{
//			j = table[j - 1];
//		}
//		if (parent[i] == pattern[j])
//		{
//			if (j == patternSize - 1)
//			{
//				printf("%d��°���� ã�ҽ��ϴ�.\n", i - patternSize + 2);
//				j = table[j];
//			}
//			else
//			{
//				j++;
//			}
//		}
//		//cout << "parent[" << i << "] : " << parent[i] << "  pattern[" << j << "] : " << pattern[j] << "  table[" << i << "] : " << table[i] << endl;
//	}
//}
//
//int main() {
//	//	freopen("input.txt", "r", stdin);
//	//	freopen("output.txt", "w", stdout);
//
//	//ios::sync_with_stdio(0);
//	//cin.tie(0);
//	//\n faster than endl. endl makes buffer flush explicitly.
//	string parent = "ababacabacaabacaaba";
//	string pattern = "abacabab";
//	KMP(parent, pattern);
//	//while (true)
//	//{
//	//	/*string pattern;
//	//	cin >> pattern;
//	//	vector<int> table = makeTable(pattern);
//
//	//	for (size_t i = 0; i < table.size(); i++)
//	//		printf("%d ", table[i]);
//	//	cout << endl;*/
//
//	//}
//
//	return 0;
//}