/*
【附加题】--复杂链表的复制。一个链表的每个节点，有一个指向next指针指向下一个节点，还有一个random指针指向这个链表中的一个随机节点或者NULL，现在要求实现复制这个链表，返回复制后的新链表。

ps : 复杂链表的结构

	typedef struct ComplexNode {

	DataType _data; // 数据 

	struct ComplexNode * _next; // 指向下一个节点的指针 

	struct ComplexNode * _random; // 指向随机节点（可以是链表中的任意节点 or 空） 

}ComplexNode;

*/

#include <iostream>

typedef int DataType;
typedef struct ComplexNode 
{
	DataType _data; // 数据 
	struct ComplexNode * _next; // 指向下一个节点的指针 
	struct ComplexNode * _random; // 指向随机节点（可以是链表中的任意节点 or 空） 
}ComplexNode;

/*
思路：
有两种解决办法：
第一种：
1，遍历一次链表，构建一条新链表，只复制_data以及_next。
2，再次遍历原来链表，获取每次遍历节点的_random，在一次循环中，再次遍历链表。获取_random指向的位置到头结点的长度。在新链表中，也指向相对位置。
时间复杂度：O(n^2)

第二种：
1，遍历原来的链表，每次循环中，在旧节点后面插入一个新节点。添加的新节点的_data是它前驱节点的_data。
2，第二次遍历构建完成后的新链表，将新节点的_random指向属于旧节点的_random指向节点的_next.
3，根据，奇偶，分离旧链表和新链表。
时间复杂度：O(n)


需要注意的情况：
1，复杂链表为NULL
2，复杂链表只有一个节点
3，复杂链表有一个以上节点
*/

ComplexNode* Copy(ComplexNode* pHead)
{
	if (NULL == pHead)  //链表为NULL
		return NULL;

	ComplexNode* pNewHead = NULL; //复制所得链表的头结点

	if (NULL == pHead->_next)  //链表只要一个节点
	{
		pNewHead = new ComplexNode;
		pNewHead->_data = pHead->_data;
		pNewHead->_next = NULL;
		pNewHead->_random = pHead->_random;
		return pNewHead;
	}

	//1，添加节点，给新节点的_data,_next赋值
	ComplexNode* pCur = pHead;
	while (pCur)
	{
		ComplexNode* pTemp = new ComplexNode;
		pTemp->_data = pCur->_data;
		pTemp->_next = pCur->_next;
		pTemp->_random = NULL;  //暂时不复制

		pCur->_next = pTemp;

		pCur = pTemp->_next;
	}

	//2，给新节点的_random赋值
	pCur = pHead;
	while (pCur)
	{
		//指向随机指向的节点的后一个节点（新开辟的节点）。
		if (pCur->_random)
			pCur->_next->_random = pCur->_random->_next;
		else
			pCur->_next->_random = NULL;

		pCur = pCur->_next->_next; //每次走两步
	}

	//3，分离添加节点后的链表
	pNewHead = pHead->_next;
	pCur = pHead;   //指向链表中的奇数位置
	ComplexNode* pCur_2 = pNewHead; //指向链表中的偶数位置
	while (pCur)
	{
		pCur->_next = pCur_2->_next;
		pCur = pCur->_next;

		if (pCur)
		{
			pCur_2->_next = pCur->_next;
			pCur_2 = pCur_2->_next;
		}
	}
	pCur_2->_next = NULL; //注意，最后一个节点的next还是指向旧节点。

	return pNewHead;
}

void Print(ComplexNode* pHead)
{
	while (pHead)
	{
		std::cout << pHead->_data << "->";
		pHead = pHead->_next;
	}
	std::cout << "NULL" << std::endl;
}

int main()
{
	ComplexNode* p = new ComplexNode[10];

	for (int i = 0; i < 9; ++i)
	{
		p[i]._data = i;
		p[i]._next = &p[i + 1];
		p[i]._random = NULL;
	}
	p[9]._data = 9;
	p[9]._next = NULL;
	p[9]._random = NULL;

	p[1]._random = &p[1];
	p[2]._random = &p[3];
	p[5]._random = &p[2];
	p[7]._random = &p[9];

	Print(p);

	ComplexNode* pNewHead = Copy(p);

	//在调试窗口，可以查看pNewHead中节点的_random是否符合

	Print(pNewHead);

	system("pause");
	return 0;
}