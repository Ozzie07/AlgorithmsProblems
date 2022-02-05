//#include <cstdio>
//
//int BSearch(int arr[], int length, int target)
//{
//	int first = 0;
//	int last = length - 1;
//	int mid;
//
//	while (first <= last)
//	{
//		mid = (first + last) / 2;
//
//		if (target == arr[mid])
//		{
//			return mid;
//		}
//		else
//		{
//			if (target < arr[mid])
//				last = mid - 1;
//			else
//				first = mid + 1;
//		}
//	}
//	return -1;
//}
//
////target �̻��� ���� ���� ó�� �����ϴ� ��ġ�� ��ȯ. arr[res] >= target
//int lower_binary(int* arr, int length, int target) 
//{
//	int start = 0;
//	int end = length - 1;
//	int mid;
//	while (end > start)
//	{
//		mid = (start + end) >> 1;
//		if (arr[mid] >= target)
//			end = mid;
//		else start = mid + 1;
//	}
//	return end;
//}
//
////target ���� ū ���� ó�� �����ϴ� ��ġ�� ��ȯ. arr[res] > target.
//int upper_binary(int* arr, int length, int target)
//{
//	int start = 0;
//	int end = length - 1;
//	int mid;
//	while (end > start)
//	{
//		mid = (start + end) >> 1;
//		if (arr[mid] > target)
//			end = mid;
//		else start = mid + 1;
//	}
//	return end;
//}
