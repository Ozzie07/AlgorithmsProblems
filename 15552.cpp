#include <cstdio>
#define _CRT_SECURE_NO_WARNINGS
int NumOfTestCase()
{
	int numOfTestCase;
	scanf("%d", &numOfTestCase);
	return numOfTestCase;
}

//GetTwoArgumentsFromInputDevice & return it.
int GetTwoParameterAdd()
{
	int a, b;
	scanf("%d %d", &a, &b);
	return a + b;
}

int main()
{
	int numOfTestCase = NumOfTestCase();
	for (int i = 0; i < numOfTestCase; i++)
	{
		printf("%d\n", GetTwoParameterAdd());
	}
	return 0;
}