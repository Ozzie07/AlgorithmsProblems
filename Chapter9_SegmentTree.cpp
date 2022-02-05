//#include <bits/stdc++.h>
//
//using namespace std;
//
//class SegmentTree
//{
//#define ARRAY_LENGTH 10
//#define TREE_SIZE 20
//
//	int arr[ARRAY_LENGTH];
//	int Tree[TREE_SIZE];
//
//	int LChildIdx(int k) { return k << 1; }
//	int RChildIdx(int k) { return (k << 1) + 1; }
//	int ParentIdx(int k) { return k >> 1; }
//
//	//MAX_ARRAY ~ 2 MAX_ARRAY - 1 까지가 원래 Array와 같음.
//	void ArrayInit()
//	{
//		int treeIdx = ARRAY_LENGTH;
//		for (size_t i = 0; i < ARRAY_LENGTH; i++)
//		{
//			Tree[treeIdx++] = arr[i];
//		}
//	}
//
//	void TreeInit()
//	{
//		for (size_t i = ARRAY_LENGTH - 1; i > 0; i--)
//		{
//			Tree[i] = Tree[RChildIdx(i)] + Tree[LChildIdx(i)];
//		}
//	}
//
//	int sum(int a, int b)
//	{
//		a += ARRAY_LENGTH;
//		b += ARRAY_LENGTH;
//		int s = 0;
//		while (b >= a)
//		{
//			if (a % 2 == 1) s += Tree[a++];
//			if (b % 2 == 0) s += Tree[b--];
//			a = a >> 1;
//			b = b >> 1;
//		}
//		return s;
//	}
//
//	void add(int k, int x)
//	{
//		k += ARRAY_LENGTH;
//		Tree[k] += x;
//		for (k /= 2; k >= 1; k /= 2) //루트 노드에 도달할 때까지...
//			Tree[k] = Tree[LChildIdx(k)] + Tree[RChildIdx(k)];
//	}
//	
//};
