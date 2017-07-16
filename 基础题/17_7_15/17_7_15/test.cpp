/*
1.�������⡿--�ж������Ƿ�������������󻷵ĳ��ȣ��������󻷵���ڵ㣿����������ÿ�������ʱ�临�Ӷȣ�

2.�������⡿--1.���һ���಻�ܱ��̳� 2.���һ����ֻ���ڶ��ϴ������� 3.���һ����ֻ����ջ�ϴ�������

ps�������������������Ƶġ�
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
	int _val;
	struct ListNode *_pNext;
}Node, *PNode;


/*
�ж������Ƿ������

˼·����������ָ�룺��ָ������ָ��
��ָ��fast��ÿ������������
��ָ��slow��ÿ����һ����
��������л����򣬿���ָ��������ײ�غϵĻ��ᡣ
���û�������ָ�룬�ջ�ָ��NULL��

ע�⣺������ײ�㡣

ʱ�临�Ӷȣ�O()
*/
PNode Is_Has_Ring(PNode pHead)
{
	//��ʱ��pHead�Ƿ�Ϊ�գ������߼��ж�֮�ڴ���
	PNode pFast = pHead;
	PNode pSlot = pHead;

	while (pFast && pFast->_pNext)
	{
		pFast = pFast->_pNext->_pNext;
		pSlot = pSlot->_pNext;

		if (pFast == pSlot) //�����ڵ����ʱ�˳�
			break;
	}

	if ((NULL == pFast) || (NULL == pFast->_pNext))
		return NULL;

	return pFast;
}

/*
�������л��ĳ���
˼·�����Ȼ�ȡ��ײ���λ�á�Ȼ�󣬿���ָ���ٴ��ߣ�ֱ���ٴ��غ�ʱ��ָ�����ߵĲ�����ʹ�����ȡ�
*/
int Get_Length_Of_Ring(PNode pHead)
{
	PNode pFast = Is_Has_Ring(pHead);
	PNode pSlot = pFast;
	int length = 0;

	if (NULL == pFast) //��������
		return 0;

	//����ָ���ٴ�����ʱ����ָ��Ĳ�������ʾ���ĳ��ȡ�
	do
	{
		pFast = pFast->_pNext->_pNext;
		pSlot = pSlot->_pNext;
		++length;
	} while (pFast != pSlot);

	return length;
}


/*
�������л�����ڵ�
˼·�������Ƶ������Ĺ�ʽ��
����ָ����ײ�㵽��ڵĲ�������ͷ�ڵ㵽��ڵĲ�����
��ʱ�������ߵĲ���һ�����Ҿ�������ڵ㡣

ʱ�临�Ӷȣ�O()
*/
PNode Get_Entrance_Of_Ring(PNode pHead)
{
	PNode pColl = Is_Has_Ring(pHead); //��ȡ��ײ��

	if (NULL == pColl) //��������
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
	Node node[10] = { 0 }; //����10��node������ʵ��
	PNode pHead = &node[0]; //ָ��ͷ���
	PNode pTemp = NULL; //ָ������K���ڵ�
	int k = 0;

	//��node��ֵ
	for (; i < 10; ++i)
		node[i]._val = i;
	//����һ��������
	for (i = 0; i < 9; ++i)
		node[i]._pNext = &node[i + 1];
	node[9]._pNext = &node[6]; //ע�⣬ͨ��node[9]._pNextָ��������Ԫ�������ɻ�

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