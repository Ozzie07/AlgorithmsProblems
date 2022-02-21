//#include <bits/stdc++.h>
//using namespace std;
//
//void printPicked(vector<int> pick);
// 
//
//// n : 전체 원소의 수
//// picked : 지금까지 고른 원소들의 번호
//// toPick : 더 고를 원소의 수
//void pick(int n, vector<int>& picked, int toPick)
//{
//	//기저 사례: 더 고를 원소가 없을 때 고른 원소들을 출력한다.
//	if (toPick == 0) { printPicked(picked); return; }
//	//고를 수 있는 가장 작은 번호.
//	int smallest = picked.empty() ? 0 : picked.back() + 1;
//
//	//여기서 원소 하나를 고름.
//	for (int next = 0; next < n; next++)
//	{
//		picked.push_back(next);
//		pick(n, picked, toPick - 1);
//		picked.pop_back();
//	}
//
//}