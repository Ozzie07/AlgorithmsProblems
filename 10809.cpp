#include <bits/stdc++.h>

using namespace std;

int main() {
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	//\n faster than endl. endl makes buffer flush explicitly.

	int arr[28];
	for (size_t i = 0; i < 27; i++)
	{
		arr[i] = -1;
	}
	char str[101];
	cin >> str;

	int i = 0;
	while (str[i] != '\0')
	{
		if(arr[(int)(str[i]) - 96] == -1)
			arr[(int)(str[i]) - 96] = i;
		i++;
	}

	for (size_t i = 1; i <= 26; i++)
	{
		cout << arr[i] << ' ';
	}

	return 0;
}