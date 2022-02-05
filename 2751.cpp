#include <bits/stdc++.h>
#define LENGTH 1000001
using namespace std;

int temp_arr[LENGTH];

void Merge(int* arr, int start, int end)
{
	int net_length = end - start + 1;
	int partition = (end + start) / 2;

	int l_start = start;
	int l_idx = l_start;
	int l_end = partition;

	int r_start = partition + 1;
	int r_idx = r_start;
	int r_end = end;

	//int* temp_arr = new int[net_length];

	int i = 0;
	for (; i < net_length; i++)
	{
		if (arr[l_idx] > arr[r_idx])
		{
			temp_arr[i] = arr[r_idx];
			r_idx++;;
		}
		else
		{
			temp_arr[i] = arr[l_idx];
			l_idx++;
		}

		if (l_idx > l_end)
		{
			for (int j = r_idx; j <= r_end; j++)
			{
				i++;
				temp_arr[i] = arr[j];
			}
			break;
		}

		if(r_idx > r_end)
		{
			for (int j = l_idx; j <= l_end; j++)
			{
				i++;
				temp_arr[i] = arr[j];
			}
			break;
		}
	}

	//Update
	int j = start;
	for (i = 0; i < net_length; i++)
	{
		arr[j] = temp_arr[i];
		j++;
	}

	//delete[] temp_arr;
	return;
}

void MergeSort(int* arr, int start, int end)
{
	if (start >= end)
		return;

	int partition = (end + start) / 2;
	MergeSort(arr, start, partition);
	MergeSort(arr, partition + 1, end);
	Merge(arr, start, end);
}

void Sort(int* arr, int size)
{
	MergeSort(arr, 0, size - 1);
}

int main() {
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	//\n faster than endl. endl makes buffer flush explicitly.
	int arr[LENGTH];
	int Length;
	cin >> Length;
	for (int i = 0; i < Length; i++)
	{
		cin >> arr[i];
	}

	//sort

	Sort(arr, Length);

	for (int i = 0; i < Length; i++)
	{
		cout << arr[i] << '\n';
	}
	cout << endl;


	return 0;
}