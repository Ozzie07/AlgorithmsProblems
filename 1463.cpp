#include <cstdio>

int min(int const& a, int const& b, int const& c)
{
	int min = a;
	if (min > b)
		min = b;
	if (min > c)
		min = c;

	return min;
}

int D(int const& value, int* memo)
{
	if (memo[value])
	{
		return memo[value];
	}
	int value1 = !(value % 3) ? value / 3 : 0;
	int value2 = !(value % 2) ? value / 2 : 0;
	int value3 = value - 1;

	if (value == 0)
		return 1000001;
	if (value == 1)
		return 0;
	return memo[value] = min(D(value1, memo) + 1, D(value2, memo) + 1, D(value3, memo) + 1);
}

int main()
{
	//memo init
	int* memo = new int[1000001];
	for (size_t i = 0; i < 1000001; i++)
	{
		memo[i] = 0;
	}

	int n;
	scanf("%d", &n);
	printf("%d\n", D(n, memo));
	return 0;
}