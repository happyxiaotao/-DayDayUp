/*
题目描述：
链表翻转。给出一个链表和一个数k。
比如链表1→2→3→4→5→6，
k=2，翻转后2→1→4→3→6→5，
若k=3,翻转后3→2→1→6→5→4，
若k=4，翻转后4→3→2→1→5→6，
用程序实现Node* RotateList(Node* list, size_t k).
提示：这个题是链表逆置的升级变型
*/

#include <iostream>
using namespace std;

typedef int DataType;
typedef struct ListNode
{
	ListNode(DataType data = DataType())
		: m_data(data)
		, m_pNext(nullptr)
	{}
	DataType m_data;
	ListNode *m_pNext;
}Node;


/*
由题目要求可知：
k=0或1时，相当于没有修改链表，可以直接返回。
k>1时，需要断开并重新连接k-1条链，另外还需一条链来连接前k个节点与后面节点

主要还是分为
1，链表我空或只有一个节点。
2，链表有2个以上节点。

对于k的要求，只需在链表逆置的基础上添加限制即可。
*/
Node* RotateList(Node* list, size_t k)
{
	//注：当k大于等于链表节点个数时，看做是把链表全翻转

	//当链表为空，或只有一个节点,或k为0或1
	if (nullptr == list || nullptr == list->m_pNext || 0 == k || 1 == k) 
		return list;

	//处理节点个数大于等于2，并且k>1 的情况
	//通过三个指针来翻转链表
	Node *pPre = list;
	Node *pCur = pPre->m_pNext;
	Node *pTail = pCur->m_pNext;

	//将链表遍历一次，或者循环k-1次
	while (pCur && k>1)
	{
		pCur->m_pNext = pPre;

		pPre = pCur;
		pCur = pTail;

		//当pTail为NULL，pCur=NULL,表示最后一个节点已经翻转过了，下次循环跳出。
		if (pTail)	
			pTail = pTail->m_pNext;

		--k;  //翻转了一个节点
	}
	
	//当pTail不为nullptr时，此时k=1，表示函数传入的k值小于节点个数，此时pTail指向第k+1个节点。
	//当pTail为nullptr时，此时k>=1，表示链表节点个数小于等于k，当做全翻转处理
	//所以，不管pTail为不为NULL，list->m_pNext都要指向pCur来连接两部分。
	list->m_pNext = pCur;

	//此时pCur指向新的头结点
	return pPre; 
}

//打印单链表
void PrintList(Node *pHead)
{
	while (pHead)
	{
		printf("%d->", pHead->m_data);
		pHead = pHead->m_pNext;
	}

	printf("NULL\n");
}

int main()
{
	int i = 0;
	Node node[10] = { 0 }; //建立10个node用来做实验
	Node *pHead = &node[0]; //指向头结点

	//给node赋值
	for (; i < 10; ++i)
		node[i].m_data = i+1;
	//构成一个单链表
	for (i = 0; i < 9; ++i)
		node[i].m_pNext = &node[i + 1];
	node[9].m_pNext = NULL; //注意，最后一个节点指向NULL

	cout << "翻转前：";
	PrintList(pHead);   //打印旧的单链表

	//翻转前k个节点
	int k = 3;
	pHead = RotateList(pHead, k);

	cout << "翻转前：";
	PrintList(pHead); //打印新的单链表

	system("pause");
	return 0;
}