/*
【基础题】--逆置 / 反转单链表 + 查找单链表的倒数第k个节点，要求只能遍历一次链表
*/


/*
注：本次代码处理的是不带环的单链表
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
	int _val;
	struct ListNode* _pNext;
}Node, *PNode;

/*
逆置 / 反转单链表:
思路：可以利用三个指针来标记三个连续节点。
1，将头结点的指针置为NUL
2，将头结点后面的节点在循环中改变指向：
	第一个指针不变，逆置中间指针的指向，保留第三个指针的指向，作为往后遍历链表的路径。
	这样遍历链表，每次逆置中间节点的指向，通过第三个节点往后遍历，将三个节点指针整体往后移一个节点。
	最终改变整个链表。
通过以上思路，将链表分为三种情况：
1，链表为空。
2，链表只含有1个节点。
3，链表有2个及以上节点。
*/
PNode ReverseList(PNode pHead)
{ 
	PNode pPre = NULL;	//第一个指针，指向连续节点中的第一个节点，最终成为新的头结点指针。
	PNode pCur = NULL;  //第二个指针，指向连续节点中的第二个节点，修改_pNext指向的指针。
	PNode pTail = NULL; //第三个指针，指向连续节点中的第三个节点，保持与单链表连接的指针。

	//链表为空的情况
	if (NULL == pHead)
		return NULL;

	//链表只有一个节点的情况
	if (NULL == pHead->_pNext)
		return pHead;

	//链表有2个及以上节点的情况

	pPre = pHead;
	pCur = pPre->_pNext;
	pTail = pCur->_pNext;

	//处理pHead的_pNext指向
	pHead->_pNext = NULL;

	//处理头结点之后的节点_pNext指向
	while (pCur)
	{
		pCur->_pNext = pPre;
		pPre = pCur;
		pCur = pTail;

		if (pTail) //当该条件不成立时，表示pTail为NULL，下一次循环中pCur也NULL，将会跳出循环。
			pTail = pTail->_pNext;
	}

	//此时pPre指向的是新的头结点
	return pPre;
}

/*
查找单链表的倒数第k个节点，要求只能遍历一次链表:

思路：通过两个指针，一个前指针，一个后指针。
1，两个指针，初始都是指向单链表的头结点。
2，前指针先走K步。然后和后指针一起往后走。
3，直到前指针指向NULL。

注意，根据K的大小与单链表中元素个数的比较。可以分为:
1,K的值大于单链表中元素个数。
2，K的值小于等于单链表中元素个数。
但是，链表中元素个数，必须通过遍历之后，才能知晓。
所以，可以在前指针往后走K步的过程中（即K-1步及之前），也判断前指针是否为NULL。
如果前指针为NULL，表示单链表元素个数小于K。否则大于等于K。
*/
PNode Find_the_penultimate_K_node(PNode pHead, size_t k)
{
	//使用左、右来标识前、后指针。pHead是否为NULL，不影响程序逻辑。
	PNode pLeft = pHead;
	PNode pRigth = pHead;

	if (0 == k)
		return NULL;

	//前指针先往后走K步
	while (k && pLeft)
	{
		pLeft = pLeft->_pNext;
		--k;
	}

	if (k) //表示元素个数小于K
		return NULL;

	//走到这一步，说明单链表元素个数大于等于K，然后，前后指针开始一起往后走。直到前指针为NULL
	while (pLeft)
	{
		pLeft = pLeft->_pNext;
		pRigth = pRigth->_pNext;
	}

	//返回倒数第K个节点指针。
	return pRigth;
}

//打印单链表
void PrintList(PNode pHead)
{
	while (pHead)
	{
		printf("%d->", pHead->_val);
		pHead = pHead->_pNext;
	}

	printf("NULL\n");
}

int main()
{
	int i = 0;
	Node node[10] = {0}; //建立10个node用来做实验
	PNode pHead = &node[0]; //指向头结点
	PNode pTemp = NULL; //指向倒数第K个节点
	int k = 0;

	//给node赋值
	for (; i < 10; ++i)
		node[i]._val = i;
	//构成一个单链表
	for (i = 0; i < 9; ++i)
		node[i]._pNext = &node[i + 1];
	node[9]._pNext = NULL; //注意，最后一个节点指向NULL

	PrintList(pHead);	//打印旧的单链表

	pTemp = Find_the_penultimate_K_node(pHead, 5); //寻找倒数第K个节点
	printf("Find the penultimate K node is %d\n", pTemp->_val);

	pHead = ReverseList(pHead); //逆置单链表
	PrintList(pHead); //打印新的单链表

	system("pause");
	return 0;
}