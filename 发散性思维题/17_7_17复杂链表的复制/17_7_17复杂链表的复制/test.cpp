/*
�������⡿--��������ĸ��ơ�һ�������ÿ���ڵ㣬��һ��ָ��nextָ��ָ����һ���ڵ㣬����һ��randomָ��ָ����������е�һ������ڵ����NULL������Ҫ��ʵ�ָ�������������ظ��ƺ��������

ps : ��������Ľṹ

	typedef struct ComplexNode {

	DataType _data; // ���� 

	struct ComplexNode * _next; // ָ����һ���ڵ��ָ�� 

	struct ComplexNode * _random; // ָ������ڵ㣨�����������е�����ڵ� or �գ� 

}ComplexNode;

*/

#include <iostream>

typedef int DataType;
typedef struct ComplexNode 
{
	DataType _data; // ���� 
	struct ComplexNode * _next; // ָ����һ���ڵ��ָ�� 
	struct ComplexNode * _random; // ָ������ڵ㣨�����������е�����ڵ� or �գ� 
}ComplexNode;

/*
˼·��
�����ֽ���취��
��һ�֣�
1������һ����������һ��������ֻ����_data�Լ�_next��
2���ٴα���ԭ��������ȡÿ�α����ڵ��_random����һ��ѭ���У��ٴα���������ȡ_randomָ���λ�õ�ͷ���ĳ��ȡ����������У�Ҳָ�����λ�á�
ʱ�临�Ӷȣ�O(n^2)

�ڶ��֣�
1������ԭ��������ÿ��ѭ���У��ھɽڵ�������һ���½ڵ㡣��ӵ��½ڵ��_data����ǰ���ڵ��_data��
2���ڶ��α���������ɺ�����������½ڵ��_randomָ�����ھɽڵ��_randomָ��ڵ��_next.
3�����ݣ���ż������������������
ʱ�临�Ӷȣ�O(n)


��Ҫע��������
1����������ΪNULL
2����������ֻ��һ���ڵ�
3������������һ�����Ͻڵ�
*/

ComplexNode* Copy(ComplexNode* pHead)
{
	if (NULL == pHead)  //����ΪNULL
		return NULL;

	ComplexNode* pNewHead = NULL; //�������������ͷ���

	if (NULL == pHead->_next)  //����ֻҪһ���ڵ�
	{
		pNewHead = new ComplexNode;
		pNewHead->_data = pHead->_data;
		pNewHead->_next = NULL;
		pNewHead->_random = pHead->_random;
		return pNewHead;
	}

	//1����ӽڵ㣬���½ڵ��_data,_next��ֵ
	ComplexNode* pCur = pHead;
	while (pCur)
	{
		ComplexNode* pTemp = new ComplexNode;
		pTemp->_data = pCur->_data;
		pTemp->_next = pCur->_next;
		pTemp->_random = NULL;  //��ʱ������

		pCur->_next = pTemp;

		pCur = pTemp->_next;
	}

	//2�����½ڵ��_random��ֵ
	pCur = pHead;
	while (pCur)
	{
		//ָ�����ָ��Ľڵ�ĺ�һ���ڵ㣨�¿��ٵĽڵ㣩��
		if (pCur->_random)
			pCur->_next->_random = pCur->_random->_next;
		else
			pCur->_next->_random = NULL;

		pCur = pCur->_next->_next; //ÿ��������
	}

	//3��������ӽڵ�������
	pNewHead = pHead->_next;
	pCur = pHead;   //ָ�������е�����λ��
	ComplexNode* pCur_2 = pNewHead; //ָ�������е�ż��λ��
	while (pCur)
	{
		pCur->_next = pCur_2->_next;
		pCur = pCur->_next;

		if (pCur)
		{
			pCur_2->_next = pCur->_next;
			pCur_2 = pCur_2->_next;
		}
	}
	pCur_2->_next = NULL; //ע�⣬���һ���ڵ��next����ָ��ɽڵ㡣

	return pNewHead;
}

void Print(ComplexNode* pHead)
{
	while (pHead)
	{
		std::cout << pHead->_data << "->";
		pHead = pHead->_next;
	}
	std::cout << "NULL" << std::endl;
}

int main()
{
	ComplexNode* p = new ComplexNode[10];

	for (int i = 0; i < 9; ++i)
	{
		p[i]._data = i;
		p[i]._next = &p[i + 1];
		p[i]._random = NULL;
	}
	p[9]._data = 9;
	p[9]._next = NULL;
	p[9]._random = NULL;

	p[1]._random = &p[1];
	p[2]._random = &p[3];
	p[5]._random = &p[2];
	p[7]._random = &p[9];

	Print(p);

	ComplexNode* pNewHead = Copy(p);

	//�ڵ��Դ��ڣ����Բ鿴pNewHead�нڵ��_random�Ƿ����

	Print(pNewHead);

	system("pause");
	return 0;
}