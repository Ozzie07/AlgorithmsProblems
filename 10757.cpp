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

	//논리의 일관성을 위해서 더 긴 수를 s1으로 저장.
	if (s1.size() < s2.size())
	{
		tmp = s1;
		s1 = s2;
		s2 = tmp;
	}

	//n1, n2 배열을 만드는 과정
	for (int i = 0; i < s1.size(); i++)
		n1[i + 1] = s1[i] - '0';

	for (int i = 0; i < s2.size(); i++)
		n2[i + 1 + (s1.size() - s2.size())] = s2[i] - '0';
	//
	
	// num배열들의 끝부분부터 덧셈을 하면서 ans벡터에 값 저장한다.
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
	
	//덧셈을 해서 맨 앞자리가 올라가도 1 밖에 안올라감.
	if (n1[0] != 0) cout << 1;

	for (int i = ans.size() - 1; i >= 0; i--)
	{
		cout << ans[i];
	}
}
