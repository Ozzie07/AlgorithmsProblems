#include <bits/stdc++.h>

using namespace std;

class Tree
{
	struct Node
	{
		char code;

		Node* Lchild;
		Node* Rchild;
	};

	Node* root;
	Node Nodes[26];
private:

	Node& MakeNode(char _code)
	{
		Node* node = new Node;
		node->Rchild = nullptr;
		node->Lchild = nullptr;
		node->code = _code;
		return *node;
	}

	void PrintValue(Node& _node)
	{
		cout << _node.code;
		// This Part Shows Children of the node.
		//cout << _node.code << endl;
		//if(_node.Lchild!=nullptr)
		//	cout << "LChild(" << _node.Lchild->code << ')' << endl;
		//if (_node.Rchild != nullptr)
		//	cout << "RChild(" << _node.Rchild->code << ')' << endl;
	}

	void PreorderTraverse(Node *_node)
	{
		//return contition needed.
		if (_node == nullptr)
			return;
		PrintValue(*_node);
		PreorderTraverse(_node->Lchild);
		PreorderTraverse(_node->Rchild);
	}

	void InorderTraverse(Node *_node)
	{
		if (_node == nullptr)
			return;
		InorderTraverse(_node->Lchild);
		PrintValue(*_node);
		InorderTraverse(_node->Rchild);
	}

	void PostorderTraverse(Node *_node)
	{
		if (_node == nullptr)
			return;
		PostorderTraverse(_node->Lchild);
		PostorderTraverse(_node->Rchild);
		PrintValue(*_node);
	}

public:

	Tree() //MakerootNode
	{
		vector<tuple<char, char, char>> inputs;
		int n;
		cin >> n;
		for (size_t i = 0; i < n; i++)
		{
			char p, c1, c2;
			cin >> p >> c1 >> c2;
			inputs.push_back(tie(p, c1, c2));
		}

		//RegisterNode
		for (size_t i = 0; i < n; i++)
			Nodes[get<0>(inputs[i]) - 65] = MakeNode(get<0>(inputs[i]));
		root = &Nodes[0];

		//RegisterLChild, RChild
		for (size_t i = 0; i < n; i++)
		{
			int currentNode = (int)get<0>(inputs[i]) - 65;
			int LChildidx = (int)get<1>(inputs[i]) - 65;
			int RChildidx = (int)get<2>(inputs[i]) - 65;
			if(LChildidx >= 0)
				Nodes[currentNode].Lchild = &Nodes[LChildidx];
			if(RChildidx >= 0)
				Nodes[currentNode].Rchild = &Nodes[RChildidx];
		}
	}

	void PreorderTraverse_fromRoot()
	{
		PreorderTraverse(root);
		cout << '\n';
	}

	void InorderTraverse_fromRoot()
	{
		InorderTraverse(root);
		cout << '\n';
	}

	void PostorderTraverse_fromRoot()
	{
		PostorderTraverse(root);
		cout << '\n';
	}
};

int main() {
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	//\n faster than endl. endl makes buffer flush explicitly.
	Tree tree;

	tree.PreorderTraverse_fromRoot();
	tree.InorderTraverse_fromRoot();
	tree.PostorderTraverse_fromRoot();
	return 0;
}