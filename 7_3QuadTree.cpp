//#include <bits/stdc++.h>
//using namespace std;
//
//struct QuadTree
//{
//	char value;
//
//	QuadTree* Node1;
//	QuadTree* Node2;
//	QuadTree* Node3;
//	QuadTree* Node4;
//};
//
//void MakeQuadTree(string input, QuadTree* root, int cursor)
//{
//	if (cursor == input.size())
//		return;
//
//	switch (input[cursor])
//	{
//	case 'x':
//	{
//		root->value = 'x';
//
//		root->Node1 = new QuadTree();
//		MakeQuadTree(input, root->Node1, cursor++);
//
//		root->Node2 = new QuadTree();
//		MakeQuadTree(input, root->Node2, cursor++);
//
//		root->Node3 = new QuadTree();
//		MakeQuadTree(input, root->Node3, cursor++);
//
//		root->Node4 = new QuadTree();
//		MakeQuadTree(input, root->Node4, cursor++);
//
//		break;
//	}
//	case 'w':
//	{
//		root->value = 'w';
//		break;
//	}
//	case 'b':
//	{
//		root->value = 'b';
//		break;
//	}
//	default:
//		break;
//	}
//}
//
//
//class Solution
//{
//#define NUM_OF_BARS 1024
//
//	char decompressed[NUM_OF_BARS][NUM_OF_BARS];
//	QuadTree* root;
//	string input;
//
//	void GetInput()
//	{
//		//root = new QuadTree();
//		getline(cin, input);
//		//MakeQuadTree(input, root, 0);
//	}
//	
//	//string Reverse(int cursor)
//	//{
//	//	if (cursor == input.size())
//	//		return "\0";
//	//	string output;
//	//	if (input[cursor] == 'x')
//	//	{
//	//		//���� 4 �༮�� Ž��.
//	//		//4 �༮�� Ž�� �ϴٰ� x�� �� �����ϸ� �� �ڸ����� �� Ž��.
//
//	//		output.push_back(input[cursor]);
//	//		string temp[4];
//	//		for (size_t i = 0; i < 4; i++)
//	//		{
//	//			temp[i] = Reverse(cursor + i + 1);
//	//		}
//
//	//		output.append(temp[2]);
//	//		output.append(temp[3]);
//	//		output.append(temp[0]);
//	//		output.append(temp[1]);
//
//	//		return output;
//	//	}
//	//	else
//	//	{
//	//		output.push_back(input[cursor]);
//	//		return output;
//	//	}
//	//}
//
//	int cursor = 0;
//	string Reverse()
//	{
//		string res;
//		if (input[cursor] != 'x')
//		{
//			char temp = input[cursor];
//			res.push_back(temp);
//			return res;
//		}
//
//		//x��� 4���� ã�Ƽ� ������� ��. �� ���������.
//		string temp[4];
//		int offset = 0;
//
//		for (size_t i = 0; i < 4; i++)
//		{
//			cursor++; //���� �ش� �κ��� �о���. ��� ���� ���� ������ �ѱ�� ���� �߿��ߴ�. �׷��� Ŭ���� ���� ������ �ξ���.
//			temp[i] = Reverse();
//		}
//
//		res.push_back('x');
//		res.append(temp[2]);
//		res.append(temp[3]);
//		res.append(temp[0]);
//		res.append(temp[1]);
//
//		return res;
//	}
//public:
//	void Invoke()
//	{
//		GetInput();
//		cout << Reverse() << '\n';
//	}
//};
//
//int main() {
//	//	freopen("input.txt", "r", stdin);
//	//	freopen("output.txt", "w", stdout);
//
//	//ios::sync_with_stdio(0);
//	//cin.tie(0);
//	//\n faster than endl. endl makes buffer flush explicitly.
//	int tc;
//	cin >> tc;
//	char whiteSpace;
//	whiteSpace = getchar();
//
//	for (size_t i = 0; i < tc; i++)
//	{
//		Solution sol;
//		sol.Invoke();
//	}
//
//	return 0;
//}