//#include <bits/stdc++.h>
//using namespace std;
//
//void printPicked(vector<int> pick);
// 
//
//// n : ��ü ������ ��
//// picked : ���ݱ��� �� ���ҵ��� ��ȣ
//// toPick : �� �� ������ ��
//void pick(int n, vector<int>& picked, int toPick)
//{
//	//���� ���: �� �� ���Ұ� ���� �� �� ���ҵ��� ����Ѵ�.
//	if (toPick == 0) { printPicked(picked); return; }
//	//�� �� �ִ� ���� ���� ��ȣ.
//	int smallest = picked.empty() ? 0 : picked.back() + 1;
//
//	//���⼭ ���� �ϳ��� ��.
//	for (int next = 0; next < n; next++)
//	{
//		picked.push_back(next);
//		pick(n, picked, toPick - 1);
//		picked.pop_back();
//	}
//
//}