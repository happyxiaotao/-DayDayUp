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

typedef struct ListNode
{
	int _val;
	ListNode* _pNext;
}Node, *PNode;


/*1.删除一个无头单链表的非尾节点
思路：

*/

/*
2.从尾到头打印单链表


*/

int main()
{


	system("pause");
	return 0;
}