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
	assert(NULL == pos); //��Ȼɾ��ĳ���ڵ㣬�Ͳ���ΪNULL

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
//������õݹ�ʵ��
void Print_List_From_Tail_To_Head(PNode pHead)
{
	if (NULL == pHead)
		return;

	Print_List_From_Tail_To_Head(pHead->_pNext);

	std::cout << pHead->_val << " ";
}


int main()
{
	int i = 0;
	Node node[10] = new[] Node;
	Node node[10] = { 0 }; //����10��node������ʵ��
	PNode pHead = &node[0]; //ָ��ͷ�ڵ�

	//��node��ֵ
	for (; i < 10; ++i)
		node[i]._val = i;
	//����һ��������
	for (i = 0; i < 9; ++i)
		node[i]._pNext = &node[i + 1];

	node[9]._pNext = NULL; //ע�⣬���һ���ڵ��_pNex��ΪNULL�����������ڻ�



	Delete_Not_Tail_Node(&node[1]);
	Print_List_From_Tail_To_Head(pHead);
	std::cout<<std::endl;
	

	system("pause");
	return 0;
}