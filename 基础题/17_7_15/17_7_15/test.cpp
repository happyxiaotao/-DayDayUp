/*
1.【基础题】--判断链表是否带环？若带环求环的长度？若带环求环的入口点？并计算以上每个问题的时间复杂度？

2.【附加题】--1.设计一个类不能被继承 2.设计一个类只能在堆上创建对象。 3.设计一个类只能在栈上创建对象。

ps：以上三个问题是类似的。
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
	int _val;
	struct ListNode *_pNext;
}Node, *PNode;


/*
判断链表是否带环。

思路：定义两个指针：快指针与满指针
快指针fast，每次走走两步。
慢指针slow，每次走一步。
如果链表有环，则，快慢指针终有碰撞重合的机会。
如果没环，则快指针，终会指向NULL。

注意：返回碰撞点。

时间复杂度：O()
*/
PNode Is_Has_Ring(PNode pHead)
{
	//此时，pHead是否为空，都在逻辑判断之内处理
	PNode pFast = pHead;
	PNode pSlot = pHead;

	while (pFast && pFast->_pNext)
	{
		pFast = pFast->_pNext->_pNext;
		pSlot = pSlot->_pNext;

		if (pFast == pSlot) //两个节点相等时退出
			break;
	}

	if ((NULL == pFast) || (NULL == pFast->_pNext))
		return NULL;

	return pFast;
}

/*
求单链表中环的长度
思路：首先获取碰撞点的位置。然后，快慢指针再次走，直到再次重合时慢指针所走的步长即使环长度。
*/
int Get_Length_Of_Ring(PNode pHead)
{
	PNode pFast = Is_Has_Ring(pHead);
	PNode pSlot = pFast;
	int length = 0;

	if (NULL == pFast) //链表不带环
		return 0;

	//快慢指针再次相遇时，慢指针的步长，表示环的长度。
	do
	{
		pFast = pFast->_pNext->_pNext;
		pSlot = pSlot->_pNext;
		++length;
	} while (pFast != pSlot);

	return length;
}


/*
求单链表中环的入口点
思路：根据推到出来的公式：
快慢指针碰撞点到入口的步长等于头节点到入口的步长。
此时，两者走的步长一样，且就在在入口点。

时间复杂度：O()
*/
PNode Get_Entrance_Of_Ring(PNode pHead)
{
	PNode pColl = Is_Has_Ring(pHead); //获取碰撞点

	if (NULL == pColl) //链表不带环
		return NULL;

	while (pColl != pHead)
	{
		pColl = pColl->_pNext;
		pHead = pHead->_pNext;
	}

	return pColl;
}

int main()
{
	int i = 0;
	Node node[10] = { 0 }; //建立10个node用来做实验
	PNode pHead = &node[0]; //指向头结点
	PNode pTemp = NULL; //指向倒数第K个节点
	int k = 0;

	//给node赋值
	for (; i < 10; ++i)
		node[i]._val = i;
	//构成一个单链表
	for (i = 0; i < 9; ++i)
		node[i]._pNext = &node[i + 1];
	node[9]._pNext = &node[6]; //注意，通过node[9]._pNext指向链表中元素来构成环

	if (Is_Has_Ring(pHead))
	{
		printf("Has ring!!!\n");

		printf("The length of ring is %d\n", Get_Length_Of_Ring(pHead));

		printf("The entrance is node[%d]\n", Get_Entrance_Of_Ring(pHead)->_val);
	}
	else
	{
		printf("Not has ring!!!\n");
	}


	system("pause");
	return 0;
}