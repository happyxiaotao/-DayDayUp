/*
�������⡿
1.�ж����������Ƿ��ཻ�����ཻ���󽻵㡣����������������
2.�ж����������Ƿ��ཻ�����ཻ���󽻵㡣������������ܴ������������桿
*/

#include <iostream> //����C++���뻷����

typedef struct ListNode
{
	int _val;
	ListNode* _pNext;
}Node, *PNode;


//��ȡ���нڵ��п���ָ�����ײ�㡣
PNode Get_Impact_Point(PNode pHead);
//��ȡ���������л�����ڵ�
PNode Get_Entrance_Point(PNode pHead);
//�ж����������Ƿ��ཻ�����ཻ���󽻵㡣����������������
PNode Is_Has_Intersection(PNode pHead_1, PNode pHead_2);
//�ж����������Ƿ��ཻ�����ཻ���󽻵㡣������������ܴ������������桿
PNode Is_Has_Intersection_2(PNode pHead_1, PNode pHead_2);


/*
1.�ж����������Ƿ��ཻ�����ཻ���󽻵㡣����������������

˼·��
����״̬��
1���ж��Ƿ��п�����
2���ж����������Ƿ���ͬһ������
3��������һ����������������pHead_1������pHead_2��һ���ֵ������

���״̬����
�����������������ཻ����ʾ�ӽ��ڵ㿪ʼ�����������еĽڵ�һֱ��ͬ��
��ô������������һ���ڵ�Ҳ��ͬ�����Ե���һ���ж�������
������������������ཻ��������һ�������ͷβ�ڵ�����������һ�������ĵ�����
��������ͱ�Ϊ�ˣ������������Ļ�����ڵ㡣
*/
PNode Is_Has_Intersection(PNode pHead_1, PNode pHead_2)
{
	if ((NULL == pHead_1) || (NULL == pHead_2)) //���п�����ʱ��û�н��㡣
		return NULL;

	if (pHead_1 == pHead_2) //�������������ͨ��һ������������
		return pHead_1;

	PNode pTail_1 = pHead_1;  //����ָ��pHead_1��β�ڵ�
	PNode pTail_2 = pHead_2;  //����ָ��pHead_2��β�ڵ�

	while (pTail_1->_pNext)   
		pTail_1 = pTail_1->_pNext;  
	while (pTail_2->_pNext)
		pTail_2 = pTail_2->_pNext;

	if (pTail_1 != pTail_2)  //�����������һ���ڵ㲻��ȣ�˵��û���ཻ��
		return NULL;  

	//�ߵ����˵��pTail_1 = pTail_2�����������ཻ�����濪ʼ�󽻵㡣
	//������һ�������ͷ�����β�ڵ�������������������ṹ��һ����������
	//�����Ϊ�����������Ļ�������ˡ�

	//1���������������Ϊ����������(pHead_2Ϊ�µ�ͷָ��)
	pTail_1->_pNext = pHead_1;
	//2���󻷵���ڡ�������д�ĺ�����
	PNode pCross = Get_Entrance_Point(pHead_2);

	return pCross;
}

//��ȡ���нڵ��п���ָ�����ײ�㡣
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

	if ((NULL == pFast) || (NULL == pFast->_pNext)) //����ʹ��pFast!=pSlow��Ϊ�ж�������������ֻ��һ��Ԫ��ʱ�������
		return NULL;
	
	return pFast;
}


//��ȡ���������л�����ڵ�
//��һ����Ҫע�⣬����������������һ��������ô���صĽڵ�ͻ���ͷ���
PNode Get_Entrance_Point(PNode pHead)
{
	PNode pImpact = Get_Impact_Point(pHead);
	if (NULL == pImpact) //�����в����ڻ�
		return NULL; 

	//ͷ��㵽��ڵ�ĳ�����Ϊ��X
	//���ĳ�����ΪR
	//��ײ�㵽��ڵĳ�����Ϊ��R1
	//ͨ�����㣨ǰһƪ������д�У��������Ƶ�������ĳһ��n��nΪ�Ǹ���������ʹ�ã�X = nR + R1.
	//���ԣ�ͷ������ײ��ͬʱ������ ���ջ�����ڵ�������
	while (pImpact != pHead)
	{
		pImpact = pImpact->_pNext;
		pHead = pHead->_pNext;
	}
	//��ʱ�����߶�����ڵ㴦��������ڵ�λ�á�
	return pImpact; 
}


