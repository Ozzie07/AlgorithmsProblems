#include <bits/stdc++.h>

using namespace std;

void ArrayCopy(int* in, int* out, int length)
{
	for (size_t i = 0; i < length; i++)
	{
		out[i] = in[i];
	}
}

int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}

void ArrayInit(int* in, int length)
{

	for (size_t i = 0; i < length; i++)
	{
		in[i] = 0;
	}
}

int main() {
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	//\n faster than endl. endl makes buffer flush explicitly.

	int n, k;
	cin >> n >> k;

	tuple<int, int> *Item = new tuple<int, int>[n + 1]; // where n + 1, to make Item idx starts from 1, not 0.
	int totalWeight = 0;
	Item[0] = make_tuple(0, 0);

	for (size_t i = 1; i < n + 1; i++)
	{
		int w, v;
		cin >> w >> v;
		Item[i] = make_tuple(w, v);

		//totalWeight += w;
	}

	//int** arr = new int* [n + 1];
	//for (size_t i = 0; i < n + 1; i++)
	//	arr[i] = new int[totalWeight + 1]; // same reason, n + 1.

	//for (size_t i = 0; i < n + 1; i++)
	//	ArrayInit(arr[i], totalWeight + 1);

	////k not included.
	//for (size_t Itemidx = 1; Itemidx < n + 1; Itemidx++)
	//{
	//	for (size_t indicateWeight = 0; indicateWeight < totalWeight + 1; indicateWeight++)
	//	{
	//		if (get<0>(Item[Itemidx]) <= indicateWeight)
	//			arr[Itemidx][indicateWeight] = get<0>(Item[Itemidx]) + arr[Itemidx][indicateWeight - get<0>(Item[Itemidx])];
	//		else
	//			arr[Itemidx][indicateWeight] = arr[Itemidx - 1][indicateWeight];
	//	}
	//}

	//k included.
	int Itemidx = 1;
	int indicateWeight = 0;

	//int maxValue = 0;
	//for (Itemidx = 1; Itemidx < n + 1; Itemidx++)
	//{
	//	for (indicateWeight = 0; indicateWeight < k + 1; indicateWeight++)
	//	{
	//		int currentValue = arr[Itemidx - 1][indicateWeight];
	//		if (get<0>(Item[Itemidx]) <= indicateWeight)
	//		{
	//			int newValue = get<1>(Item[Itemidx]) + arr[Itemidx][indicateWeight - get<0>(Item[Itemidx])];
	//			if (currentValue < newValue)
	//				arr[Itemidx][indicateWeight] = newValue;
	//			else
	//				arr[Itemidx][indicateWeight] = currentValue;
	//		}
	//		else
	//			arr[Itemidx][indicateWeight] = currentValue;
	//		maxValue = arr[Itemidx][indicateWeight];
	//	}
	//} // before space optimization.

	totalWeight = k;

	int* lastArr = new int[totalWeight + 1];
	int* currentArr = new int[totalWeight + 1];
	ArrayInit(lastArr, totalWeight + 1);
	ArrayInit(currentArr, totalWeight + 1);

	//for (Itemidx = 1; Itemidx < n + 1; Itemidx++)
	//{
	//	for (indicateWeight = 0; indicateWeight < totalWeight + 1; indicateWeight++)
	//	{
	//		int lastValue = lastArr[indicateWeight];
	//		if (get<0>(Item[Itemidx]) <= indicateWeight)
	//		{
	//			currentArr[indicateWeight] = max(lastArr[indicateWeight], 
	//				(lastArr[indicateWeight - get<0>(Item[Itemidx])] + get<1>(Item[Itemidx])));
	//		}
	//		else
	//		{
	//			currentArr[indicateWeight] = lastArr[indicateWeight];
	//		}
	//		//cout << Itemidx << " : " << indicateWeight << " = " << currentArr[indicateWeight] << '\n';

	//	}
	//	ArrayCopy(currentArr, lastArr, totalWeight + 1);
	//} Optimization #1


	for (Itemidx = 1; Itemidx < n + 1; Itemidx++)
	{
		for (indicateWeight = 0; indicateWeight < totalWeight + 1; indicateWeight++)
		{
			int lastValue = lastArr[indicateWeight];
			if (get<0>(Item[Itemidx]) <= indicateWeight)
			{
				currentArr[indicateWeight] = max(lastArr[indicateWeight],
					(lastArr[indicateWeight - get<0>(Item[Itemidx])] + get<1>(Item[Itemidx])));
			}
			else
			{
				currentArr[indicateWeight] = lastArr[indicateWeight];
			}
			//cout << Itemidx << " : " << indicateWeight << " = " << currentArr[indicateWeight] << '\n';

		}
		ArrayCopy(currentArr, lastArr, totalWeight + 1);
	}

	cout << currentArr[k];
	return 0;
}