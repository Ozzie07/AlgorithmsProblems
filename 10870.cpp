#include <cstdio>
typedef long long Data;

Data Fibonacci(Data N)
{

	if (N >= 2)
		return Fibonacci(N - 2) + Fibonacci(N - 1);
	else if (N == 1)
		return 1;
	else if (N == 0)
		return 0;

}

int main()
{
	Data N;
	scanf("%lld", &N);
	printf("%lld", Fibonacci(N));
	return 0;
}