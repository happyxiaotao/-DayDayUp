/*
1.�������⡿--1.ɾ��һ����ͷ������ķ�β�ڵ� 2.��β��ͷ��ӡ������

ps:����Ļ�����Ƚϼ򵥣�������������С���ˡ�

2.�������⡿--��������ĸ��ơ�һ�������ÿ���ڵ㣬��һ��ָ��nextָ��ָ����һ���ڵ㣬����һ��randomָ��ָ����������е�һ������ڵ����NULL������Ҫ��ʵ�ָ�������������ظ��ƺ��������

ps: ��������Ľṹ

typedef struct ComplexNode{

DataType _data ; // ����

struct ComplexNode * _next; // ָ����һ���ڵ��ָ��

struct ComplexNode * _random; // ָ������ڵ㣨�����������е�����ڵ� or �գ�

}ComplexNode;
*/

#include <iostream>
#include <cassert>
#include <stack>
typedef int DataType;
typedef struct ListNode
{
	DataType _val;
	ListNode* _pNext;
}Node, *PNode;


/*1.ɾ��һ����ͷ������ķ�β�ڵ�
˼·��
�����Ŀ��ɾ���ڵ����ף������Ѿ������������ɾ��֮��ֳ������ֵ�����
����˼���������ֽڽⷨ��
1�����������ָ��Ļ���һ��ָ��ɾ���ڵ��ǰ����һ��ָ��ɾ���ڵ㣬һ��ָ��ɾ���ڵ�ĺ�̡�
2���ڶ��ְ취��ɾ���ڵ㽫���ĺ�̽ڵ��ֵ�������Լ���Ȼ��ɾ����̽ڵ㡣Ч����һ���ġ�
*/
//������õڶ��ַ���
void Delete_Not_Tail_Node(PNode pos) //������ʾ���Ǳ���ɾ�����Ǹ���β�ڵ�
{
	assert(NULL != pos); //��Ȼɾ��ĳ���ڵ㣬�Ͳ���ΪNULL

	if (NULL == pos->_pNext) //pos��β�ڵ�
		return; 

	PNode pDelete = pos->_pNext; //��Ҫɾ���ĺ�̽ڵ�
	pos->_val = pDelete->_val; //ȡ������
	pos->_pNext = pDelete->_pNext; //������̽ڵ㣬ָ���̵ĺ��

	delete pDelete;
	pDelete = NULL;
}

/*
2.��β��ͷ��ӡ������
˼·��
1�����õݹ�����ԣ��Ӻ���ǰ���ر��������ݡ�
2������ջ�洢ÿ�α�����ֵ��Ȼ���ջ��
*/

//����ջʵ��
void Print_Lis_From_Tal_To_Head_1(PNode pHead)
{
	std::stack<PNode> s;

	while (pHead)
	{
		s.push(pHead);
		pHead = pHead->_pNext;
	}

	while (!s.empty())
	{
		PNode pTemp = s.top();
		std::cout << pTemp->_val << " ";
		s.pop();
	}
}

//������õݹ�ʵ��
void Print_List_From_Tail_To_Head_2(PNode pHead)
{
	if (NULL == pHead)
		return;

	Print_List_From_Tail_To_Head_2(pHead->_pNext);

	std::cout << pHead->_val << " ";
}


int main()
{
	int i = 0;
;	
	//����10��Node������ʵ��
	PNode pHead = new Node; //ָ��ͷ�ڵ�
	pHead->_val = 0;
	pHead->_pNext = NULL;
	PNode pCur = pHead;
	//��������
	for (int i = 1; i < 10; ++i)
	{
		Node* pTemp = new Node;
		pTemp->_val = i;
		pTemp->_pNext  = NULL;
		pCur->_pNext = pTemp;
		pCur = pCur->_pNext;
	}

	//Delete_Not_Tail_Node(pHead->_pNext);
	Print_Lis_From_Tal_To_Head_1(pHead);
	//Print_Lis_From_Tal_To_Head_2(pHead);
	std::cout<<std::endl;
	
	system("pause");
	return 0;
}