#include <cstdio>
#define MAX_LENGTH 10001
class Array
{
private:

	int arr[MAX_LENGTH];
	int length;

public:

	Array()
	{
		length = 0;
	}

	void add(int element)
	{
		arr[length++] = element;
	}

	void printOut()
	{
		for (size_t i = 0; i < length; i++)
		{
			printf("%d ", arr[i]);
		}
	}

};

int GetData()
{
	int input;
	scanf("%d", &input);

	return input;
}

int main()
{
	int N;
	int X;
	Array arr;
	N = GetData();
	X = GetData();

	for (size_t i = 0; i < N; i++)
	{
		int input;
		input = GetData();

		if (input < X)
			arr.add(input);
	}

	arr.printOut();

	return 0;
}