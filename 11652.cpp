#include <bits/stdc++.h>

using namespace std;

int main() {
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	//\n faster than endl. endl makes buffer flush explicitly.

	//test case
	//3 3 1 2  => 1
	//7 1 2 1 2 1 2 3 => 1
	//6 1 2 1 2 1 2  => 1

	map<long long, int> map;

	long long max_idx = 0;
	long long max = 0;
	int numOfCards;
	int num;
	cin >> num;
	long long input;

	cin >> input;
	map.insert(make_pair(input, 1));
	max_idx = input;
	max = 1;

	for (size_t i = 1; i < num; i++)
	{
		cin >> input;
		if (map.end() == map.find(input))
		{
			map.insert(make_pair(input, 1));
			if (max <= 1)
			{
				if (max == 1)
				{
					if (max_idx > input)
						max_idx = input;
					continue;
				}
				max = 1;
				max_idx = input;
			}
		}
		else
		{
			numOfCards = map.find(input)->second + 1;
			map.insert_or_assign(input, numOfCards);

			//max value update;
			{
				if (max <= numOfCards)
				{
					if (max == numOfCards)
					{
						if (max_idx > input)
							max_idx = input;
						continue;
					}
					max = numOfCards;
					max_idx = input;
				}
			}
		}
	}

	cout << max_idx;
	return 0;
}