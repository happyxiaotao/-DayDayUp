/*
【基础题】
1.判断两个链表是否相交，若相交，求交点。（假设链表不带环）
2.判断两个链表是否相交，若相交，求交点。（假设链表可能带环）【升级版】
*/

#include <iostream> //采用C++编译环境。

typedef struct ListNode
{
	int _val;
	ListNode* _pNext;
}Node, *PNode;


//获取环中节点中快慢指针的碰撞点。
PNode Get_Impact_Point(PNode pHead);
//获取带环链表中环的入口点
PNode Get_Entrance_Point(PNode pHead);
//判断两个链表是否相交，若相交，求交点。（假设链表不带环）
PNode Is_Has_Intersection(PNode pHead_1, PNode pHead_2);
//判断两个链表是否相交，若相交，求交点。（假设链表可能带环）【升级版】
PNode Is_Has_Intersection_2(PNode pHead_1, PNode pHead_2);


/*
1.判断两个链表是否相交，若相交，求交点。（假设链表不带环）

思路：
三种状态：
1，判断是否有空链表
2，判断两个链表是否是同一个链表
3，不是用一个链表的情况（存在pHead_1可能是pHead_2的一部分的情况）

针对状态三：
不带环的两个链表相交，表示从交节点开始，两个链表中的节点一直相同。
那么两个链表的最后一个节点也相同。可以当做一个判断条件。
如果两个不带环链表相交，则将其中一个链表的头尾节点相连，构成一个带环的单链表。
这样问题就变为了，求带环单链表的环的入口点。
*/
PNode Is_Has_Intersection(PNode pHead_1, PNode pHead_2)
{
	if ((NULL == pHead_1) || (NULL == pHead_2)) //当有空链表时，没有交点。
		return NULL;

	if (pHead_1 == pHead_2) //如果两个链表是通过一个链表的情况。
		return pHead_1;

	PNode pTail_1 = pHead_1;  //用来指向pHead_1的尾节点
	PNode pTail_2 = pHead_2;  //用来指向pHead_2的尾节点

	while (pTail_1->_pNext)   
		pTail_1 = pTail_1->_pNext;  
	while (pTail_2->_pNext)
		pTail_2 = pTail_2->_pNext;

	if (pTail_1 != pTail_2)  //两个链表最后一个节点不相等，说明没有相交。
		return NULL;  

	//走到这里，说明pTail_1 = pTail_2。两个链表相交，下面开始求交点。
	//将其中一个链表的头结点与尾节点相连。最终两个链表会构成一带环单链表
	//问题变为求带环单链表的环的入口了。

	//1，将两个单链表变为带环单链表(pHead_2为新的头指针)
	pTail_1->_pNext = pHead_1;
	//2，求环的入口。（调用写的函数）
	PNode pCross = Get_Entrance_Point(pHead_2);

	return pCross;
}

//获取环中节点中快慢指针的碰撞点。
PNode Get_Impact_Point(PNode pHead)
{
	if (NULL == pHead)
		return NULL;

	PNode pFast = pHead;
	PNode pSlow = pHead;
	
	while ((NULL != pFast) && (NULL != pFast->_pNext))
	{
		pFast = pFast->_pNext->_pNext;
		pSlow = pSlow->_pNext;

		if (pFast == pSlow)
			break;
	}

	if ((NULL == pFast) || (NULL == pFast->_pNext)) //不可使用pFast!=pSlow作为判断条件，当链表只有一个元素时，会出错。
		return NULL;
	
	return pFast;
}


//获取带环链表中环的入口点
//有一点需要注意，如果单链表，本身就是一个环，那么返回的节点就会是头结点
PNode Get_Entrance_Point(PNode pHead)
{
	PNode pImpact = Get_Impact_Point(pHead);
	if (NULL == pImpact) //链表中不存在环
		return NULL; 

	//头结点到入口点的长度设为：X
	//环的长度设为R
	//碰撞点到入口的长度设为：R1
	//通过计算（前一篇博文中写有），可以推到出存在某一个n（n为非负整数），使得：X = nR + R1.
	//所以，头结点和碰撞点同时出发， 最终会在入口点相遇。
	while (pImpact != pHead)
	{
		pImpact = pImpact->_pNext;
		pHead = pHead->_pNext;
	}
	//此时，两者都在入口点处，返回入口点位置。
	return pImpact; 
}


//2.判断两个链表是否相交，若相交，求交点。（假设链表可能带环）【升级版】
/*
思路:
先判断两个链表是否是同一个链表的情况。
1，相同，直接返回头结点。
2，不相同，在往下走。
再判断两个链表是否带环。
1，都不带环--->判断两个不带环单链表是否相交，若相交，求交点。
2，一个带环，一个不带环---->不想交
3，两个链表都带环---->若相交，环是公有的，则判断链表1的碰撞点是否在链表2的环中。
*/
//将函数改写为下
PNode Is_Has_Intersection_2(PNode pHead_1, PNode pHead_2)
{
	//存在空链表，不存在交点
	if ((NULL == pHead_1) || (NULL == pHead_2))
		return NULL;

	//如果两个链表是同一个链表，则直接返回头结点。
	if (pHead_1 == pHead_2)
		return pHead_1;

	PNode pCross = NULL; //交点

	//获取链表快慢指针的碰撞点，如果存在，则说明链表有环
	PNode pImpact_1 = Get_Impact_Point(pHead_1);
	PNode pImpact_2 = Get_Impact_Point(pHead_2);

	//都不带环--->判断两个不带环单链表是否相交，若相交，求交点。
	if ((NULL == pImpact_1) && (NULL == pImpact_2))
	{
		pCross = Is_Has_Intersection(pHead_1, pHead_2);
		return pCross;
	}

	//一个带环，一个不带环---->不想交
	if (pImpact_1 || pImpact_2) 
		return NULL;

	//两个链表都带环---->若相交，环是公有的，则判断链表1的碰撞点是否在链表2的环中
	
	PNode pCur = pImpact_2;   //作为遍历pHead_2的指针 
	//需要注意的是，在遍历pHead_2时，如果pHead_1的碰撞点不在pHead_2的环中，会死循环
	//所以，需要从pHead_2的碰撞点，开始遍历，直到再次遇到碰撞点。
	while (pCur != pImpact_1)
	{
		pCur = pCur->_pNext;
		if (pCur == pImpact_2) //防止死循环
			break;
	}
	//pHead_1的碰撞点pImpact_1在pHead_2的环中，即相交
	if (pCur == pImpact_1)
		pCross = Get_Entrance_Point(pHead_1);

	return pCross;
}



int main()
{
	std::cout << "链表不带环的情况" << std::endl;
	for (int indx = 0; indx < 10; ++indx)
	{
		int i = 0;
		Node node[10] = { 0 }; //建立10个node用来做实验
		PNode pHead_1 = &node[0]; //指向头结点
		PNode pHead_2 = NULL;

		//给node赋值
		for (; i < 10; ++i)
			node[i]._val = i;
		//构成一个单链表
		for (i = 0; i < 9; ++i)
			node[i]._pNext = &node[i + 1];
	
		node[9]._pNext = NULL; //注意，最后一个节点的_pNex赋为NULL，则链表不存在环
	
		pHead_2 = &node[indx]; //给pHead_2赋值

		PNode pTemp = Is_Has_Intersection_2(pHead_1, pHead_2);

		if (pTemp)
			std::cout << "存在交点：" << pTemp->_val << std::endl;
		else
			std::cout << "不存在交点" << node[9]._val<<std::endl;
	}
	
	system("pause");
	return 0;
}