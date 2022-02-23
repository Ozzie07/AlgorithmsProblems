#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int N;
char sum;
char n1[10001], n2[10001];
string s1, s2, tmp;
vector<int> ans;

int main()
{
	cin >> s1 >> s2;

	//���� �ϰ����� ���ؼ� �� �� ���� s1���� ����.
	if (s1.size() < s2.size())
	{
		tmp = s1;
		s1 = s2;
		s2 = tmp;
	}

	//n1, n2 �迭�� ����� ����
	for (int i = 0; i < s1.size(); i++)
		n1[i + 1] = s1[i] - '0';

	for (int i = 0; i < s2.size(); i++)
		n2[i + 1 + (s1.size() - s2.size())] = s2[i] - '0';
	//
	
	// num�迭���� ���κк��� ������ �ϸ鼭 ans���Ϳ� �� �����Ѵ�.
	for (int i = s1.size(); i > 0; i--)
	{
		sum = n1[i] + n2[i];
		if (sum >= 10)
		{
			n1[i - 1]++;
			sum -= 10;
		}
		ans.push_back(sum);
	}
	//
	
	//������ �ؼ� �� ���ڸ��� �ö󰡵� 1 �ۿ� �ȿö�.
	if (n1[0] != 0) cout << 1;

	for (int i = ans.size() - 1; i >= 0; i--)
	{
		cout << ans[i];
	}
}
