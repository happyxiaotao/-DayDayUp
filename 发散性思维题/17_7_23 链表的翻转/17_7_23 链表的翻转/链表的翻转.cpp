/*
��Ŀ������
����ת������һ�������һ����k��
��������1��2��3��4��5��6��
k=2����ת��2��1��4��3��6��5��
��k=3,��ת��3��2��1��6��5��4��
��k=4����ת��4��3��2��1��5��6��
�ó���ʵ��Node* RotateList(Node* list, size_t k).
��ʾ����������������õ���������
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
����ĿҪ���֪��
k=0��1ʱ���൱��û���޸���������ֱ�ӷ��ء�
k>1ʱ����Ҫ�Ͽ�����������k-1���������⻹��һ����������ǰk���ڵ������ڵ�

��Ҫ���Ƿ�Ϊ
1�������ҿջ�ֻ��һ���ڵ㡣
2��������2�����Ͻڵ㡣

����k��Ҫ��ֻ�����������õĻ�����������Ƽ��ɡ�
*/
Node* RotateList(Node* list, size_t k)
{
	//ע����k���ڵ�������ڵ����ʱ�������ǰ�����ȫ��ת

	//������Ϊ�գ���ֻ��һ���ڵ�,��kΪ0��1
	if (nullptr == list || nullptr == list->m_pNext || 0 == k || 1 == k) 
		return list;

	//����ڵ�������ڵ���2������k>1 �����
	//ͨ������ָ������ת����
	Node *pPre = list;
	Node *pCur = pPre->m_pNext;
	Node *pTail = pCur->m_pNext;

	//���������һ�Σ�����ѭ��k-1��
	while (pCur && k>1)
	{
		pCur->m_pNext = pPre;

		pPre = pCur;
		pCur = pTail;

		//��pTailΪNULL��pCur=NULL,��ʾ���һ���ڵ��Ѿ���ת���ˣ��´�ѭ��������
		if (pTail)	
			pTail = pTail->m_pNext;

		--k;  //��ת��һ���ڵ�
	}
	
	//��pTail��Ϊnullptrʱ����ʱk=1����ʾ���������kֵС�ڽڵ��������ʱpTailָ���k+1���ڵ㡣
	//��pTailΪnullptrʱ����ʱk>=1����ʾ����ڵ����С�ڵ���k������ȫ��ת����
	//���ԣ�����pTailΪ��ΪNULL��list->m_pNext��Ҫָ��pCur�����������֡�
	list->m_pNext = pCur;

	//��ʱpCurָ���µ�ͷ���
	return pPre; 
}

//��ӡ������
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
	Node node[10] = { 0 }; //����10��node������ʵ��
	Node *pHead = &node[0]; //ָ��ͷ���

	//��node��ֵ
	for (; i < 10; ++i)
		node[i].m_data = i+1;
	//����һ��������
	for (i = 0; i < 9; ++i)
		node[i].m_pNext = &node[i + 1];
	node[9].m_pNext = NULL; //ע�⣬���һ���ڵ�ָ��NULL

	cout << "��תǰ��";
	PrintList(pHead);   //��ӡ�ɵĵ�����

	//��תǰk���ڵ�
	int k = 3;
	pHead = RotateList(pHead, k);

	cout << "��תǰ��";
	PrintList(pHead); //��ӡ�µĵ�����

	system("pause");
	return 0;
}