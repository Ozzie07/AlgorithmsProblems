#include <vector>
using namespace std;

void SelectionSort(vector<int>& A)
{
	for (int i = 0; i < A.size(); i++)
	{
		int minIndex = i;
		for (size_t j = 0; j < A.size(); j++)
		{
			if (A[minIndex] > A[j])
				minIndex = j;
			swap(A[i], A[minIndex]);
		}
	}
}

void InsertionSort(vector<int>& A)
{
	for (size_t i = 0; i < A.size(); i++)
	{
		int j = i;
		while (j > 0 && A[j - 1] > A[j])
		{
			swap(A[j - 1], A[j]);
			--j;
		}
	}
}