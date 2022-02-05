#include <cstdio>
#define ARR_SIZE 13
typedef long long DATA;

void arrInit(DATA* arr)
{
	for (size_t i = 0; i < ARR_SIZE; i++)
	{
		arr[i] = 1;
	}
}

void MakeFactorial(DATA* arr, int N)
{
	for (size_t i = 1; i <= N; i++)
	{
		arr[i] = i * arr[i - 1];
	}
}

void printOut(DATA* arr, DATA N)
{
	//for (size_t i = 1; i <= N; i++)
	//{
	//	printf("%lld\n", arr[i]);
	//}
	printf("%lld", arr[N]);
}

int main()
{
	DATA N;
	DATA arr[ARR_SIZE];
	scanf("%lld", &N);

	arrInit(arr);
	MakeFactorial(arr, N);
	printOut(arr, N);

	return 0;
}