/*
�������⡿--���� / ��ת������ + ���ҵ�����ĵ�����k���ڵ㣬Ҫ��ֻ�ܱ���һ������
*/


/*
ע�����δ��봦����ǲ������ĵ�����
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
	int _val;
	struct ListNode* _pNext;
}Node, *PNode;

/*
���� / ��ת������:
˼·��������������ָ����������������ڵ㡣
1����ͷ����ָ����ΪNUL
2����ͷ������Ľڵ���ѭ���иı�ָ��
	��һ��ָ�벻�䣬�����м�ָ���ָ�򣬱���������ָ���ָ����Ϊ������������·����
	������������ÿ�������м�ڵ��ָ��ͨ���������ڵ�����������������ڵ�ָ������������һ���ڵ㡣
	���ոı���������
ͨ������˼·���������Ϊ���������
1������Ϊ�ա�
2������ֻ����1���ڵ㡣
3��������2�������Ͻڵ㡣
*/
PNode ReverseList(PNode pHead)
{ 
	PNode pPre = NULL;	//��һ��ָ�룬ָ�������ڵ��еĵ�һ���ڵ㣬���ճ�Ϊ�µ�ͷ���ָ�롣
	PNode pCur = NULL;  //�ڶ���ָ�룬ָ�������ڵ��еĵڶ����ڵ㣬�޸�_pNextָ���ָ�롣
	PNode pTail = NULL; //������ָ�룬ָ�������ڵ��еĵ������ڵ㣬�����뵥�������ӵ�ָ�롣

	//����Ϊ�յ����
	if (NULL == pHead)
		return NULL;

	//����ֻ��һ���ڵ�����
	if (NULL == pHead->_pNext)
		return pHead;

	//������2�������Ͻڵ�����

	pPre = pHead;
	pCur = pPre->_pNext;
	pTail = pCur->_pNext;

	//����pHead��_pNextָ��
	pHead->_pNext = NULL;

	//����ͷ���֮��Ľڵ�_pNextָ��
	while (pCur)
	{
		pCur->_pNext = pPre;
		pPre = pCur;
		pCur = pTail;

		if (pTail) //��������������ʱ����ʾpTailΪNULL����һ��ѭ����pCurҲNULL����������ѭ����
			pTail = pTail->_pNext;
	}

	//��ʱpPreָ������µ�ͷ���
	return pPre;
}

/*
���ҵ�����ĵ�����k���ڵ㣬Ҫ��ֻ�ܱ���һ������:

˼·��ͨ������ָ�룬һ��ǰָ�룬һ����ָ�롣
1������ָ�룬��ʼ����ָ�������ͷ��㡣
2��ǰָ������K����Ȼ��ͺ�ָ��һ�������ߡ�
3��ֱ��ǰָ��ָ��NULL��

ע�⣬����K�Ĵ�С�뵥������Ԫ�ظ����ıȽϡ����Է�Ϊ:
1,K��ֵ���ڵ�������Ԫ�ظ�����
2��K��ֵС�ڵ��ڵ�������Ԫ�ظ�����
���ǣ�������Ԫ�ظ���������ͨ������֮�󣬲���֪����
���ԣ�������ǰָ��������K���Ĺ����У���K-1����֮ǰ����Ҳ�ж�ǰָ���Ƿ�ΪNULL��
���ǰָ��ΪNULL����ʾ������Ԫ�ظ���С��K��������ڵ���K��
*/
PNode Find_the_penultimate_K_node(PNode pHead, size_t k)
{
	//ʹ����������ʶǰ����ָ�롣pHead�Ƿ�ΪNULL����Ӱ������߼���
	PNode pLeft = pHead;
	PNode pRigth = pHead;

	if (0 == k)
		return NULL;

	//ǰָ����������K��
	while (k && pLeft)
	{
		pLeft = pLeft->_pNext;
		--k;
	}

	if (k) //��ʾԪ�ظ���С��K
		return NULL;

	//�ߵ���һ����˵��������Ԫ�ظ������ڵ���K��Ȼ��ǰ��ָ�뿪ʼһ�������ߡ�ֱ��ǰָ��ΪNULL
	while (pLeft)
	{
		pLeft = pLeft->_pNext;
		pRigth = pRigth->_pNext;
	}

	//���ص�����K���ڵ�ָ�롣
	return pRigth;
}

//��ӡ������
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
	Node node[10] = {0}; //����10��node������ʵ��
	PNode pHead = &node[0]; //ָ��ͷ���
	PNode pTemp = NULL; //ָ������K���ڵ�
	int k = 0;

	//��node��ֵ
	for (; i < 10; ++i)
		node[i]._val = i;
	//����һ��������
	for (i = 0; i < 9; ++i)
		node[i]._pNext = &node[i + 1];
	node[9]._pNext = NULL; //ע�⣬���һ���ڵ�ָ��NULL

	PrintList(pHead);	//��ӡ�ɵĵ�����

	pTemp = Find_the_penultimate_K_node(pHead, 5); //Ѱ�ҵ�����K���ڵ�
	printf("Find the penultimate K node is %d\n", pTemp->_val);

	pHead = ReverseList(pHead); //���õ�����
	PrintList(pHead); //��ӡ�µĵ�����

	system("pause");
	return 0;
}