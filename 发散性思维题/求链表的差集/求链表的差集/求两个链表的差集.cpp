/*
题目描述：
已知集合A和B的元素分别用不含头结点的单链表存储，函数difference()用于求解集合A与B的差集，
并将结果保存在集合A的单链表中。例如，若集合A={5,10,20,15,25,30}，集合B={5,15,35,25}，完成计算后A={10,20,30}。 

链表结点的结构类型定义如下： 
struct node 
{ 
int elem; 
node* next; 
}; 
请完成函数void difference(node** LA , node* LB)；


思路：
穷举法
*/

/*
#include <iostream>
#include <cassert>

using namespace std;

typedef struct node
{
	node(int val = int())
		: elem(val)
		, next(nullptr)
	{}
	int elem;
	node* next;
}node;

void difference(node **LA, node *LB) //注意，LA是二级指针，因为有可能修改链表头结点指向。
{
	assert(nullptr != LA);
	assert(nullptr != *LA);
	assert(nullptr != LB);

	node *pPre = nullptr; //指向pa先驱节点
	node *pa = *LA;		//指向LA中的节点
	node *pb = LB;		//指向LB中的节点
	node *pTemp = nullptr; //临时指针

	//循环LA中的节点，每次都在LB中寻找
	while (pa)
	{
		pb = LB; //每次循环重新赋值，从LB头开始，遍历LB
		while (pb && (pa->elem != pb->elem))
			pb = pb->next;

		if (pb)  //说明找到了。（注意：此处不能用pa->elem == pb->elempb作为判定条件，因为只要pb不为空，才有可能比较）
		{
			//此时pb->elem == pb->elem，找到了两个链表中值相同的节点，进行删除操作
			//判断删除的是否是LA的头结点
			if (nullptr == pPre) //直接对LA进行操作，修改链表头指向（注意LA是二级指针）
				*LA = pa->next; 
			else  //不是头结点
				pPre->next = pa->next;

			pTemp = pa;		
			pa = pa->next; //更新pa
			delete pTemp;
			pTemp = nullptr;
		}
		else	//遍历完LB，还是没有找到与pa->elem相同的节点。
		{
			pPre = pa;	//更新前驱节点
			pa = pa->next;	//更新pa
		}
	}
}

void Test();

int main()
{
	Test();

	system("pause");
	return 0;
}

void PrintList(node *pnode)
{
	while (pnode)
	{
		cout << pnode->elem << "->";
		pnode = pnode->next;
	}
	cout << "nullptr"<< endl;
}

void Test()
{
	node *p1 = new node[10];
	node *p2 = new node[5];

	int i = 0;
	for (; i < 10; ++i)
		p1[i].elem = i;
	for (i = 0; i < 10-1; ++i)
		p1[i].next = &p1[i + 1];


	for (i = 0; i < 5; ++i)
		p2[i].elem = i * 2;
	for (i = 0; i < 5-1; ++i)
		p2[i].next = &p2[i + 1];

	node *list1 = &p1[0];
	node *list2 = &p2[0];
	PrintList(list1);//PrintList(list1);也可以
	PrintList(list2);

	difference(&list1, list2);//difference(&p1, p2);会出问题，分析？

	PrintList(list1);//PrintList(list1);也可以
	PrintList(list2);
}

*/
//，若集合A={5,10,20,15,25,30}，集合B={5,15,35,25}，完成计算后A={10,20,30}。 
#include <iostream>
using namespace std;
struct node
{
	node(int data) :elem(data), next(NULL)
	{}

	int elem;
	node* next;

};
//A={5,10,20,15,25,30
node* creat(int arr[], int size)
{
	node* phead = new node(arr[0]);//头结点
	node* pcur = phead;
	//node* pnew=NULL;
	for (int i = 1; i<size; i++)
	{
		node* pnew = new node(arr[i]);
		pcur->next = pnew;
		pcur = pnew;
	}
	return phead;
}
void difference(node** LA, node* LB)
{
	node* pa = *LA;
	node* pb = LB;
	node* pre = NULL;
	node* temp = NULL;
	while (pa)
	{
		pb = LB;//保证每次从LB的第一个节点找起
		while (pb&&pb->elem != pa->elem)//寻找PB中和PA相同的元素
			pb = pb->next;
		if (pb)//找到了
		{

			if (NULL == pre)//PA是头结点
				*LA = pa->next;
			else
			{
				pre->next = pa->next;//连接前后节点
			}
			temp = pa;
			pa = pa->next;
			free(temp);

		}
		else//没找到PA中的当前节点，继续寻找PA的下一个节点
		{
			pre = pa;
			pa = pa->next;
		}

	}

}
void print(node* l)
{
	node* pcur = l;
	while (pcur)
	{
		cout << pcur->elem << " ";
		pcur = pcur->next;

	}
	cout << endl;
}
int main()
{
	int A[] = { 5,10,20,15,25,30 };
	int B[] = { 5,15,35,25 };
	node* la = creat(A, sizeof(A) / sizeof(A[0]));
	node* lb = creat(B, sizeof(B) / sizeof(B[0]));
	difference(&la, lb);
	print(la);

	system("pause");
	return 0;
}