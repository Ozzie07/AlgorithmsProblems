#include <bits/stdc++.h>
using namespace std;

char str[9000000];
int Lenght = 0;
void star(int i, int j, int num) //분하다. 이런 문제를 못풀어 답을 보아야하는 내 모습
{	

	if ((i / num) % 3 == 1 && (j / num) % 3 == 1)
	{
		str[Lenght++] = ' ';
	}
	else
	{
		if (num / 3 == 0)
			str[Lenght++] = '*';
		else
			star(i, j, num / 3);
	}
}

int main() {
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	//\n faster than endl. endl makes buffer flush explicitly.
	int num;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			star(i, j, num);
		}
		str[Lenght++] = '\n';
	}
	cout << str;
	
	return 0;
}