#include <bits/stdc++.h>

using namespace std;
//TODO ::
// front와 동일한 방식으로 fianl node 정의하기. front와 final의 위치는 바뀌지 않음.
template <class T>
class Node
{
public:
	Node<T>* prev;
	Node<T>* next;
	T data;
};

template <class T>
class Deque_BASE
{
public:
	Node<T>* Base_Node; //front - 1
	Node<T>* Final_Node;
	int size;

	Node<T>* MakeNode(T _in)
	{
		Node<T>* node = new Node<T>;
		node->prev = nullptr;
		node->next = nullptr;
		node->data = _in;
		return node;
	}

	void InterConnect(Node<T>* a1, Node<T>* a2)
	{
		a1->next = a2;
		a2->prev = a1;
	}

	void DisConnect(Node<T>* a1, Node<T>* a2)
	{
		a1->next = nullptr;
		a2->prev = nullptr;
	}

public:
	Deque_BASE()
	{
		Base_Node = MakeNode(0);
		Final_Node = MakeNode(0);
		Base_Node->next = Final_Node;
		Final_Node->prev = Base_Node;
		size = 0;
	}

	void push_front(T _in)
	{
		Node<T>* newNode = MakeNode(_in);
		if (empty())
		{
			InterConnect(Base_Node, newNode);
			InterConnect(newNode, Final_Node);
		}
		else
		{
			InterConnect(newNode, Base_Node->next);
			InterConnect(Base_Node, newNode);
		}

		size++;
	}

	void push_back(T _in)
	{
		Node<T>* newNode = MakeNode(_in);
		if (empty())
		{
			InterConnect(newNode, Final_Node);
			InterConnect(Base_Node, newNode);
		}
		else
		{
			InterConnect(Final_Node->prev, newNode);
			InterConnect(newNode, Final_Node);
		}

		size++;
	}

	bool pop_front()
	{
		if (empty())
		{
			return false;
		}
		else
		{
			size--;
			if (!empty())
			{
				Node<T>* resNode = Base_Node->next;
				Node<T>* newFirst = Base_Node->next->next;
				DisConnect(Base_Node->next, Base_Node->next->next);
				DisConnect(Base_Node, Base_Node->next);
				//T res = *resNode->data;
				delete[] resNode;
				InterConnect(Base_Node, newFirst);
			}
			else
			{
				Node<T>* resNode = Base_Node->next;
				InterConnect(Base_Node, Final_Node);
				delete[] resNode;
			}
			return true;
		}
	}

	bool pop_back()
	{
		if (empty())
		{
			return false;
		}
		else
		{
			size--;
			if (!empty())
			{
				Node<T>* resNode = Final_Node->prev;
				Node<T>* newFinal = Final_Node->prev->prev;
				DisConnect(Final_Node->prev->prev, Final_Node->prev);
				DisConnect(Final_Node->prev, Final_Node);
				delete[] resNode;
				InterConnect(newFinal, Final_Node);
			}
			else
			{
				Node<T>* resNode = Final_Node->prev;
				InterConnect(Base_Node, Final_Node);
				delete[] resNode;
			}

			return true;
		}
	}

	int Size()
	{
		return size;
	}

	bool empty()
	{
		if (!size)
			return true;
		return false;
	}

	T front();

	T back();

};


template <class T>
class Deque : public Deque_BASE<T>
{
};

template <>
class Deque<int> : public Deque_BASE<int>
{
public:
	int front()
	{
		if (empty())
		{
			return -1;
		}
		else
		{
			return this->Base_Node->next->data;
		}
	}
	int back()
	{
		if (empty())
		{
			return -1;
		}
		else
		{
			return this->Final_Node->prev->data;
		}
	}
};

void initstr(char* str)
{
	for (size_t i = 0; i < 20; i++)
	{
		str[i] = 0;
	}
}

int main() {
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	//\n faster than endl. endl makes buffer flush explicitly.

	int n;
	cin >> n;
	char operation[20];
	int input;
	Deque<int> deque;
	for (size_t i = 0; i < n; i++)
	{
		initstr(operation);
		cin >> operation;
		//
		if (operation[5] == 'f')
		{
			cin >> input;
			deque.push_front(input);
			//push_front
		}
		else if (operation[5] == 'b')
		{
			cin >> input;
			deque.push_back(input);
			//push_back;
		}
		else if (operation[4] == 'f')
		{
			cout << deque.front() << ' ';
			if (!deque.empty())
			{
				deque.pop_front();
			}
			//pop_front;
		}
		else if (operation[4] == 'b')
		{
			cout << deque.back() << ' ';
			if (!deque.empty())
			{
				deque.pop_back();
			}
			//pop_back;
		}
		else if (operation[0] == 's')
		{
			cout << deque.Size() << ' ';
			//size;
		}
		else if (operation[0] == 'e')
		{
			cout << deque.empty() << ' ';
			//empty
		}
		else if (operation[0] == 'f')
		{
			cout << deque.front() << ' ';
			//front
		}
		else if (operation[0] == 'b')
		{
			cout << deque.back() << ' ';
			//back
		}
	}

	return 0;
}