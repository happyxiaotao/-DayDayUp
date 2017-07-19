/*
1.【基础题】--1.删除一个无头单链表的非尾节点 2.从尾到头打印单链表

ps:今天的基础题比较简单，所以上了两道小凉菜。

2.【附加题】--复杂链表的复制。一个链表的每个节点，有一个指向next指针指向下一个节点，还有一个random指针指向这个链表中的一个随机节点或者NULL，现在要求实现复制这个链表，返回复制后的新链表。

ps: 复杂链表的结构

typedef struct ComplexNode{

DataType _data ; // 数据

struct ComplexNode * _next; // 指向下一个节点的指针

struct ComplexNode * _random; // 指向随机节点（可以是链表中的任意节点 or 空）

}ComplexNode;
*/

#include <iostream>
#include <cassert>
#include <stack>
typedef int DataType;
typedef struct ListNode
{
	DataType _val;
	ListNode* _pNext;
}Node, *PNode;


/*1.删除一个无头单链表的非尾节点
思路：
这道题目，删除节点容易，但是难就难在如何连接删除之后分成两部分的链表。
本人思考除了两种节解法。
1，如果用三个指针的话，一个指向删除节点的前驱，一个指向删除节点，一个指向删除节点的后继。
2，第二种办法，删除节点将它的后继节点的值拷贝到自己，然后删除后继节点。效果是一样的。
*/
//这里采用第二种方法
void Delete_Not_Tail_Node(PNode pos) //参数表示的是本该删除的那个非尾节点
{
	assert(NULL != pos); //既然删除某个节点，就不能为NULL

	if (NULL == pos->_pNext) //pos是尾节点
		return; 

	PNode pDelete = pos->_pNext; //将要删除的后继节点
	pos->_val = pDelete->_val; //取得数据
	pos->_pNext = pDelete->_pNext; //跳过后继节点，指向后继的后继

	delete pDelete;
	pDelete = NULL;
}

/*
2.从尾到头打印单链表
思路：
1，利用递归的特性，从后往前返回遍历的内容。
2，利用栈存储每次遍历的值，然后出栈。
*/

//利用栈实现
void Print_Lis_From_Tal_To_Head_1(PNode pHead)
{
	std::stack<PNode> s;

	while (pHead)
	{
		s.push(pHead);
		pHead = pHead->_pNext;
	}

	while (!s.empty())
	{
		PNode pTemp = s.top();
		std::cout << pTemp->_val << " ";
		s.pop();
	}
}

//这里采用递归实现
void Print_List_From_Tail_To_Head_2(PNode pHead)
{
	if (NULL == pHead)
		return;

	Print_List_From_Tail_To_Head_2(pHead->_pNext);

	std::cout << pHead->_val << " ";
}


int main()
{
	int i = 0;
;	
	//建立10个Node用来做实验
	PNode pHead = new Node; //指向头节点
	pHead->_val = 0;
	pHead->_pNext = NULL;
	PNode pCur = pHead;
	//构成链表
	for (int i = 1; i < 10; ++i)
	{
		Node* pTemp = new Node;
		pTemp->_val = i;
		pTemp->_pNext  = NULL;
		pCur->_pNext = pTemp;
		pCur = pCur->_pNext;
	}

	//Delete_Not_Tail_Node(pHead->_pNext);
	Print_Lis_From_Tal_To_Head_1(pHead);
	//Print_Lis_From_Tal_To_Head_2(pHead);
	std::cout<<std::endl;
	
	system("pause");
	return 0;
}