//2.�ж����������Ƿ��ཻ�����ཻ���󽻵㡣������������ܴ������������桿
/*
˼·:
���ж����������Ƿ���ͬһ������������
1����ͬ��ֱ�ӷ���ͷ��㡣
2������ͬ���������ߡ�
���ж����������Ƿ������
1����������--->�ж������������������Ƿ��ཻ�����ཻ���󽻵㡣
2��һ��������һ��������---->���뽻
3��������������---->���ཻ�����ǹ��еģ����ж�����1����ײ���Ƿ�������2�Ļ��С�
*/
//��������дΪ��
PNode Is_Has_Intersection_2(PNode pHead_1, PNode pHead_2)
{
	//���ڿ����������ڽ���
	if ((NULL == pHead_1) || (NULL == pHead_2))
		return NULL;

	//�������������ͬһ��������ֱ�ӷ���ͷ��㡣
	if (pHead_1 == pHead_2)
		return pHead_1;

	PNode pCross = NULL; //����

	//��ȡ�������ָ�����ײ�㣬������ڣ���˵�������л�
	PNode pImpact_1 = Get_Impact_Point(pHead_1);
	PNode pImpact_2 = Get_Impact_Point(pHead_2);

	//��������--->�ж������������������Ƿ��ཻ�����ཻ���󽻵㡣
	if ((NULL == pImpact_1) && (NULL == pImpact_2))
	{
		pCross = Is_Has_Intersection(pHead_1, pHead_2);
		return pCross;
	}

	//һ��������һ��������---->���뽻
	if (pImpact_1 || pImpact_2) 
		return NULL;

	//������������---->���ཻ�����ǹ��еģ����ж�����1����ײ���Ƿ�������2�Ļ���
	
	PNode pCur = pImpact_2;   //��Ϊ����pHead_2��ָ�� 
	//��Ҫע����ǣ��ڱ���pHead_2ʱ�����pHead_1����ײ�㲻��pHead_2�Ļ��У�����ѭ��
	//���ԣ���Ҫ��pHead_2����ײ�㣬��ʼ������ֱ���ٴ�������ײ�㡣
	while (pCur != pImpact_1)
	{
		pCur = pCur->_pNext;
		if (pCur == pImpact_2) //��ֹ��ѭ��
			break;
	}
	//pHead_1����ײ��pImpact_1��pHead_2�Ļ��У����ཻ
	if (pCur == pImpact_1)
		pCross = Get_Entrance_Point(pHead_1);

	return pCross;
}



int main()
{
	std::cout << "�������������" << std::endl;
	for (int indx = 0; indx < 10; ++indx)
	{
		int i = 0;
		Node node[10] = { 0 }; //����10��node������ʵ��
		PNode pHead_1 = &node[0]; //ָ��ͷ���
		PNode pHead_2 = NULL;

		//��node��ֵ
		for (; i < 10; ++i)
			node[i]._val = i;
		//����һ��������
		for (i = 0; i < 9; ++i)
			node[i]._pNext = &node[i + 1];
	
		node[9]._pNext = NULL; //ע�⣬���һ���ڵ��_pNex��ΪNULL�����������ڻ�
	
		pHead_2 = &node[indx]; //��pHead_2��ֵ

		PNode pTemp = Is_Has_Intersection_2(pHead_1, pHead_2);

		if (pTemp)
			std::cout << "���ڽ��㣺" << pTemp->_val << std::endl;
		else
			std::cout << "�����ڽ���" << node[9]._val<<std::endl;
	}
	
	system("pause");
	return 0;
}