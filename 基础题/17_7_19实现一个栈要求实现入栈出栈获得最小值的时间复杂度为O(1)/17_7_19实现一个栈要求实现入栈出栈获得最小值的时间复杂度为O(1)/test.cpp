#include <iostream>


template <typename T>
class Stack
{
	typedef struct Node
	{
		Node(const T& data = T())
			: _data(data)
			, _pNext(NULL)
		{}
		T _data;
		T* _pNext;
	}Node;
public:
	Stack()
		: _pStart(NULL)
		, _pEnd(NULL)
		, _pMin(NULL)
	{}

public:
	void Push(const T& data)
	{
		Node *pTemp = new Node(data);

		if (NULL == _pStart) //栈本来为空时
		{
			_pStart = pTemp;
			_pEnd = pTemp;
			_pMin = pTemp;

			return;
		}

		//栈不为空时
		_pEnd->_pNext = pTemp;
		_pEnd = pTemp;
		
		if (pTemp->_data < _pMin->_data)
		{
			_pMin = pTemp;
		}
	}

	void Pop()
	{

	}

	T& Get_Min()
	{
		return T();
	}

private:
	Node* _pStart;  //指向链表头结点
	Node* _pEnd;   //指向链表尾节点
	Node* _pMin;   //指向链表值最小的节点
};

int main()
{
	int a = int();
	int &ra = a;

	printf("%d\n", ra);
	system("pause");
	return 0;
}